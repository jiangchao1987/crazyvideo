//
//  Tools.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-18.
//
//

#include "Tools.h"
#include "GameScene.h"
//#inlcude "GameScene.h"

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
	Size size = Director::getInstance()->getVisibleSize();
	string logoName;
	logoName = "play_navbar_bg.png";
	Sprite* logo = Sprite::create(logoName);
	logo->setAnchorPoint(Point(0, 0));
	logo->setPosition(Point(0, size.height - logo->getContentSize().height));
	
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
	
	Scale9Sprite*	normal = Scale9Sprite::create(bgname);
	Scale9Sprite*	select = Scale9Sprite::create(bgseledname);
	Scale9Sprite* hightlight = Scale9Sprite::create(bgseledname);
	Scale9Sprite* disable = Scale9Sprite::create(bgname);
	
	//522 88
//	normal->setContentSize(Size(522, 88));
//	select->setContentSize(Size(522, 88));
//	hightlight->setContentSize(Size(522, 88));
//	disable->setContentSize(Size(522, 88));
//	btn->setContentSize(Size(522,88));
	btn->setBackgroundSpriteForState(normal, Control::State::NORMAL);
	btn->setBackgroundSpriteForState(select, Control::State::SELECTED);
	btn->setBackgroundSpriteForState(hightlight, Control::State::HIGH_LIGHTED);
	btn->setBackgroundSpriteForState(disable, Control::State::DISABLED);
	
	
    LabelTTF *titleButton = LabelTTF::create(title, "Marker Felt", 30);//添加文字
	titleButton->setColor(Color3B(0, 0, 0));//设置文字点击前的颜色
    btn->setPreferredSize(Size(522, 88));
	
	btn->setTitleLabel(titleButton);
//	
//    button->setBackgroundSpriteForState(backgroundHighlightedButton, Control::State::HIGH_LIGHTED);
//    button->setTitleColorForState(Color3B::WHITE, Control::State::HIGH_LIGHTED);//设置文字点击后的颜色
//    
    return btn;
}

