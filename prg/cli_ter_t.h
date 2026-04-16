
#ifndef cli_ter_t_H
#define cli_ter_t_H

#include "2.h"



// ter  检测结束标记
class cli_ter_t  
{
private:
	int m_iTerCounter;
	
public:
	cli_ter_t();
	virtual ~cli_ter_t();

public:
	void clean_proc_env();
	void do_ter_direct();
	void do_ter_timeout();
	
public:
	void ResetTerCounter();
	void RiseTerFlag();

	void ter_chance();
};



extern cli_ter_t  *gp_cli_ter;






#endif




