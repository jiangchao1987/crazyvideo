//
//  LevelView.cpp
//  Map
//
//  Created by leafsoar on 7/27/13.
//
//

#include "LevelView.h"
#include "StartScene.h"
#include "Tools.h"
#include "UserInfoMgr.h"

LevelView::LevelView():
m_nCurPage(0),
m_nPageCount(0),
m_pScrollView(0)
{
    
}

LevelView::~LevelView(){
    
}

Scene* LevelView::scene(){
    Scene* scene = Scene::create();
    Layer* layer = LevelView::create();
    scene->addChild(layer);
    return scene;
}

bool LevelView::init(){
    bool bRef = false;
    do{
        CC_BREAK_IF(!Layer::init());
//        Size winSize = Director::getInstance()->getWinSize();

		Size visibleSize = Director::getInstance()->getVisibleSize();
		Point origin = Director::getInstance()->getVisibleOrigin();
	
        // 添加一个半透明的灰显层
        Layer* backLayerColor = createCommonBackLayer();
        this->addChild(backLayerColor);
		
		////back
		auto backItem = MenuItemImage::create(
											  "setting_back.png",
											  "setting_back_selected.png",
											  CC_CALLBACK_1(LevelView::menuBackCallback, this));
		setItemPosition(backLayerColor, Point(0.5f, 0.5f),
						Point(origin.x + visibleSize.width / 7, origin.y +visibleSize.height * 6 / 7 + backItem->getContentSize().height / 2), backItem);
		
        
        // 创建一个 CCScrollView, 内容大小和当前的界面一样
        ScrollView* scrollView = ScrollView::create(this->getContentSize());
        scrollView->setContainer(getContainLayer());
        scrollView->setTouchEnabled(false);
        

        setScrollView(scrollView);
        this->addChild(scrollView);


        log("level view ...");
		
		auto myListener = EventListenerTouchOneByOne::create();
		
		myListener->onTouchBegan = CC_CALLBACK_2(LevelView::onTouchBegan, this);
		myListener->onTouchMoved = CC_CALLBACK_2(LevelView::onTouchMoved, this);
		myListener->onTouchEnded = CC_CALLBACK_2(LevelView::onTouchEnded, this);
	
		
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		dispatcher->addEventListenerWithSceneGraphPriority(myListener, this);
		
        setCurPageBall();
    
        bRef = true;
    }while (0);
    return bRef;
}

void LevelView::touchEventAction(LsTouch *touch, int type){
    // type 事件类型，0：touchbegin 1：touchend 触发 2：touchend 未触发
    if (touch)
        CCLog("touch event action id: %d  type: %d", touch->getEventId(), type);
    const int selectTag = 10001;
    if (type == 0 && touch){
        getScrollView()->getContainer()->removeChildByTag(selectTag);
        // 添加选撞状态的精灵，背景
        Sprite* sprite = Sprite::create("level/sel.png");
        sprite->setScaleX(2);
        sprite->setScaleY(4);
        sprite->setPosition(touch->getPosition());
        getScrollView()->getContainer()->addChild(sprite, 1, selectTag);
        
    } else {
        getScrollView()->getContainer()->removeChildByTag(selectTag);
    }
    if (type == 1 && touch){
        // 收到 type 为 1 表示触发关卡选择
		playEffectBtnClicked();
        CCString* str = CCString::createWithFormat("您选择的关卡为 %d .", touch->getEventId() + 1);
      //  MessageBox("关卡", str->getCString());
		
		UserInfoMgr::getInstance()->setFreedomLevel( touch->getEventId());
		enterGameScene();
    }
}

//void LevelView::registerWithTouchDispatcher(){
//    CCDirector::getInstance()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
//}

