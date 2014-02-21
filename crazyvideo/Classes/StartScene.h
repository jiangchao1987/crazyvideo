//
//  StartScene.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#ifndef __crazyvideo__StartScene__
#define __crazyvideo__StartScene__

#include <iostream>

#include "cocos2d.h"

class StartScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
	void menu1CloseCallback(Object* pSender);
    void menu2CloseCallback(Object* pSender);
    void menu3CloseCallback(Object* pSender);
	
	// test
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	

    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
	
	void onEnter();
	void onExit();
	
	cocos2d::Layer* createStartBackLayer();
};


#endif /* defined(__crazyvideo__StartScene__) */
