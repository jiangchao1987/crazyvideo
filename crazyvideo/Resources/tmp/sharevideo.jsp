<!DOCTYPE html>
<%@ page contentType="text/html; charset=UTF-8" %>
<html lang="zh-CN"><!--<![endif]--><head>
<link rel="stylesheet" type="text/css" href="buttons.css"/>
<!-- <meta name="viewport" content="width=device-width, initial-scale=1.0">
-->
<style type="text/css">
<!--
.iframestyle {
    position: absolute;
    width: 500px;
    height: 345px;
    top: 320px;
    left: 238px;
}

#question {
    position: absolute;
    font-size: 60px;
    font-family: 黑体;
    color: #fff;
    width: 90%;
    height: 345px;
    top: 745px;
    left: 6%;
    text-align: center;
}

#guanka_index {
    position: absolute;
    font-size: 80px;
    font-family: 黑体;
    color: #fff;
    width: 100%;
    height: 50px;
    top: 0px;
    left: 0px;
    text-align: center;
    margin-top: 20px;
}


#topic_title {
    position: absolute;
    font-size: 40px;
    font-family: 黑体;
    color: #fff;
    width: 100%;
    height: 345px;
    top: 60px;
    left: 0px;
    text-align: center;
}

#optionlist {
    position: absolute;
    width: 740px;
    height: 345px;
    top: 955px;
    left: 178px;
    list-style:none;
}

#optionlist li {
    font-size: 48px;
    font-family: 黑体;
    color: #000;
    line-height:151px;
}

#download_button {
    position: absolute;
    top: 8px;
    left: 10px;
    width: 330px;
}

#loadingpage {
    position: absolute;
    width: 100%;
    top: 0;
    left: 0;
}
-->
</style>
</head>

<body style="margin: 0px" bgcolor="#000000">
    <!--加载页-->
    <img id="loadingpage" src="http://ww1.sinaimg.cn/mw690/b9bc48e9gw1eclic4xe48j20hs0u0dgt.jpg" width="100%"/>
    <!--直接猜图页-->
    <div id="play_page_div" style="display:none;">
        <img id="play_bg" src="http://ww4.sinaimg.cn/mw690/b9bc48e9gw1ecuo5fj26mj20hs0u2ab7.jpg" width="100%"/>
        <img id="download_button" src="http://ww2.sinaimg.cn/mw690/b9bc48e9gw1ecuo8kaxt7j2062024q2w.jpg" onclick='jump_down_url()'/>

        <p id="guanka_index"></p>
        <p id="topic_title"></p>
        <h1 id="question"></h1>
        <ul id="optionlist">
            <li id="option1"></li>
            <li id="option2"></li>
            <li id="option3"></li>
            <li id="option4"></li>
        </ul>
        <%
            String sourceurl = request.getParameter("sourceurl");
            String youkuPrefix = "/id_";
            String v56Prefix = "/v_";
            String commonProfix = ".html";
            int hashStartingIndex = 0;
            int i = sourceurl.indexOf(youkuPrefix);
            int hashEndingIndex = sourceurl.indexOf(commonProfix);
            String hashCode;
            //youku
            if (i >= 0) {
                hashStartingIndex = i + youkuPrefix.length();
                hashCode = sourceurl.substring(hashStartingIndex, hashEndingIndex);
        %><iframe id="videoiframe" class="iframestyle" src="http://player.youku.com/embed/<%=hashCode%>" frameborder=0 allowfullscreen></iframe><%
            } else {
            //56net
                i = sourceurl.indexOf(v56Prefix);
                hashStartingIndex = i + v56Prefix.length();	
                hashCode = sourceurl.substring(hashStartingIndex, hashEndingIndex);
        %><iframe id="videoiframe" class="iframestyle" src="http://www.56.com/iframe/<%=hashCode%>" frameborder="0" allowfullscreen=""></iframe><%
            }
        %>
    </div>
</body>

<script>
function alertDown()
{
    window.location.href="guoguan.jsp";
//    document.getElementById("guoguanpage").style.display='block';
//    document.getElementsByTagName('body')[0].scrollTop = 0;
}

