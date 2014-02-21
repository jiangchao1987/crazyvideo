//
//  PopUpWrongLayer.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-20.
//
//

#include "PopUpWrongLayer.h"
PopUpWrongLayer::PopUpWrongLayer():
m_callbackListener(NULL)
, m1_(NULL)
, m2_(NULL)
, m3_(NULL)
{
    
}

PopUpWrongLayer::~PopUpWrongLayer(){
}

bool PopUpWrongLayer::init(){
    bool bRef = false;
    do{
		CC_BREAK_IF(!CCLayerColor::initWithColor(Color4B( 0x0a, 0x0a, 0x0a, 150 )) );
        
		this->setUpView();
		auto myListener = EventListenerTouchOneByOne::create();
		myListener->onTouchBegan = CC_CALLBACK_2(PopUpWrongLayer::onTouchBegan, this);
		myListener->onTouchMoved = CC_CALLBACK_2(PopUpWrongLayer::onTouchMoved, this);
		myListener->onTouchEnded = CC_CALLBACK_2(PopUpWrongLayer::onTouchEnded, this);
		
		myListener->setSwallowTouches(true);
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		dispatcher->addEventListenerWithSceneGraphPriority(myListener, this);
		
		
        bRef = true;
    }while(0);
    return bRef;
}

bool PopUpWrongLayer::onTouchBegan(Touch *touch, Event *unused_event){
	log("PopupLayer touch");
	return true;
}

void PopUpWrongLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}
void PopUpWrongLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}
void PopUpWrongLayer::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}

void PopUpWrongLayer::onEnter(){
    Layer::onEnter();
	
	
    // 弹出效果
    Action* popupLayer = Sequence::create(CCScaleTo::create(0.0, 0.0),
										  CCScaleTo::create(0.06, 1.05),
										  CCScaleTo::create(0.08, 0.95),
										  CCScaleTo::create(0.08, 1.0), NULL);
    bgLay->runAction(popupLayer);
	
}

void PopUpWrongLayer::onExit(){
    
    log("popup on exit.");
    CCLayer::onExit();
}

#pragma mark --
#pragma mark -- Functions

void PopUpWrongLayer::setUpView(){
	Size winSize = Director::getInstance()->getWinSize();
    Point pCenter = Point(winSize.width / 2, winSize.height / 2);
	
	std::vector<std::string> imgs;
	imgs.push_back(std::string("play_dialog_bg.png"));//bg
	imgs.push_back(std::string("UMS_qq_icon@2x.png"));
	imgs.push_back(std::string("UMS_qzone_icon_bonus@2x.png"));
	imgs.push_back(std::string("UMS_wechat_session_icon@2x.png"));
	imgs.push_back(std::string("UMS_wechat_timeline_icon_bonus@2x.png"));
	imgs.push_back(std::string("play_dialog_button.png")); //close b n
	imgs.push_back(std::string("play_dialog_button_selected.png")); //close b s
	
	Sprite* bg = Sprite::create( imgs.at(0));
	auto menuItem1 = MenuItemImage::create(
										   imgs.at(1),
										   imgs.at(1),
										   CC_CALLBACK_1(PopUpWrongLayer::wrongShare, this));
	auto menuItem2 = MenuItemImage::create(
										   imgs.at(2),
										   imgs.at(2),
										   CC_CALLBACK_1(PopUpWrongLayer::wrongBomb, this));
	auto menuItem3 = MenuItemImage::create(
										   imgs.at(3),
										   imgs.at(3),
										   CC_CALLBACK_1(PopUpWrongLayer::wrongBomb, this));
		
	bg->setAnchorPoint(Point(0.5f, 0.5f));
	menuItem1->setAnchorPoint(Point(0.5f, 0.5f));
	menuItem2->setAnchorPoint(Point(0.5f, 0.5f));
	menuItem3->setAnchorPoint(Point(0.5f, 0.5f));
	
	// create menu, it's an autorelease object
    auto menu = Menu::create(menuItem1, menuItem2, menuItem3, NULL);
    menu->setPosition(Point::ZERO);
	
	menuItem2->setPosition(Point(pCenter.x - 70,  pCenter.y - 50));
	menuItem1->setPosition(Point(pCenter.x - 70 *3 ,  pCenter.y - 50));
	menuItem3->setPosition(Point(pCenter.x + 70,  pCenter.y - 50));
	
//	backItem->setPosition(Point(pCenter.x, pCenter.y - 200 ));
//	LabelTTF* title = LabelTTF::create("关闭", "Arial", 40, backItem->getContentSize(), TextHAlignment::CENTER);
//	title->cocos2d::Node::setAnchorPoint(Point(0.5f, 0.5f));
//	title->setPosition(backItem->getPosition());
	bg->setPosition(pCenter);
	
	bgLay = Layer::create();
	bgLay->setContentSize(winSize);
	bgLay->addChild(bg);
    bgLay->addChild(menu, 1);
//	bgLay->addChild(title,2);
	
	this->addChild(bgLay);
}
void PopUpWrongLayer::setCallbackFunc(Object* target, SEL_CallFuncN m1, SEL_CallFuncN m2, SEL_CallFuncN m3){
	m_callbackListener = target;
	m1_ = m1;
	m2_ = m2;
	m3_ = m3;
}


void PopUpWrongLayer::wrongShare(Object * pSender){
	
	Node* node = dynamic_cast<Node*>(pSender);
    if (m1_ && m_callbackListener){
        (m_callbackListener->*m1_)(node);
    }
	
}
void PopUpWrongLayer::wrongBomb(Object * pSender){
	Node* node = dynamic_cast<Node*>(pSender);
    if (m2_ && m_callbackListener){
        (m_callbackListener->*m2_)(node);
    }
}
void PopUpWrongLayer::wrongBack(Object * pSender){
	Node* node = dynamic_cast<Node*>(pSender);
    if (m3_ && m_callbackListener){
        (m_callbackListener->*m3_)(node);
    }
}
