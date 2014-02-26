
//
//  StartScene.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#include "StartScene.h"
#include "AboutScene.h"
#include "LevelScene.h"
#include "CloudScene.h"
#include "LevelView.h"
#include "Tools.h"
#include "SimpleAudioEngine.h"
#include "ShopScene.h"


USING_NS_CC;

Scene* StartScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = StartScene::create();
	
    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
	
    /////////////////////////////
    // 3. add your codes below...
	
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
							 origin.y + visibleSize.height - label->getContentSize().height));
	
    // add the label as a child to this layer
	// this->addChild(label, 1);
	
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
	
    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	Layer* backLayer =	createCommonBackLayer();
	
	//logo
	Sprite* spriteLogo = createLogo();
	backLayer->addChild(spriteLogo);
	MoveTo* move1 = MoveTo::create(2, Point( spriteLogo->getPositionX(),spriteLogo->getPositionY() - 10));
	MoveTo* move2 = MoveTo::create(2, Point( spriteLogo->getPositionX(), spriteLogo->getPositionY() + 10));
	spriteLogo->runAction( RepeatForever::create(Sequence::create(move1, move2, NULL)));

	//play
	auto closeItem = MenuItemImage::create(
                                           "index_play.png",
                                           "index_play_selected.png",
                                           CC_CALLBACK_1(StartScene::menu1CloseCallback, this));
	closeItem->setAnchorPoint(Point(0.5f, 0.5f));

	closeItem->setPosition(Point(origin.x + visibleSize.width/2,
								 visibleSize.height/2 - closeItem->getContentSize().height));
	
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    backLayer->addChild(menu, 1);
	
	//shop
	auto shopItem = MenuItemImage::create(
                                           "index_store.png",
                                           "index_store_selected.png",
                                           CC_CALLBACK_1(StartScene::menu2CloseCallback, this));
    shopItem->setAnchorPoint(Point(0.5f, 0.5f));
	shopItem->setPosition(Point(visibleSize.width/2 - shopItem->getContentSize().width/2  ,
								 visibleSize.height/4 ));
	
    // create menu, it's an autorelease object
    auto menu1 = Menu::create(shopItem, NULL);
    menu1->setPosition(Point::ZERO);
    backLayer->addChild(menu1, 1);
	
	//setting
	auto settingItem = MenuItemImage::create(
										  "index_setting.png",
										  "index_setting_selected.png",
										  CC_CALLBACK_1(StartScene::menu3CloseCallback, this));
    settingItem->setAnchorPoint(Point(0.5f, 0.5f));
	settingItem->setPosition(Point(visibleSize.width/2 + settingItem->getContentSize().width/2  ,
								visibleSize.height/4 ));
	
    // create menu, it's an autorelease object
    auto menu2 = Menu::create(settingItem, NULL);
    menu2->setPosition(Point::ZERO);
    backLayer->addChild(menu2, 1);
	
	
    
	auto listener = EventListenerTouchOneByOne::create();
	//listener->registerScriptHandler();
	listener->onTouchBegan = NULL;
	listener->onTouchEnded = NULL;
	
	auto myListener = EventListenerTouchOneByOne::create();

	myListener->onTouchBegan = CC_CALLBACK_2(StartScene::onTouchBegan, this);
    myListener->onTouchMoved = CC_CALLBACK_2(StartScene::onTouchMoved, this);
    myListener->onTouchEnded = CC_CALLBACK_2(StartScene::onTouchEnded, this);
	
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(myListener, this);
	
	this->addChild(backLayer);
	return true;
}

void StartScene::onEnter(){
	CCLayer::onEnter();
	playBackGroundMusic();
}
void StartScene::onExit(){
	CCLayer::onExit();
}
void StartScene::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();
	
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void StartScene::menu1CloseCallback(Object* pSender){
//	Scene* s = LevelScene::createScene();
	
	//CloudScene.h
	
	playEffectBtnClicked();
	Scene* s = LevelView::scene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
void StartScene::menu2CloseCallback(Object* pSender){
	playEffectBtnClicked();

	Scene* s = ShopScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
void StartScene::menu3CloseCallback(Object* pSender){
	playEffectBtnClicked();
	
	Scene* s = AboutScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
cocos2d::Layer* StartScene::createStartBackLayer(){
	return NULL;
}

//test
bool StartScene::onTouchBegan(Touch *touch, Event *unused_event){
	log("bbbb");
	return true;
}
void StartScene::onTouchMoved(Touch *touch, Event *unused_event){
	log("mmm");

}
void StartScene::onTouchEnded(Touch *touch, Event *unused_event){
	log("eeee");

}
void StartScene::onTouchCancelled(Touch *touch, Event *unused_event){
	log("ccc");

}