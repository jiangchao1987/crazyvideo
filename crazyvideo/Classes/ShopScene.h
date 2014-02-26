//
//  ShopScene.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-26.
//
//

#ifndef __crazyvideo__ShopScene__
#define __crazyvideo__ShopScene__

#include "cocos2d.h"

USING_NS_CC;

class ShopScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuBackCallback(Object* pSender);
	void menuSoundCallback(Object* pSender);
    void menuMailCallback(Object* pSender);
    void menuResetCallback(Object* pSender);
	void menuRateCallback(Object* pSender);
	void menuTeamCallback(Object* pSender);
	void menuDeclaimerCallback(Object* pSender);
	
	
    // implement the "static create()" method manually
    CREATE_FUNC(ShopScene);
	
	//void onEnter();
	//void onExit();
		
	MenuItemImage* mii1;
	MenuItemImage* mii2;
};

#endif /* defined(__crazyvideo__ShopScene__) */
