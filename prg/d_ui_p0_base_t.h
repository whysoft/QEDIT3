
#ifndef K1_D_UI_P0_BASE_T_H
#define K1_D_UI_P0_BASE_T_H


#include "2.h"
#include "bu_quickflow_t.h"




// 是线程。在线程中启动FSM。	 
class d_ui_p0_base_t : public WThrd  
{
public:
	wl::th_eonsera_t  m_eea;
	std::string  m_my_pagepathname;

public:
	d_ui_p0_base_t();
	virtual ~d_ui_p0_base_t();

	virtual void tr_on_pre_thrd();
	virtual void tr_on_post_thrd();
	virtual int tr_on_user_run(); 

	virtual void flow(){}

public:
	tbool detect_is_eea_or_page_change(); 	// 时代变迁...和页面变迁.....  
};




#endif



