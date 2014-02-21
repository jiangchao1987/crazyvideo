//
//  TeamScene.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#ifndef __crazyvideo__TeamScene__
#define __crazyvideo__TeamScene__

#include <iostream>

#include "cocos2d.h"

USING_NS_CC;

class TeamScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuBackCallback(Object* pSender);
	void menuCehuaCallback(Object* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(TeamScene);
	
	cocos2d::Layer* createStartBackLayer();

};

#endif /* defined(__crazyvideo__TeamScene__) */
