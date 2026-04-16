//
#include "2.h"
#include "env_t.h"
#include "d_config_t.h"
#include "de_log_t.h"
#include "CJsonObject.h"
#include "d_session_t.h"
#include "d_fcw_hightlog_t.h"
#include "d_fcw_rpcmain_t.h"


 

// 
d_fcw_hightlog_t::d_fcw_hightlog_t()
{
	//LinkFc( gp_d_fcw_candy );
	LinkFcHigh( gp_fc_rpcmain );
}



// 
d_fcw_hightlog_t::~d_fcw_hightlog_t()
{ 
}



//	
tbool d_fcw_hightlog_t::lingy( const std::string &strFn , WNava &para , const std::string &strWholePara , funcandy_t::actwebele_t *pweb )
{
	neb::CJsonObject oJson;
	std::string str1;
	std::string str2;

	pweb->ckPostBody.mk_str( str1 );
	oJson.Parse( str1 );
	oJson.Get( "cmd", str2 );

	//printf( "%d\t`%s`---`%s`\t`%s`\n", (int)(pweb->m_tSvr.m_myport), strFn.c_str(), strWholePara.c_str() , str2.c_str() ); 

	if( str1.length() > 456 )
	{
		str1 = str1.substr( 0, 456 );
	}

	//MYLOG2( 
	//		" port=" << (int)(pweb->m_tSvr.m_myport) << 
	//		" remoteip=" << pweb->m_tSvr.m_strRemoteIPAddress << 
	//		" fn="   << strFn << 
	//		" wholepara=" << strWholePara << 
	//		" cmd=" << str2 << 
	//		" json_workload=" << str1 
	//	); 

	return 0;
}




