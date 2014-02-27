//
//  PopUpGoldNotEnough.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-26.
//
//

#ifndef __crazyvideo__PopUpGoldNotEnough__
#define __crazyvideo__PopUpGoldNotEnough__

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class PopUpGoldNotEnough: public LayerColor{
public:
    PopUpGoldNotEnough();
    ~PopUpGoldNotEnough();
    
    virtual bool init();
    CREATE_FUNC(PopUpGoldNotEnough);
    
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	
	void setCallbackFunc(Object* target, SEL_CallFuncN m1);
	
    
    virtual void onEnter();
    virtual void onExit();
    
private:
    
	Layer* bgLay;
    void setUpView();
    
    Object* m_callbackListener;
	SEL_CallFuncN m1_;
	
	void godNotEnoughClose(Object * pSender);
    
};
#endif /* defined(__crazyvideo__PopUpGoldNotEnough__) */
