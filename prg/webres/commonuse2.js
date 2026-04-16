
//<!--  一段中文注释 -->


var j_env = { };
j_env.my_pagenumber = -999;
		


//EPFC引擎	
function WH_js()
{
	var j1 = { };
	var j2 = { };

	var f = 
	function ()
	{
		var xhr = new XMLHttpRequest();
		var strReq;
	
		j1.cmd = "WH_js";
		j1.n = j_env.my_pagenumber;
		
		strReq =  "aa?"
		strReq += "cmd=post"; 
		strReq += "&aa=" + String( Math.random() );
            
		xhr.onreadystatechange = function ()
		{
			if( xhr.readyState != 4 ) return;

			if( xhr.status != 200 ) 
			{
				setTimeout( f, 999 ); 
				return;
			}

			//alert(xhr.responseText);
			j2 = { };
			j2 = JSON.parse(xhr.responseText); 
 
			//document.getElementById("div_show_time").innerHTML = jo2.div_show_time;
			 
			var mydelay = 777;

			if( j2.rc == 1 )
			{
				try {
					var s_js = j2.js;
					eval(s_js); 
				} 
				catch(err) {
				}
				finally{
					mydelay = 9;
				}
			} 

			setTimeout( f, mydelay ); 
			return;
		};

		xhr.open( "POST" , strReq , true );	 
		xhr.setRequestHeader("Content-type","application/json");
		xhr.setRequestHeader("If-Modified-Since","0");
		xhr.send( JSON.stringify(j1) );
	};

	setTimeout( f, 9 ); 
	 
	return false;
}



//  
function EPFC_getpagename()
{
	var j1 = { };
	var j2 = { };

	var f = 
	function ()
	{
		var xhr = new XMLHttpRequest();
		var strReq;
	
		j1.cmd = "EPFC_getpagename";
		j1.n = j_env.my_pagenumber;
		
		strReq =  "aa?"
		strReq += "cmd=post"; 
		strReq += "&aa=" + String( Math.random() );
            
		xhr.onreadystatechange = function ()
		{
			if( xhr.readyState != 4 ) return;

			if( xhr.status != 200 ) 
			{
				setTimeout( f, 999 ); 
				return;
			}

			setTimeout( f, 999 ); 
			return;
		};

		xhr.open( "POST" , strReq , true );	 
		xhr.setRequestHeader("Content-type","application/json");
		xhr.setRequestHeader("If-Modified-Since","0");
		xhr.send( JSON.stringify(j1) );
	};

	setTimeout( f, 1000 ); 
	 
	return false;
}



//  
function EPFC_show_time()
{
	var j1 = { };
	var j2 = { };

	var f = 
	function ()
	{
		var xhr = new XMLHttpRequest();
		var strReq;
	
		j1.cmd = "EPFC_show_time";
		j1.para = document.getElementById("div_show_time").innerHTML;
		
		strReq =  "aa?"
		strReq += "cmd=post"; 
		strReq += "&aa=" + String( Math.random() );
            
		xhr.onreadystatechange = function ()
		{
			if( xhr.readyState != 4 ) return;

			if( xhr.status != 200 ) 
			{
				setTimeout( f, 999 ); 
				return;
			}

			//alert(xhr.responseText);
			//j2 = JSON.parse(xhr.responseText); 
 
			//document.getElementById("div_show_time").innerHTML = jo2.div_show_time;
		 
			setTimeout( f, 999 ); 
			return;
		};

		xhr.open( "POST" , strReq , true );	 
		xhr.setRequestHeader("Content-type","application/json");
		xhr.setRequestHeader("If-Modified-Since","0");
		xhr.send( JSON.stringify(j1) );
	};

	setTimeout( f, 1 ); 
	 
	return false;
}



