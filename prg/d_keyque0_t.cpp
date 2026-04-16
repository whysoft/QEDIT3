//
#include "env_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "d_keyque0_t.h"



d_keyque0_t  *gp_job_page_paint; 
d_keyque0_t  *gp_job_butt_event; 



//
d_keyque0_t::d_keyque0_t()
{
	///////=====================================================================
	if( IsOsWin() )
	{
		m_SIZE = 33; 
	}
	else
	{
		m_SIZE = 22; 
	}

	this->k_init();
}


//
d_keyque0_t::~d_keyque0_t()
{
	MYAUTOLOCK(m_lckDev);
}


//
int d_keyque0_t::tr_on_user_run()
{
	WThrd::tr_sleepu( 9 + SStrf::rand1() + 8 * SStrf::rand1() );
	WThrd::tr_sleepu( 0.99 );

	if( m_eea.eo_is_out() )
	{
		this->k_send_idle_job();
		return 0;
	}

	this->k_send_idle_job();
	return 1;
}


// 
tbool d_keyque0_t::k_init()  
{		
	MYAUTOLOCK(m_lckDev);

	static tuint16 PortCurrUse = 61011;
	tuint16 PortOut;
	tbool rc(0);

	while(!rc)
	{
		rc = this->m_Ki_job.KeyInit( PortCurrUse, &PortOut );
		printf( "rc=%d, the KeyInit PortOut=%d\n", (int)rc, (int)PortOut );
		if(rc) break;
		WThrd::tr_sleepu( 0.11 );
	}

	this->tr_openx();
	PortCurrUse = PortOut + 1;
	if( PortCurrUse > 61011 ) PortCurrUse = 59011;

	return 1;
}
 

// 
void d_keyque0_t::k_send_idle_job()  
{
	if(1)
	{
		MYAUTOLOCK(m_lckDev);

		if( (int)m_lot_job_type.size() > m_SIZE ) 
		{
			if( !IsOsWin() )
			{
				this->m_Ki_job.other_release();
				this->m_Ki_job.me_lock();
			}
			return;
		}

		m_lot_job_type.push_back( 0 );
		m_lot_job_content.push_back( "" );

	int i;

	i = (int)m_lot_job_type.size();
	//printf( "%s k_send_idle_job, job_type.size=[%d]\n", WThrd::tr_GetCurrentThreadId().c_str(), i );

	}

	this->m_Ki_job.other_release();
}
 

// 
void d_keyque0_t::k_send_job( std::string str_job_content )  
{
	if(1)
	{
		MYAUTOLOCK(m_lckDev);

		if( (int)m_lot_job_type.size() > m_SIZE ) 
		{
			if( !IsOsWin() )
			{
				this->m_Ki_job.other_release();
				this->m_Ki_job.me_lock();
			}
			return;
		}

		m_lot_job_type.push_back( 1 );
		m_lot_job_content.push_back( str_job_content );
	}

	this->m_Ki_job.other_release();
}

 

// 
int d_keyque0_t::k_get_job( std::string & ref_str_job_content )  
{
	this->m_Ki_job.me_lock();		

	if(1)
	{
		MYAUTOLOCK(m_lckDev);

		std::string s1 = "";
		int itype(0);

		int i(0);

		i = (int)m_lot_job_type.size();
		//printf( "job_type.size=[%d]\t", i );

		if(i)
		{
			itype = m_lot_job_type.front();
			s1   =  m_lot_job_content.front();

			m_lot_job_type.pop_front();
			m_lot_job_content.pop_front();
		}

		ref_str_job_content = s1;

		return itype;
	}
}


// 
void d_keyque0_t::k_clear_alljobs()
{
	MYAUTOLOCK(m_lckDev);
 
	m_lot_job_type.clear();
	m_lot_job_content.clear();
}


