
#ifndef K1_d_uiproc_t_H
#define K1_d_uiproc_t_H


#include "2.h"



//  
class d_uiproc_t  
{
public:
    WProcRun2 m_run;

public:
	d_uiproc_t();
	virtual ~d_uiproc_t();

public:
	void pr_begin(); 
	void pr_end(); 

	tbool pr_install(); 
};



extern d_uiproc_t  *gp_d_uiproc;



#endif



