//
#include "2.h"
#include "env_t.h"
#include "d_config_t.h"
#include "de_log_t.h"
#include "CJsonObject.h"
#include "d_session_t.h"
#include "d_fcw_pagesupport_t.h"
#include "d_fcw_rpcmain_t.h"




//	 
static tbool g18makeparts( std::string strPFn , std::vector< std::string > &vName, std::vector< std::string > &vVal )
{
	WFile fl;
	std::vector< std::string > vCont;
	std::string strOldName;
	std::string strCurrName;
	std::string *pstrCurrVal;

	fl.bind( strPFn );

	if( !fl.exists() ) 
	{
		return 0;
	}

	fl.read_vecstr( vCont, "\n", 1 );

	strOldName = strCurrName = "";
		
	vName.push_back( "" );
	vVal.push_back( "" );
	pstrCurrVal = &(vVal.back()); // 这3个是一组，保障name/val一样多，还保障最后一个val是可操作的
	 
	for( long j = 0; j < (long)vCont.size(); j++ )
	{
		SStrf::strim( vCont[j] );

		std::string s = vCont[j];

		if( s == "" ) 
		{
			//continue;
		}

		if( s.find( "<!--##" ) == 0 && 
			s.find( "#-->" ) != std::string::npos && 
			s.size() >= 10	)  //<!--###-->
		{
			SStrf::sreplstr( s, "<!--##", "" );
			SStrf::sreplstr( s, "#-->", "" );
			SStrf::strim(s);
			strCurrName = s;
		}
	
		if( strOldName != strCurrName )
		{
			strOldName = strCurrName;

			vName.push_back( strCurrName );
			vVal.push_back( vCont[j] );
			pstrCurrVal = &(vVal.back()); // 这3个是一组，保障name/val一样多，还保障最后一个val是可操作的
		}

		*pstrCurrVal += vCont[j] + "\r\n";
	}

	return 1;
}



// 
static std::string g18normalpage( const std::string &strPFn , WNava &wpara , funcandy_t::actwebele_t *pweb )
{
	if( strPFn == "" ) return "";

	std::stringstream stmOut;
	std::vector< std::string > vName;
	std::vector< std::string > vVal;

	if( !g18makeparts( strPFn , vName , vVal ) )
	{
		return "";
	}

	for( int j = 0; j < (int)vName.size(); j++ )
	{
		gp_d_session->html_part_replace_filter( vName[j], vVal[j], wpara, pweb ); /* 一个综合过滤器 */
		stmOut << vVal[j];
	}

	stmOut << "\r\n";
	stmOut << "\r\n";

	return stmOut.str();
}


	
// 需要任何文件资源时	 
static tbool g18openfile( const std::string &strFn , WNava &para , const std::string &strWholePara , funcandy_t::actwebele_t *pweb )
{
	std::string strFile;
	std::string strResRoot;
	std::string::size_type i;
	std::string strExt;
	SCake ck;
	SFile fl;

	if( strFn.empty() ) return 0;

	i = strFn.find(".");

	if( i == std::string::npos )
	{
		return 0;
	}
	
	strFile = strFn;

	strResRoot = "webres" + SFile::GetPathSep();
	 
	if( strFn.find("*") == 0 )
	{
		if( IsOsWin() )
		{
			strResRoot = "d:\\t\\";
			strFile = "aa.png";
		}
		else
		{
			strResRoot = "/tmp/picture/";
			strFile = strFn.c_str() + 1;
		}
	}
	 
	strExt = strFn.substr( i+1 );

	if( strExt == "css" ||
		strExt == "js" )
	{
		fl.bind( strResRoot + strFile );
		fl.read( ck );
	
		pweb->RtnWebContent( "text/" + strExt , "", &ck );

		return 1;
	}

	if( strExt == "html" ||
		strExt == "htm" )
	{
		//fl.bind( strResRoot + strFile );
		//fl.read( ck );
		//pweb->RtnWebContent( "text/" + strExt , "", &ck );

		pweb->RtnWebContent( "text/" + strExt , g18normalpage( strResRoot + strFile, para , pweb ) );

		return 1;
	}

	if( strExt == "jpg" ||
		strExt == "png" ||
		strExt == "gif" )
	{
		fl.bind( strResRoot + strFile );
		fl.read( ck );
	
		pweb->RtnWebContent( "image/" + strExt , "", &ck );

		return 1;
	}

	if( strExt == "pdf" ||
		strExt == "exe" ||
		strExt == "pdf" )
	{
		SCake ck2;

		ck2.lets( strFile );

		//MYLOG( "strFile=" << strFile );
		//MYLOG( "strFile=" << ck2.Seri_S() );

		fl.bind( strResRoot + strFile );
		if( !fl.exists() )
		{
			std::string s1 = strFile;
			SStrf::bs_de( s1, SStrf::bs_esc2 );
			if( IsOsWin() )
			{
				WFile::Utf8toCh(s1);
			}
			else
			{
				//WFile::Utf8toCh(s1);
			}
			fl.bind( strResRoot + s1 );
		}
		fl.read( ck );
	
		pweb->RtnWebContent( "application/" + strExt , "", &ck );

		return 1;
	}
	

	// 有时会求网站图标？ favicon.ico
	
	fl.bind( strResRoot + "logo.png" );
	fl.read( ck );
	
	pweb->RtnWebContent( "image/png" , "", &ck );

	return 1;
}



// 
d_fcw_pagesupport_t::d_fcw_pagesupport_t()
{
	LinkFc( gp_fc_rpcmain );
	//LinkFcHigh( gp_fc_rpcmain );
}



// 
d_fcw_pagesupport_t::~d_fcw_pagesupport_t()
{ 
}



//	
tbool d_fcw_pagesupport_t::lingy( const std::string &strFn , WNava &para , const std::string &strWholePara , funcandy_t::actwebele_t *pweb )
{
	tbool rc;

	rc = g18openfile( strFn , para , strWholePara , pweb );

	if( rc ) return 1;
	
	return 0;
}




