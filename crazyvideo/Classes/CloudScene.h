#ifndef __CloudScene_H__
#define __CloudScene_H__

#include "cocos2d.h"
#include "TiledFourCell.h"
USING_NS_CC;

class CloudScene : public LayerColor {
public:
    static Scene* scene();
    virtual bool init();

    CREATE_FUNC(CloudScene);

//    virtual void ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent );
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);

private:
    TMXTiledMap* map;

    /* ����ά����ת��Ϊ��Ƭ�������� */
    Point getMapTiledPos( TMXTiledMap* map, Point pos );

	Dictionary* tiledCellsDict; // ��Ƭ�������Ƭ������� ��ֵ��
	Array* gidsArray; // ��ƬͼƬgid����Ƭ������ֵ�ܺͶ�Ӧ

    /* ���õ�ǰ��Ƭ������ֵ���Լ������԰���Ƭ������ֵ */
    void changeCloudTiled4( TMXLayer* layer, Point pos );
    void changeCloudTiled8( TMXLayer* layer, Point pos );
    void changeCloudTiled1( TMXLayer* layer, Point pos );
    void changeCloudTiled2( TMXLayer* layer, Point pos );

    /* ��ȡĳ����Ƭ���ӵĶ������ */
    TiledFourCell* getCellByTiledPos( Point pos );

    /* ������Ƭ�����ĸ�������ܺͣ�������Ƭ����ͼ�� */
    void setGidByTotalNum( TMXLayer* layer, Point pos, int iTotalNum );
};

#endif