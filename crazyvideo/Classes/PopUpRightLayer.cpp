//
//  PopUpRightLayer.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-20.
//
//

#include "PopUpRightLayer.h"
PopUpRightLayer::PopUpRightLayer():
m_callbackListener(NULL)
, m1_(NULL)
, m2_(NULL)
{
    
}

PopUpRightLayer::~PopUpRightLayer(){
}

bool PopUpRightLayer::init(){
    bool bRef = false;
    do{
		CC_BREAK_IF(!CCLayerColor::initWithColor(Color4B( 0x0a, 0x0a, 0x0a, 150 )) );
        
		this->setUpView();
		auto myListener = EventListenerTouchOneByOne::create();
		myListener->onTouchBegan = CC_CALLBACK_2(PopUpRightLayer::onTouchBegan, this);
		myListener->onTouchMoved = CC_CALLBACK_2(PopUpRightLayer::onTouchMoved, this);
		myListener->onTouchEnded = CC_CALLBACK_2(PopUpRightLayer::onTouchEnded, this);
		
		myListener->setSwallowTouches(true);
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		dispatcher->addEventListenerWithSceneGraphPriority(myListener, this);
		
		
        bRef = true;
    }while(0);
    return bRef;
}

bool PopUpRightLayer::onTouchBegan(Touch *touch, Event *unused_event){
	log("PopupLayer touch");
	return true;
}

void PopUpRightLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}
void PopUpRightLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}
void PopUpRightLayer::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}

void PopUpRightLayer::onEnter(){
    Layer::onEnter();
	
	
    // 弹出效果
    Action* popupLayer = Sequence::create(CCScaleTo::create(0.0, 0.0),
										  CCScaleTo::create(0.06, 1.05),
										  CCScaleTo::create(0.08, 0.95),
										  CCScaleTo::create(0.08, 1.0), NULL);
    bgLay->runAction(popupLayer);
	
}

void PopUpRightLayer::onExit(){
    
    log("popup on exit.");
    CCLayer::onExit();
}

#pragma mark --
#pragma mark -- Functions

void PopUpRightLayer::setUpView(){
	Size winSize = Director::getInstance()->getWinSize();
    Point pCenter = Point(winSize.width / 2, winSize.height / 2);
	
	std::vector<std::string> imgs;
	imgs.push_back(std::string("play_dialog_bg.png"));//bg
	imgs.push_back(std::string("play_continue_share.png"));
	imgs.push_back(std::string("play_continue_share_selected.png"));
	
	imgs.push_back(std::string("success_continue.png"));
	imgs.push_back(std::string("success_continue_selected.png")); //close b n

	Sprite* bg = Sprite::create( imgs.at(0));
	auto menuItem1 = MenuItemImage::create(
										   imgs.at(1),
										   imgs.at(1),
										   CC_CALLBACK_1(PopUpRightLayer::rightAskFriends, this));
	auto menuItem2 = MenuItemImage::create(
										   imgs.at(2),
										   imgs.at(2),
										   CC_CALLBACK_1(PopUpRightLayer::rightContinue, this));
	
	bg->setAnchorPoint(Point(0.5f, 0.5f));
	menuItem1->setAnchorPoint(Point(0.5f, 0.5f));
	menuItem2->setAnchorPoint(Point(0.5f, 0.5f));
	
	// create menu, it's an autorelease object
    auto menu = Menu::create(menuItem1, menuItem2, NULL);
    menu->setPosition(Point::ZERO);
	
	menuItem2->setPosition(Point(pCenter.x - 70,  pCenter.y - 50));
	menuItem1->setPosition(Point(pCenter.x - 70 *3 ,  pCenter.y - 50));
	
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
void PopUpRightLayer::setCallbackFunc(Object* target, SEL_CallFuncN m1, SEL_CallFuncN m2, SEL_CallFuncN m3){
	m_callbackListener = target;
	m1_ = m1;
	m2_ = m2;
}


void PopUpRightLayer::rightAskFriends(Object * pSender){
	
	Node* node = dynamic_cast<Node*>(pSender);
    if (m1_ && m_callbackListener){
        (m_callbackListener->*m1_)(node);
    }
	
}
void PopUpRightLayer::rightContinue(Object * pSender){
	Node* node = dynamic_cast<Node*>(pSender);
    if (m2_ && m_callbackListener){
        (m_callbackListener->*m2_)(node);
    }
}
