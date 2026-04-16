
#ifndef K1_d_keyque0_t_H
#define K1_d_keyque0_t_H


#include "2.h"
#include "bu_quickflow_t.h"


//   
class d_keyque0_t : private WThrd 
{
public:
	WCrsc	m_lckDev;
	th_eonsera_t  m_eea;

private:
	WKeyinput3				 m_Ki_job;		// key-input-type-lock	
	std::list< int >		 m_lot_job_type;
	std::list< std::string > m_lot_job_content;
	int  m_SIZE;

public:
	d_keyque0_t();
	virtual ~d_keyque0_t();

	virtual int tr_on_user_run();

private:
	tbool k_init(); 

private:
	void k_send_idle_job();

public:
	void k_send_job( std::string str_job_content );
	int k_get_job( std::string & ref_str_job_content );
	void k_clear_alljobs();
};

 

extern d_keyque0_t  *gp_job_page_paint;   // 对页面的更改需求 worker out page in 
extern d_keyque0_t  *gp_job_butt_event;   // 页面产生的事件 butt event, worker in page out



#endif



