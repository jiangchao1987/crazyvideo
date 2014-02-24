//
//  GameScene.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#include "GameScene.h"
#include "Tools.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
#include "StartScene.h"
#include "DataMgr.h"
#include "Defines.h"
#include "CrossPlatformHelper.h"
#include "PopLayerHeader.h"
#include "SimpleAudioEngine.h"
#include "LevelView.h"
#include "UserInfoMgr.h"

USING_NS_CC;
USING_NS_CC_EXT;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
	
    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
}

Scene* GameScene::createScene( bool bShowVideoOnAppear){

	// 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
	
	layer->setShowVideoOnShow( bShowVideoOnAppear);
    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
	
    guanka_index = LabelTTF::create("Hello World", "Arial", 30);
    
    // position the label on the center of the screen
    guanka_index->setPosition(Point(origin.x + visibleSize.width/2,
							 origin.y + visibleSize.height - guanka_index->getContentSize().height));
	
    // add the label as a child to this layer
	 this->addChild(guanka_index, 1);
//	topic_title->retain();
	
	topic_title = LabelTTF::create("Hello World", "Arial", 24);
    topic_title->setPosition(Point(origin.x + visibleSize.width/2,
								   origin.y + visibleSize.height - topic_title->getContentSize().height- guanka_index->getContentSize().height));
	
    // add the label as a child to this layer
	this->addChild(topic_title, 1);
	
	gold = LabelTTF::create("209", "Arial", 36);
	gold->setHorizontalAlignment(TextHAlignment::RIGHT);
	gold->setAnchorPoint(Point(1,0));
    gold->setPosition(Point(origin.x + visibleSize.width - 20,
								   origin.y + visibleSize.height - (topic_title->getContentSize().height- guanka_index->getContentSize().height) - 48 - 24));
	
    // add the label as a child to this layer
	this->addChild(gold, 1);
	
	
 
	Layer* backLayer =	createCommonBackLayer();
	//nav
	Sprite* nav = createGameNavBg();
	backLayer->addChild(nav);
	
	//back
	
	auto backItem = MenuItemImage::create(
                                           "play_back.png",
                                           "play_back_selected.png",
                                           CC_CALLBACK_1(GameScene::menuBackCallback, this));
	backItem->setAnchorPoint(Point(0.0f, 0.0f));
	
	backItem->setPosition(Point(origin.x + 10, nav->getPosition().y + 50));
	
    // create menu, it's an autorelease object
    auto menu = Menu::create(backItem, NULL);
    menu->setPosition(Point::ZERO);
    backLayer->addChild(menu, 1);
	
	// coin bg
	
	auto coinBgkItem = MenuItemImage::create(
										  "play_navbar_getcoin.png",
										  "play_navbar_getcoin_selected.png",
										  CC_CALLBACK_1(GameScene::menuGoldCallback, this));
	coinBgkItem->setAnchorPoint(Point(0.0f, 0.0f));
	
	coinBgkItem->setPosition(Point(origin.x + visibleSize.width - coinBgkItem->getContentSize().width - 10, nav->getPosition().y + 60));
	
    // create menu, it's an autorelease object
    auto menu1 = Menu::create(coinBgkItem, NULL);
    menu1->setPosition(Point::ZERO);
    backLayer->addChild(menu1, 1);
	
	//help
	//
	
	auto shareItem = MenuItemImage::create(
											 "play_share.png",
											 "play_share_selected.png",
											 CC_CALLBACK_1(GameScene::menuShareCallback, this));
	shareItem->setAnchorPoint(Point(0.0f, 0.0f));
	
	shareItem->setPosition(Point(origin.x + 10, nav->getPosition().y - 260));
	
    // create menu, it's an autorelease object
    auto menu2 = Menu::create(shareItem, NULL);
    menu2->setPosition(Point::ZERO);
    backLayer->addChild(menu2, 1);
	
	//bomb
	auto bombItem = MenuItemImage::create(
										   "play_bombtool.png",
										   "play_bombtool_selected.png",
										   CC_CALLBACK_1(GameScene::menuBombCallback, this));
	bombItem->setAnchorPoint(Point(0.0f, 0.0f));
	
	bombItem->setPosition(Point(origin.x + visibleSize.width - bombItem->getContentSize().width/2 -10, nav->getPosition().y - 220));
	
    // create menu, it's an autorelease object
    auto menu3 = Menu::create(bombItem, NULL);
    menu3->setPosition(Point::ZERO);
    backLayer->addChild(menu3, 1);
	
	// tv Bg
	Sprite* tvBg = Sprite::create("play_video_bg.png");
	bombItem->setAnchorPoint(Point(0.5f, 0.5f));
	tvBg->setPosition(origin.x + visibleSize.width/2 + 20, nav->getPositionY() - 260);
	
	backLayer->addChild(tvBg);

	//play
	auto playItem = MenuItemImage::create(
                                           "play_video_button.png",
                                           "play_video_button.png",
                                           CC_CALLBACK_1(GameScene::menuPlayCallback, this));
	playItem->setAnchorPoint(Point(0.5f, 0.5f));
	
	playItem->setPosition(Point(origin.x + 485, nav->getPositionY() - 350 - 15));
	
    // create menu, it's an autorelease object
    auto menu4 = Menu::create(playItem, NULL);
    menu4->setPosition(Point::ZERO);
    backLayer->addChild(menu4, 1);

	// question
	String* str = String::createWithFormat("你到底爱不爱我safsafsfs撒旦就发来时就按了福建省老奥发来 ");
	
	question = LabelTTF::create(str->getCString(), "AmericanTypewriter-Bold", 30, Size(300, 200), TextHAlignment::CENTER, cocos2d::TextVAlignment::CENTER);
	question->setAnchorPoint(Point(0.5f,0.5f));
	question->setPosition(origin.x + visibleSize.width/2, nav->getPositionY() - 260 + 0);

	backLayer->addChild(question);
	
	string title1 = "";
	string title2 = "";
	string title3 = "";
	string title4 = "";
	
//522 88

	btn1 = standardButtonWithTitle("play_answer_a_bg.png", "play_answer_a_bg.png", "");
	btn2 = standardButtonWithTitle("play_answer_b_bg.png", "play_answer_b_bg.png", "");
	btn3 = standardButtonWithTitle("play_answer_c_bg.png", "play_answer_c_bg.png", "");
	btn4 = standardButtonWithTitle("play_answer_d_bg.png", "play_answer_d_bg.png", "");
	
	int ybase = nav->getPositionY() - 850;
	int offset = 20;

	btn1->setAnchorPoint(Point(0.5f, 0.5f));
	btn2->setAnchorPoint(Point(0.5f, 0.5f));
	btn3->setAnchorPoint(Point(0.5f, 0.5f));
	btn4->setAnchorPoint(Point(0.5f, 0.5f));

	btn1->setPosition( visibleSize.width/2 ,ybase + (btn1->getContentSize().height + offset) * 3 );
	btn2->setPosition( visibleSize.width/2 ,ybase + (btn1->getContentSize().height + offset) * 2 );
	btn3->setPosition( visibleSize.width/2 ,ybase + (btn1->getContentSize().height + offset) * 1 );
	btn4->setPosition( visibleSize.width/2 ,ybase + (btn1->getContentSize().height + offset) * 0);
	
	/*
	 potentiometer->addTargetWithActionForControlEvents(this, cccontrol_selector(ControlPotentiometer::onValueChange), CCControlEventValueChanged)
	 */
	btn1->addTargetWithActionForControlEvents(this, cccontrol_selector( GameScene::btn1callBack),Control::EventType::TOUCH_UP_INSIDE);
	btn2->addTargetWithActionForControlEvents(this, cccontrol_selector( GameScene::btn2callBack),Control::EventType::TOUCH_UP_INSIDE);
	btn3->addTargetWithActionForControlEvents(this, cccontrol_selector( GameScene::btn3callBack),Control::EventType::TOUCH_UP_INSIDE);
	btn4->addTargetWithActionForControlEvents(this, cccontrol_selector( GameScene::btn4callBack),Control::EventType::TOUCH_UP_INSIDE);

//	addTargetWithActionForControlEvents
	backLayer->addChild(btn1);
	backLayer->addChild(btn2);
	backLayer->addChild(btn3);
	backLayer->addChild(btn4);

	this->addChild(backLayer);
    
	auto listener = EventListenerTouchOneByOne::create();
	//listener->registerScriptHandler();
	listener->onTouchBegan = NULL;
	listener->onTouchEnded = NULL;
	
	EventDispatcher* eventDispatcher = backLayer->getEventDispatcher();
	//eventDispatcher->addEventListenerWithSceneGraphPriority( listener, backLayer);
	
	return true;
}

