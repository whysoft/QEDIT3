
// 一段中文注释 
#include "2.h"
#include "env_t.h"
#include "d_config_t.h"
#include "de_log_t.h"
#include "CJsonObject.h"
#include "d_session_t.h"
#include "bu_asynwork_t.h"
#include "g06.h"
#include "gfunc_md5.h"
#include "d_uiproc_t.h"



d_uiproc_t  *gp_d_uiproc = NULL;



#ifdef LINUENV_
//
#else
// 
#endif



// 
d_uiproc_t::d_uiproc_t()
{
}



// 
d_uiproc_t::~d_uiproc_t()
{ 
}



// 
void do_delay_erase_py_relative()
{
	WFile fl;

	WThrd::tr_sleep( 3 );

	fl.bind( "ui.py" );
	fl.erase();

	fl.bind( "ui.py_args" );
	fl.erase();
}



//
void d_uiproc_t::pr_begin()
{
	std::string strResfile;
	std::string strDestfile;
	std::string strCmd;
	std::string strPara; 

	//if( IsOsWin() )
	//{
	//	strResfile = "SimpleEdit.exe.bin";
	//	strDestfile = "SimpleEdit.exe";
	//	strCmd = "SimpleEdit.exe";
	//	strPara = "QEDIT3_software http://127.0.0.1:8066/a.html?"+WFile::MkRUStr();
	//}

	//if( IsOsWin() )
	//{
	//	strResfile = "SimpleEdit.exe.bin";
	//	strDestfile = "SimpleEdit.exe";
	//	strCmd = "\"c:\\Program Files\\Mozilla Firefox\\firefox.exe\"";
	//	strPara = "--private-window --safe-mode  http://127.0.0.1:8066/a.html?"+WFile::MkRUStr();
	//}

	if( IsOsWin() )
	{
		strResfile = "WindowsApplication1.exe.bin";
		strDestfile = "TMPDATA\\WindowsApplication1.exe";
		strCmd = "TMPDATA\\WindowsApplication1.exe";
		strPara = SStrf::sltoa(gp_env->m_service_port);
	}

	if( !IsOsWin() )
	{
		strResfile = "ui.py";
		strDestfile = "ui.py";
		strCmd = "python3";
		strPara = "ui.py"; 

		WFile fl;
	
		fl.bind( "ui.py_args" );
        //# url = 'http://127.0.0.1:8066/a.html'
		fl.write_str( "http://127.0.0.1:" + SStrf::sltoa(gp_env->m_service_port) + "/a.html?"+WFile::MkRUStr() );

		bu_asynwork_t::DoPf( do_delay_erase_py_relative );
	} 

	copy_data_2_file( strResfile, strDestfile );
	
	m_run.Init( strCmd , strPara );
	m_run.Invoke();
	m_run.Wait();
}



//
void d_uiproc_t::pr_end()
{
	m_run.Kill();
	return;
}




//
tbool d_uiproc_t::pr_install()
{ 
	std::string strResfile;
	std::string strDestfile;
	std::string strResContent;
	SCake ck;
	WFile fl;
	std::string strCmd;
	std::string strHome; 
	tbool rc; 


	if( IsOsWin() )
	{
		std::cout << "IsOsWin=" << IsOsWin() << std::flush << std::endl; 
		std::cout << "not install." << std::flush << std::endl; 

		return 0;
	}
 
	// now is linux env.
	strResfile = "QEDIT3RUN.desktop.txt";
	strDestfile = "QEDIT3RUN.desktop";
	
	gfBINDDATA( strResfile.c_str(), NULL, NULL, &ck );
	strResContent = ck.mk_str();
	SStrf::sreplstr( strResContent, "/home/kat/QEDIT3RUN", SFile::GetDir(gp_env->m_strCmdLnSelf)  );  // 把执行目录换掉 
	
	strCmd = "echo $HOME";
	rc = WFile::get_shellpipe_output( strCmd, strHome );
	SStrf::strim(strHome);

	fl.bind( strHome + "/Desktop/" + strDestfile );
	fl.write_str( strResContent );
	strCmd = "chmod +x " + fl.filename();
	std::cout << strCmd << std::flush << std::endl; 
	rc = WFile::run_exe( strCmd );

	fl.bind( strHome + "/.local/share/applications/" + strDestfile );
	fl.write_str( strResContent );
	strCmd = "chmod +x " + fl.filename();
	std::cout << strCmd << std::flush << std::endl; 
	rc = WFile::run_exe( strCmd );
	
	std::cout << "pyqt5 and xclip required. use the following command:"  << std::flush << std::endl; 
	std::cout << "sudo apt-get install python3-pyqt5 python3-pyqt5.qtwebengine xclip"  << std::flush << std::endl; 

	return 1;
}



