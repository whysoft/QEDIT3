
#ifndef env_t_H
#define env_t_H

#include "2.h"
//#include "de_log_t.h"



class env_t : public WThrd 
{
public:
	std::string		m_strName;
	std::string		m_strVer;
	std::string		m_strSysVerInternal;
	std::string		m_strHelp;
	std::string		m_strMainThrdId;
	
	WNava	m_nvCmdLn;
	std::vector< std::string > m_vecCmdLn;
	std::string  m_strCmdLn;
	std::string  m_strCmdLnSelf;  // 绝对路径 

	tuint16  m_service_port; // 服务端口号，逐渐加 

public:
	env_t();
	virtual ~env_t();
	
	virtual int tr_on_user_run();

	void SeeCmdLn( int argc, char* argv[] );
	void MkDirs();
	std::string GetLOGDir();
	std::string GetDBDir();
};



extern env_t  *gp_env;



////=====-----------

extern char * gfBINDDATA(const char *szName = NULL , long *piLen = NULL , std::vector< std::string > *pvFn1 = NULL, wl::SCake *pck = NULL ); 
extern bool IsOsWin(); 
extern bool IsExeCharSetUtf8();
extern tbool copy_data_2_file( std::string strDataName, std::string strPFn ); 
//extern bool IsHot(); 





#endif



