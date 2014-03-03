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
	
	public static void shareToFriends()
	{
		Log.d("android crazyvideo debug info", "c++ call java, shareToFriends");
		Message message = new Message();
		message.what = 2;
		Cocos2dxActivity.handler.sendMessage(message);
	}
	
	public static void shareToFriend()
	{
		Log.d("android crazyvideo debug info", "c++ call java, shareToFriend");
		Message message = new Message();
		message.what = 3;
		Cocos2dxActivity.handler.sendMessage(message);
	}
	
	public native static void shareToFriendsCallback(boolean success);
	
	public native static void shareToFriendCallback(boolean success);
	
}
