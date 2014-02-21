//
//  PopUpRightLayer.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-20.
//
//

#ifndef __crazyvideo__PopUpRightLayer__
#define __crazyvideo__PopUpRightLayer__

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class PopUpShareLayer: public Layer{
public:
    PopUpShareLayer();
    ~PopUpShareLayer();
    
    virtual bool init();
    CREATE_FUNC(PopUpShareLayer);
    
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event);
	
    static PopUpShareLayer* create(const char* backgroundImage);
    
    void setTitle(const char* title, int fontsize = 20);
    void setContentText(const char* text, int fontsize = 20, int padding = 50, int paddintTop = 100);
	
    void setCallbackFunc(CCObject* target, SEL_CallFuncN callfun);
    
    bool addButton(const char* normalImage, const char* selectedImage, const char* title, int tag = 0);
    virtual void onEnter();
    virtual void onExit();
    
private:
    
    void buttonCallback(CCObject* pSender);
	
    // 文字内容两边的空白区
    int m_contentPadding;
    int m_contentPaddingTop;
    
    Object* m_callbackListener;
    SEL_CallFuncN m_callback;
	
    CC_SYNTHESIZE_RETAIN(Menu*, m__pMenu, MenuButton);
    CC_SYNTHESIZE_RETAIN(Sprite*, m__sfBackGround, SpriteBackGround);
    CC_SYNTHESIZE_RETAIN(Scale9Sprite*,m__s9BackGround, Sprite9BackGround);
    CC_SYNTHESIZE_RETAIN(LabelTTF*, m__ltTitle, LabelTitle);
    CC_SYNTHESIZE_RETAIN(LabelTTF*, m__ltContentText, LabelContentText);
    
};
#endif /* defined(__crazyvideo__PopUpRightLayer__) */
