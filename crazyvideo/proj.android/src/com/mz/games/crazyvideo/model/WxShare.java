package com.mz.games.crazyvideo.model;

import android.app.Activity;
import android.graphics.Bitmap;

import com.mz.games.crazyvideo.util.ImageUtil;
import com.tencent.mm.sdk.openapi.IWXAPI;
import com.tencent.mm.sdk.openapi.SendMessageToWX;
import com.tencent.mm.sdk.openapi.WXAPIFactory;
import com.tencent.mm.sdk.openapi.WXMediaMessage;
import com.tencent.mm.sdk.openapi.WXWebpageObject;

public class WxShare {
	
	public static final String APP_ID = "wx4176fde382a55b67";
	private IWXAPI api;
	private final Activity mDetailActivity;
	
	public WxShare(Activity detailActivity) {
		this.mDetailActivity = detailActivity;
	}

	public void init() {
		api = WXAPIFactory.createWXAPI(mDetailActivity, APP_ID, false);
		api.registerApp(APP_ID);  
	}
	
	public boolean share(String title, String summary, Bitmap bitmap, boolean timeline) {
		WXWebpageObject webpage = new WXWebpageObject();
		webpage.webpageUrl = "http://m.candou.com/";
		WXMediaMessage msg = new WXMediaMessage(webpage);
		msg.title = title;
		msg.description = summary;
		msg.thumbData = ImageUtil.bmpToByteArray(bitmap, true);
		
		SendMessageToWX.Req req = new SendMessageToWX.Req();
		req.transaction = buildTransaction("webpage");
		req.message = msg;
		req.scene = timeline ? SendMessageToWX.Req.WXSceneTimeline : SendMessageToWX.Req.WXSceneSession;
		return api.sendReq(req);
	}
	
	private String buildTransaction(final String type) {
		return (type == null) ? String.valueOf(System.currentTimeMillis()) : type + System.currentTimeMillis();
	}
	
}
