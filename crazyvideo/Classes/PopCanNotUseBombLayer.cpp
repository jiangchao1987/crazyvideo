//
//  PopCanNotUseBombLayer.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-26.
//
//

#include "PopCanNotUseBombLayer.h"
PopCanNotUseBombLayer::PopCanNotUseBombLayer():
m_callbackListener(NULL)
, m1_(NULL)
, m2_(NULL)
{
    
}

PopCanNotUseBombLayer::~PopCanNotUseBombLayer(){
}

bool PopCanNotUseBombLayer::init(){
    bool bRef = false;
    do{
		CC_BREAK_IF(!CCLayerColor::initWithColor(Color4B( 0x0a, 0x0a, 0x0a, 150 )) );
        
		this->setUpView();
		auto myListener = EventListenerTouchOneByOne::create();
		myListener->onTouchBegan = CC_CALLBACK_2(PopCanNotUseBombLayer::onTouchBegan, this);
		myListener->onTouchMoved = CC_CALLBACK_2(PopCanNotUseBombLayer::onTouchMoved, this);
		myListener->onTouchEnded = CC_CALLBACK_2(PopCanNotUseBombLayer::onTouchEnded, this);
		
		myListener->setSwallowTouches(true);
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		dispatcher->addEventListenerWithSceneGraphPriority(myListener, this);
		
		
        bRef = true;
    }while(0);
    return bRef;
}

bool PopCanNotUseBombLayer::onTouchBegan(Touch *touch, Event *unused_event){
	log("PopupLayer touch");
	return true;
}

void PopCanNotUseBombLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}
void PopCanNotUseBombLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}
void PopCanNotUseBombLayer::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}

void PopCanNotUseBombLayer::onEnter(){
    Layer::onEnter();
	
	
    // 弹出效果
    Action* popupLayer = Sequence::create(CCScaleTo::create(0.0, 0.0),
										  CCScaleTo::create(0.06, 1.05),
										  CCScaleTo::create(0.08, 0.95),
										  CCScaleTo::create(0.08, 1.0), NULL);
	//  bgLay->runAction(popupLayer);
	
}

void PopCanNotUseBombLayer::onExit(){
    
    log("popup on exit.");
    CCLayer::onExit();
}

#pragma mark --
#pragma mark -- Functions

void PopCanNotUseBombLayer::setUpView(){
	Size winSize = Director::getInstance()->getWinSize();
    Point pCenter = Point(winSize.width / 2, winSize.height / 2);
	
	std::vector<std::string> imgs;
	imgs.push_back(std::string("play_dialog_bg.png"));//bg
	
	imgs.push_back(std::string("play_dialog_button_long.png")); //close b n
	imgs.push_back(std::string("play_dialog_button_long_selected.png")); //close b s
	
	bgLay = Layer::create();
	
	
	LabelTTF * tip = LabelTTF::create("提示", "AmericanTypewriter", 30);//添加文字
	tip->setAnchorPoint(Point(0.5f, 0.5f));
	tip->setColor(Color3B::YELLOW);
	tip->setPosition(Point(pCenter.x, pCenter.y + 40));
	bgLay->addChild(tip, 2);
	
	LabelTTF *label = LabelTTF::create("金币不足无法使用道具，\n去领取金币么？", "AmericanTypewriter", 40);//添加文字
	label->setAnchorPoint(Point(0.5f, 0.5f));
	label->setColor(Color3B::WHITE);
	label->setPosition(Point(pCenter.x, pCenter.y - 60));
	bgLay->addChild(label, 2);
	
	
	Sprite* bg = Sprite::create( imgs.at(0));
	auto menuItem1 = MenuItemImage::create(
										   imgs.at(1),
										   imgs.at(2),
										   CC_CALLBACK_1(PopCanNotUseBombLayer::bombCannotUseOK, this));
	auto menuItem2 = MenuItemImage::create(
										   imgs.at(1),
										   imgs.at(2),
										   CC_CALLBACK_1(PopCanNotUseBombLayer::bombCannotUseClose, this));
	
	bg->setAnchorPoint(Point(0.5f, 0.5f));
	menuItem1->setAnchorPoint(Point(0.5f, 0.5f));
	menuItem2->setAnchorPoint(Point(0.5f, 0.5f));
	
	// create menu, it's an autorelease object
    auto menu = Menu::create(menuItem1, menuItem2, NULL);
    menu->setPosition(Point::ZERO);
	
	menuItem1->setPosition(Point(pCenter.x - 120,  pCenter.y - 180));
	menuItem2->setPosition(Point(pCenter.x + 120 ,  pCenter.y - 180));
	
	LabelTTF *label1 = LabelTTF::create("好的", "AmericanTypewriter", 30);//添加文字
	
	label1->setColor(Color3B::WHITE);
	label1->setPosition(menuItem1->getPosition());
	bgLay->addChild(label1, 2);
	
	LabelTTF *label2 = LabelTTF::create("忍着不领", "AmericanTypewriter", 30);//添加文字
	
	label2->setColor(Color3B::WHITE);
	label2->setPosition(menuItem2->getPosition());
	bgLay->addChild(label2,2);
	
	bg->setPosition(Point(pCenter.x, pCenter.y + 20));
	
	bgLay->setContentSize(winSize);
	bgLay->addChild(bg);
    bgLay->addChild(menu, 1);
	//	bgLay->addChild(title,2);
	
	this->addChild(bgLay);
}
void PopCanNotUseBombLayer::setCallbackFunc(Object* target, SEL_CallFuncN m1, SEL_CallFuncN m2){
	m_callbackListener = target;
	m1_ = m1;
	m2_ = m2;
}

//	void bombUse(Object * pSender);
//void bombNot(Object * pSender);

void PopCanNotUseBombLayer::bombCannotUseClose(Object * pSender){
	
	Node* node = dynamic_cast<Node*>(pSender);
    if (m1_ && m_callbackListener){
        (m_callbackListener->*m1_)(node);
    }
	
}
void PopCanNotUseBombLayer::bombCannotUseOK(Object * pSender){
	Node* node = dynamic_cast<Node*>(pSender);
    if (m2_ && m_callbackListener){
        (m_callbackListener->*m2_)(node);
    }
}