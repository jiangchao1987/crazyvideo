#include "CloudScene.h"
#include "StringUtil.h"
#include "TiledFourCell.h"

CCScene* CloudScene::scene() {
    CCScene* scene = CCScene::create();
    CloudScene* layer = CloudScene::create();

    scene->addChild(layer);

    return scene;
}

bool CloudScene::init() {
	bool bRet = false;

    do {
        CC_BREAK_IF(! CCLayerColor::initWithColor(Color4B(255, 255, 255, 255)));

        map = CCTMXTiledMap::create("blackCloud.tmx");
        this->addChild(map, 1);
        this->setTouchEnabled(true);

	    gidsArray = CCArray::createWithCapacity(16);
	    tiledCellsDict = CCDictionary::create();
	    gidsArray->retain();
	    tiledCellsDict->retain();
 
	    /* ��Ƭ��ͼʹ��4X4��ͼƬ��ÿ��СͼƬ��Ӧ����ֵ���£�
	    0 4 8 12
	    1 5 9 13
	    2 6 10 14
	    3 7 11 15
 
	    ������ֵΪ��Ƭ���ӵ�����ֵ��
 
	    ��Ƭͼ�ش�1��ʼ���������£�
	    1 2 3 4
	    5 6 7 8
	    9 10 11 12
	    13 14 15 16
	    ��������ֵ4����Ӧ����Ƭͼ����2������ֵ10����Ӧ����Ƭͼ����11��
	    */
 
	    /* ������ֵΪ����������ȡ����Ƭͼ�� */
	    gidsArray->addObject(CCInteger::create(1));//�����ܺ�0����Ӧͼ��IDΪ1
	    gidsArray->addObject(CCInteger::create(5));// �����ܺ�1����Ӧͼ��IDΪ5
	    gidsArray->addObject(CCInteger::create(9));// �����ܺ�2����Ӧͼ��IDΪ9
	    gidsArray->addObject(CCInteger::create(13));// �����ܺ�3����Ӧͼ��IDΪ13
	    gidsArray->addObject(CCInteger::create(2));// �����ܺ�4����Ӧͼ��IDΪ2
	    gidsArray->addObject(CCInteger::create(6));// �����ܺ�5����Ӧͼ��IDΪ6
	    gidsArray->addObject(CCInteger::create(10));
	    gidsArray->addObject(CCInteger::create(14));
	    gidsArray->addObject(CCInteger::create(3));
	    gidsArray->addObject(CCInteger::create(7));
	    gidsArray->addObject(CCInteger::create(11));
	    gidsArray->addObject(CCInteger::create(15));
	    gidsArray->addObject(CCInteger::create(4));
	    gidsArray->addObject(CCInteger::create(8));
	    gidsArray->addObject(CCInteger::create(12));
	    gidsArray->addObject(CCInteger::create(16));

        bRet = true;
    } while (0);

    return bRet;
}

bool CloudScene::onTouchBegan(Touch *touch, Event *unused_event){
	
//	CCTouch* touch = (CCTouch*)pTouches->anyObject();
    CCPoint pos = CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
	
    CCPoint tiledMapPos = getMapTiledPos(map, pos);
	
    CCLOG("mapPos x = %f, y = %f", tiledMapPos.x, tiledMapPos.y);
	
	CCTMXLayer* cloudLayer = map->layerNamed("cloudLayer");
	
	/* ���õ�ǰ��Ƭ������ֵ���Լ������԰���Ƭ������ֵ */
	changeCloudTiled4(cloudLayer, tiledMapPos);
	changeCloudTiled8(cloudLayer, ccp(tiledMapPos.x + 1, tiledMapPos.y));
	changeCloudTiled1(cloudLayer, ccp(tiledMapPos.x, tiledMapPos.y + 1));
	changeCloudTiled2(cloudLayer, ccp(tiledMapPos.x + 1, tiledMapPos.y + 1));

	return true;
}
//void CloudScene::ccTouchesBegan( CCSet *pTouches, CCEvent *pEvent ) {
//    CCTouch* touch = (CCTouch*)pTouches->anyObject();
//    CCPoint pos = CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
//
//    CCPoint tiledMapPos = getMapTiledPos(map, pos);
//
//    CCLOG("mapPos x = %f, y = %f", tiledMapPos.x, tiledMapPos.y);
//
//	CCTMXLayer* cloudLayer = map->layerNamed("cloudLayer");
//
//	/* ���õ�ǰ��Ƭ������ֵ���Լ������԰���Ƭ������ֵ */
//	changeCloudTiled4(cloudLayer, tiledMapPos);
//	changeCloudTiled8(cloudLayer, ccp(tiledMapPos.x + 1, tiledMapPos.y));
//	changeCloudTiled1(cloudLayer, ccp(tiledMapPos.x, tiledMapPos.y + 1));
//	changeCloudTiled2(cloudLayer, ccp(tiledMapPos.x + 1, tiledMapPos.y + 1));
//
//}

