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

//class GameAnswerState1 : public CCObject{
//
//public:
//	GameAnswerState  state_;
//};

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
	
//	void menuCloseCallback(Object* pSender);
//	void menu1CloseCallback(Object* pSender);
//    void menu2CloseCallback(Object* pSender);
//    void menu3CloseCallback(Object* pSender);
	
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
	void popNoBombLayer();
	void popCanNotUseBombLayer();
	void popNoGoldNotEnoughLayer();

	
	//share pop call back
	void shareToFriends(Node * node);
	void shareToFriend(Node * node);
	void shareToTencent(Node * node);
	void shareToQZone(Node * node);
	void shareClose(Node *node);
	//wrong pop call back
	void wrongShare(Node * pSender);
	void wrongBomb(Node * pSender);
	void wrongBack(Node * pSender);
    //bomb pop call back
	void bombUse(Node * pSender);
	void bombNotUse(Node * pSender);
	//right pop call back
	void rightAskFriends(Node * pSender);
	void rightContinue(Node * pSender);
	//no bomb pop call back
	void noBombClose(Node * pSender);
	//cannot use bomb
	void bombCannotUseClose(Node * pSender);
	void bombCannotUseOK(Node * pSender);
    //gold not engough
	void goldNotEnoughClose(Node * pSender);


	
	//检查 是否答对
	bool checkAnswer(int answerIndex, bool useBomb = false);
	void answerAnimation( int answerIndex);
	
	// 播放
	void playTheVideo();
//	void btnStateLogic(int nIndex, bool bChanged);
private:
	Dictionary* currentDic_;
	GameAnswerState answerStateArr_[4];

//	GameAnswerState answerOneState_;
//	GameAnswerState answerTwoState_;
//	GameAnswerState answerThreeState_;
//	GameAnswerState answerFouState_;
	
private:
	bool  bShowVideoOnShow_;
//	CCArray*  answerStateArr_;
public :
	void setShowVideoOnShow(bool bShow);

};

#endif /* defined(__crazyvideo__GameScene__) */
