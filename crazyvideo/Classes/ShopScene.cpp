//
//  ShopScene.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-26.
//
//

#include "ShopScene.h"
#include "TeamScene.h"
#include "Tools.h"
#include "SimpleAudioEngine.h"
#include "StartScene.h"
#include "DataMgr.h"
#include "UserInfoMgr.h"
#include "CrossPlatformHelper.h"

USING_NS_CC;

Scene* ShopScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	
	// 'layer' is an autorelease object
	auto layer = ShopScene::create();
	
	// add layer as a child to scene
	scene->addChild(layer);
	
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool ShopScene::init()
{
	//////////////////////////////
	if (!Layer::init())
	{
		return false;
	}
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	
	Layer* backLayer = createCommonBackLayer();
	
	////back
	auto backItem = MenuItemImage::create(
										  "setting_back.png",
										  "setting_back_selected.png",
										  CC_CALLBACK_1(ShopScene::menuBackCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
					Point(origin.x + visibleSize.width / 7, origin.y + visibleSize.height * 6 / 7 + backItem->getContentSize().height / 2), backItem);
	

	////mail
	auto mailItem = MenuItemImage::create(
										  "play_dialog_button_long.png",
										  "play_dialog_button_long_selected.png",
										  CC_CALLBACK_1(ShopScene::menuMailCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
					Point(origin.x + visibleSize.width/2, origin.y + visibleSize.height * 3 / 4), mailItem);
	
	
	
	////rate
	auto rateItem = MenuItemImage::create(
										  "play_dialog_button_long.png",
										  "play_dialog_button_long_selected.png",
										  CC_CALLBACK_1(ShopScene::menuRateCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
					Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2), rateItem);
	
	////version label
	auto getGold = LabelTTF::create("获取金币", "Arial", 30);
	getGold->setAnchorPoint(Point(0.5f, 0.5f));
	getGold->setPosition( rateItem->getPosition());
	backLayer->addChild(getGold, 1);
	
	////team
	auto teamItem = MenuItemImage::create(
										  "play_dialog_button_long.png",
										  "play_dialog_button_long_selected.png",
										  CC_CALLBACK_1(ShopScene::menuTeamCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
					Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - teamItem->getContentSize().height), teamItem);
	
	/// label
	auto shareToFriends = LabelTTF::create("分享获取金币", "Arial", 30);
	shareToFriends->setAnchorPoint(Point(0.5f, 0.5f));
	shareToFriends->setPosition( teamItem->getPosition());
	backLayer->addChild(shareToFriends, 1);
	
	
	////version label
	auto versionLabel = LabelTTF::create("Version: 1.0", "Arial", 30);
	versionLabel->setAnchorPoint(Point(0.5f, 0.5f));
	versionLabel->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 8));
	backLayer->addChild(versionLabel, 1);
	
	this->addChild(backLayer);
	
	return true;
}

void ShopScene::menuBackCallback(Object* pSender){
	playEffectBtnClicked();
	
//	Scene* s = StartScene::createScene();
	Director::getInstance()->popScene();
}
void ShopScene::menuSoundCallback(Object* pSender){
	playEffectBtnClicked();
	
	if ( (MenuItemImage*) pSender == mii1){
		mii1->setVisible(false);
		mii2->setVisible(true);
		DataMgr::getInstance()->openBgSound(false);
		stopBackGroundMusic();
	}else{
		mii1->setVisible(true);
		mii2->setVisible(false);
		DataMgr::getInstance()->openBgSound(true);
		playBackGroundMusic();
	}
}

void ShopScene::menuMailCallback(Object* pSender){
	playEffectBtnClicked();
	
}
void ShopScene::menuResetCallback(Object* pSender){
	playEffectBtnClicked();
	
	//X_showOffWall();
}
void ShopScene::menuRateCallback(Object* pSender){
	playEffectBtnClicked();
	
	UserInfoMgr::getInstance()->buyGold(100);
	
}
void ShopScene::menuTeamCallback(Object* pSender){
	playEffectBtnClicked();
	
	Scene* s = TeamScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
void ShopScene::menuDeclaimerCallback(Object* pSender){
	playEffectBtnClicked();
	
}

