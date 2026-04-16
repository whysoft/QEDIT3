
#include "env_t.h"
#include "bu_asynwork_t.h"
#include "CJsonObject.h"
#include "d_session_t.h"
#include "d_config_t.h"



//
bu_asynwork_t::bu_asynwork_t() 
{
	m_f = NULL;
}


//
bu_asynwork_t:: ~bu_asynwork_t()
{
	tr_destruct();
}



// 
int bu_asynwork_t::tr_on_user_run()
{
	if(m_f) (this->*m_f)();
	return 0;
}


//-----------------

//
void bu_asynwork_t::Do_demo( std::string s1 )
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::Do_demo_m;

	paw->m_para.let( "a", s1 );

	paw->tr_openx();
}

//
void bu_asynwork_t::Do_demo_m()
{
	std::string s1;

	s1 = m_para.get( "a" );

	WThrd::tr_sleepu( 1.7 );
	
	printf( "%s\n", s1.c_str() );
}



//-----------------

//
void bu_asynwork_t::Do_exit()
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::Do_exit_m;

	paw->tr_openx();
}

//
void bu_asynwork_t::Do_exit_m()
{
	//gp_conf->m_biSysShouldExit = 1;
		
	WThrd::tr_sleepu( 0.06 );

	exit( 0 );
}


//-----------------

//
void bu_asynwork_t::DoPf( void (*pf)() )
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::DoPf_m;
	
	paw->m_para.let( "a", SStrf::b2s(pf) );

	paw->tr_openx();
}

//
void bu_asynwork_t::DoPf_m()
{
	void (*pf)();

	SStrf::s2b( m_para.get("a"), pf );

	pf();
}



//-----------------

//
void bu_asynwork_t::DoPfEra( void (*pf2)(int*,int), int *pera, int era2 )
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::DoPfEra_m;
	
	paw->m_para.let( "a", SStrf::b2s(pf2) );
	paw->m_para.let( "b", SStrf::b2s(pera) );
	paw->m_para.let( "c", SStrf::b2s(era2) );

	paw->tr_openx();
}

//
void bu_asynwork_t::DoPfEra_m()
{
	void (*pf2)(int*,int);
	int *pera;
	int era2;

	SStrf::s2b( m_para.get("a"), pf2 );
	SStrf::s2b( m_para.get("b"), pera );
	SStrf::s2b( m_para.get("c"), era2 );
	(*pf2)(pera,era2);
}



//-----------------

//
void bu_asynwork_t::Do_reboot()
{
	bu_asynwork_t  *paw;

	SStrf::newobjptr(paw);
	paw->m_f = &bu_asynwork_t::Do_reboot_m;

	paw->tr_openx();
}

//
void bu_asynwork_t::Do_reboot_m()
{
	const char *s = "sudo reboot&";

	WThrd::tr_sleep( 3 );

	if( IsOsWin() )
	{
		printf( "%s\n", s );
		WThrd::tr_sleepu( 2 );
	}
	else
	{
		WFile::run_exe( "sync" ); 
		WFile::run_exe( s ); 
	}
}



//-----------------


