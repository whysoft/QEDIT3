
#include "env_t.h"
#include "CJsonObject.h"
#include "d_session_t.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "de_log_t.h"
#include "g06.h"
#include "d_ui_mngr_t.h"
#include "d_ui_p1_util_timer_t.h"



//
d_ui_p1_util_timer_t::d_ui_p1_util_timer_t() 
{
}


//
d_ui_p1_util_timer_t:: ~d_ui_p1_util_timer_t()
{
}



// 
void d_ui_p1_util_timer_t::flow()
{
	// 窗体初始化 
	 //

	// 事件循环处理  
	while(1)
	{ 
		//WThrd::tr_sleepu( 0.1 );
		WThrd::tr_sleep( 1 );
		if( this->detect_is_eea_or_page_change() ) break;		// 时代变迁..和页面变迁..
		// -------------------------- --------    
			

		neb::CJsonObject jinput;
		std::string strj;

		jinput.Add( "cmd" , "local_timer" );
		jinput.Add( "cmd_id" , WFile::MkRUStr() );
		jinput.Add( "pagepathname" , this->m_my_pagepathname );
		jinput.Add( "sub1cmd" , "sub1cmd_local_timer" ); 
		
		strj = jinput.ToFormattedString();
		gp_job_butt_event->k_send_job( strj );
	}

	return;
}





