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
	auto soundItem = MenuItemImage::create(
										   "setting_soundon.png",
										   "setting_soundon.png",

		CC_CALLBACK_1(AboutScene::menuSoundCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width / 3 - 10, origin.y + visibleSize.height * 3 / 4), soundItem);

	auto soundItem1 = MenuItemImage::create(
										   "setting_soundoff.png",
										   "setting_soundoff.png",
					   
										   CC_CALLBACK_1(AboutScene::menuSoundCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
					Point(origin.x + visibleSize.width / 3 - 10, origin.y + visibleSize.height * 3 / 4), soundItem1);
	soundItem->setTag(10000);
	soundItem1->setTag(10001);
	
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
	Scene* s = StartScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
void AboutScene::menuSoundCallback(Object* pSender){
	
	MenuItemImage* mii1 = (MenuItemImage*)this->getChildByTag(10000);
	MenuItemImage* mii2 = (MenuItemImage*)this->getChildByTag(10001);

	if ( (MenuItemImage*) pSender == mii1){
		mii1->setVisible(false);
		mii2->setVisible(true);
	}else{
		mii1->setVisible(true);
		mii2->setVisible(false);
	}
}

void AboutScene::menuMailCallback(Object* pSender){

}
void AboutScene::menuResetCallback(Object* pSender){

}
void AboutScene::menuRateCallback(Object* pSender){

}
void AboutScene::menuTeamCallback(Object* pSender){
	Scene* s = TeamScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
void AboutScene::menuDeclaimerCallback(Object* pSender){

}
cocos2d::Layer* AboutScene::createStartBackLayer(){
	return NULL;
}

//void AboutScene::setItemPos(Layer* backLayer, Point anchor, Point position, MenuItemImage* item) {
//	item->setAnchorPoint(anchor);
//	item->setPosition(position);
//	// create menu, it's an autorelease object
//	auto menu = Menu::create(item, NULL);
//	menu->setPosition(Point::ZERO);
//	backLayer->addChild(menu, 1);
//}
