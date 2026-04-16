
//
#include "env_t.h"
#include "de_log_t.h"
#include "d_config_t.h"
#include "CJsonObject.h"
#include "bu_asynwork_t.h"
#include "bu_quickflow_t.h"
#include "g06.h"
#include "d_keyque0_t.h"
#include "d_ui_mngr_t.h"
#include "d_ui_p1_a_html_t.h"



d_ui_mngr_t  *gp_d_ui_mngr;



#define BD_MYLOG MYLOG 
//#define BD_MYLOG   

 

#define TRY_NEW_PAGE(Classname,Pagepathname)\
		if(1)\
		{\
			Classname *pu = new Classname;\
			pu->m_eea.eo_align(&(this->m_eea_pub));\
			pu->m_my_pagepathname = Pagepathname;\
			if( pu->m_my_pagepathname == this->um_get_curr_pagepathname() ) { pu->tr_openx(); break; }\
			this->m_eea_pub.eo_move();\
			pu->tr_openx();\
		}\



//
d_ui_mngr_t::d_ui_mngr_t()
{
	MYAUTOLOCK(m_lckDev);

	// this->m_eea_pub, init , no need. 
	this->m_curr_pagepathname = "";
}


//
d_ui_mngr_t::~d_ui_mngr_t()
{
	MYAUTOLOCK(m_lckDev);
	this->m_eea_pub.eo_move();
}



//
void d_ui_mngr_t::um_longpull_consume_page_paint( neb::CJsonObject &joutput, neb::CJsonObject jinput, std::string str_pagepathname ) 
{
	std::string str_pagepathname_old;
	tbool rc_pagepathname_change_occur(0);

	std::string strCmd = jinput.Get2( "cmd" );
	std::string str_cmd_id = jinput.Get2( "cmd_id" );
	std::string str_fp = jinput.Get2( "fp" );
	std::string str_location_href = jinput.Get2( "location_href" );  	// std::string str_bigtoken = jinput.Get2( "bigtoken" );  // 	std::string str_pagepathname = jinput.Get2( "pathname" ); 

	if( str_pagepathname == "" )
	{
		//return 0; 空没问题，向下走...
	}

	str_pagepathname_old = um_get_curr_pagepathname();


	if( str_pagepathname_old != str_pagepathname )  // 换页面事件	
	{
		rc_pagepathname_change_occur = 1;
	}


	if( rc_pagepathname_change_occur )
	{
		MYAUTOLOCK(m_lckDev);
		
		this->m_eea_pub.eo_move();  // 旧的 全报废 

		BD_MYLOG( m_curr_pagepathname << "  new=" << str_pagepathname );

		m_curr_pagepathname = str_pagepathname; 
		// 此时 m_curr_pagepathname 已更新
	}
	
	if( rc_pagepathname_change_occur )	  // 换页面事件 销毁旧页面 	
	{
		// 新页面名称 已登记。 
		for( int i = 0; i < 3; i++ )		// work around  
		{
			this->m_eea_pub.eo_move();
			//MYLOG( "*--登--** m_curr_pagepathname=" << um_get_curr_pagepathname() );
			this->um_page_paint_update( um_get_curr_pagepathname(), doj_nop() ); 
			//MYLOG( "*--登--** str_pagepathname_old=" << str_pagepathname_old );
			this->um_page_paint_update( str_pagepathname_old, doj_nop() ); 
		}
	}

	if( rc_pagepathname_change_occur )		// 换页面事件 创造新页面	---------------------------------
	{
		do{
			TRY_NEW_PAGE( d_ui_p1_a_html_t,	 "/a.html" )
			//TRY_NEW_PAGE( d_ui_p2send3gcmd_t,  "/p2send3gcmd.html" )
		}while(0);
	}		 


	// consume 
	int i_job_type;
	std::string str_nv_job;
	WNava nv;

	i_job_type = gp_job_page_paint->k_get_job( str_nv_job );


	if( str_nv_job == "" )
	{
		joutput.Add( "havejsblock" , (int)0 );
		//MYLOG( "*-** havejsblock=0, m_curr_pagepathname=" << m_curr_pagepathname );
		return;
	}

	nv.unserialize( str_nv_job );

	joutput.Add( "pagepathname" , nv.get("pagepathname") );
	joutput.Add( "havejsblock" , (int)SStrf::satol(nv.get("havejsblock")) );
	joutput.Add( "jsblock" , nv.get("jsblock") );
	joutput.Add( "para" , nv.get("para") );
}



