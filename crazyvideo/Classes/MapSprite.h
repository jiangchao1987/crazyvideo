#ifndef __MapSprite_H__
#define __MapSprite_H__

#include "cocos2d.h"
USING_NS_CC;

class MapSprite : public CCNode {
public:
    static MapSprite* createWithSpriteFrameName(const char* sPath);
    static MapSprite* createWithSprite(CCSprite* sprite);

    bool initWithSprite(CCSprite* sprite);

    CCSprite* getSprite();
    void setiNum(int iNum);
    int getiNum();
private:
    CCSprite* sprite;

    int m_iNum;
};

#endif