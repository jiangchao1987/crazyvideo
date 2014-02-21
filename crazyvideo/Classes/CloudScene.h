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

    /* 将二维坐标转换为瓦片格子坐标 */
    Point getMapTiledPos( TMXTiledMap* map, Point pos );

	Dictionary* tiledCellsDict; // 瓦片坐标和瓦片顶点对象 键值对
	Array* gidsArray; // 瓦片图片gid与瓦片顶点数值总和对应

    /* 设置当前瓦片的数据值，以及设置旁白瓦片的数据值 */
    void changeCloudTiled4( TMXLayer* layer, Point pos );
    void changeCloudTiled8( TMXLayer* layer, Point pos );
    void changeCloudTiled1( TMXLayer* layer, Point pos );
    void changeCloudTiled2( TMXLayer* layer, Point pos );

    /* 获取某个瓦片格子的顶点对象 */
    TiledFourCell* getCellByTiledPos( Point pos );

    /* 根据瓦片格子四个顶点的总和，设置瓦片格子图素 */
    void setGidByTotalNum( TMXLayer* layer, Point pos, int iTotalNum );
};

#endif