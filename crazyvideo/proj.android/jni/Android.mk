LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
../../Classes/AppDelegate.cpp \
../../Classes/HelloWorldScene.cpp \
../../Classes/AboutScene.cpp \
../../Classes/CloudScene.cpp \
../../Classes/CrossPlatformHelper.cpp \
../../Classes/DataMgr.cpp \
../../Classes/GameScene.cpp \
../../Classes/JAVAHelper.cpp \
../../Classes/LevelScene.cpp \
../../Classes/LevelView.cpp \
../../Classes/LsTouch.cpp \
../../Classes/PopUpBombLayer.cpp \
../../Classes/PopUpLevelUpLayer.cpp \
../../Classes/PopUpRightLayer.cpp \
../../Classes/PopUpShareLayer.cpp \
../../Classes/PopUpWrongLayer.cpp \
../../Classes/StartScene.cpp \
../../Classes/StringUtil.cpp \
../../Classes/TeamScene.cpp \
../../Classes/TiledFourCell.cpp \
../../Classes/Tools.cpp \
../../Classes/UserInfoMgr.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,2d)
$(call import-module,audio/android)
$(call import-module,Box2D)
$(call import-module,extensions)