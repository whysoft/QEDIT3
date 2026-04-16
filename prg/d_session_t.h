
#ifndef d_session_t_H
#define d_session_t_H


#include "2.h"
#include "CJsonObject.h"



//  
class d_session_t  
{
public:
	WCrsc	m_lckDev;

public:
	d_session_t();
	virtual ~d_session_t();
	
public:
	void html_part_replace_filter( std::string &str_name, std::string &str_val , WNava &wpara , funcandy_t::actwebele_t *pweb );

public:
	tbool ss_verify( neb::CJsonObject &jinput, neb::CJsonObject &joutput );

};


extern d_session_t  *gp_d_session;



#endif

