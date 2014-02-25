//
//  PopUpNoBombLayer.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-25.
//
//

#ifndef __crazyvideo__PopUpNoBombLayer__
#define __crazyvideo__PopUpNoBombLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class PopUpNoBombLayer: public LayerColor{
public:
    PopUpNoBombLayer();
    ~PopUpNoBombLayer();
    
    virtual bool init();
    CREATE_FUNC(PopUpNoBombLayer);
    
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
	
	void noBombClose(Object * pSender);
//	void bombNotUse(Object * pSender);
    
};

#endif /* defined(__crazyvideo__PopUpNoBombLayer__) */
