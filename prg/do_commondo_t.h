
#ifndef K1_do_commondo_t_H
#define K1_do_commondo_t_H


#include "2.h"



//  
class do_commondo_t : public funcandy_t::item_t	  
{
public:
	do_commondo_t();
	virtual ~do_commondo_t();

public:
	virtual tbool lingy( const std::string &strFn , WNava &para , const std::string &strWholePara , funcandy_t::actwebele_t *pweb );

public:
	tbool cd_com_ver( neb::CJsonObject &jinput, neb::CJsonObject &joutput, std::string strCmd , funcandy_t::actwebele_t *pweb ); 
	tbool cd_com_longpull_consume( neb::CJsonObject &jinput, neb::CJsonObject &joutput, std::string strCmd , funcandy_t::actwebele_t *pweb ); 
	tbool cd_com_butt_event( neb::CJsonObject &jinput, neb::CJsonObject &joutput, std::string strCmd , funcandy_t::actwebele_t *pweb ); 
};




#endif