function jump_down_url(){
	location.href = "http://ti50.3g.qq.com/open/s?aid=jumpurl&url=http://url.cn/Rn8Jxu";
}

</script>
<script type="text/javascript" src="jquery-1.7.2.min.js"></script>

<!--ajax请求数据-->
<script language="javascript">
//创建XMLHttpRequest对象
var request = false;
try {
 request = new XMLHttpRequest();
} catch (trymicrosoft) {
 try {
 request = new ActiveXObject("Msxml2.XMLHTTP");
 } catch (othermicrosoft) {
 try {
 request = new ActiveXObject("Microsoft.XMLHTTP");
 } catch (failed) {
 request = false;
 }
 }
}
if (!request)alert("Error initializing XMLHttpRequest!");

//获取信息
function getInfo() {
 var url = "https://cn.avoscloud.com/1/classes/JingDian?where=" + encodeURIComponent('{"detail_url":"<%=request.getParameter("sourceurl")%>"}');

// alert(url);
 request.open("GET", url, true);
 request.setRequestHeader("X-AVOSCloud-Application-Id", "piy3lsbfn0febj1vi2chtderu6qwqmucv0to1xrqumnykyru");
 request.setRequestHeader("X-AVOSCloud-Application-Key", "dtlsjhf1zwj5oc8wn4vzcj7094sqgfz240whser3jlvewwb6");

 request.onreadystatechange = updatePage;
 request.send(null);
}
//更新页面
function updatePage() {
     if (request.readyState == 4) {
         if (request.status == 200) {
             var response = request.responseText;
             var myObject = eval('(' + response + ')');
             document.getElementById("guanka_index").innerText = myObject.results[0].guanka_index;
             document.getElementById("topic_title").innerText = myObject.results[0].topic_title;

             document.getElementById("question").innerText = myObject.results[0].question;

            //生成0-3的随机数
            var correctIndex = Math.floor(Math.random()*4);
            var wrongArray = new Array(myObject.results[0].option2, myObject.results[0].option3, myObject.results[0].option4);

            var wrongpointer = 0;
            for (var i = 0;i < 4;i++)
            {
                var optionId = 'option'+(i+1);
                if(i == correctIndex) {//正确答案
                    document.getElementById(optionId).innerText = myObject.results[0].option1;
                    document.getElementById(optionId).onclick =function(){
                        window.location.href='guoguan.jsp?right=1';
                    }
                } else {
                    document.getElementById(optionId).innerText = wrongArray[wrongpointer++];
                    document.getElementById(optionId).onclick =function(){
                        window.location.href='guoguan.jsp?right=0';
                    }
                }
            }
             startHideLoadingTimer();
         } else if(request.status == 404) {
             alert ("Requested URL is not found.");
         } else if (request.status == 403) {
             alert("Access denied.");
         } else
             alert("status is " + request.status);
     }
}
getInfo();

function startHideLoadingTimer()
{
	setTimeout(hideLoading, 1*1000);
}

function hideLoading() {
    //平台、设备和操作系统
    var system ={  
        win : false,
        mac : false,
        xll : false
    };
 
    //检测平台   
    var p = navigator.platform;
    system.win = p.indexOf("Win") == 0;  
    system.mac = p.indexOf("Mac") == 0;
    system.x11 = (p == "X11") || (p.indexOf("Linux") == 0);
 
    //pc跳转语句
    if(system.win||system.mac||system.xll){
        alert('您的朋友分享的视频，来自这个nb的iPhone游戏');
        window.location.href="https://itunes.apple.com/cn/app/er-zi-qu-na-er/id757889902?ls=1&mt=8";
    } else {//手机浏览器执行语句
        if (/(iPhone|iPad|iPod|iOS)/i.test(navigator.userAgent)) {
            document.getElementById("loadingpage").style.display = 'none';
            document.getElementById("play_page_div").style.display = 'block';
        } else if (/(Android)/i.test(navigator.userAgent)) {
            window.location.href="https://itunes.apple.com/cn/app/er-zi-qu-na-er/id757889902?ls=1&mt=8";
        }
    }
}

function jump_down_url(){
	location.href = "http://ti50.3g.qq.com/open/s?aid=jumpurl&url=http://url.cn/Rn8Jxu";
}

</script>
</html>