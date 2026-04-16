
//<!--  一段中文注释 -->

function getQueryStringArgs(inputstring)
{
		var qs=inputstring;
		var args={};
		var items=qs.length ? qs.split("&") : [];
		var item=null,
			name=null,
			value=null,
			len=items.length;

		for(var i=0;i<len;i++)
		{
			item=items[i].split("=");
			if(item[0].length)
			{
				//name=decodeURIComponent(item[0]);       //decodeURIComponent() 函数可对 encodeURIComponent() 函数编码的 URI 进行解码。
				name=item[0];

				//value=decodeURIComponent(item[1]);
				value=item[1];
				args[name]=value;
			}
		}
		return args;
}


function sleep1(millis){var njf1 = njen(this,arguments,"millis");nj:while(1) {try{switch(njf1.cp) { case 0:njf1._notifier=NjsRuntime.createNotifier();setTimeout(njf1._notifier,njf1._millis);njf1.cp = 1;njf1._notifier.wait(njf1);return;case 1:break nj; }} catch(ex) { if(!njf1.except(ex,1)) return; }} njf1.pf();}

function mysleep(mm)
{
	//	alert( "bbb1" );

	try{
		sleep1(mm);
	}
	catch(ex)
	{
		//alert( "ccc" );
	}
		//alert( "ccc" );
}



function getQueryStringArgs2(inputstring)
{
		var qs=inputstring;
		var args={};
		var items=qs.length ? qs.split("&") : [];
		var item=null,
			name=null,
			value=null,
			len=items.length;

		for(var i=0;i<len;i++)
		{
			item=items[i].split("=");

			alert( item[0] );
			alert( item[1] );


			if(item[0].length)
			{
				//name=decodeURIComponent(item[0]);       //decodeURIComponent() 函数可对 encodeURIComponent() 函数编码的 URI 进行解码。
				name=item[0];

				//value=decodeURIComponent(item[1]);
				value=item[1];
				args[name]=value;
			}
		}
		return args;
}


// var radios = document.getElementsByName("radio");
// var tag = false;
// var val;
// for(radio in radios) {
//    if(radios[radio].checked) {
//       tag = true;
//       val = radios[radio].value;
//       break;
//    }
// }
// if(tag) {
//    alert(val);
// } 
// else {
//   alert("请选择。。。。");
// }




function hide_cursor()
{
	// setTimeout(scrollTo,0,0,0); 

	
	var body=document.body;    //隐藏光标
	body.style="cursor:none";

}




//  
function butt_effect( obj )
{
	var bb = document.getElementById( String( obj.id ) );
 
	var f_high = function ()
	{ 
		bb.style.color = '#0062cc';
		bb.style.backgroundColor = "#ff020c";
	
		setTimeout( f_normal, 444 ); 
	};
	
	var f_normal = function ()
	{ 
		bb.style.color = '#000000';
		bb.style.backgroundColor = "#eeeeff";
	};

	setTimeout( f_high, 0 ); 

}



//  
function butt_effect1( obj )
{
	var bb = document.getElementById( String( obj.id ) );
 
	var f_high = function ()
	{ 
		bb.style.color = '#0062cc';
		bb.style.backgroundColor = "#ff02fc";
	
		setTimeout( f_normal, 222 ); 
	};
	
	var f_normal = function ()
	{ 
		bb.style.color = '#000000';
		bb.style.backgroundColor = "#dedede";
	};

	setTimeout( f_high, 0 ); 

}


//  
function butt_effect2( obj )
{
	var bb = document.getElementById( String( obj.id ) );
 
	var f_high = function ()
	{ 
		bb.style.color = '#0062cc';
		bb.style.backgroundColor = "#0002ff";
	
		setTimeout( f_normal, 222 ); 
	};
	
	var f_normal = function ()
	{ 
		bb.style.color = '#000000';
		bb.style.backgroundColor = "#dedede";
	};

	setTimeout( f_high, 0 ); 

}


//  
function butt_effect3( obj )
{
	var bb = document.getElementById( String( obj.id ) );
 
	var f_high = function ()
	{ 
		bb.style.color = '#0062cc';
		bb.style.backgroundColor = "#00ff00";
	
		setTimeout( f_normal, 222 ); 
	};
	
	var f_normal = function ()
	{ 
		bb.style.color = '#000000';
		bb.style.backgroundColor = "#dedede";
	};

	setTimeout( f_high, 0 ); 

}



