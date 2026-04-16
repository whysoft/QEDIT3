
//
#include "env_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "CJsonObject.h"
#include "bu_asynwork_t.h"
#include "g06.h"
#include "d_keyque0_t.h"
#include "d_ui_mngr_t.h"
#include "d_ui_p0_base_t.h"



#define BD_MYLOG MYLOG 
//#define BD_MYLOG   



//
d_ui_p0_base_t::d_ui_p0_base_t() 
{
	m_my_pagepathname = "";
}


//
d_ui_p0_base_t:: ~d_ui_p0_base_t()
{
}


//	
void d_ui_p0_base_t::tr_on_pre_thrd()
{}


//
void d_ui_p0_base_t::tr_on_post_thrd()
{}



//
int d_ui_p0_base_t::tr_on_user_run()
{
	if( this->m_eea.eo_is_out() ) return 0;
	this->flow();
	return 0;
}


//
tbool d_ui_p0_base_t::detect_is_eea_or_page_change()  	     
{
	if( gp_d_ui_mngr->um_get_curr_pagepathname() != this->m_my_pagepathname ) 
	{	
		// BD_MYLOG( "*--2----** this->m_str_my_pagepathname=" << this->m_str_my_pagepathname );
		return 1;
	}
		
	if( this->m_eea.eo_is_out() ) 
	{	
		//BD_MYLOG( "*--3----** =" << this->m_eonsera << "\t" << *(this->pm_eonsera_public) );
		return 1;
	}

	return 0;
}



