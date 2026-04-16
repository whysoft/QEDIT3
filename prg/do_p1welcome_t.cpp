//
#include "2.h"
#include "env_t.h"
#include "d_config_t.h"
#include "de_log_t.h"
#include "CJsonObject.h"
#include "d_session_t.h"
#include "d_fcw_rpcmain_t.h"
#include "do_p1welcome_t.h"
#include "d_keyque0_t.h"
#include "d_ui_mngr_t.h"



// 
do_p1welcome_t::do_p1welcome_t()
{
	//LinkFc( gp_fc_rpcmain );
	LinkFcHigh( gp_fc_rpcmain );
}



// 
do_p1welcome_t::~do_p1welcome_t()
{ 
}


 
// 
tbool do_p1welcome_t::lingy( const std::string &strFn , WNava &para , const std::string &strWholePara , funcandy_t::actwebele_t *pweb )
{
	if( pweb->m_strCmdVerb != "POST" ) return 0;

	neb::CJsonObject oJson;
	neb::CJsonObject oj2;  
	std::string strRecv;
	std::string strCmd;

	//// 判断是否本页使用的方法 
	//if( strFn != "p1welcome.html" )
	//{
	//	return 0;		
	//}
	std::string page_set = 
		"p1welcome.html \t"
		"p2choose_yesno.html \t"
		"";

	if( page_set.find(strFn) == std::string::npos )
	{
		return 0;		
	}


	pweb->ckPostBody.mk_str( strRecv );
	oJson.Parse( strRecv );

	//if( oJson.Get2( "pathname" ) != "/p1welcome.html" )
	//{
	//	return 0;		
	//}

	oJson.Get( "cmd", strCmd );

	do{
		// 安全模块 
		if( this->my_danger( oJson, oj2, strCmd, pweb ) ) break;

		//if( this->butt1_submit( oJson, oj2, strCmd, pweb ) ) break;
		//if( this->page_init( oJson, oj2, strCmd, pweb ) ) break;


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
tbool do_p1welcome_t::my_danger( neb::CJsonObject &jinput, neb::CJsonObject &joutput, std::string strCmd, funcandy_t::actwebele_t *pweb )
{
	//if( ! gp_d_session->ss_verify( jinput, joutput ) )
	//{
	//	return 1;
	//}

	return 0;
}


