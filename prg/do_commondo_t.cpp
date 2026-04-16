//
#include "2.h"
#include "env_t.h"
#include "d_config_t.h"
#include "de_log_t.h"
#include "CJsonObject.h"
#include "g06.h"
#include "d_session_t.h"
#include "d_fcw_rpcmain_t.h"
#include "do_commondo_t.h"
#include "gfunc_md5.h"
#include "d_keyque0_t.h"
#include "d_ui_mngr_t.h"



// 
do_commondo_t::do_commondo_t()
{
	//LinkFc( gp_d_fcw_candy );
	LinkFcHigh( gp_fc_rpcmain );
}



// 
do_commondo_t::~do_commondo_t()
{ 
}


 
// 
tbool do_commondo_t::lingy( const std::string &strFn , WNava &para , const std::string &strWholePara , funcandy_t::actwebele_t *pweb )
{
	if( pweb->m_strCmdVerb != "POST" ) return 0;

	neb::CJsonObject oJson;
	neb::CJsonObject oj2;  
	std::string strRecv;
	std::string strCmd;

	//// 判断是否本页使用的方法 
	//if( strFn != "commondo.html.do" )
	//{
	//	return 0;		
	//}

	pweb->ckPostBody.mk_str( strRecv );
	oJson.Parse( strRecv );

	//if( oJson.Get2( "pathname" ) != "/a.html" )
	//{
	//	return 0;		
	//}

	oJson.Get( "cmd", strCmd );

	do{
		if( this->cd_com_ver( oJson, oj2, strCmd, pweb ) ) break;
		if( this->cd_com_longpull_consume( oJson, oj2, strCmd, pweb ) ) break;	
		if( this->cd_com_butt_event( oJson, oj2, strCmd, pweb ) ) break;

		return 0;		

		// BAD_CMD 
		if(1)
		{
			oj2.Add( "rc" , (int)0 );
			oj2.Add( "msg" , "unknown cmd:" + strCmd );
		}
	}while(0);


	oj2.Add( "time" , SDte::GetNow().ReadString() );
	oj2.Add( "remote_ip" , pweb->m_tSvr.GetRemoteIPAddress() );

	pweb->RtnWebContent_Header( "application/json" );  

	std::string s1;
	std::string s2;

	s1 = oJson.ToFormattedString();
	s2 = oj2.ToFormattedString();

	//GOOD_CMD
	std::string strOut;

	strOut = oj2.ToFormattedString();
	strOut += "\r\n";
	strOut += "\r\n";

	pweb->RtnWebContent_Body( strOut );  

	return 1;
}



//
tbool do_commondo_t::cd_com_ver( neb::CJsonObject &jinput, neb::CJsonObject &joutput, std::string strCmd, funcandy_t::actwebele_t *pweb )
{
	if( strCmd != "com_ver" ) return 0;
		
	std::string str_cmd_id = jinput.Get2( "cmd_id" );
	std::string str_fp = jinput.Get2( "fp" ); 
	std::string str_location_href = jinput.Get2( "location_href" );
	std::string str_pagepathname = jinput.Get2( "pagepathname" );   //   = "/a.html"  

	std::string s1;
	char sz[999];
	SDte dtt;

	s1 = jinput.ToFormattedString();

	s1 = WThrd::tr_GetCurrentThreadId();

#ifdef LINUENV_
	pid_t ii;
	ii = getpid();
	s1 = SStrf::b2s( ii );
#endif

	sprintf( sz, "%s %s %s___%s<br> " , 
					gp_env->m_strName.c_str() , 
					gp_env->m_strVer.c_str() , 
					gp_env->m_strSysVerInternal.c_str() , 
						s1.c_str() 
					);

	joutput.Add( "ver" , sz );
	joutput.Add( "ver1" , gp_env->m_strName );
	joutput.Add( "ver2" , gp_env->m_strVer );
	joutput.Add( "ver3" , gp_env->m_strSysVerInternal );
	joutput.Add( "ver4" , gp_env->m_strMainThrdId );
	joutput.Add( "ip" , pweb->m_tSvr.GetRemoteIPAddress() );

	dtt.MakeNow();
	
	joutput.Add( "time" , dtt.ReadString() );

	joutput.Add( "cmd_id" , str_cmd_id );
	joutput.Add( "rc" , (int)1 );

	joutput.Add( "debug_msg", 
							pweb->m_tSvr.GetRemoteIPAddress() + " " + 
							gp_env->m_strVer + " " +
							SDte().MakeNow().ReadString() + " " +
							strCmd
							);
	return 1;
}



//
tbool do_commondo_t::cd_com_longpull_consume( neb::CJsonObject &jinput, neb::CJsonObject &joutput, std::string strCmd, funcandy_t::actwebele_t *pweb )
{
	if( strCmd != "cd_com_longpull_consume" ) return 0;

	//MYLOG2OBJ;

	std::string str_cmd_id = jinput.Get2( "cmd_id" );
	std::string str_fp = jinput.Get2( "fp" );
	std::string str_location_href = jinput.Get2( "location_href" );
	std::string str_pagepathname = jinput.Get2( "pagepathname" );
	

	gp_d_ui_mngr->um_longpull_consume_page_paint( joutput, jinput, str_pagepathname );


	joutput.Add( "cmd_id" , str_cmd_id );
	joutput.Add( "rc" , (int)1 );
 
	return 1;
}



//
tbool do_commondo_t::cd_com_butt_event( neb::CJsonObject &jinput, neb::CJsonObject &joutput, std::string strCmd, funcandy_t::actwebele_t *pweb )
{
	if( strCmd != "cd_com_butt_event" ) return 0;

	//MYLOG2OBJ;

	std::string str_cmd_id = jinput.Get2( "cmd_id" );
	std::string str_fp = jinput.Get2( "fp" ); 
	std::string str_location_href = jinput.Get2( "location_href" );
	std::string str_pagepathname = jinput.Get2( "pagepathname" );
	
 
	std::string strj;

	strj = jinput.ToFormattedString();
	gp_job_butt_event->k_send_job( strj );

	//MYLOG( "str_pathname=" << str_pathname );
	//MYLOG( "strj=" << strj );


	joutput.Add( "cmd_id" , str_cmd_id );
	joutput.Add( "rc" , (int)1 );
 
	return 1;
}



