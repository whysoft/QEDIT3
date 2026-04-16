//
#include "2.h"
#include "env_t.h"
#include "de_log_t.h"


env_t  *gp_env;



//
env_t::env_t()	
{
	m_strName = "QEDIT3";
	m_strVer = "V1.53";
	m_strSysVerInternal = "20260414.230150" + std::string(" ") + std::string(__DATE__) + std::string(" ") + std::string(__TIME__) + std::string(" ");
	m_strHelp = "hello hello QEDIT3 help.";
	m_strMainThrdId = WThrd::tr_GetCurrentThreadId();

	this->m_service_port = 8066 + (int)( 22 * SStrf::rand1() );
}


//
env_t::~env_t()	
{
}


//
int env_t::tr_on_user_run()
{
	WThrd::tr_sleep( 33 );
	return 1;
}



//
void env_t::SeeCmdLn( int argc, char* argv[] )
{
	(this->m_nvCmdLn).InterpCmdLine( argc, argv );


	for( int i = 1; i < argc; i += 1 )
	{
		m_vecCmdLn.push_back(argv[i]);
		m_strCmdLn += argv[i] + std::string(" ");
	}
	SStrf::strim(m_strCmdLn);


	m_strCmdLnSelf = "";

#ifdef WINENV_  
	m_strCmdLnSelf = WMsg::GetProcExePathFilename();
#endif

#ifdef LINUENV_
	WFile::get_shellpipe_output( "realpath " + std::string(argv[0]), m_strCmdLnSelf );
#endif

	if( m_strCmdLnSelf == "" ) m_strCmdLnSelf = argv[0];
	SStrf::strim(m_strCmdLnSelf);   // 绝对路径  

}




//
void env_t::MkDirs()
{
	//////
	//MakeDiskEnv
	//WFile::makedir( this->GetDBDir() );
	WFile::makedir( this->GetLOGDir() ); 


	WFile::makedir( "TMPDATA" ); 
}



//
std::string env_t::GetLOGDir()
{
	std::string s1;

	s1 = this->m_strName;
	SStrf::sucase( s1 );

	return s1 + ".LOG";
}


//
std::string env_t::GetDBDir()
{
	std::string s1;

	s1 = this->m_strName;
	SStrf::sucase( s1 );

	return s1 + ".SDB";
}




////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


#include "A-bind_data.xpp"



#ifdef LINUENV_
#include <signal.h>
struct A
{
	A()
	{
		signal(SIGPIPE, signal_handler);
	}
	static void signal_handler(int sig)
	{
		if( sig==SIGPIPE ) return;
	}
};
static A aaaaa;
#endif





// 
bool IsOsWin()
{
#ifdef WINENV_
	return true;
#else
	return false;
#endif
}




//
bool IsExeCharSetUtf8()
{
	const char *p = "亖";
	if( p[2] ) return true;
	return false;
}



//
tbool copy_data_2_file( std::string strDataName, std::string strPFn )
{
	WFile fl;
	SCake ck;

	gfBINDDATA( strDataName.c_str(), NULL, NULL, &ck );
	fl.bind( strPFn );
	return fl.write( ck );
}



