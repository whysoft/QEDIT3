//
#include "2.h"
#include "env_t.h"
#include "de_log_t.h"
#include "cli_ter_t.h"



cli_ter_t  *gp_cli_ter;


 
//
cli_ter_t::cli_ter_t()	
{
	m_iTerCounter = 0;
}


//
cli_ter_t::~cli_ter_t()	
{
}



//
void cli_ter_t::clean_proc_env()
{
	//std::string strRunCmdLine;
	
	//strRunCmdLine = "killall xclip";
	//if( !IsOsWin() ) WFile::run_exe( strRunCmdLine );
}



//
void cli_ter_t::do_ter_direct()
{
	//WThrd::tr_sleepu( 0.1 );
	//exit( 0 );
}


	
//
void cli_ter_t::do_ter_timeout()
{
	//RiseTerFlag();

	if( !IsOsWin() )
	{
		//WFile::run_exe( "sudo reboot" );
	}
}




//
void cli_ter_t::ResetTerCounter()
{
	m_iTerCounter = 0;
}


//
void cli_ter_t::RiseTerFlag()
{
	WFile f;
	
	f.bind( gp_env->m_strName + "_ter.txt" ); // exit the process
	f.write_str( "aaa" );
}


//
void cli_ter_t::ter_chance()
{
	WFile f;
	
	f.bind( gp_env->m_strName + "_ter.txt" ); // exit the process
	
	if( f.exists() )
	{
		MYLOG( f.filename() ); 

		f.erase();
		this->do_ter_direct();
	}

	m_iTerCounter ++;

	if( m_iTerCounter > 5 ) 
	{
		this->do_ter_timeout();
	}
}



