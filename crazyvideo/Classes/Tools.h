//
//  Tools.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#ifndef __crazyvideo__Tools__
#define __crazyvideo__Tools__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

#define SaveStringToXML CCUserDefault::sharedUserDefault()->setStringForKey
#define SaveIntegerToXML CCUserDefault::sharedUserDefault()->setIntegerForKey
#define SaveBooleanToXML CCUserDefault::sharedUserDefault()->setBoolForKey
#define LoadStringFromXML CCUserDefault::sharedUserDefault()->getStringForKey
#define LoadIntegerFromXML CCUserDefault::sharedUserDefault()->getIntegerForKey
#define LoadBooleanFromXML CCUserDefault::sharedUserDefault()->getBoolForKey
#define WriteDisk CCUserDefault::sharedUserDefault()->flush()


cocos2d::Layer* createCommonBackLayer();
cocos2d::Sprite* createLogo();
cocos2d::Sprite* createGameNavBg();
void enterGameScene();

ControlButton* standardButtonWithTitle( const char * bgname, const char * bgseledname, const char * title);

//cocos2d::Sprite* create();

void setItemPosition(Layer* layer, Point anchor, Point position, MenuItemImage* item);

void playBackGroundMusic();
void stopBackGroundMusic();

void playEffectBtnClicked();

#endif /* defined(__crazyvideo__Tools__) */
