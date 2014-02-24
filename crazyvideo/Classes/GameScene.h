//
//  GameScene.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#ifndef __crazyvideo__GameScene__
#define __crazyvideo__GameScene__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

typedef enum GameAnswerState{
	GameStateAnswerStateInit = 0x00,
	GameStateAnswerStateWrong = 0x01,
	GameStateAnswerStateRight = 0x02,

}GameAnswerState;

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	static cocos2d::Scene* createScene( bool bShowVideoOnAppear);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuBackCallback(Object* pSender);
	void menuGoldCallback(Object* pSender);
    void menuShareCallback(Object* pSender);
    void menuBombCallback(Object* pSender);
	void menuPlayCallback(Object* pSender);
	
	void menuCloseCallback(Object* pSender);
	void menu1CloseCallback(Object* pSender);
    void menu2CloseCallback(Object* pSender);
    void menu3CloseCallback(Object* pSender);
	
	void btn1callBack(Object *pSender, Control::EventType controlEvents);
	void btn2callBack(Object *pSender, Control::EventType controlEvents);
	void btn3callBack(Object *pSender, Control::EventType controlEvents);
	void btn4callBack(Object *pSender, Control::EventType controlEvents);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
	
	void onEnter();
	void onExit();
	
	cocos2d::Layer* createStartBackLayer();
	
	LabelTTF* gold;
	LabelTTF* topic_title;
	LabelTTF* guanka_index;
	LabelTTF* question;
	ControlButton* btn1 ;
	ControlButton* btn2 ;
	ControlButton* btn3 ;
	ControlButton* btn4 ;
	
	void getCurrentDic();
	void resetView();
	
	void popShareLayer();
	void popBombLayer();
	void popRightLayer();
	void popWrongLayer();
	
	//share pop call back
	void shareToFriends(CCNode * node);
	void shareToFriend(CCNode * node);
	void shareToTencent(CCNode * node);
	void shareToQZone(CCNode * node);
	void shareClose(CCNode *node);
	//wrong pop call back
	void wrongShare(CCNode * pSender);
	void wrongBomb(CCNode * pSender);
	void wrongBack(CCNode * pSender);
    //bomb pop call back
	void bombUse(CCNode * pSender);
	void bombNotUse(CCNode * pSender);
	//right pop call back
	
	void rightAskFriends(CCNode * pSender);
	void rightContinue(CCNode * pSender);
	
	//检查 是否答对
	bool checkAnswer(int answerIndex);
	void answerAnimation( int answerIndex);
	
	// 播放
	void playTheVideo();
//	void btnStateLogic(int nIndex, bool bChanged);
private:
	Dictionary* currentDic_;
	GameAnswerState answerOneState_;
	GameAnswerState answerTwoState_;
	GameAnswerState answerThreeState_;
	GameAnswerState answerFouState_;
	
private:
	bool  bShowVideoOnShow_;
public :
	void setShowVideoOnShow(bool bShow);

};

#endif /* defined(__crazyvideo__GameScene__) */
