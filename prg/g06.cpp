
// 一段中文注释 
#pragma warning(disable: 4312)
#pragma warning(disable: 4996)
 
#include "2.h"
#include "g06.h"
#include "env_t.h"
#include "de_log_t.h"
#include "d_keyque0_t.h"
#include "d_config_t.h"
#include "CJsonObject.h"
#include "d_fcw_rpcmain_t.h"
#include "bu_asynwork_t.h"
#include "d_session_t.h"
#include "cli_ter_t.h"
#include "d_ui_mngr_t.h"


#ifdef LINUENV_
#endif


#ifdef OS_MACOSX_
#endif


#ifdef WINENV_
#include <atlbase.h>
#include <atlcom.h>
#include "comutil.h"
#include "comdef.h"
#endif




//
void test_x1()  //  
{
	std::cout << std::flush; 
}



//
void gf_show_sizeof()
{
	printf( "------------------------------\n" );
	printf( "sizeof(float)=%d\n", (int)sizeof(float) );
	printf( "sizeof(double)=%d\n", (int)sizeof(double) );
	printf( "sizeof(tint8)=%d\n", (int)sizeof(tint8) );
	printf( "sizeof(tuint8)=%d\n", (int)sizeof(tuint8) );
	printf( "sizeof(tint16)=%d\n", (int)sizeof(tint16) );
	printf( "sizeof(tuint16)=%d\n", (int)sizeof(tuint16) );
	printf( "sizeof(tint32)=%d\n", (int)sizeof(tint32) );
	printf( "sizeof(tuint32)=%d\n", (int)sizeof(tuint32) );
	printf( "sizeof(tint64)=%d\n", (int)sizeof(tint64) );
	printf( "sizeof(tuint64)=%d\n", (int)sizeof(tuint64) );
	printf( "sizeof(tbool)=%d\n", (int)sizeof(tbool) );
	printf( "sizeof(tsize)=%d\n", (int)sizeof(tsize) );
	printf( "sizeof(toffset)=%d\n", (int)sizeof(toffset) );
	printf( "sizeof(DWORD)=%d\n", (int)sizeof(DWORD) );

	int j,i;
	unsigned char *p;

	j = 1;
	p = (unsigned char *)(&j);
	i = *p;

	printf( "lsb val=%d\n", i );

	i = sizeof(int);
	printf( "int size=%d\n", i );

	i = sizeof( long int );
	printf( "long int size=%d\n", i );

	i = sizeof( unsigned long );
	printf( "unsigned long size=%d\n", i );
	
	printf( "------------------------------\n" );
}



// 
void test_gen_job1()
{
	WThrd::tr_sleep( 1 );
	int i;

	for( i = 0; i < 55; i++ )
	{
		gp_job_page_paint->k_send_job( "gp_job_page_paint-" + WFile::MkRUStr() + "-" + SStrf::sltoa(i) );
		WThrd::tr_sleepu( 0.02 );   
		//WThrd::tr_sleepu( 0.004 );   
		//gp_job_page_paint->k_clear_alljobs();
	}
	//WThrd::tr_sleep( 1 );
}

// 
void test_gen_job2()
{
	int i;

	for( i = 0; i < 55; i++ )
	{
		gp_job_butt_event->k_send_job( "gp_job_butt_event-" + WFile::MkRUStr() + "-" + SStrf::sltoa(i) );
		WThrd::tr_sleepu( 0.02 );   
	}

	WThrd::tr_sleep( 6 );
	gp_job_page_paint->k_clear_alljobs();
	gp_job_butt_event->k_clear_alljobs();
}



// 
void test_use_job()
{
	int i_job_type;
	std::string str_job;

	for( int i = 0; i < 11; i++ )
	{
		i_job_type = gp_job_butt_event->k_get_job( str_job );
		std::cout << i << "\t" << i_job_type << "***" << str_job << "***\n" << std::flush; 
		//WThrd::tr_sleepu( 0.002 );
	}

	for( int i = 0; i < 11; i++ )
	{
		i_job_type = gp_job_page_paint->k_get_job( str_job );
		std::cout << i << "\t" << i_job_type << "***" << str_job << "***\n" << std::flush; 
		//WThrd::tr_sleepu( 0.002 );
	}

	WThrd::tr_sleep( 1 );

	//gp_cli_ter->RiseTerFlag();
	//gp_cli_ter->ter_chance();
}



//
void mybeep( int flag /*= 0*/ )
{
	std::string strCmd; 
	int iCmdrc(999);

	if( IsOsWin() )
	{
		strCmd = "d:\\_mytools\\multibox.exe -c beep";
	}
	else
	{
		strCmd = "/sbin/elemepi/multibox/multibox -c beep";
	}

	if(flag)
	{
		strCmd += "2";
	}

	iCmdrc = WFile::run_exe(strCmd);
}



//
wl::tchar my_bs_esc(void)
{
	return '%';
}




//
std::vector< std::string > gbstr_2_vec( std::string str1 )
{
	SCake ck1;
	std::vector< std::string > vec1;
	char sz[3];

	sz[2] = 0;
	ck1.lets(str1); 
	ck1.append( (tchar)0x00 ); 	// 至少需要两个字符来判断一个汉字编码对	 

	for( int i = 0; i < (int)ck1.len(); )
	{
		const char *p = (const char *)ck1.buf() + i;
		unsigned char high = *(unsigned char*)p; // 获取高位字节
		unsigned char low = *(unsigned char*)(p + 1); // 获取低位字节

		if( high == 0 ) break;

		if(high >= 0x81 && high <= 0xFE && low >= 0x40 && low <= 0xFE && low != 0x7F)  // 更准确的范围判断
		{
			sz[0] = (char)high;
			sz[1] = (char)low;
			i+=2;
		}
		else
		{
			sz[0] = (char)high;
			sz[1] = 0;
			i++;
		}

		vec1.push_back(sz);
	}

	return vec1;
}





#ifdef LINUENV_
#include "g06_li.xpp"
#endif


#ifdef OS_MACOSX_
// 
#endif


#ifdef WINENV_ 
#include "g06_wi.xpp"
#endif