//
void d_ui_mngr_t::um_page_paint_update( std::string str_pagepathname, std::string str_jsblock, std::string str_para/* = ""*/ )
{
	WNava nv;
	
	//MYLOG( "*----** str_pagepathname=" << str_pagepathname );
	//MYLOG( "*----** str_jsblock=" << str_jsblock );

	nv.let( "pagepathname", str_pagepathname );
	nv.let( "havejsblock", "1" );
	nv.let( "jsblock", str_jsblock );
	nv.let( "para", str_para );

	gp_job_page_paint->k_send_job( nv.serialize() );
}



//
std::string d_ui_mngr_t::um_get_curr_pagepathname()
{
	MYAUTOLOCK(m_lckDev);

	return m_curr_pagepathname;
}




//# =================================================================================

//
std::string doj_label_txt( std::string name, std::string txt )
{
	std::string sj = 
		"(function () \n"
		"{ \n"
		"var f1 = \n"
		"function() \n"
		"{ \n"
		"//window.location.href = \"http://www.baidu.com?aa=bb\"; \n"
		"}; \n"
		"var f2 = \n"
		"function() \n"
		"{ \n"
		"document.getElementById(\"$$$1$\").innerHTML = \"$$$2$\"; \n"
		"}; \n"
		"setTimeout( f2, 1 ); \n"
		"})(); \n";

	SStrf::sreplstr( txt, "\"", "\\\"" );
	//SStrf::sreplstr( txt, "\"", "&quot;" );
	SStrf::sreplstr( txt, "&",  "&amp;" );
	SStrf::sreplstr( txt, "<",  "&lt;" );
	SStrf::sreplstr( txt, ">",  "&gt;" );
	SStrf::sreplstr( txt, " ",  "&nbsp;" );
	SStrf::sreplstr( txt, "\r", ""  );
	SStrf::sreplstr( txt, "\n", "<br />" );

	SStrf::sreplstr( sj, "$$$1$", name );
	SStrf::sreplstr( sj, "$$$2$", txt );

	return sj;
}



// 清空value值，并置焦点。	
std::string doj_text_value( std::string name, std::string txt )
{
	std::string sj = 
		"(function () \n"
		"{ \n"
		"var f2 = \n"
		"function() \n"
		"{ \n"
		"document.getElementById(\"$$$1$\").value = \"$$$2$\"; \n"
		"document.getElementById(\"$$$1$\").focus();\n"
		"}; \n"
		"setTimeout( f2, 1 ); \n"
		"})(); \n";

	SStrf::sreplstr( txt, "\"", "\\\"" );
	//SStrf::sreplstr( txt, "\"", "&quot;" );
	SStrf::sreplstr( txt, "&",  "&amp;" );
	SStrf::sreplstr( txt, "<",  "&lt;" );
	SStrf::sreplstr( txt, ">",  "&gt;" );
	SStrf::sreplstr( txt, " ",  "&nbsp;" );
	SStrf::sreplstr( txt, "\r", ""  );
	SStrf::sreplstr( txt, "\n", "<br />" );

	SStrf::sreplstr( sj, "$$$1$", name );
	SStrf::sreplstr( sj, "$$$2$", txt );

	return sj;
}



//
std::string doj_goto_url( std::string str_url )
{
	std::string sj = 
		"(function () \n"
		"{ \n"
		"var f1 = \n"
		"function() \n"
		"{ \n"
		"window.location.href = \"$$$3$\"; \n"
		"}; \n"
		"var f2 = \n"
		"function() \n"
		"{ \n"
		"document.getElementById(\"$$$1$\").innerHTML = \"$$$2$\"; \n"
		"}; \n"
		"setTimeout( f1, 1 ); \n"
		"})(); \n";

	SStrf::sreplstr( sj, "$$$3$", str_url + "?aaa=" + WFile::MkRUStr()  );

	return sj;
}



//
std::string doj_nop()
{
	std::string sj = 
		"(function () \n"
		"{ \n"
		"var f1 = \n"
		"function() \n"
		"{ \n"
		"var jj = { };\n"
		"jj.fp = get_the_fp();  \n"
		"jj.cmd_id = String( Math.random() );\n"
		"var ss = JSON.stringify(jj);\n"
		"}; \n"
		"setTimeout( f1, 1 ); \n"
		"})(); \n";

	return sj;
}




