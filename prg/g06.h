
#ifndef K1_G06_H
#define K1_G06_H

#include "2.h"
#include "CJsonObject.h"



void test_x1();

void gf_show_sizeof();
void test_gen_job1();
void test_gen_job2();
void test_use_job();

void mybeep( int flag = 0 );
wl::tchar my_bs_esc(void);
std::vector< std::string > gbstr_2_vec( std::string str1 );

void txt_into_clip( std::string str1, std::string str2 );
void pic_into_clip( std::string str1, std::string str2 );

void clip_append_to_end( std::string str_pagepathname, std::string str1, std::string str2 );
void clip_insert_to_begin( std::string str_pagepathname, std::string str1, std::string str2 );

void undo_a( std::string str_pagepathname, std::string str1, std::string str2, std::vector< std::string > &vec_text_main_lot );
void trim_a( std::string str_pagepathname, std::string str1, std::string str2 );
void reverse_a( std::string str_pagepathname, std::string str1, std::string str2 );

void windows_os_relative( std::string str_sub2cmd, std::string str_pagepathname, std::string str1, std::string str2 );


#endif