bool LevelView::onTouchBegan(Touch *touch, Event *unused_event){
	log("touch begin.");
    m_touchPoint = CCDirector::getInstance()->convertToGL(touch->getLocationInView());
    m_touchOffset = getScrollView()->getContentOffset();
    // 发送触摸消息，并会在 touEventAction 自动相应， 如果触摸到元素
    sendTouchMessage(touch, 0);
    
    return true;
}
void LevelView::onTouchMoved(Touch *touch, Event *unused_event){

	Point movePoint = CCDirector::getInstance()->convertToGL(touch->getLocationInView());
    float distance = movePoint.x - m_touchPoint.x;
    // 设定当前偏移位置
    Point adjustPoint = Point(m_touchOffset.x + distance, 0);
    getScrollView()->setContentOffset(adjustPoint, false);
}
void LevelView::onTouchEnded(Touch *touch, Event *unused_event){
	Point endPoint = CCDirector::getInstance()->convertToGL(touch->getLocationInView());
    float distance = endPoint.x - m_touchPoint.x;
    float distanceY = endPoint.y - m_touchPoint.y;
	
	log("distance x:%f y:%f", distance, distanceY);
//    if (fabs(distance) < 3 && fabs(distanceY) < 3){
	if (fabs(distance) < 10 ){

        // 小于三，不做拖动操作，也排除了（抖动误操作）,第二个参数，事件类型 1： touch end， 由 touchEventAction 自动相应
        sendTouchMessage(touch, 1);
		
    }else if (fabs(distance) > 50){
        // 大于 50，执行拖动效果
        adjustScrollView(distance);
        setCurPageBall();
    }else{
        // 回退为拖动之前的位置
        adjustScrollView(0);
    }
    
    sendTouchMessage(touch, 2);
}
void LevelView::onTouchCancelled(Touch *touch, Event *unused_event){
	adjustScrollView(0);

}
/*
bool LevelView::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    CCLog("touch begin.");
    m_touchPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    m_touchOffset = getScrollView()->getContentOffset();
    // 发送触摸消息，并会在 touEventAction 自动相应， 如果触摸到元素
    sendTouchMessage(pTouch, 0);
    
    return true;
}

void LevelView::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    CCPoint movePoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    float distance = movePoint.x - m_touchPoint.x;
    // 设定当前偏移位置
    CCPoint adjustPoint = ccp(m_touchOffset.x + distance, 0);
    getScrollView()->setContentOffset(adjustPoint, false);
}

void LevelView::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    CCPoint endPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
    float distance = endPoint.x - m_touchPoint.x;
    float distanceY = endPoint.y - m_touchPoint.y;
    if (fabs(distance) < 3 && fabs(distanceY) < 3){
        // 小于三，不做拖动操作，也排除了（抖动误操作）,第二个参数，事件类型 1： touch end， 由 touchEventAction 自动相应
        sendTouchMessage(pTouch, 1);

    }else if (fabs(distance) > 50){
        // 大于 50，执行拖动效果
        adjustScrollView(distance);
        setCurPageBall();
    }else{
        // 回退为拖动之前的位置
        adjustScrollView(0);
    }
    
    sendTouchMessage(pTouch, 2);
}

void LevelView::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    adjustScrollView(0);
}

 */
void LevelView::adjustScrollView(float offset){
    CCSize winSize = Director::getInstance()->getWinSize();
    // 我们根据 offset 的实际情况来判断移动效果
    if (offset < 0)
        m_nCurPage ++;
    else if (offset > 0)
        m_nCurPage --;

    if (m_nCurPage < 0)
        m_nCurPage = 0;
    else if (m_nCurPage > m_nPageCount - 1)
        m_nCurPage = m_nPageCount - 1;
    
    Point adjustPoint = Point(-winSize.width * m_nCurPage , 0);
    getScrollView()->setContentOffsetInDuration(adjustPoint, 0.2f);
    
    log("current page index: %d", m_nCurPage);
}

