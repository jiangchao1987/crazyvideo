//
//  LevelScene.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#include "LevelScene.h"

#include "Tools.h"
#include "SimpleAudioEngine.h"

#include "StartScene.h"
USING_NS_CC;

Scene* LevelScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LevelScene::create();
	
    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool LevelScene::init()
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
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
	
    // add a "close" icon to exit the progress. it's an autorelease object
	//    auto closeItem = MenuItemImage::create(
	//                                           "CloseNormal.png",
	//                                           "CloseSelected.png",
	//                                           CC_CALLBACK_1(StartScene::menuCloseCallback, this));
	//
	//	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
	//								 origin.y + closeItem->getContentSize().height/2));
	//
	//    // create menu, it's an autorelease object
	//    auto menu = Menu::create(closeItem, nullptr);
	//    menu->setPosition(Point::ZERO);
	//    this->addChild(menu, 1);
	
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
	
    // add the sprite as a child to this layer
	// this->addChild(sprite, 0);
	
	Size size = Director::getInstance()->getVisibleSize();
	
	Layer* backLayer =	createCommonBackLayer();
	
	//logo
	Sprite* spriteLogo = createLogo();
	backLayer->addChild(spriteLogo);
	MoveTo* move1 = MoveTo::create(2, Point( spriteLogo->getPositionX(),spriteLogo->getPositionY() - 10));
	MoveTo* move2 = MoveTo::create(2, Point( spriteLogo->getPositionX(), spriteLogo->getPositionY() + 10));
	spriteLogo->runAction( RepeatForever::create(Sequence::create(move1, move2, nullptr)));
	
	//play
	auto closeItem = MenuItemImage::create(
                                           "index_play.png",
                                           "index_play_selected.png",
                                           CC_CALLBACK_1(LevelScene::menu1CloseCallback, this));
	closeItem->setAnchorPoint(Point(0.5f, 0.5f));
	
	closeItem->setPosition(Point(origin.x + visibleSize.width/2,
								 visibleSize.height/2 - closeItem->getContentSize().height));
	
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, nullptr);
    menu->setPosition(Point::ZERO);
    backLayer->addChild(menu, 1);
	
	//shop
	auto shopItem = MenuItemImage::create(
										  "index_store.png",
										  "index_store_selected.png",
										  CC_CALLBACK_1(LevelScene::menu2CloseCallback, this));
    shopItem->setAnchorPoint(Point(0.5f, 0.5f));
	shopItem->setPosition(Point(visibleSize.width/2 - shopItem->getContentSize().width/2  ,
								visibleSize.height/4 ));
	
    // create menu, it's an autorelease object
    auto menu1 = Menu::create(shopItem, nullptr);
    menu1->setPosition(Point::ZERO);
    backLayer->addChild(menu1, 1);
	
	//setting
	auto settingItem = MenuItemImage::create(
											 "index_setting.png",
											 "index_setting_selected.png",
											 CC_CALLBACK_1(LevelScene::menu3CloseCallback, this));
    settingItem->setAnchorPoint(Point(0.5f, 0.5f));
	settingItem->setPosition(Point(visibleSize.width/2 + settingItem->getContentSize().width/2  ,
								   visibleSize.height/4 ));
	
    // create menu, it's an autorelease object
    auto menu2 = Menu::create(settingItem, nullptr);
    menu2->setPosition(Point::ZERO);
    backLayer->addChild(menu2, 1);
	
	
	this->addChild(backLayer);
    
	auto listener = EventListenerTouchOneByOne::create();
	//listener->registerScriptHandler();
	listener->onTouchBegan = nullptr;
	listener->onTouchEnded = nullptr;
	
	EventDispatcher* eventDispatcher = backLayer->getEventDispatcher();
	//eventDispatcher->addEventListenerWithSceneGraphPriority( listener, backLayer);
	
	
	return true;
}

void LevelScene::onEnter(){
	CCLayer::onEnter();
	
	if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
		;
	}else{
		
		CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("background.wav", true);
	}
}
void LevelScene::onExit(){
	CCLayer::onExit();
}
void LevelScene::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();
	
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void LevelScene::menu1CloseCallback(Object* pSender){
	
}
void LevelScene::menu2CloseCallback(Object* pSender){
	
}
void LevelScene::menu3CloseCallback(Object* pSender){
	
	Scene* s = StartScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
cocos2d::Layer* LevelScene::createStartBackLayer(){
	return nullptr;
}