//
//  PopUpNoBombLayer.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-25.
//
//

#include "PopUpNoBombLayer.h"

PopUpNoBombLayer::PopUpNoBombLayer():
m_callbackListener(NULL)
, m1_(NULL)
{
    
}

PopUpNoBombLayer::~PopUpNoBombLayer(){
}

bool PopUpNoBombLayer::init(){
    bool bRef = false;
    do{
		CC_BREAK_IF(!CCLayerColor::initWithColor(Color4B( 0x0a, 0x0a, 0x0a, 150 )) );
        
		this->setUpView();
		auto myListener = EventListenerTouchOneByOne::create();
		myListener->onTouchBegan = CC_CALLBACK_2(PopUpNoBombLayer::onTouchBegan, this);
		myListener->onTouchMoved = CC_CALLBACK_2(PopUpNoBombLayer::onTouchMoved, this);
		myListener->onTouchEnded = CC_CALLBACK_2(PopUpNoBombLayer::onTouchEnded, this);
		
		myListener->setSwallowTouches(true);
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		dispatcher->addEventListenerWithSceneGraphPriority(myListener, this);
		
		
        bRef = true;
    }while(0);
    return bRef;
}

bool PopUpNoBombLayer::onTouchBegan(Touch *touch, Event *unused_event){
	log("PopupLayer touch");
	return true;
}

void PopUpNoBombLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}
void PopUpNoBombLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}
void PopUpNoBombLayer::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}

void PopUpNoBombLayer::onEnter(){
    Layer::onEnter();
	
	
    // 弹出效果
    Action* popupLayer = Sequence::create(CCScaleTo::create(0.0, 0.0),
										  CCScaleTo::create(0.06, 1.05),
										  CCScaleTo::create(0.08, 0.95),
										  CCScaleTo::create(0.08, 1.0), NULL);
	//  bgLay->runAction(popupLayer);
	
}

void PopUpNoBombLayer::onExit(){
    
    log("popup on exit.");
    CCLayer::onExit();
}

#pragma mark --
#pragma mark -- Functions

void PopUpNoBombLayer::setUpView(){
	Size winSize = Director::getInstance()->getWinSize();
    Point pCenter = Point(winSize.width / 2, winSize.height / 2);
	
	std::vector<std::string> imgs;
	imgs.push_back(std::string("play_dialog_bg.png"));//bg
	
	imgs.push_back(std::string("play_dialog_button_long.png")); //close b n
	imgs.push_back(std::string("play_dialog_button_long_selected.png")); //close b s
	
	bgLay = Layer::create();
	
	Sprite* bg = Sprite::create( imgs.at(0));
	auto menuItem1 = MenuItemImage::create(
										   imgs.at(1),
										   imgs.at(2),
										   CC_CALLBACK_1(PopUpNoBombLayer::noBombClose, this));
//	auto menuItem2 = MenuItemImage::create(
//										   imgs.at(1),
//										   imgs.at(2),
//										   CC_CALLBACK_1(PopUpNoBombLayer::bombNotUse, this));
	
	bg->setAnchorPoint(Point(0.5f, 0.5f));
	menuItem1->setAnchorPoint(Point(0.5f, 0.5f));
	//menuItem2->setAnchorPoint(Point(0.5f, 0.5f));
	
	// create menu, it's an autorelease object
	
	LabelTTF * tip = LabelTTF::create("提示", "AmericanTypewriter", 30);//添加文字
	tip->setAnchorPoint(Point(0.5f, 0.5f));
	tip->setColor(Color3B::YELLOW);
	tip->setPosition(Point(pCenter.x, pCenter.y + 40));
	bgLay->addChild(tip, 2);
	
	LabelTTF *label = LabelTTF::create("亲~看看还剩下几个答案，\n这是要闹哪样？", "AmericanTypewriter", 40);//添加文字
	label->setAnchorPoint(Point(0.5f, 0.5f));
	label->setColor(Color3B::WHITE);
	label->setPosition(Point(pCenter.x, pCenter.y - 60));
	bgLay->addChild(label, 2);
	
	
    auto menu = Menu::create(menuItem1, NULL);
    menu->setPosition(Point::ZERO);
	menuItem1->setPosition(Point(pCenter.x,  pCenter.y - 180));
	
	LabelTTF *label1 = LabelTTF::create("知道啦", "AmericanTypewriter", 30);//添加文字
	
	label1->setColor(Color3B::WHITE);
	label1->setPosition(menuItem1->getPosition());
	bgLay->addChild(label1, 2);
//	
//	LabelTTF *label2 = LabelTTF::create("忍着不用", "AmericanTypewriter", 30);//添加文字
//	
//	label2->setColor(Color3B::WHITE);
//	label2->setPosition(menuItem2->getPosition());
//	bgLay->addChild(label2,2);
//	
	bg->setPosition(pCenter);
	
	bgLay->setContentSize(winSize);
	bgLay->addChild(bg);
    bgLay->addChild(menu, 1);
	
	this->addChild(bgLay);
}
void PopUpNoBombLayer::setCallbackFunc(Object* target, SEL_CallFuncN m1){
	m_callbackListener = target;
	m1_ = m1;
}

void PopUpNoBombLayer::noBombClose(Object * pSender){
	Node* node = dynamic_cast<Node*>(pSender);
    if (m1_ && m_callbackListener){
        (m_callbackListener->*m1_)(node);
    }
}