Layer* LevelView::getContainLayer(){
    // 48 个关卡
    int levelCount = 48;
    int widthCount = 4;
    int heightCount = 4;
    m_nPageCount = (levelCount - 1) / (widthCount * heightCount) + 1;
    
    log("关卡数：%d, 页数：%d", levelCount, m_nPageCount);
    
//    Size winSize = CCDirector::getInstance()->getWinSize();
//    Point pointCenter = Point(winSize.width / 2, winSize.height / 2);
    
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();
	Point pointCenter = Point(visibleSize.width / 2, visibleSize.height / 2);

	
    Layer* layer = Layer::create();
    layer->setPosition(Point::ZERO);
    
    // 添加 frame
	Point p = Point(0,0);
	Size z = Size(0, 0);
    for (int i = 0; i < m_nPageCount; i++) {
        Sprite* frame = Sprite::create("level/frame.png");
        frame->setPosition(pointCenter + Point(visibleSize.width * i, 0));
        layer->addChild(frame, 0, 0);
		if ( i == 0 ) {
			p.x = frame->getPosition().x;
			p.y = frame->getPosition().y;
			
			z.width = frame->getContentSize().width;
			z.height = frame->getContentSize().height;
		}
    }
    
    // 添加关卡项
    for (int i = 0; i < levelCount; i ++) {
        Node* level = getSpriteByLevel(i);
        // 设置位置
        int curPageIndex = i / (widthCount * heightCount);
        float xOffset = i % 4 * 100 + 165;
        float yOffset = p.y + z.height/2 - 80  - ((i % (widthCount * heightCount)) / widthCount * 120 );
        
        level->setPosition(Point(xOffset + visibleSize.width * curPageIndex, yOffset));
        layer->addChild(level ,2, i);
    }
    
    layer->setContentSize(Size(visibleSize.width * m_nPageCount, visibleSize.height));

    return layer;
}

Node* LevelView::getSpriteByLevel(int level){

    Sprite* sprite = CCSprite::create("level/level.png");
    // 添加关卡标示
    String* str = String::createWithFormat("%d", level + 1);
    LabelBMFont* label = LabelBMFont::create(str->getCString(),"level/prim30.fnt");
    label->setPosition(Point(40, 45));
    sprite->addChild(label);
    // 这里可以再为 关卡精灵做些装饰，就像 lable 一样
    
    // 触摸处理
    LsTouch* touch = LsTouch::create();
    touch->setDisplay(sprite);
    this->addLsTouch(touch, level);
    
    return touch;
}


void LevelView::setCurPageBall()
{
	Size size = Director::getInstance()->getVisibleSize();
    const int tagNodeBall = 1002;
	float fs = 0.2f;
	float scale = 0.7f;
	// 根据分屏数量显示小圆球标示
	Node* layer = this->getChildByTag(tagNodeBall);
	if (layer)
	{
		Layer* lyBall = dynamic_cast<Layer*>(layer);
		for (int i = 0; i < m_nPageCount; i++)
		{
			Node* n = lyBall->getChildByTag(i);
			if (n)
			{
				Sprite* sprite = dynamic_cast<Sprite*>(n);
				if (m_nCurPage == i)
				{
					sprite->runAction(
                                      CCScaleTo::create(fs,
                                                        1.0f));
				}
				else
				{
					sprite->runAction(
                                      CCScaleTo::create(0.5,
                                                        scale));
				}
			}
		}
	}
	else
	{
		Layer* lyBall = Layer::create();
		this->addChild(lyBall, 0, tagNodeBall);
        
		int ball_width = 30;			// 圆球间距
		for (int i = 0; i < m_nPageCount; i++)
		{
			Sprite* sprite = Sprite::create("level/ball.png");
			sprite->setPosition(Point(ball_width / 2 + (i - 1) * ball_width, ball_width / 2));
			sprite->setScale(scale);
			lyBall->addChild(sprite, 0, i);
			if (i == m_nCurPage)
			{
				sprite->runAction(CCScaleTo::create(fs, 1.0f));
			}
		}
		lyBall->setPosition(
                            size.width / 2 - ball_width * (m_nPageCount - 1) / 2,
                            size.height / 2 + 516 / 2 + 5);
	}
}

void LevelView::menuBackCallback(Object* pSender){
	
	playEffectBtnClicked();
	Scene* s = StartScene::createScene();
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, s));
}
