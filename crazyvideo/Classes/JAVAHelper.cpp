//
//  JAVAHelper.cpp
//  knowledgegame
//
//  Created by 畅玩 on 13-10-14.
//
//

#include "JAVAHelper.h"

#include "platform/android/jni/JniHelper.h"
#include "cocos2d.h"
#include <jni.h>

using namespace cocos2d;
void wxHelp_JAVA(){
	JniMethodInfo methodInfo;

	if (JniHelper::getStaticMethodInfo(methodInfo, "com/candou/knowledgegame/util/JniManager", "wxHelp", "()V")) {
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, 0);
	}
}
void wxSendHelpByFriend_JAVA(){
	
}
void wxSendToFriendCircle_JAVA(){
	
}
void buy_JAVA(int goodId){
	
}

//void playLocalVideo_JAVA()
//{
//	JniMethodInfo methodInfo;
//	if (JniHelper::getStaticMethodInfo(methodInfo, "com/mz/games/crazyvideo/util/JniManager", "playLocalVideo", "()V")) {
//		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, 0);
//	}
//}

void playLocalVideo_JAVA(std::string& filename) {
	JniMethodInfo methodInfo;
	if (JniHelper::getStaticMethodInfo(methodInfo, "com/mz/games/crazyvideo/util/JniManager", "playLocalVideo", "(Ljava/lang/String;)V"))
	{
		jstring jmsg = methodInfo.env->NewStringUTF(filename.c_str());
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jmsg);
	}

}

//JNIEXPORT void JNICALL Java_com_candou_knowledgegame_util_JniManager_wxSendHelpByFriend
//	(JNIEnv *, jclass){
//	CCLog("java call c++, wxSendHelpByFriend");
//}

//JNIEXPORT void JNICALL Java_com_candou_knowledgegame_util_JniManager_wxSendHelpByTimeline
//  (JNIEnv *, jclass) {
//	CCLog("java call c++, wxSendHelpByTimeline");
//}