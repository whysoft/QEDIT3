
// 一段中文注释 
#include "2.h"
#include "env_t.h"
#include "d_config_t.h"
#include "de_log_t.h"
#include "CJsonObject.h"
#include "d_session_t.h"
#include "g06.h"
#include "gfunc_md5.h"
#include "d_cmdcli_t.h"



#ifdef LINUENV_
//
#else
//#include "d_cmdcli_t.winfake.xpp"
#endif



// 
d_cmdcli_t::d_cmdcli_t()
{
}



// 
d_cmdcli_t::~d_cmdcli_t()
{ 
}



//
tbool d_cmdcli_t::cc_process()
{
	if( m_nvCmdLn.get( "-c" ) != "cli" )
	{
		//return 1;
		return 0;
	}

	//return 0;
	return 1;
}