//  
function EPFC_a( cmd )
{
	var j1 = { };

	var f = 
	function ()
	{
		var xhr = new XMLHttpRequest();
		var strReq;
	
		j1.cmd = cmd;
		
		strReq =  "aa?"
		strReq += "cmd=post"; 
		strReq += "&aa=" + String( Math.random() );
            
		xhr.onreadystatechange = function ()
		{
			if( xhr.readyState != 4 ) return;
			return;
		};

		xhr.open( "POST" , strReq , true );	 
		xhr.setRequestHeader("Content-type","application/json");
		xhr.setRequestHeader("If-Modified-Since","0");
		xhr.send( JSON.stringify(j1) );
	};

	setTimeout( f, 1 ); 
	 
	return false;
}



// 带参数的 EP_a	 
function EPFC_a_p( cmd, paraj )
{
	var j1 = { };

	var f = 
	function ()
	{
		var xhr = new XMLHttpRequest();
		var strReq;
	
		j1.cmd = cmd;
		j1.para = JSON.stringify(paraj);
		
		strReq =  "aa?"
		strReq += "cmd=post"; 
		strReq += "&aa=" + String( Math.random() );
            
		xhr.onreadystatechange = function ()
		{
			if( xhr.readyState != 4 ) return;
			return;
		};

		xhr.open( "POST" , strReq , true );	 
		xhr.setRequestHeader("Content-type","application/json");
		xhr.setRequestHeader("If-Modified-Since","0");
		xhr.send( JSON.stringify(j1) );
	};

	setTimeout( f, 1 ); 
	 
	return false;
}



// 带参数发出命令，回调1个函数	 
// f_act定义2个参数： true/false, 返回的json 
function EP_a2( jsonobj, f_act )
{
	var json_out = { };

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
				f_act( false, json_out );
				return;
			}

			// alert(xhr.responseText);

			try {
				json_out = JSON.parse(xhr.responseText); 
			} 
			catch(err) {
				f_act( false, json_out );
				return;	
			}
			finally{
			}
			
			if( json_out.rc == "1" )
			{			
				f_act( true, json_out );
				return;
			}

			f_act( false, json_out );
			return;	
		};

		xhr.open( "POST" , strReq , true );	 
		xhr.setRequestHeader("Content-type","application/json");
		xhr.setRequestHeader("If-Modified-Since","0");
		xhr.send( JSON.stringify(jsonobj) );
	};

	setTimeout( f, 1 ); 
	 
	return false;
}




// 简单型，接收 json_send和f_act，调用f_act之时带一个json_recv参数 f_act( json_recv ); 
function EP_a3( json_send, f_act )
{
	var json_recv = { };

	var f = 
	function ()
	{
		var xhr = new XMLHttpRequest();
		var strReq;
		
		strReq =  window.location.pathname + "?"
		strReq += "cmd=post"; 
		strReq += "&aa=" + String( Math.random() );
            
		xhr.onreadystatechange = function ()
		{
			if( xhr.readyState != 4 ) return;

			if( xhr.status != 200 ) 
			{
				json_recv.rc = 0; 
				f_act( json_recv );
				return;
			}

			// alert(xhr.responseText);

			try {
				json_recv = JSON.parse(xhr.responseText); 
			} 
			catch(err) {
				json_recv.rc = 0; 
				f_act( json_recv );
				return;	
			}
			finally{
			}
			
			f_act( json_recv );
			return;	
		};

		xhr.open( "POST" , strReq , true );	 
		xhr.setRequestHeader("Content-type","application/json");
		xhr.setRequestHeader("If-Modified-Since","0");
		xhr.send( JSON.stringify(json_send) );
	};

	setTimeout( f, 1 ); 
	 
	return false;
}



//function gb2utf8(s)
//{
//    var xx=new GB2312UTF8();
//    return xx.Utf8ToGb2312(s);
//     
//}
//

