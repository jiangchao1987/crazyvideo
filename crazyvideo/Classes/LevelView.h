//
//  LevelView.h
//  Map
//
//  Created by leafsoar on 7/27/13.
//
//

#ifndef Map_LevelView_h
#define Map_LevelView_h

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "LsTouch.h"

USING_NS_CC;
USING_NS_CC_EXT;

class LevelView: public Layer, LsTouchEvent{
public:
    LevelView();
    ~LevelView();
    
    static Scene* scene();
    virtual bool init();
    CREATE_FUNC(LevelView);
    
	void onEnter();
	void onExit();
	
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    virtual void onTouchCancelled(Touch *touch, Event *unused_event);

	
	virtual void touchEventAction(LsTouch* touch, int type);

    void adjustScrollView(float offset);
    Layer* getContainLayer();
    
    Node* getSpriteByLevel(int level);
    
    void setCurPageBall();
    

	void menuBackCallback(Object* pSender);
	void menuGoldCallback(Object* pSender);
	LabelTTF* gold;

	void resetView();
	void popGodTipsLayer();
	
	void godTipsGetGod(Node * pSender);
	void godTipsGiveUp(Node * pSender);
private:
    Point m_touchPoint;
    Point m_touchOffset;
    
    int m_nCurPage;
    int m_nPageCount;

    CC_SYNTHESIZE_RETAIN(ScrollView*, m_pScrollView, ScrollView);
};

#endif
