//
#include "2.h"
#include "env_t.h"
#include "d_session_t.h"
#include "g06.h"
#include "de_log_t.h"
#include "d_config_t.h"



//
d_session_t  *gp_d_session;


 
//
d_session_t::d_session_t()	
{
	MYAUTOLOCK(m_lckDev);
}



//
d_session_t::~d_session_t()	
{
}


//
void d_session_t::html_part_replace_filter( std::string &str_name, std::string &str_val , WNava &wpara , funcandy_t::actwebele_t *pweb )
{
	//各种过滤器罗列在下 
	if( str_name == "session_token_finger" )
	{
		std::string t = "hidden"; // text	hidden 
		str_val =
				  "<input id=\"a_p\" type=\"" + t + "\" value=\"" + wpara.get("a_p") + "\" size=\"22\">\n" 
				  "<input id=\"a_s\" type=\"" + t + "\" value=\"" + wpara.get("a_s") + "\" size=\"55\">\n" 
		          "<input id=\"a_f\" type=\"" + t + "\" value=\"" + wpara.get("a_f") + "\" size=\"22\">\n"
					//"<input id=\"a_ip\" type=\"" + t + "\" value=\"" + pweb->m_tSvr.GetRemoteIPAddress() + "\" size=\"22\">\n"
					//"<input id=\"a_port\" type=\"" + t + "\" value=\"" + SStrf::sltoa((int)(pweb->m_tSvr.m_myport)) + "\" size=\"22\">\n"
				  "<input id=\"a_para\" type=\"" + t + "\" value=\"" + wpara.get("a_para") + "\" size=\"22\">\n"
				  ;
	}

	if( str_name == "session_private_zone" )
	{
		if( IsOsWin() )
		{
			if( !WFile::exists("D:\\_mytools\\multibox.exe") )
				str_val = "";
		}
		else
		{
			if( !WFile::exists("/sbin/elemepi/multibox/multibox") )
				str_val = "";
		}
	}

	return;
}



// a_veri=0: 填写rc/a_veri，否定型决策。
// a_veri=1：只填写a_veri
tbool d_session_t::ss_verify( neb::CJsonObject &jinput, neb::CJsonObject &joutput )
{
	MYAUTOLOCK(m_lckDev);

	std::string s1 ;//= this->ss_get_rowuid(jinput);

	if( s1 == "" )
	{
		joutput.Add( "a_veri" , (int)0 );
		joutput.Add( "rc" , (int)1 );

		return 0;
	}

	joutput.Add( "a_s" , jinput.Get2( "a_s" ) );
	joutput.Add( "a_f" ,jinput.Get2( "a_f" ) ); 

	joutput.Add( "a_veri" , (int)1 );
		
	return 1;
}

	
