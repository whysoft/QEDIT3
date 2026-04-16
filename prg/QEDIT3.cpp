//
#include "2.h"
#include "env_t.h"
#include "de_log_t.h"
#include "d_keyque0_t.h"
#include "cli_ter_t.h"
#include "d_config_t.h"
#include "bu_asynwork_t.h"
#include "g06.h"
#include "CJsonObject.h"
#include "bu_quickflow_t.h"
#include "d_fcw_rpcmain_t.h"
#include "d_session_t.h"
#include "d_fcw_hightlog_t.h"
#include "d_fcw_pagesupport_t.h"
#include "d_cmdcli_t.h"
#include "d_ui_mngr_t.h"
#include "do_commondo_t.h"
#include "d_uiproc_t.h"



//	 
int main( int argc, char* argv[] )
{
	int mainrc(0);

	gp_env = new env_t();
	gp_env->SeeCmdLn( argc, argv );


	// WNava nvCmdLn;
	WNava &nvCmdLn( gp_env->m_nvCmdLn );

	// keyque job
	gp_job_page_paint = new d_keyque0_t;
	gp_job_butt_event = new d_keyque0_t;
	
	gf_show_sizeof();
	//bu_asynwork_t::DoPf( test_gen_job1 );  
	//bu_asynwork_t::DoPf( test_gen_job2 );  
	//test_use_job();


	d_cmdcli_t cli;

	cli.m_nvCmdLn = nvCmdLn;

	if( cli.cc_process() )
	{
		mainrc = cli.m_mainrc;
		goto L_MAINEND;
	}

	// 命令行解析 -c 空，就不做事.  
	if( nvCmdLn.get( "-c" ) == "nop" )
	{
		printf( "%s %s\n", gp_env->m_strName.c_str(), gp_env->m_strVer.c_str() );
		printf( "%s\n", gp_env->m_strHelp.c_str() );
		mainrc = 33;
		goto L_MAINEND;
	}


	gp_env->MkDirs();

	// log
	gp_log = new de_log4_t();
	gp_log->Init( gp_env->GetLOGDir(), "LOG1", 22 );
	LOGSTREAM( *gp_log, LOGPOSI << "==========================---------------====================" ); 
	MYLOG( "Init" << "==========================--====----------===============" ); 
	MYLOG( gp_env->m_strName ); 
	MYLOG( gp_env->m_strVer ); 
	MYLOG( gp_env->m_strSysVerInternal ); 

	//log2
	gp_log2 = new de_log4_t();
	gp_log2->Init( gp_env->GetLOGDir(), "LOG2", 22 );
	LOGSTREAM( *gp_log2, LOGPOSI << "==========================----------====================" ); 
	MYLOG2( "Init" << "==========================--====----------===============" ); 
	MYLOG2( gp_env->m_strName ); 
	MYLOG2( gp_env->m_strVer ); 
	MYLOG2( gp_env->m_strSysVerInternal ); 


	// ter 
	gp_cli_ter = new cli_ter_t; 
	gp_cli_ter->clean_proc_env();

	// config
	gp_conf = new d_config_t;
	gp_conf->InitConf();


	// ui proc
	gp_d_uiproc = new d_uiproc_t;


	if( nvCmdLn.get( "--help" ) != "" || nvCmdLn.get( "-help" ) != "" || nvCmdLn.get( "-h" ) != "" )
	{
		printf( "%s %s\n", gp_env->m_strName.c_str(), gp_env->m_strVer.c_str() );
		printf( "%s\n", gp_env->m_strHelp.c_str() );
		
		goto L_MAINEND;
	}

	// -c ter
	if( nvCmdLn.get( "-c" ) == "ter" )
	{
		gp_cli_ter->RiseTerFlag();
		
		goto L_MAINEND;
	}


	// 命令行解析 -c x1
	if( nvCmdLn.get( "-c" ) == "x1" )
	{
		test_x1();

		goto L_MAINEND;
	}


	// 命令行解析 -c install
	if( nvCmdLn.get( "-c" ) == "install" )
	{
		gp_d_uiproc->pr_install();

		goto L_MAINEND;
	}



	bu_asynwork_t::Do_demo( gp_env->m_strName );
	bu_asynwork_t::Do_demo( gp_env->m_strVer );
	bu_asynwork_t::Do_demo( gp_env->m_strSysVerInternal );
	bu_asynwork_t::Do_demo( gp_env->m_strMainThrdId );


	if( nvCmdLn.get( "-c" ) == "" || 
		nvCmdLn.get( "-c" ) == "svr" || 
		nvCmdLn.get( "-c" ) == "ui"	||
		nvCmdLn.get( "-c" ) == "loop_up"
	   )
	{
		// do work
		tbool rc;
		//tuint16 uiPortOut;
 

		// 会话权限控制	
		gp_d_session = new d_session_t;


		// 硬件 在 welcome页面里。	
		//gp_bd_ctrlboard = new bd_ctrlboard_t; 


		// ui管理  
		gp_d_ui_mngr = new d_ui_mngr_t;


		// 服务框架 
		gp_fc_rpcmain = new funcandy_t;
		while(1)
		{
			tuint16 &service_port(gp_env->m_service_port);

			rc = gp_fc_rpcmain->InitFlow( service_port ); 
			printf( "gp_fc init, rc=%d,Port=%d\n", (int)rc, (int)service_port );
			if(rc) break;
			WThrd::tr_sleep( 2 );
			service_port++;
		}

		// 服务细则  
		new d_fcw_pagesupport_t;
		//new do_p1welcome_t;
		new do_commondo_t;
		new d_fcw_hightlog_t; 


		//test1();
		//test2_list_tbl();
		//test2_seq();

		// FSA	
		//bu_asynwork_t::DoPf( fl_front_form );
		//bu_asynwork_t::DoPf( folder_purge );


		//if( nvCmdLn.get( "-c" ) == "ui" )
		{
			WThrd::tr_sleepu( 0.1 );
			gp_d_uiproc->pr_begin();
			gp_d_ui_mngr->m_eea_pub.eo_move();

			goto L_MAINEND;
		}


		while(1)
		{
			WThrd::tr_sleep( 2 );
			gp_cli_ter->ter_chance();
		}


		goto L_MAINEND;
	}


	//show error msg, 不能解释的命令行参数。	 
	printf( "%s %s\n", gp_env->m_strName.c_str(), gp_env->m_strVer.c_str() );
	printf( "i cannot explain command line.\n" );


L_MAINEND:
	
	gp_cli_ter->clean_proc_env();

	if( IsOsWin() )
	{
		//int i;
		//i = WFile::run_exe("pause");
	}
	
	WThrd::tr_sleepu( 1 * SStrf::rand1() );
	WThrd::tr_sleepu( 0.1 );
	//WThrd::tr_sleep( 1 );

	return mainrc;
}