// GB2312UTF8().Utf8ToGb2312("aaa");
function GB2312UTF8(){
	this.Dig2Dec=function(s){
		var retV = 0;
		if(s.length == 4){
			for(var i = 0; i < 4; i ++){
				retV += eval(s.charAt(i)) * Math.pow(2, 3 - i);
			}
			return retV;
		}
		return -1;
	} 
	this.Hex2Utf8=function(s){
		var retS = "";
		var tempS = "";
		var ss = "";
		if(s.length == 16){
			tempS = "1110" + s.substring(0, 4);
			tempS += "10" + s.substring(4, 10); 
			tempS += "10" + s.substring(10,16); 
			var sss = "0123456789ABCDEF";
			for(var i = 0; i < 3; i ++){
				retS += "%";
				ss = tempS.substring(i * 8, (eval(i)+1)*8);
				retS += sss.charAt(this.Dig2Dec(ss.substring(0,4)));
				retS += sss.charAt(this.Dig2Dec(ss.substring(4,8)));
		 }
			return retS;
		}
		return "";
	} 
	this.Dec2Dig=function(n1){
		var s = "";
		var n2 = 0;
		for(var i = 0; i < 4; i++){
			n2 = Math.pow(2,3 - i);
			if(n1 >= n2){
				s += '1';
				n1 = n1 - n2;
			}
			else
				s += '0';
		}
		return s;      
	}

	this.Str2Hex=function(s){
		var c = "";
		var n;
		var ss = "0123456789ABCDEF";
		var digS = "";
		for(var i = 0; i < s.length; i ++){
			c = s.charAt(i);
			n = ss.indexOf(c);
			digS += this.Dec2Dig(eval(n));
		}
		return digS;
	}
	this.Gb2312ToUtf8=function(s1){
		var s = escape(s1);
		var sa = s.split("%");
		var retV ="";
		if(sa[0] != ""){
			retV = sa[0];
		}
		for(var i = 1; i < sa.length; i ++){
			if(sa[i].substring(0,1) == "u"){
				retV += this.Hex2Utf8(this.Str2Hex(sa[i].substring(1,5)));
				if(sa[i].length){
					retV += sa[i].substring(5);
				}
			}
			else{
				retV += unescape("%" + sa[i]);
				if(sa[i].length){
					retV += sa[i].substring(5);
				}
			}
		}
		return retV;
	}
	this.Utf8ToGb2312=function(str1){
		var substr = "";
		var a = "";
		var b = "";
		var c = "";
		var i = -1;
		i = str1.indexOf("%");
		if(i==-1){
			return str1;
		}
		while(i!= -1){
			if(i<3){
				substr = substr + str1.substr(0,i-1);
				str1 = str1.substr(i+1,str1.length-i);
				a = str1.substr(0,2);
				str1 = str1.substr(2,str1.length - 2);
				if(parseInt("0x" + a) & 0x80 == 0){
					substr = substr + String.fromCharCode(parseInt("0x" + a));
				}
				else if(parseInt("0x" + a) & 0xE0 == 0xC0){ //two byte
					b = str1.substr(1,2);
					str1 = str1.substr(3,str1.length - 3);
					var widechar = (parseInt("0x" + a) & 0x1F) << 6;
					widechar = widechar | (parseInt("0x" + b) & 0x3F);
					substr = substr + String.fromCharCode(widechar);
				}
				else{
					b = str1.substr(1,2);
					str1 = str1.substr(3,str1.length - 3);
					c = str1.substr(1,2);
					str1 = str1.substr(3,str1.length - 3);
					var widechar = (parseInt("0x" + a) & 0x0F) << 12;
					widechar = widechar | ((parseInt("0x" + b) & 0x3F) << 6);
					widechar = widechar | (parseInt("0x" + c) & 0x3F);
					substr = substr + String.fromCharCode(widechar);
				}
			}
			else {
				substr = substr + str1.substring(0,i);
				str1= str1.substring(i);
			}
			i = str1.indexOf("%");
		}

		return substr+str1;
	}
}




//日期格式化 
function dayFormat()
{
	var date = new Date();
	var current_date = date.getDate();
	var year = date.getFullYear();
	var month = date.getMonth() + 1;
	var day = date.getDate();
	if (month < 10)
	{
		month = "0" + month;
	}
	if (day < 10)
	{
		day = "0" + day;
	}
	var nowDate = year + "-" + month + "-" + day;
	return nowDate;
}


