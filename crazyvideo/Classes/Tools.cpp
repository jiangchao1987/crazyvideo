//
//  Tools.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#include "Tools.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "DataMgr.h"

Layer* createCommonBackLayer(){
	
	Layer* layerBg = Layer::create();
	u_int32_t randomBgIndex = arc4random();
	
	randomBgIndex = randomBgIndex%2;
	
	string bgName;
	if ( randomBgIndex == 0) {
		bgName = "bg_day.png";
	}else{
		bgName = "bg_night.png";
	}
	
	bgName = "index_bg_iphone5.png";
	Size size = Director::getInstance()->getVisibleSize();
	
	
	Sprite* bg = Sprite::create(bgName);
	bg->setPosition(Point(size.width/2, size.height/2));
	
	layerBg->addChild(bg);
	
	return layerBg;
}

cocos2d::Sprite* createLogo(){
	
	Size size = Director::getInstance()->getVisibleSize();
	string logoName;
	logoName = "index_title.png";
	Sprite* logo = Sprite::create(logoName);
	logo->setPosition(Point(size.width/2 - 5, size.height/2 + logo->getSpriteFrame()->getRect().size.height/2));

	return logo;
}

cocos2d::Sprite* createGameNavBg(){
	/*
	 Size visibleSize = Director::getInstance()->getVisibleSize();
	 Point origin = Director::getInstance()->getVisibleOrigin();
	 */
	
	Size size = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	string logoName;
	logoName = "play_navbar_bg.png";
	Sprite* logo = Sprite::create(logoName);
	logo->setAnchorPoint(Point(0, 0));
	logo->setPosition(Point( origin.x + 0, origin.y + size.height - logo->getContentSize().height));
	
	return logo;
}

void enterGameScene(){
	Scene* s = GameScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}

ControlButton* standardButtonWithTitle( const char * bgname, const char * bgseledname, const char * title){

	//Creates and return a button with a default background and title color.
//    Scale9Sprite *backgroundButton = Scale9Sprite::create(bgname);//按下前
//    Scale9Sprite *backgroundHighlightedButton = Scale9Sprite::create(bgseledname);//按下后
	

	ControlButton* btn = ControlButton::create();
	btn->setPreferredSize(Size(522, 88));

	Scale9Sprite*	normal = Scale9Sprite::create(bgname);
	Scale9Sprite*	select = Scale9Sprite::create(bgseledname);
	Scale9Sprite* hightlight = Scale9Sprite::create(bgseledname);
	Scale9Sprite* disable = Scale9Sprite::create(bgname);
	
	btn->setBackgroundSpriteForState(normal, Control::State::NORMAL);
	btn->setBackgroundSpriteForState(select, Control::State::SELECTED);
	btn->setBackgroundSpriteForState(hightlight, Control::State::HIGH_LIGHTED);
	btn->setBackgroundSpriteForState(disable, Control::State::DISABLED);
	
	
    LabelTTF *titleButton = LabelTTF::create(title, "AmericanTypewriter", 30);//添加文字
	titleButton->setAnchorPoint(Point(0.5f, 0.5f));
	titleButton->setPosition(Point(btn->getContentSize().width/2, btn->getContentSize().height/2));
	titleButton->setColor(Color3B::BLACK);//设置文字点击前的颜色
	titleButton->setTag(1000);
	btn->addChild(titleButton);

    return btn;
}

void setItemPosition(Layer* backLayer, Point anchor, Point position, MenuItemImage* item) {
	item->setAnchorPoint(anchor);
	item->setPosition(position);
	// create menu, it's an autorelease object
	auto menu = Menu::create(item, NULL);
	menu->setPosition(Point::ZERO);
	backLayer->addChild(menu, 1);
}

void playBackGroundMusic(){
	if (!CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
		
		if(DataMgr::getInstance()->isBgSoundOpen()){
			CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("background.wav");
		}
	}else{
	}
}

void stopBackGroundMusic(){
	if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}else{
	}
}
void playEffectBtnClicked(){
	//pop3.mp3
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("pop3.mp3");
}

