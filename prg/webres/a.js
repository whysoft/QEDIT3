
//<!--  一段中文注释 -->


	
var g_js_para = "";   


//  
function take_text_main_buff()
{
	var vi_text_main = "";  

	var f1 = 
	function()
	{
		var t1 = document.getElementById("text_main"); 

		if( t1.value != "" && t1.value != vi_text_main )
		{
			//alert(g_text_main);
			vi_text_main = t1.value;
			butt_a_take_text_main_buf();
		}

		setTimeout( f1, 777 ); 
	};

	setTimeout( f1, 888 ); 
}



//
function on_enter_event(event)
{
	//alert(event.ctrlKey);

	var myevent = event || window.event ;
	var mykeyCode = myevent.keyCode||myevent.which; // 对于 IE8 及以下版本使用 event.keyCode，其他使用 event.which
    
	//console.log(mykeyCode); // 输出按键的代码
	//key_code_alert(mykeyCode); 

	//var t1 = document.getElementById("text_main").value; 
	//if( t1 != "" )
	//{
	//	g_text_main = t1;
	//	alert(g_text_main);
	//}
 

	if(mykeyCode == 13)	// keycode 13 = Enter  
	{
		// window.location.reload(true); 
		//butt_a_quit();
	}

	if(mykeyCode == 112)	//keycode 112 = F1
	{
		butt_a_shortcut(mykeyCode);
		return false;
	}

	if(mykeyCode == 113)	//keycode 113 = F2
	{
		butt_a_shortcut(mykeyCode);
		return false;
	}
 
	if(mykeyCode == 114)	//keycode 114 = F3
	{
		butt_a_shortcut(mykeyCode);
		return false;
	}

	if(mykeyCode == 115)	//keycode 115 = F4
	{
		butt_a_shortcut(mykeyCode);
		return false;
	}

	if(mykeyCode == 27)	// keycode 27 = Escape 
	{
		butt_a_shortcut(mykeyCode);
		return false;
	}

	//return false;
	//return true;
}


//
function key_code_alert(mykeycode)
{        　      　　
	var keyName = String.fromCharCode(mykeycode);        　
	alert("按键码: " + mykeycode + " 字符: " + keyName);       
}       


//
function bodyload()
{
	//setTimeout(scrollTo,0,0,0); 
	//hide_cursor();
	document.onkeydown = on_enter_event;   // 两个OS的firefox都可。 IE浏览器可但弹出F1帮助。IE控件不可。后来用C#的IE控件，可。以下两条都不用了。	 
	//document.onkeypress = on_enter_event;  // IE控件可 但只有ESC，而且r错了。 firfox不行。 干脆两个都用上。反正是退出。 
	//document.onkeyup = on_enter_event;

	//alert(33);  

	// .onkeydown   onkeypress;   .onkeyup ;
	//document.getElementById('text_main').onkeypress = on_enter_event;
	//document.getElementById('text_sub').onkeypress = on_enter_event;
	 

	pg_fp_init();
	time_get_show();
	page_change_notify();
	page_change_notify();
	longpull_consume();
	take_text_main_buff();

		
	//document.getElementById("div_time").style.color = "#556677";
	//document.getElementById("div_time").setAttribute("style", "color: #5566c7; font-size: 0.90rem;");

	
	var f1 = 
	function()
	{
		var tt=document.getElementById("text_main"); 
		tt.focus(); // 使该对象获得焦点  
	};

	setTimeout( f1, 11 ); 
}



//  
function pg_fp_init()
{
	var fp = new Fingerprint(); 
	var a = ""; 
	a = fp.get();  
    //document.getElementById("a_f").value = a;
	//document.getElementById("a_p").value = window.location.pathname;
}


//  
function get_the_fp()
{
	var fp = new Fingerprint(); 
	var a = ""; 
	a = fp.get();  
    return a;
}


//=========================================================================

