//
#include "2.h"
#include "d_config_t.h"
#include "de_log_t.h"
#include "env_t.h"



//
d_config_t  *gp_conf;


	
//
d_config_t::d_config_t()	
{ 
}

	
//
d_config_t::~d_config_t()	
{
}


//
tbool d_config_t::InitConf()
{
	MYAUTOLOCK(m_lckDev);

	SFile fInFile;
	std::string strFileContent;


	strFileContent = "";
	fInFile.bind( gp_env->m_strName + ".config.txt" );
	fInFile.read_str( strFileContent );
	m_nvConf.clear();
	m_nvConf.impconf( strFileContent );


	strFileContent = "";
	fInFile.bind( gp_env->m_strName + ".config.conf1" );
	fInFile.read_str( strFileContent );
	m_nvConf_conf1.clear();
	m_nvConf_conf1.impconf( strFileContent );


	strFileContent = "";
	fInFile.bind( gp_env->m_strName + ".config.conf2" ); 
	fInFile.read_str( strFileContent );
	m_nvConf_conf2.clear();
	m_nvConf_conf2.unserialize( strFileContent ); 


	return 1;
}
	

//
WNava d_config_t::GetAllConf()
{
	return m_nvConf;
}


//
std::string d_config_t::GetItem( std::string strName )
{
	MYAUTOLOCK(m_lckDev);
	return m_nvConf.get(strName);
}


//
std::string d_config_t::GetItem_conf1( std::string strName )
{
	MYAUTOLOCK(m_lckDev);
	return m_nvConf_conf1.get(strName);
}



/*
patch=1 分配IP范围扩大。
*/
std::string d_config_t::GetItem_conf2( std::string strName )
{
	MYAUTOLOCK(m_lckDev);
	return m_nvConf_conf2.get(strName);
}


//
void d_config_t::put_item_conf2( std::string strName , std::string str_val )
{
	MYAUTOLOCK(m_lckDev);

	WNava &nv(m_nvConf_conf2);

	WFile fl;
	std::string strFileContent;

	nv.let( strName, str_val );

	fl.bind( gp_env->m_strName + ".config_conf2" );
	strFileContent = nv.serialize();

	fl.write_str( strFileContent ); 
}


//  	
tbool d_config_t::is_service_off()
{
	//std::string s1;

	//s1 = gp_conf->GetItem("SERVICE_STATE");
 
	WFile f;
	
	f.bind( gp_env->m_strName + "_off.txt" );   
	
	if( f.exists() )
	{
		return 1;
	}
	 
	return 0;
}


