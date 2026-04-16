
#ifndef K1_do_p1welcome_t_H
#define K1_do_p1welcome_t_H


#include "2.h"



//  
class do_p1welcome_t : public funcandy_t::item_t	  
{
public:
	do_p1welcome_t();
	virtual ~do_p1welcome_t();

public:
	virtual tbool lingy( const std::string &strFn , WNava &para , const std::string &strWholePara , funcandy_t::actwebele_t *pweb );

public:
	tbool my_danger( neb::CJsonObject &jinput, neb::CJsonObject &joutput, std::string strCmd , funcandy_t::actwebele_t *pweb ); 
	//tbool butt1_submit( neb::CJsonObject &jinput, neb::CJsonObject &joutput, std::string strCmd , funcandy_t::actwebele_t *pweb ); 
	//tbool page_init( neb::CJsonObject &jinput, neb::CJsonObject &joutput, std::string strCmd , funcandy_t::actwebele_t *pweb ); 

};





#endif