//  
function time_get_show()
{
	var jsonsend = { };

	jsonsend.cmd = "com_ver";
	jsonsend.cmd_id = String( Math.random() );
	jsonsend.fp = get_the_fp(); 
	jsonsend.location_href = window.location.href;
	jsonsend.pagepathname = window.location.pathname;
	//jsonsend.date = document.getElementById("week_1").value; 
	
	var f_act = 
	function( j )
	{
		if( j.rc == 1 )
		{
			//var s2 = `${j.time} ${j.ver1} ${j.ver2} ${j.ver3} ${j.ver4} ${j.ip}`;
			var s2 = j.time + " " + j.ver1 + " " + j.ver2 + " " + j.ver3 + " " + j.ver4 + " " + j.ip ;

			document.getElementById("div_time").innerHTML = s2;
			//document.getElementById("div_status").innerHTML = j.turbo;
			//document.body.style.background = j.bg;
			//document.bgColor="black"
			//document.fgColor = j.fg;
		}
	
		setTimeout( time_get_show, 999 ); 
	};

	EP_a3( jsonsend, f_act ); 
	 
	return false;
}



//
function page_change_notify()
{
	var jsonsend = { };

	jsonsend.cmd = "cd_com_butt_event";
	jsonsend.cmd_id = String( Math.random() );
	jsonsend.fp = get_the_fp(); 
	jsonsend.location_href = window.location.href;
	jsonsend.pagepathname = window.location.pathname;
	//jsonsend.date = document.getElementById("week_1").value; 
	//jsonsend.passwd = document.getElementById("passwd").value;
	jsonsend.sub1cmd = "page_change_notify";
	
	var f_act = 
	function( j )
	{
		if( j.rc == 1 && j.havejsblock == 1 )
		{
		}

		if( j.rc == 1 )
		{
		}
	};

	EP_a3( jsonsend, f_act ); 
	 
	return false;
}



//  
function longpull_consume()
{
	var jsonsend = { };

	jsonsend.cmd = "cd_com_longpull_consume";
	jsonsend.cmd_id = String( Math.random() );
	jsonsend.fp = get_the_fp(); 
	jsonsend.location_href = window.location.href;
	jsonsend.pagepathname = window.location.pathname; 
	
	var f_act = 
	function( j )
	{
		//document.getElementById("div_j_src").innerHTML = JSON.stringify(j);  显示原始json码，用于调试 后来就不用了 

		if( j.rc == 1 && j.pagepathname == window.location.pathname && j.havejsblock == 1 )
		{ 
			var s2 = j.jsblock;
			g_js_para = j.para;

			setTimeout( s2, 1 ); 
		}
		 
		if( j.rc == 1 )
		{
			setTimeout( longpull_consume, 1 ); 
		}
		else
		{
			setTimeout( longpull_consume, 999 ); 
		}
	};

	EP_a3( jsonsend, f_act ); 
	 
	return false;
}



//  
function butt_a_submit(buttobj)
{
	butt_effect3( buttobj );

	var jsonsend = { };

	jsonsend.cmd = "cd_com_butt_event";
	jsonsend.cmd_id = String( Math.random() );
	jsonsend.fp = get_the_fp(); 
	jsonsend.location_href = window.location.href;
	jsonsend.pagepathname = window.location.pathname;
	//jsonsend.date = document.getElementById("week_1").value; 
	//jsonsend.passwd = document.getElementById("passwd").value;
	jsonsend.sub1cmd = "page_butt";
	jsonsend.sub2cmd = buttobj.value; 
	jsonsend.text_main = document.getElementById("text_main").value; 
	jsonsend.text_sub = document.getElementById("text_sub").value; 
	
	var f_act = 
	function( j )
	{
		if( j.rc == 1 && j.havejsblock == 1 )
		{
		}

		if( j.rc == 1 )
		{
			var f2 = function()	{ butt_effect2( buttobj );	};
			var f3 = function()	{ butt_effect1( buttobj );	};
			setTimeout( f2, 111 );
			//setTimeout( f3, 555 );
		}
	};

	EP_a3( jsonsend, f_act ); 
	 
	return false;
}



//  
function butt_a_shortcut( mykeycode )
{
	//key_code_alert(mykeycode); 

	var jsonsend = { };

	jsonsend.cmd = "cd_com_butt_event";
	jsonsend.cmd_id = String( Math.random() );
	jsonsend.fp = get_the_fp(); 
	jsonsend.location_href = window.location.href;
	jsonsend.pagepathname = window.location.pathname;
	//jsonsend.date = document.getElementById("week_1").value; 
	//jsonsend.passwd = document.getElementById("passwd").value;
	jsonsend.sub1cmd = "butt_shortcut";
	jsonsend.mykeycode = mykeycode;  
	jsonsend.text_sub = document.getElementById("text_sub").value; 
	
	var keyName = String.fromCharCode(mykeycode);        　
	jsonsend.string_msg = ("按键码: " + mykeycode + " 字符: " + keyName);    

	var f_act = 
	function( j )
	{
		if( j.rc == 1 && j.havejsblock == 1 )
		{
		} 
	};

	EP_a3( jsonsend, f_act ); 
	 
	return false;
}



