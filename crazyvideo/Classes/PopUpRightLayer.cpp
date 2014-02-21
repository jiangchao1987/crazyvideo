//
//  PopUpRightLayer.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-20.
//
//

#include "PopUpRightLayer.h"
PopUpShareLayer::PopUpShareLayer():
m__pMenu(NULL)
, m_contentPadding(0)
, m_contentPaddingTop(0)
, m_callbackListener(NULL)
, m_callback(NULL)
, m__sfBackGround(NULL)
, m__s9BackGround(NULL)
, m__ltContentText(NULL)
, m__ltTitle(NULL)
{
    
}

PopUpShareLayer::~PopUpShareLayer(){
    CC_SAFE_RELEASE(m__pMenu);
    CC_SAFE_RELEASE(m__sfBackGround);
    CC_SAFE_RELEASE(m__ltContentText);
    CC_SAFE_RELEASE(m__ltTitle);
    CC_SAFE_RELEASE(m__s9BackGround);
}

bool PopUpShareLayer::init(){
    bool bRef = false;
    do{
        CC_BREAK_IF(!CCLayer::init());
        this->setContentSize(Size::ZERO);
        
        // 初始化需要的 Menu
        Menu* menu = Menu::create();
        menu->setPosition(Point::ZERO);
        setMenuButton(menu);
        
        setTouchEnabled(true);
        
		auto myListener = EventListenerTouchOneByOne::create();
		myListener->onTouchBegan = CC_CALLBACK_2(PopUpShareLayer::onTouchBegan, this);
		myListener->onTouchMoved = CC_CALLBACK_2(PopUpShareLayer::onTouchMoved, this);
		myListener->onTouchEnded = CC_CALLBACK_2(PopUpShareLayer::onTouchEnded, this);
		
		myListener->setSwallowTouches(true);
		auto dispatcher = Director::getInstance()->getEventDispatcher();
		dispatcher->addEventListenerWithSceneGraphPriority(myListener, this);
		
		
        bRef = true;
    }while(0);
    return bRef;
}

//void PopupLayer::registerWithTouchDispatcher(){
//    // 这里的触摸优先级设置为 -128 这保证了，屏蔽下方的触摸
//    CCDirector::getInstance()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
//
//}
//
//bool PopupLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
//    //
//    CCLog("PopupLayer touch");
//    return true;
//}
bool PopUpShareLayer::onTouchBegan(Touch *touch, Event *unused_event){
	log("PopupLayer touch");
	return true;
}

void PopUpShareLayer::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}
void PopUpShareLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}
void PopUpShareLayer::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event){
	
}



PopUpShareLayer* PopUpShareLayer::create(const char *backgroundImage){
    PopUpShareLayer* ml = PopUpShareLayer::create();
    ml->setSpriteBackGround(CCSprite::create(backgroundImage));
    ml->setSprite9BackGround(Scale9Sprite::create(backgroundImage));
    return ml;
}

void PopUpShareLayer::setTitle(const char *title, int fontsize){
    LabelTTF* ltfTitle = LabelTTF::create(title, "", fontsize);
    setLabelTitle(ltfTitle);
}

void PopUpShareLayer::setContentText(const char *text, int fontsize, int padding, int paddingTop){
    CCLabelTTF* ltf = CCLabelTTF::create(text, "", fontsize);
    setLabelContentText(ltf);
    m_contentPadding = padding;
    m_contentPaddingTop = paddingTop;
}

void PopUpShareLayer::setCallbackFunc(cocos2d::CCObject *target, SEL_CallFuncN callfun){
    m_callbackListener = target;
    m_callback = callfun;
}


bool PopUpShareLayer::addButton(const char *normalImage, const char *selectedImage, const char *title, int tag){
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCPoint pCenter = ccp(winSize.width / 2, winSize.height / 2);
    
    // 创建图片菜单按钮
    MenuItemImage* menuImage = MenuItemImage::create(normalImage, selectedImage, this, menu_selector(PopUpShareLayer::buttonCallback));
    menuImage->setTag(tag);
    menuImage->setPosition(pCenter);
    
    // 添加文字说明并设置位置
    Size imenu = menuImage->getContentSize();
    LabelTTF* ttf = LabelTTF::create(title, "", 20);
    ttf->setColor(ccc3(0, 0, 0));
    ttf->setPosition(ccp(imenu.width / 2, imenu.height / 2));
    menuImage->addChild(ttf);
    
    getMenuButton()->addChild(menuImage);
    return true;
}

void PopUpShareLayer::buttonCallback(cocos2d::Object *pSender){
    Node* node = dynamic_cast<CCNode*>(pSender);
    log("touch tag: %d", node->getTag());
    if (m_callback && m_callbackListener){
        (m_callbackListener->*m_callback)(node);
    }
    this->removeFromParent();
}

void PopUpShareLayer::onEnter(){
    Layer::onEnter();
    
    Size winSize = Director::getInstance()->getWinSize();
    Point pCenter = Point(winSize.width / 2, winSize.height / 2);
    
    Size contentSize;
    // 设定好参数，在运行时加载
    if (getContentSize().equals(Size::ZERO)) {
        getSpriteBackGround()->setPosition(Point(winSize.width / 2, winSize.height / 2));
        this->addChild(getSpriteBackGround(), 0, 0);
        contentSize = getSpriteBackGround()->getTexture()->getContentSize();
    } else {
        Scale9Sprite *background = getSprite9BackGround();
        background->setContentSize(getContentSize());
        background->setPosition(Point(winSize.width / 2, winSize.height / 2));
        this->addChild(background, 0, 0);
        contentSize = getContentSize();
    }
    
    // 添加按钮，并设置其位置
    this->addChild(getMenuButton());
    float btnWidth = contentSize.width / (getMenuButton()->getChildrenCount() + 1);
    
	//    Array* array = getMenuButton()->getChildren();
	Vector<Node*>& array = getMenuButton()->getChildren();
	
    Object* pObj = NULL;
    int i = 0;
	/*
	 vector<NODE>::iterator it;
	 
	 for (it=v.begin(); it!=v.end(); it++)
	 {
	 v[*it]->id=2;
	 
	 }
	 */
	Vector<Node*>::iterator it;
	
    for (it=array.begin() ; it!=array.end(); it++) {
        Node* node = *it;//dynamic_cast<Node*>(array[*it]);
        node->setPosition(Point( winSize.width / 2 - contentSize.width / 2 + btnWidth * (i + 1), winSize.height / 2 - contentSize.height / 3));
        i++;
    }
    
    
    // 显示对话框标题
    if (getLabelTitle()){
        getLabelTitle()->setPosition(pCenter + Point(0, contentSize.height / 2 - 35.0f));
        this->addChild(getLabelTitle());
    }
    
    // 显示文本内容
    if (getLabelContentText()){
        LabelTTF* ltf = getLabelContentText();
        ltf->setPosition(Point(winSize.width / 2, winSize.height / 2));
        ltf->setDimensions(Size(contentSize.width - m_contentPadding * 2, contentSize.height - m_contentPaddingTop));
        ltf->setHorizontalAlignment(kCCTextAlignmentLeft);
        this->addChild(ltf);
    }
	
    // 弹出效果
    Action* popupLayer = Sequence::create(CCScaleTo::create(0.0, 0.0),
										  CCScaleTo::create(0.06, 1.05),
										  CCScaleTo::create(0.08, 0.95),
										  CCScaleTo::create(0.08, 1.0), NULL);
    this->runAction(popupLayer);
	
}

void PopUpShareLayer::onExit(){
    
    CCLog("popup on exit.");
    CCLayer::onExit();
}