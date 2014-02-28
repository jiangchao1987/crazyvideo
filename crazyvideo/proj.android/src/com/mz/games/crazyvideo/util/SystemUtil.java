package com.mz.games.crazyvideo.util;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;

import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Environment;

public class SystemUtil {

	public static File createFolderOnSdcard(String folderName)
	{
		File folder = new File(Environment.getExternalStorageDirectory().getPath()
				+ File.separator + folderName);
		if (!folder.exists()) {
			folder.mkdirs();
		}
		return folder;
	}
	
	public static void copyFileFromAssetsToSdcard(Context context, File folder, String fileName)
	{
		File file = new File(folder.getAbsoluteFile() + File.separator + fileName);
		if (!file.exists()) {
			try {
				InputStream ins = context.getResources().getAssets().open(fileName);  
				FileOutputStream fos = new FileOutputStream(file);
				byte[] buffer = new byte[8192];
				int count = 0;
				while ((count = ins.read(buffer)) > 0) {
					fos.write(buffer, 0, count);
				}
				fos.close();
				ins.close();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
	
	public static void playVideoBySystemPlayer(Context context, String path) {
		File audioFile = new File(path);
		Intent intent = new Intent(Intent.ACTION_VIEW);
		intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
		intent.putExtra("oneshot", 0);
		intent.putExtra("configchange", 0);
		Uri uri = Uri.fromFile(audioFile);
		intent.setDataAndType(uri, "video/mp4");
		context.startActivity(intent);
	}
	
}
