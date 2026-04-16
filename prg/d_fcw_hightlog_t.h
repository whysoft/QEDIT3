
#ifndef K1_d_fcw_hightlog_t_H
#define K1_d_fcw_hightlog_t_H


#include "2.h"




//  
class d_fcw_hightlog_t : public funcandy_t::item_t	  
{
public:
	d_fcw_hightlog_t();
	virtual ~d_fcw_hightlog_t();

public:
	virtual tbool lingy( const std::string &strFn , WNava &para , const std::string &strWholePara , funcandy_t::actwebele_t *pweb );
};





#endif



