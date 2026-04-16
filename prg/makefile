#CC = arm-linux-gcc
CC = gcc
CC1 = $(CC) -c 
CC3 = $(CC) -lpthread 
.PHONY: clean

O_FILES = cJSON.o d_cmdcli_t.o d_fcw_hightlog_t.o d_fcw_pagesupport_t.o d_ui_p0_base_t.o d_fcw_rpcmain_t.o do_commondo_t.o CJsonObject.o d_ui_p1_a_html_t.o bu_asynwork_t.o d_ui_mngr_t.o d_uiproc_t.o g06.o gfunc_md5.o d_config_t.o d_session_t.o d_ui_p1_util_timer_t.o do_p1welcome_t.o de_log_t.o d_keyque0_t.o cli_ter_t.o bu_quickflow_t.o QEDIT3.o env_t.o 

QEDIT3: $(O_FILES)
	$(CC) -o QEDIT3 $(O_FILES) -lpthread  -lstdc++ -ldl

cJSON.o :cJSON.cpp
	$(CC1) cJSON.cpp

d_cmdcli_t.o :d_cmdcli_t.cpp
	$(CC1) d_cmdcli_t.cpp

d_fcw_hightlog_t.o :d_fcw_hightlog_t.cpp
	$(CC1) d_fcw_hightlog_t.cpp

d_fcw_pagesupport_t.o :d_fcw_pagesupport_t.cpp
	$(CC1) d_fcw_pagesupport_t.cpp

d_ui_p0_base_t.o :d_ui_p0_base_t.cpp
	$(CC1) d_ui_p0_base_t.cpp

d_fcw_rpcmain_t.o :d_fcw_rpcmain_t.cpp
	$(CC1) d_fcw_rpcmain_t.cpp

do_commondo_t.o :do_commondo_t.cpp
	$(CC1) do_commondo_t.cpp

CJsonObject.o :CJsonObject.cpp
	$(CC1) CJsonObject.cpp

d_ui_p1_a_html_t.o :d_ui_p1_a_html_t.cpp
	$(CC1) d_ui_p1_a_html_t.cpp

bu_asynwork_t.o :bu_asynwork_t.cpp
	$(CC1) bu_asynwork_t.cpp

d_ui_mngr_t.o :d_ui_mngr_t.cpp
	$(CC1) d_ui_mngr_t.cpp

d_uiproc_t.o :d_uiproc_t.cpp
	$(CC1) d_uiproc_t.cpp

g06.o :g06.cpp
	$(CC1) g06.cpp

gfunc_md5.o :gfunc_md5.cpp
	$(CC1) gfunc_md5.cpp

d_config_t.o :d_config_t.cpp
	$(CC1) d_config_t.cpp

d_session_t.o :d_session_t.cpp
	$(CC1) d_session_t.cpp

d_ui_p1_util_timer_t.o :d_ui_p1_util_timer_t.cpp
	$(CC1) d_ui_p1_util_timer_t.cpp

do_p1welcome_t.o :do_p1welcome_t.cpp
	$(CC1) do_p1welcome_t.cpp

de_log_t.o :de_log_t.cpp
	$(CC1) de_log_t.cpp

d_keyque0_t.o :d_keyque0_t.cpp
	$(CC1) d_keyque0_t.cpp

cli_ter_t.o :cli_ter_t.cpp
	$(CC1) cli_ter_t.cpp

bu_quickflow_t.o :bu_quickflow_t.cpp
	$(CC1) bu_quickflow_t.cpp

QEDIT3.o :QEDIT3.cpp
	$(CC1) QEDIT3.cpp

env_t.o :env_t.cpp
	$(CC1) env_t.cpp


clean :
	rm -fv $(O_FILES)

