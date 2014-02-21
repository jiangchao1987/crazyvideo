//
//  PopUpShareLayer.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-20.
//
//

#ifndef __crazyvideo__PopUpShareLayer__
#define __crazyvideo__PopUpShareLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class PopUpShareLayer: public LayerColor{
public:
    PopUpShareLayer();
    ~PopUpShareLayer();
    
    virtual bool init();
    CREATE_FUNC(PopUpShareLayer);
    
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	
	void setCallbackFunc(CCObject* target, SEL_CallFuncN callfun, SEL_CallFuncN m1, SEL_CallFuncN m2, SEL_CallFuncN m3, SEL_CallFuncN m4);

    
    virtual void onEnter();
    virtual void onExit();
    
private:
    
	Layer* bgLay;
    void setUpView();
    
    Object* m_callbackListener;
    SEL_CallFuncN m_callback;
	SEL_CallFuncN m1_;
	SEL_CallFuncN m2_;
	SEL_CallFuncN m3_;
	SEL_CallFuncN m4_;
	
	void shareToFriends(Object * pSender);
	void shareToFriend(Object * pSender);
	void shareToTencent(Object * pSender);
	void shareToQZone(Object * pSender);
	void shareClose(Object *pSender);
    
};

#endif /* defined(__crazyvideo__PopUpShareLayer__) */