void GameScene::onEnter(){
	CCLayer::onEnter();
	stopBackGroundMusic();
	currentDic_ = DataMgr::getInstance()->getCurrentQuestion();
	this->resetView();
	
	if ( bShowVideoOnShow_ ) {
		this->menuPlayCallback(NULL);
	}
}
void GameScene::onExit(){
	CCLayer::onExit();
	playBackGroundMusic();

}
void GameScene::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();
	
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameScene::menu1CloseCallback(Object* pSender){
	
}
void GameScene::menu2CloseCallback(Object* pSender){
	
}
void GameScene::menu3CloseCallback(Object* pSender){
	
	playEffectBtnClicked();

	Scene* s = StartScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}

#pragma mark --
#pragma mark -- Menu Functions

void GameScene::menuBackCallback(Object* pSender){
	playEffectBtnClicked();

	playBackGroundMusic();
	
	Scene* s = LevelView::scene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
void GameScene::menuGoldCallback(Object* pSender){
	playEffectBtnClicked();
}
void GameScene::menuShareCallback(Object* pSender){
	playEffectBtnClicked();
	this->popShareLayer();
}
void GameScene::menuBombCallback(Object* pSender){
	playEffectBtnClicked();
	this->popBombLayer();
}
void GameScene::menuPlayCallback(Object* pSender){
	playEffectBtnClicked();
	
	String* isLocal = (String*)currentDic_->objectForKey(Key_local_resource);
	String* netstr = (String*)currentDic_->objectForKey(Key_m3u8_url);
	String* localstr = (String*)currentDic_->objectForKey(Key_resource_name);
	
	
	if ( !isLocal->compare( "1" )){
		playLocalVideo(localstr->_string);
	}else{
		playNetVideo(netstr->_string);
	}
}



cocos2d::Layer* GameScene::createStartBackLayer(){
	return NULL;
}

void GameScene::getCurrentDic(){
	
}

void GameScene::resetView(){
	
	String* o1 = (String*)currentDic_->objectForKey(Key_option1);
	String* o2 = (String*)currentDic_->objectForKey(Key_option2);
	CCString* o3 = (CCString*)currentDic_->objectForKey(Key_option3);
	CCString* o4 = (CCString*)currentDic_->objectForKey(Key_option4);
	CCString* q = (CCString*)currentDic_->objectForKey(Key_question);
	CCString* index = (CCString*) currentDic_->objectForKey(Key_guanka_index);
	CCString* topic = (CCString*) currentDic_->objectForKey(Key_topic_title);
	

	LabelTTF* t1 = (LabelTTF*)btn1->getChildByTag(1000);
	LabelTTF* t2 = (LabelTTF*)btn2->getChildByTag(1000);
	LabelTTF* t3 = (LabelTTF*)btn3->getChildByTag(1000);
	LabelTTF* t4 = (LabelTTF*)btn4->getChildByTag(1000);

	t1->setString(o1->_string);
	t2->setString(o2->_string);
	t3->setString(o3->_string);
	t4->setString(o4->_string);

	
	question->setString(q->_string);
	guanka_index->setString(index->_string);
	topic_title->setString(topic->_string);
	
	answerOneState_ = GameStateAnswerStateInit;
	answerTwoState_ = GameStateAnswerStateInit;
	answerThreeState_ = GameStateAnswerStateInit;
	answerFouState_ = GameStateAnswerStateInit;
	
	int nGold = UserInfoMgr::getInstance()->getGold();
	CCString* goldStr = CCString::createWithFormat("%d", nGold);
	gold->setString(goldStr->_string);
}

#pragma mark --
#pragma mark -- Button Clicks
void GameScene::btn1callBack(Object *pSender, Control::EventType controlEvents){
	playEffectBtnClicked();

	if ( controlEvents == Control::EventType::TOUCH_UP_INSIDE ) {
		this->checkAnswer(1);
	}
}

void GameScene::btn2callBack(Object *pSender, Control::EventType controlEvents){
	playEffectBtnClicked();

	if ( controlEvents == Control::EventType::TOUCH_UP_INSIDE ) {
		this->checkAnswer(2);
	}
}
void GameScene::btn3callBack(Object *pSender, Control::EventType controlEvents){
	playEffectBtnClicked();

	if ( controlEvents == Control::EventType::TOUCH_UP_INSIDE ) {
		this->checkAnswer(3);
	}
}
void GameScene::btn4callBack(Object *pSender, Control::EventType controlEvents){
	playEffectBtnClicked();

	if ( controlEvents == Control::EventType::TOUCH_UP_INSIDE ) {
		this->checkAnswer(4);
	}
}

#pragma mark --
#pragma mark -- Pop Functions  Share
void GameScene::popShareLayer(){
	
	PopUpShareLayer* p = PopUpShareLayer::create();//create("play_dialog_bg.png");
	p->setTag(POPUPSHARELAYER_TAG);
	p->setCallbackFunc(this, callfuncN_selector(GameScene::shareClose),callfuncN_selector(GameScene::shareToFriend),callfuncN_selector(GameScene::shareToFriends),callfuncN_selector(GameScene::shareToTencent),callfuncN_selector(GameScene::shareToQZone) );
	this->addChild(p,2);
}
void GameScene::popBombLayer(){
	PopUpBombLayer* p = PopUpBombLayer::create();//create("play_dialog_bg.png");
	p->setTag(POPUPBOMBLAYER_TAG);
	p->setCallbackFunc(this, callfuncN_selector(GameScene::bombUse),callfuncN_selector(GameScene::bombNotUse) );
	this->addChild(p,2);
}
void GameScene::popRightLayer(){
	PopUpRightLayer* p = PopUpRightLayer::create();
	p->setTag(POPUPRIGHTLAYER_TAG);
	p->setCallbackFunc(this, callfuncN_selector(GameScene::rightAskFriends),callfuncN_selector(GameScene::rightContinue));
	this->addChild(p,2);
}
void GameScene::popWrongLayer(){
	PopUpWrongLayer* p = PopUpWrongLayer::create();
	p->setTag(POPUPWRONGLAYER_TAG);
	p->setCallbackFunc(this, callfuncN_selector(GameScene::wrongShare),callfuncN_selector(GameScene::wrongBomb), callfuncN_selector(GameScene::wrongBack) );
	this->addChild(p,2);
}

#pragma mark --
#pragma mark PopShareLayer CallBack
//share pop call back
void GameScene::shareToFriends(Node * node){
	
}
void GameScene::shareToFriend(Node * node){
	
}
void GameScene::shareToTencent(Node * node){
	
}
void GameScene::shareToQZone(Node * node){
//	Scene* s = GameScene::createScene();
//	Director::getInstance()->replaceScene(s);
//	
}
void GameScene::shareClose(Node *node){
	PopUpShareLayer* p = (PopUpShareLayer*)this->getChildByTag(POPUPSHARELAYER_TAG);
	p->removeFromParentAndCleanup(true);
}

#pragma mark --
#pragma mark PopWrongLayer CallBack
//wrong pop call back
void GameScene::wrongShare(Node * pSender){
	PopUpWrongLayer* p = (PopUpWrongLayer*)this->getChildByTag(POPUPWRONGLAYER_TAG);
	p->removeFromParentAndCleanup(true);
	
	this->popShareLayer();
}
void GameScene::wrongBomb(Node * pSender){
	PopUpWrongLayer* p = (PopUpWrongLayer*)this->getChildByTag(POPUPWRONGLAYER_TAG);
	p->removeFromParentAndCleanup(true);
	
	this->popBombLayer();
}
void GameScene::wrongBack(Node * pSender){
	PopUpWrongLayer* p = (PopUpWrongLayer*)this->getChildByTag(POPUPWRONGLAYER_TAG);
	p->removeFromParentAndCleanup(true);
	
}

#pragma mark --
#pragma mark PopBombLayer CallBack
//bomb pop call back
void GameScene::bombUse(CCNode * pSender){
	PopUpWrongLayer* p = (PopUpWrongLayer*)this->getChildByTag(POPUPBOMBLAYER_TAG);
	p->removeFromParentAndCleanup(true);
}
void GameScene::bombNotUse(CCNode * pSender){
	PopUpWrongLayer* p = (PopUpWrongLayer*)this->getChildByTag(POPUPBOMBLAYER_TAG);
	p->removeFromParentAndCleanup(true);
}

#pragma mark --
#pragma mark PopRightLayer CallBack

void GameScene::rightAskFriends(CCNode * pSender){
//	PopUpRightLayer* p = (PopUpRightLayer*)this->getChildByTag(POPUPRIGHTLAYER_TAG);
//	p->removeFromParentAndCleanup(true);
//
	this->popShareLayer();
}
void GameScene::rightContinue(CCNode * pSender){
	PopUpRightLayer* p = (PopUpRightLayer*)this->getChildByTag(POPUPRIGHTLAYER_TAG);
	p->removeFromParentAndCleanup(true);
	
	Scene* s = GameScene::createScene(true);
	
	Director::getInstance()->replaceScene(s);
}

#pragma mark --
#pragma mark -- Game Logic Functions
bool GameScene::checkAnswer(int answerIndex){
	
	bool bRet = false;
	int a = ((CCString*)currentDic_->objectForKey(Key_answer_index))->intValue();
	
	if ( a == answerIndex ){
		bRet = true;
	}else{
		bRet = false;
	}
	
	if ( bRet ) {
		if ( answerIndex == 1) {
			answerOneState_ = GameAnswerState::GameStateAnswerStateRight;
		}else if( answerIndex == 2){
			answerTwoState_ = GameAnswerState::GameStateAnswerStateRight;
		}else if( answerIndex == 3){
			answerThreeState_ = GameAnswerState::GameStateAnswerStateRight;
		}else if( answerIndex == 4){
			answerFouState_ = GameAnswerState::GameStateAnswerStateRight;
		}
	}else{
		if ( answerIndex == 1) {
			answerOneState_ = GameAnswerState::GameStateAnswerStateWrong;
		}else if( answerIndex == 2){
			answerTwoState_ = GameAnswerState::GameStateAnswerStateWrong;
		}else if( answerIndex == 3){
			answerThreeState_ = GameAnswerState::GameStateAnswerStateWrong;
		}else if( answerIndex == 4){
			answerFouState_ = GameAnswerState::GameStateAnswerStateWrong;
		}
	}
	
	this->answerAnimation( answerIndex );
	if ( bRet ) {
		this->popRightLayer();
		UserInfoMgr::getInstance()->answerRight();
		
	}else{
		this->popWrongLayer();
		UserInfoMgr::getInstance()->answerWrong();
	}
	
	int nGold = UserInfoMgr::getInstance()->getGold();
	CCString* goldStr = CCString::createWithFormat("%d", nGold);
	gold->setString(goldStr->_string);
	
	return bRet;
}

void GameScene::answerAnimation( int answerIndex){
	
	GameAnswerState st;
	ControlButton* btn;
	switch ( answerIndex ) {
		case 1:
			st = answerOneState_;
			btn = btn1;
			break;
		case 2:
			st = answerTwoState_;
			btn = btn2;
		    break;
		case 3:
			st = answerThreeState_;
			btn = btn3;
			break;
		case 4:
			st = answerFouState_;
			btn = btn4;
			break;
		default:
			break;
	}
	
	std::string correctwrongImgStr;
	
	if ( st == GameStateAnswerStateRight ) {
		//right
		correctwrongImgStr = "play_correct.png";
	}else{
		correctwrongImgStr = "play_wrong.png";
	}
	
	btn->setEnabled(false);
	Sprite* sp = Sprite::create(correctwrongImgStr);
	sp->setPosition( Point( btn->getPositionX() - btn->getContentSize().width/2 + sp->getContentSize().width, btn->getPositionY()));
	this->addChild(sp);
	
//	CCLabelBMFont* label = CCLabelBMFont::create("23","prim30.fnt");
//	label->setColor(Color3B::BLACK);
//	label->setPosition(sp->getPosition());
//	this->addChild(label);
	
}

#pragma mark --
#pragma mark -- ShowVideo On EnterScene

void GameScene::setShowVideoOnShow(bool bShow){
	bShowVideoOnShow_ = bShow;
}