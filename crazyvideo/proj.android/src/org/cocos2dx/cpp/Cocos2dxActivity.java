package org.cocos2dx.cpp;

import java.io.File;

import android.app.NativeActivity;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;

import com.mz.games.crazyvideo.util.SystemUtil;

public class Cocos2dxActivity extends NativeActivity{

	public static Cocos2dxActivity coco;
	
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
			default:
				break;
			}
		}
	};
}
