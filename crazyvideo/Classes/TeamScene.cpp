//
//  TeamScene.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#include "TeamScene.h"
#include "AboutScene.h"
#include "Tools.h"
#include "SimpleAudioEngine.h"

#include "StartScene.h"
USING_NS_CC;

Scene* TeamScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TeamScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool TeamScene::init()
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
		CC_CALLBACK_1(TeamScene::menuBackCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width / 7, origin.y + visibleSize.height * 6 / 7 + backItem->getContentSize().height / 2), backItem);

	////cehua
	auto cehuaItem = MenuItemImage::create(
		"team_cehua.png",
		"team_cehua.png",
		CC_CALLBACK_1(TeamScene::menuCehuaCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width / 4, origin.y + visibleSize.height / 2 + cehuaItem->getContentSize().height * 3 / 2 - 10), cehuaItem);

	////cehua label
	auto cehuaLabel = LabelTTF::create("策划: 赤裸裸的抄袭", "Arial", 30);
	cehuaLabel->setAnchorPoint(Point(0, 0.5f));
	cehuaLabel->setPosition(Point(origin.x + visibleSize.width / 3 + 30, origin.y + visibleSize.height / 2 + cehuaItem->getContentSize().height * 3 / 2 - 10));
	backLayer->addChild(cehuaLabel, 1);

	////chengxu
	auto chengxuItem = MenuItemImage::create(
		"team_chengxu.png",
		"team_chengxu.png",
		CC_CALLBACK_1(TeamScene::menuCehuaCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width / 4, origin.y + visibleSize.height / 2), chengxuItem);

	////chengxu label
	auto chengxuLabel = LabelTTF::create("程序: h && c", "Arial", 30);
	chengxuLabel->setAnchorPoint(Point(0, 0.5f));
	chengxuLabel->setPosition(Point(origin.x + visibleSize.width / 3 + 30, origin.y + visibleSize.height / 2));
	backLayer->addChild(chengxuLabel, 1);

	////meishu
	auto meishuItem = MenuItemImage::create(
		"team_meishu.png",
		"team_meishu.png",
		CC_CALLBACK_1(TeamScene::menuCehuaCallback, this));
	setItemPosition(backLayer, Point(0.5f, 0.5f),
		Point(origin.x + visibleSize.width / 4, origin.y + visibleSize.height / 2 - meishuItem->getContentSize().height * 3 / 2 + 10), meishuItem);

	////meishu label
	auto meishuLabel = LabelTTF::create("美术: fixpng!!!", "Arial", 30);
	meishuLabel->setAnchorPoint(Point(0, 0.5f));
	meishuLabel->setPosition(Point(origin.x + visibleSize.width / 3 + 30, origin.y + visibleSize.height / 2 - meishuItem->getContentSize().height * 3 / 2 + 10));
	backLayer->addChild(meishuLabel, 1);

	////studio label
	auto studioLabel = LabelTTF::create("豆豆 studio", "Arial", 30);
	studioLabel->setAnchorPoint(Point(0.5f, 0.5f));
	studioLabel->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 7));
	backLayer->addChild(studioLabel, 1);

	this->addChild(backLayer);

	return true;
}

void TeamScene::menuBackCallback(Object* pSender){
	playEffectBtnClicked();

	Scene* s = AboutScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}

void TeamScene::menuCehuaCallback(Object* pSender) {
	playEffectBtnClicked();

}

cocos2d::Layer* TeamScene::createStartBackLayer(){
	return NULL;
}
