
#ifndef K1__CONFIG_T_H
#define K1__CONFIG_T_H


#include "2.h"


//
class d_config_t
{
private:
	WNava  m_nvConf;
	WNava  m_nvConf_conf1;  // seri
	WNava  m_nvConf_conf2;  // patch  

public: 	
	WCrsc	m_lckDev;

public:
	d_config_t();
	~d_config_t();

public:
	tbool InitConf(); 

	WNava GetAllConf();
	std::string GetItem( std::string strName ); 

	std::string GetItem_conf1( std::string strName ); 

	std::string GetItem_conf2( std::string strName ); 
	void put_item_conf2( std::string strName , std::string str_val ); 

	tbool is_service_off();
};



//
extern d_config_t  *gp_conf;



#endif


