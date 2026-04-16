
#ifndef K1_d_ui_mngr_T_H
#define K1_d_ui_mngr_T_H


#include "2.h"
#include "CJsonObject.h"
#include "bu_quickflow_t.h"



//   
class d_ui_mngr_t 
{
private:
	WCrsc  m_lckDev;

public:
	th_eonsera_t  m_eea_pub; 

private:
	std::string  m_curr_pagepathname;


public:
	d_ui_mngr_t();
	virtual ~d_ui_mngr_t();

public:
	void um_longpull_consume_page_paint( neb::CJsonObject &joutput, neb::CJsonObject jinput, std::string str_pagepathname );
	void um_page_paint_update( std::string str_pagepathname, std::string str_jsblock, std::string str_para = "" );
	std::string um_get_curr_pagepathname();
};


extern d_ui_mngr_t  *gp_d_ui_mngr;



std::string doj_label_txt( std::string name, std::string txt );
std::string doj_text_value( std::string name, std::string txt );
std::string doj_goto_url( std::string str_url );
std::string doj_nop();




#endif



