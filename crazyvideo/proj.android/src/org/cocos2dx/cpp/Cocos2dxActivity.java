package org.cocos2dx.cpp;

import java.io.File;
import java.io.InputStream;

import android.app.NativeActivity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.widget.Toast;

import com.mz.games.crazyvideo.model.WxShare;
import com.mz.games.crazyvideo.util.JniManager;
import com.mz.games.crazyvideo.util.SystemUtil;

public class Cocos2dxActivity extends NativeActivity{

	public static Cocos2dxActivity coco;
	private static WxShare wx;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		
		coco = this;
		
		//For supports translucency
		
		//1.change "attribs" in cocos\2d\platform\android\nativeactivity.cpp
		/*const EGLint attribs[] = {
	            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
	            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,  
	            //EGL_BLUE_SIZE, 5,   -->delete 
	            //EGL_GREEN_SIZE, 6,  -->delete 
	            //EGL_RED_SIZE, 5,    -->delete 
	            EGL_BUFFER_SIZE, 32,  //-->new field
	            EGL_DEPTH_SIZE, 16,
	            EGL_STENCIL_SIZE, 8,
	            EGL_NONE
	    };*/
		
		//2.Set the format of window
		// getWindow().setFormat(PixelFormat.TRANSLUCENT);
		
		wx = new WxShare(this);
		wx.init();
		
	}
	
	public static Handler handler = new Handler() {

		@Override
		public void handleMessage(Message msg) {
			super.handleMessage(msg);
			switch (msg.what) {
			case 1:
				File folder = SystemUtil.createFolderOnSdcard("crazyvideo");
				String videoName = (String) msg.obj + ".mp4";
				SystemUtil.copyFileFromAssetsToSdcard(coco, folder, videoName);
				SystemUtil.playVideoBySystemPlayer(coco, folder.getAbsolutePath() + File.separator + videoName);
				break;
			case 2:
				Toast.makeText(coco, "分享给好友", Toast.LENGTH_SHORT).show();
				boolean success = shareToWx(false);
				JniManager.shareToFriendsCallback(success);
				break;
			case 3:
				Toast.makeText(coco, "分享到微信圈", Toast.LENGTH_SHORT).show();
				success = shareToWx(true);
				JniManager.shareToFriendCallback(success);
				break;
			default:
				break;
			}
		}
	};
	
	private static boolean shareToWx(boolean timeline)
	{
		boolean success = false;
		try {
			InputStream is = coco.getResources().getAssets().open("HelloWorld.png");
			success = wx.share("title", "summary", Bitmap.createScaledBitmap(BitmapFactory.decodeStream(is), 50, 50, timeline), false);
		} catch (Exception e) {
			e.printStackTrace();
		}
		return success;
	}
}
