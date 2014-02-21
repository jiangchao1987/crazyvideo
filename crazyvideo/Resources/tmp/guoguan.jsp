<!DOCTYPE html>
<%@ page contentType="text/html; charset=UTF-8" %>
<html lang="zh-CN"><!--<![endif]--><head>
<style type="text/css">
<!--

#guoguanpage {
    position: absolute;
    width: 100%;
    top: 0;
    left: 0;
}

#righttag {
    position: absolute;
    top: 420px;
    width: 100%;
    text-align: center;

    font-size: 70px;
    font-family: 黑体;
    color: #0f0;
}

#wrongtag {
    position: absolute;
    top: 420px;
    width: 100%;
    text-align: center;

    font-size: 70px;
    font-family: 黑体;
    color: #f00;
}

#guodu {
    position: absolute;
    top: 530px;
    width: 100%;
    text-align: center;

    font-size: 65px;
    font-family: 黑体;
    color: #ff0;

}

#downsuggest {
    position: absolute;
    top: 740px;
    width: 100%;
    text-align: center;

    font-size: 50px;
    font-family: 黑体;
    color: #fff;
}

-->
</style>
</head>

<body style="margin: 0px" bgcolor="#000000">
    <!--过关页-->
    <img id="guoguanpage" src="http://ww4.sinaimg.cn/mw690/b9bc48e9gw1ecmgc5qbi0j20hs0u0q6j.jpg" width="100%" onclick='jump_down_url()'/>
    <%
    String right = request.getParameter("right");
    int i = right.indexOf('1');
    if (i >= 0) {//正确答案
    %>
        <h1 id="righttag">答对！土豪我们做朋友吧</h1>
        <h1 id="guodu">别让你朋友蒙在鼓里^_^</h1>
        <h1 id="downsuggest">更多精彩题目等你挑战 就不信你都知道</h1>
    <%} else {%>
        <h1 id="wrongtag">错啦！亲的智商是硬伤呀</h1>
        <h1 id="guodu">想知道答案吗?^_^</h1>
        <h1 id="downsuggest">那就赶快去下载完整版吧 更多精彩题目</h1>
    <%}%>
</body>

<script>

function jump_down_url(){
	location.href = "http://ti50.3g.qq.com/open/s?aid=jumpurl&url=http://url.cn/Rn8Jxu";
}

</script>
</html>