//
//  PopUpRightLayer.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-20.
//
//

#ifndef __crazyvideo__PopUpRightLayer__
#define __crazyvideo__PopUpRightLayer__
#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class PopUpRightLayer: public LayerColor{
public:
    PopUpRightLayer();
    ~PopUpRightLayer();
    
    virtual bool init();
    CREATE_FUNC(PopUpRightLayer);
    
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	
	void setCallbackFunc(Object* target, SEL_CallFuncN m1, SEL_CallFuncN m2 );
	
    
    virtual void onEnter();
    virtual void onExit();
    
private:
    
	Layer* bgLay;
    void setUpView();
    
    Object* m_callbackListener;
	SEL_CallFuncN m1_;
	SEL_CallFuncN m2_;
	
	void rightAskFriends(Object * pSender);
	void rightContinue(Object * pSender);
    
};
#endif /* defined(__crazyvideo__PopUpRightLayer__) */