// 使用相对地址 
function lf_post_ajax( buttobj, jsonobj, outtxt_id )
{
	butt_effect( buttobj );
	var outtxt = document.getElementById(outtxt_id);
	var json = jsonobj;
	outtxt.value = "";

	var f = 
	function ()
	{
		var xhr = new XMLHttpRequest();
		var strReq;
		
		strReq =  "aa?"
		strReq += "cmd=post"; 
		strReq += "&aa=" + String( Math.random() );
            
		xhr.onreadystatechange = function ()
		{
			if( xhr.readyState != 4 ) return;

			if( xhr.status != 200 ) 
			{
				// setTimeout( f, 500 ); 
				butt_effect3( buttobj );
				return;
			}

			// alert(xhr.responseText);
			json = JSON.parse(xhr.responseText);
			outtxt.value = xhr.responseText

			if( json.rc != 1 )
			{
				//setTimeout( f, 1500 ); 
				butt_effect1( buttobj );
				return;
			}
			
			butt_effect2( buttobj );

			return;
		};

		xhr.open( "POST" , strReq , true );	 
		xhr.setRequestHeader("Content-type","application/json");
		xhr.setRequestHeader("If-Modified-Since","0");
		xhr.send( JSON.stringify(json) );
	};

	setTimeout( f, 66 ); 
	 
	return false;
}





// 使用绝对地址  
function lf_post_ajax2( buttobj, jsonobj, outtxt_id )
{
	butt_effect( buttobj );
	var outtxt = document.getElementById(outtxt_id);
	var json = jsonobj;
	outtxt.value = "";

	var f = 
	function ()
	{
		var xhr = new XMLHttpRequest();
		var strReq;
		
		strReq =  "http://192.168.2.123:9091/a?"
		strReq += "cmd=post"; 
		strReq += "&aa=" + String( Math.random() );
            
		xhr.onreadystatechange = function ()
		{
			if( xhr.readyState != 4 ) return;

			if( xhr.status != 200 ) 
			{
				// setTimeout( f, 500 ); 
				butt_effect3( buttobj );
				return;
			}

			// alert(xhr.responseText);
			json = JSON.parse(xhr.responseText);
			outtxt.value = xhr.responseText

			if( json.rc != 1 )
			{
				//setTimeout( f, 1500 ); 
				butt_effect1( buttobj );
				return;
			}
			
			butt_effect2( buttobj );

			return;
		};

		xhr.open( "POST" , strReq , true );	 
		xhr.setRequestHeader("Content-type","application/json");
		xhr.setRequestHeader("If-Modified-Since","0");
		xhr.send( JSON.stringify(json) );
	};

	setTimeout( f, 66 ); 
	 
	return false;
}



// 使用相对地址，参数信息有回放  
function lf_post_ajax_showpara( buttobj, jsonobj, paratxt_id, outtxt_id )
{
	butt_effect( buttobj );

	var json = jsonobj;

	var paratxt = document.getElementById(paratxt_id);
	var outtxt = document.getElementById(outtxt_id);

	paratxt.value = "";
	outtxt.value = "";

	var f_do_ajax = 
	function ()
	{
		var xhr = new XMLHttpRequest();
		var strReq;
		
		strReq =  "a?";
		strReq += "aa=" + String( Math.random() );
            
		xhr.onreadystatechange = function ()
		{
			if( xhr.readyState != 4 ) return;

			if( xhr.status != 200 ) 
			{
				// setTimeout( f, 500 ); 
				butt_effect3( buttobj );
				return;
			}

			// alert(xhr.responseText);
			json = JSON.parse(xhr.responseText);
			outtxt.value = xhr.responseText;

			if( json.rc != 1 )
			{
				//setTimeout( f, 1500 ); 
				butt_effect1( buttobj );
				return;
			}
			
			butt_effect2( buttobj );

			return;
		};

		xhr.open( "POST" , strReq , true );	 
		xhr.setRequestHeader("Content-type","application/json");
		xhr.setRequestHeader("If-Modified-Since","0");
		xhr.send( JSON.stringify(json) );
	};

	var f_show_para = 
	function ()
	{
		// alert(JSON.stringify(json));
		paratxt.value = JSON.stringify(json);
	};

	setTimeout( f_show_para, 40 ); 
	setTimeout( f_do_ajax, 60 ); 
	 
	return false;
}





