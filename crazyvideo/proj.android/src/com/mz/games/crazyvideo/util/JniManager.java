package com.mz.games.crazyvideo.util;

import org.cocos2dx.cpp.Cocos2dxActivity;

import android.os.Message;
import android.util.Log;

public class JniManager {

	public static void playLocalVideo(String filename)
	{
		Log.d("android crazyvideo debug info", "c++ call java, playLocalVideo");
		Message message = new Message();
		message.what = 1;
		message.obj = filename;
		Cocos2dxActivity.handler.sendMessage(message);
	}
	
}
