//
//  DataMgr.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-19.
//
//

#ifndef __crazyvideo__DataMgr__
#define __crazyvideo__DataMgr__

#include <iostream>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class DataMgr {
	
private:
	// user data
	int   currnetIndex;
	// data;
	Array*   dataArr;
public:
	
	DataMgr();
	~DataMgr();
	static DataMgr* getInstance();
private:
	static DataMgr* instance;
	
private:
	bool loadData();
	bool loadUserData();
	
public:
	CCDictionary* getCurrentQuestion();
	
	int getCurrentQuestionIndex();
	void answerRight();
	
};

#endif /* defined(__crazyvideo__DataMgr__) */
