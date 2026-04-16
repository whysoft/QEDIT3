
#ifndef K1_de_log_t_H
#define K1_de_log_t_H

#include "2.h"


	//LOGSTREAM( *gp_log, LOGPOSI << "485-2-DOWN-openrc=" << rc << " connstring=" << s2 );
	//gp_log = new de_log4_t();
	//WFile::makedir( "LOGelevatorman4" );
	//WFile::makedir( WFile::MkDir2Path("LOGelevatorman4") + "LOG1"  );
	//gp_log->Init( "LOGelevatorman4", "LOG1", 22 );
	//LOGSTREAM( *gp_log, LOGPOSI << "===================================================" );

#define LOGPOSI  ( SDte::GetNow().Get_now_mtime() + "|" + std::string(__FUNCTION__) + "|" + SStrf::sltoa(__LINE__) + "\t" ).c_str()
#define LOGSTREAM2(Suffix,logobj,streamexp)  do{std::stringstream stream1a ## Suffix ; stream1a ## Suffix<<streamexp; (logobj).LogPrintStr( stream1a ## Suffix.str() ); }while(0)
#define LOGSTREAM1(Suffix,logobj,streamexp) LOGSTREAM2(Suffix,logobj,streamexp)
#define LOGSTREAM(logobj,streamexp) LOGSTREAM1(__LINE__,logobj,streamexp)
//#define MYLOG(exp) LOGSTREAM1( __LINE__, (*gp_log), exp ) 
#define MYLOG(exp) LOGSTREAM( *gp_log, LOGPOSI << exp ) 
#define MYLOG2(exp) LOGSTREAM( *gp_log2, LOGPOSI << exp ) 



typedef std::string * PLogTaskType_t;


//  
class de_log4_t : public LOG4_t< 5 > , public WIdleThrd< PLogTaskType_t >  
{
private:

public:
	de_log4_t();
	virtual ~de_log4_t();

public:
	void LogPrintStr( const std::string & ss );

	virtual void OnRunTask( PLogTaskType_t t );

};



extern de_log4_t  *gp_log;

extern de_log4_t  *gp_log2;


//
class mylog2_t
{
	std::string m_strPosi;

public:
	mylog2_t( std::string strPosi )
	{
		m_strPosi = strPosi;
		//LOGSTREAM( *gp_log,  "ENTER: " << m_strPosi << " " << WThrd::tr_GetCurrentThreadId() ); 
		LOGSTREAM( *gp_log2, "ENTER: " << m_strPosi << " " << WThrd::tr_GetCurrentThreadId() ); 
	}

	virtual ~mylog2_t()
	{
		//LOGSTREAM( *gp_log,  "EXIT:  " << m_strPosi << " " << WThrd::tr_GetCurrentThreadId() << " " << LOGPOSI ); 
		LOGSTREAM( *gp_log2, "EXIT:  " << m_strPosi << " " << WThrd::tr_GetCurrentThreadId() << " " << LOGPOSI ); 
	}
};



#define MYLOG2OBJ mylog2_t aaaa( LOGPOSI ) 




#endif



