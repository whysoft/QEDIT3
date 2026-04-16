
#include "env_t.h"
#include "CJsonObject.h"
#include "d_session_t.h"
#include "cli_ter_t.h"
#include "d_config_t.h"
#include "bu_quickflow_t.h"
#include "de_log_t.h"
#include "g06.h"
#include "d_ui_mngr_t.h"
#include "d_ui_p1_a_html_t.h"
#include "d_ui_p1_util_timer_t.h"
#include "d_uiproc_t.h"




#define BD_MYLOG MYLOG 
//#define BD_MYLOG   



//
d_ui_p1_a_html_t::d_ui_p1_a_html_t() 
{
	//pm_job = new d_keyque0_t;
}


//
d_ui_p1_a_html_t:: ~d_ui_p1_a_html_t()
{
	//delete pm_job;  job 对象用eronsera 管理析构。	
		//Beep( 622, 333 );
}




// 
void d_ui_p1_a_html_t::flow()
{
	// 窗体初始化 
	 //
	d_ui_p1_util_timer_t *ptimer = new d_ui_p1_util_timer_t;

	ptimer->m_eea.eo_align( this->m_eea) ;
	ptimer->m_my_pagepathname = this->m_my_pagepathname;
	ptimer->tr_openx();

	std::vector< std::string > vec_text_main_lot;
	int text_main_lot_maxsize = 99;

	for( int i = 0; i < text_main_lot_maxsize; i++ )
	{
		vec_text_main_lot.push_back("");
	}

	std::string strTxt;
	std::string strDojs;  

	// 命令行参数  写到text_main 
	strTxt = gp_env->m_strCmdLn;
	if( !IsOsWin() ) WFile::Utf8toCh(strTxt); 
	strDojs = 
		"(function () \n"
		"{ \n"
		"var f2 = \n"
		"function() \n"
		"{ \n" 
		"set_text_main_value( g_js_para, 1 );\n"
		"}; \n"
		"setTimeout( f2, 0 ); \n"
		"})(); \n";

	gp_d_ui_mngr->um_page_paint_update( this->m_my_pagepathname, strDojs, strTxt ); 

	strTxt = "(显示字数统计)";
	strDojs = doj_label_txt( "div_label_sta", strTxt );
	gp_d_ui_mngr->um_page_paint_update( this->m_my_pagepathname, strDojs );


	// 事件循环处理  
	while(1)
	{
		// get input
		int i_job_type;
		std::string str_job; 
		neb::CJsonObject j_job_input; 
 
		if( this->detect_is_eea_or_page_change() ) break;		// 时代变迁..和页面变迁..
		i_job_type = gp_job_butt_event->k_get_job( str_job ); 
		if( this->detect_is_eea_or_page_change() ) break;		// 时代变迁..和页面变迁..
		// -------------------------- --------   
		if( i_job_type == 0 ) continue;
		if( str_job == "" ) continue;
		if( !j_job_input.Parse( str_job ) ) continue; 
			

		std::string str_cmd = j_job_input.Get2( "cmd" );
		std::string str_cmd_id = j_job_input.Get2( "cmd_id" );
		std::string str_fp = j_job_input.Get2( "fp" ); 
		std::string str_location_href = j_job_input.Get2( "location_href" );
		std::string str_pagepathname = j_job_input.Get2( "pagepathname" );
		std::string str_sub1cmd = j_job_input.Get2( "sub1cmd" );

		// 这里要比较一下 pagepathname
		if( str_pagepathname != gp_d_ui_mngr->um_get_curr_pagepathname() ) continue;


		// 各种区分事件 
		if( str_cmd == "local_timer" && str_sub1cmd == "sub1cmd_local_timer" )
		{
			// BD_MYLOG( "*-- sub1cmd_local_timer ----**  " << str_job );
			strTxt = SDte::GetNow().ReadString() + "-\"" + WThrd::tr_GetCurrentThreadId() + "\"-" + WFile::MkRUStr() + "-\"";
			strDojs = doj_label_txt( "div_time2", strTxt );
			gp_d_ui_mngr->um_page_paint_update( this->m_my_pagepathname, strDojs );
		}

		if( str_cmd == "cd_com_butt_event" && str_sub1cmd == "page_change_notify" )
		{
			BD_MYLOG( "*-- str_cmd=" << str_cmd << " --**  str_sub1cmd=" << str_sub1cmd << "***" << str_job );
			gp_d_ui_mngr->um_page_paint_update( this->m_my_pagepathname, doj_nop() ); 
		}

		if( str_cmd == "cd_com_butt_event" && str_sub1cmd == "page_butt" )  
		{
			BD_MYLOG( "*-- str_cmd=" << str_cmd << " --**  str_sub1cmd=" << str_sub1cmd << "***" << str_job );
			std::string str_sub2cmd = j_job_input.Get2( "sub2cmd" );
			std::string str_text_main = j_job_input.Get2( "text_main" ); 
			std::string str_text_sub = j_job_input.Get2( "text_sub" );

			#include "p1_ex_txt_into_clip_quit.xpp"
			#include "p1_ex_pic_into_clip_quit.xpp"
			#include "p1_ex_txt_into_clip_stay.xpp"
			#include "p1_ex_pic_into_clip_stay.xpp"
			#include "p1_ex_discard_quit.xpp"

			#include "p1_ex_clip_append_to_end.xpp"
			#include "p1_ex_clip_insert_to_begin.xpp"

			#include "p1_ex_undo_a.xpp"
			#include "p1_ex_trim_a.xpp"
			#include "p1_ex_reverse_a.xpp"
			#include "p1_ex_upper_case.xpp"  // 大小写都在此。	
			#include "p1_ex_url_encode.xpp"  // en de 写都在此。	
			#include "p1_ex_make_def_name.xpp"
			#include "p1_ex_keil_str_protect.xpp"
			#include "p1_ex_select_the_file.xpp"

			#include "p1_ex_replace_a.xpp"
			#include "p1_ex_add_head_tail.xpp"
			#include "p1_ex_one_line_use_trim.xpp"
			#include "p1_ex_one_line_use_join.xpp"
			#include "p1_ex_distinct_lines.xpp"
			#include "p1_ex_get_column.xpp"
			#include "p1_ex_hint_word.xpp"		  // 括号词 
			#include "p1_ex_yyyymmdd_hhmmss.xpp"  // dt 类的都在此。	

			windows_os_relative( str_sub2cmd, this->m_my_pagepathname, str_text_main, str_text_sub ); 

			#include "p1_ex_glb_write_string.xpp"
			#include "p1_ex_add_email_sign.xpp"
		}

		if( str_cmd == "cd_com_butt_event" && str_sub1cmd == "butt_shortcut" )
		{
			BD_MYLOG( "*-- str_cmd=" << str_cmd << " --**  str_sub1cmd=" << str_sub1cmd << "***" << str_job );
		
			std::string str_mykeycode = j_job_input.Get2( "mykeycode" );

			if( SStrf::satol(str_mykeycode) == 27 || SStrf::satol(str_mykeycode) == 112 )  //keycode 112 = F1
			{
				std::string str_sub2cmd = "txt into clip quit";
				std::string str_text_main = *(vec_text_main_lot.rbegin());
				std::string str_text_sub = j_job_input.Get2( "text_sub" );
				#include "p1_ex_txt_into_clip_quit.xpp"
			}
		
			if( SStrf::satol(str_mykeycode) == 115 )   		//keycode 115 = F4
			{
				std::string str_sub2cmd = "pic into clip quit";
				std::string str_text_main = *(vec_text_main_lot.rbegin());
				std::string str_text_sub = j_job_input.Get2( "text_sub" );
				#include "p1_ex_pic_into_clip_quit.xpp"
			}
		
			if( SStrf::satol(str_mykeycode) == 113 )   	//keycode 113 = F2
			{
				strDojs = doj_text_value( "text_main", "" );
				gp_d_ui_mngr->um_page_paint_update( this->m_my_pagepathname, strDojs ); 
			}

			if( SStrf::satol(str_mykeycode) == 114 )   	//keycode 114 = F3
			{
				strDojs = doj_text_value( "text_sub", "" );
				gp_d_ui_mngr->um_page_paint_update( this->m_my_pagepathname, strDojs ); 
			}
		}

		if( str_cmd == "cd_com_butt_event" && str_sub1cmd == "take_text_main_buf" )
		{
			//BD_MYLOG( "*-- str_cmd=" << str_cmd << " --**  str_sub1cmd=" << str_sub1cmd << "***" << str_job );
			BD_MYLOG( "*-- str_cmd=" << str_cmd << " --**  str_sub1cmd=" << str_sub1cmd << "***" );
		 
			std::string str_text_main = j_job_input.Get2( "text_main" );  
			std::string str_text_sub = j_job_input.Get2( "text_sub" );
				
			if( *(vec_text_main_lot.rbegin()) != str_text_main )
			{
				vec_text_main_lot.push_back(str_text_main);  // undo缓冲区，保存的是utf8原始值。 

				while( (int)vec_text_main_lot.size() > text_main_lot_maxsize )
				{
					vec_text_main_lot.erase( vec_text_main_lot.begin() );
				}	
			}
			
			std::string str1;
			std::vector< std::string > vec1;
			str1 = str_text_main;
			WFile::Utf8toCh(str1); 
			vec1 = gbstr_2_vec(str1); 

			strTxt = SStrf::sltoa((int)str_text_main.length()) + "(B) " + SStrf::sltoa((int)vec1.size()) + "(W) "; // 显示字数统计 
			strDojs = doj_label_txt( "div_label_sta", strTxt );
			gp_d_ui_mngr->um_page_paint_update( this->m_my_pagepathname, strDojs );
		}

	} // end while

	return;
}





