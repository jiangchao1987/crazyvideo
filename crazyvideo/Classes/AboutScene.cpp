//
//  AboutScene.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#include "AboutScene.h"
#include "TeamScene.h"
#include "Tools.h"
#include "SimpleAudioEngine.h"
#include "StartScene.h"
#include "DataMgr.h"
USING_NS_CC;

Scene* AboutScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = AboutScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool AboutScene::init()
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
		CC_CALLBACK_1(AboutScene::menuBackCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width / 7, origin.y + visibleSize.height * 6 / 7 + backItem->getContentSize().height / 2), backItem);
	
	////sound
//	auto soundItem = MenuItemImage::create(
//		"setting_soundon.png",
//		"setting_soundoff.png",
	mii1 = MenuItemImage::create(
										   "setting_soundon.png",
										   "setting_soundon.png",

		CC_CALLBACK_1(AboutScene::menuSoundCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width / 3 - 10, origin.y + visibleSize.height * 3 / 4), mii1);

	mii2 = MenuItemImage::create(
										   "setting_soundoff.png",
										   "setting_soundoff.png",
					   
										   CC_CALLBACK_1(AboutScene::menuSoundCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
					Point(origin.x + visibleSize.width / 3 - 10, origin.y + visibleSize.height * 3 / 4), mii2);
	
	if ( DataMgr::getInstance()->isBgSoundOpen() ){
		mii1->setVisible(true);
		mii2->setVisible(false);
	}else{
		mii1->setVisible(false);
		mii2->setVisible(true);
	}

	////mail
	auto mailItem = MenuItemImage::create(
		"setting_mail.png",
		"setting_mail_selected.png",
		CC_CALLBACK_1(AboutScene::menuMailCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width * 2 / 3 + 10, origin.y + visibleSize.height * 3 / 4), mailItem);

	////reset
	auto resetItem = MenuItemImage::create(
		"setting_reset.png",
		"setting_reset_selected.png",
		CC_CALLBACK_1(AboutScene::menuResetCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 + resetItem->getContentSize().height), resetItem);

	////rate
	auto rateItem = MenuItemImage::create(
		"setting_rate.png",
		"setting_rate_selected.png",
		CC_CALLBACK_1(AboutScene::menuRateCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2), rateItem);

	////team
	auto teamItem = MenuItemImage::create(
		"setting_team.png",
		"setting_team_selected.png",
		CC_CALLBACK_1(AboutScene::menuTeamCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - teamItem->getContentSize().height), teamItem);

	////declaimer
	auto declaimerItem = MenuItemImage::create(
		"setting_declaimer.png",
		"setting_declaimer_selected.png",
		CC_CALLBACK_1(AboutScene::menuDeclaimerCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2 - declaimerItem->getContentSize().height * 2), declaimerItem);

	////version label
	auto versionLabel = LabelTTF::create("Version: 1.0", "Arial", 30);
	versionLabel->setAnchorPoint(Point(0.5f, 0.5f));
	versionLabel->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 8));
	backLayer->addChild(versionLabel, 1);

	this->addChild(backLayer);

	return true;
}

void AboutScene::menuBackCallback(Object* pSender){
	playEffectBtnClicked();

	Scene* s = StartScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
void AboutScene::menuSoundCallback(Object* pSender){
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

void AboutScene::menuMailCallback(Object* pSender){
	playEffectBtnClicked();

}
void AboutScene::menuResetCallback(Object* pSender){
	playEffectBtnClicked();

}
void AboutScene::menuRateCallback(Object* pSender){
	playEffectBtnClicked();

}
void AboutScene::menuTeamCallback(Object* pSender){
	playEffectBtnClicked();

	Scene* s = TeamScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
void AboutScene::menuDeclaimerCallback(Object* pSender){
	playEffectBtnClicked();

}
cocos2d::Layer* AboutScene::createStartBackLayer(){
	return NULL;
}