cocos2d::CCPoint CloudScene::getMapTiledPos( CCTMXTiledMap* map, CCPoint pos ) {
	CCSize mapSize = map->getMapSize();
	CCSize tiledSize = map->getTileSize();

	int iMapHeight = mapSize.height * tiledSize.height;

	/* posΪ�ѿ�������ϵ�����꣬����y����Ҫ���� */
	int x = pos.x / tiledSize.width;
	int y = (iMapHeight - pos.y) / tiledSize.height;

	return CCPointMake(x, y);
}


void CloudScene::setGidByTotalNum( CCTMXLayer* layer, CCPoint pos, int iTotalNum ) {
    CCSize mapSize = map->getMapSize();

    /* ���ⳬ����Χ */
    if(pos.x < 0 || pos. y < 0
        || pos.x >= mapSize.width || pos.y >= mapSize.height) {

            return;
    }

    /* iTotalNum����Ƭ��4����������ֵ���ܺͣ�ͨ�����ֵ��ö�Ӧ����Ƭͼ�� */
    CCInteger* gidInt = (CCInteger*)gidsArray->objectAtIndex(iTotalNum);

    /* ���µ���Ƭͼ���滻pos�����ϵ���Ƭͼ�� */
    layer->setTileGID(gidInt->getValue(), pos);
}

void CloudScene::changeCloudTiled4( CCTMXLayer* layer, CCPoint pos ) {

	TiledFourCell* cell = getCellByTiledPos(pos);

	/* ��ֵ4������Ƭ���½� */
	cell->setiRightBottom(4);

	/* ������Ƭ4������֮�����õ�ͼ��Ƭ��ͼƬ */
	setGidByTotalNum(layer, pos, cell->getiTotalNum());

}

TiledFourCell* CloudScene::getCellByTiledPos( CCPoint pos ) {
	CCSize mapSize = map->getMapSize();

	/* ��Ƭ����ԭ���Ƕ�ά���꣬ת��Ϊһά��ֵ */
	int index = mapSize.width * pos.x + pos.y;

	/* ȡ����Ƭ�Ķ������ݶ��� */
	const char* keyCh = CCString::createWithFormat("%d", index)->getCString();

	CCObject* obj = tiledCellsDict->objectForKey(keyCh);
	TiledFourCell* cell = NULL;
	if(obj == NULL) {
		/* �������Ƭû�ж������ݶ����򴴽�һ������������ֵĬ�϶�Ϊ0 */
		cell = TiledFourCell::create();
		tiledCellsDict->setObject(cell, keyCh);
	}
	else {
		cell = (TiledFourCell*)obj;
	}
	return cell;
}

void CloudScene::changeCloudTiled8( CCTMXLayer* layer, CCPoint pos ) {
	TiledFourCell* cell = getCellByTiledPos(pos);

	/* ��ֵ8������Ƭ���½� */
	cell->setiLeftBottom(8);

	/* ������Ƭ4������֮�����õ�ͼ��Ƭ��ͼƬ */
	setGidByTotalNum(layer, pos, cell->getiTotalNum());

}

void CloudScene::changeCloudTiled1( CCTMXLayer* layer, CCPoint pos ) {
	TiledFourCell* cell = getCellByTiledPos(pos);

	/* ��ֵ1������Ƭ���Ͻ� */
	cell->setiRightTop(1);

	/* ������Ƭ4������֮�����õ�ͼ��Ƭ��ͼƬ */
	setGidByTotalNum(layer, pos, cell->getiTotalNum());
}

void CloudScene::changeCloudTiled2( CCTMXLayer* layer, CCPoint pos ) {
	TiledFourCell* cell = getCellByTiledPos(pos);

	/* ��ֵ2������Ƭ���Ͻ� */
	cell->setiLeftTop(2);

	/* ������Ƭ4������֮�����õ�ͼ��Ƭ��ͼƬ */
	setGidByTotalNum(layer, pos, cell->getiTotalNum());
}