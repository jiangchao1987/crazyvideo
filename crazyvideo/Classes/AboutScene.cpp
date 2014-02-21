//
//  AboutScene.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#include "AboutScene.h"
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
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
	
    
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
	
    // add the sprite as a child to this layer
	// this->addChild(sprite, 0);
	
	Size size = Director::getInstance()->getVisibleSize();
	
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
                                           CC_CALLBACK_1(AboutScene::menu1CloseCallback, this));
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
										  CC_CALLBACK_1(AboutScene::menu2CloseCallback, this));
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
											 CC_CALLBACK_1(AboutScene::menu3CloseCallback, this));
    settingItem->setAnchorPoint(Point(0.5f, 0.5f));
	settingItem->setPosition(Point(visibleSize.width/2 + settingItem->getContentSize().width/2  ,
								   visibleSize.height/4 ));
	
    // create menu, it's an autorelease object
    auto menu2 = Menu::create(settingItem, NULL);
    menu2->setPosition(Point::ZERO);
    backLayer->addChild(menu2, 1);
	
	
	this->addChild(backLayer);
    
	auto listener = EventListenerTouchOneByOne::create();
	//listener->registerScriptHandler();
	listener->onTouchBegan = NULL;
	listener->onTouchEnded = NULL;
	
	EventDispatcher* eventDispatcher = backLayer->getEventDispatcher();
	//eventDispatcher->addEventListenerWithSceneGraphPriority( listener, backLayer);
	
	
	return true;
}

void AboutScene::onEnter(){
	CCLayer::onEnter();
	
	if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
		;
	}else{
		
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("background.wav", true);
	}
}
void AboutScene::onExit(){
	CCLayer::onExit();
}
void AboutScene::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();
	
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void AboutScene::menu1CloseCallback(Object* pSender){
	
}
void AboutScene::menu2CloseCallback(Object* pSender){
	
}
void AboutScene::menu3CloseCallback(Object* pSender){
	Scene* s = StartScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
cocos2d::Layer* AboutScene::createStartBackLayer(){
	return NULL;
}