//  
function butt_a_take_text_main_buf()
{
	var jsonsend = { };

	jsonsend.cmd = "cd_com_butt_event";
	jsonsend.cmd_id = String( Math.random() );
	jsonsend.fp = get_the_fp(); 
	jsonsend.location_href = window.location.href;
	jsonsend.pagepathname = window.location.pathname;
	//jsonsend.date = document.getElementById("week_1").value; 
	//jsonsend.passwd = document.getElementById("passwd").value;
	jsonsend.sub1cmd = "take_text_main_buf"; 
	jsonsend.text_main = document.getElementById("text_main").value; 
	jsonsend.text_sub = document.getElementById("text_sub").value; 
	
	var f_act = 
	function( j )
	{
		if( j.rc == 1 && j.havejsblock == 1 )
		{
		}
	};

	EP_a3( jsonsend, f_act ); 
	 
	return false;
}



//=========================================================================


////
//function textarea_color_effect1( area )
//{
//	var f1 = 
//	function()
//	{
//		area.style="background-color:#9598FF;color:red;"
//	}
//
//	var f2 = 
//	function()
//	{
//		area.style="background-color:#ffFFff;color:#0;"
//	}
//	
//	setTimeout( f1, 111 ); 
//	setTimeout( f2, 444 ); 
//}



//  
function clear_text1(buttobj)
{
	butt_effect3( buttobj );
	
	var tt1 = document.getElementById("text_main");
	var tt2 = document.getElementById("text_sub");

	var f2 = 
	function()
	{
		tt1.value = "";
		//tt2.value = "";
		tt1.focus(); // 使该对象获得焦点  
	}
	
	var f1 = 
	function()
	{
		tt1.select();
		//tt2.select();
		
		//textarea_color_effect1(tt1);
		setTimeout( f2, 33 );
	};

	setTimeout( f1, 11 );
}



//  
function clear_text2(buttobj)
{
	butt_effect3( buttobj );
	 
	var tt2 = document.getElementById("text_sub");

	var f2 = 
	function()
	{ 
		tt2.value = "";
		tt2.focus(); // 使该对象获得焦点  
	} 

	setTimeout( f2, 11 );
}



//  
function add_cr(buttobj)
{
	butt_effect3( buttobj );
	
	var tt1 = document.getElementById("text_main"); 

	var f2 = 
	function()
	{
		tt1.value = tt1.value + "\r\n"; 
		tt1.focus(); // 使该对象获得焦点  
	}
	
	setTimeout( f2, 11 );
}
	


//
function moveCursorToHead0Tail1(head0tail1)
{
	var textInput = document.getElementById("text_main");

    textInput.focus(); // 确保textarea获得焦点 

    if(textInput.setSelectionRange)
	{
        // 对于支持setSelectionRange的方法（如非IE）
        var length = textInput.value.length;
		if( head0tail1 == 0 )
		{
			textInput.setSelectionRange(0, 0);
		}
		else
		{
			/*
			聚焦光标到开头?：setSelectionRange(0, 0)
			聚焦光标到末尾?：setSelectionRange(value.length, value.length)
			选中全部文本?：setSelectionRange(0, value.length)
			*/
			textInput.setSelectionRange(length, length);
		}
    }
	else if(textInput.createTextRange) 
	{
        // 对于IE浏览器
        var range = textInput.createTextRange();
		if( head0tail1 == 0 )
		{        
			range.moveStart('character',0);     
			range.collapse(true);     
			range.select();     
		}    
		else
		{
			range.collapse(false); // 将光标移动到末尾
			range.select();
		}
    }
}



//  
function set_text_main_value( txt, head0tail1 )
{
	var tt1 = document.getElementById("text_main");

	var f2 = 
	function()
	{
		tt1.value = txt;
		tt1.focus(); // 使该对象获得焦点  

		moveCursorToHead0Tail1(head0tail1);
	}
	 
	setTimeout( f2, 11 );
}
	


