
#ifndef K1_d_cmdcli_t_H
#define K1_d_cmdcli_t_H


#include "2.h"



//  
class d_cmdcli_t  
{
public:
	WNava  m_nvCmdLn;
	int  m_mainrc;

public:
	d_cmdcli_t();
	virtual ~d_cmdcli_t();

private:
 

public:
	tbool cc_process(); 
};




#endif



