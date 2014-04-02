//
//  DataMgr.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-19.
//
//



#include "DataMgr.h"
#include "json/document.h"
#include "Defines.h"
#include "Tools.h"
#include "UserInfoMgr.h"
#include "StringUtil.h"
#include <ctime>
#include <cstdlib>

std::string& trim(std::string &s)
{
    if (s.empty())
    {
        return s;
    }
	
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}
using namespace rapidjson;

DataMgr* DataMgr::instance = NULL;

DataMgr::DataMgr(): dataArr(NULL){
	
	dataArr = CCArray::create();
	dataArr->retain();

	this->loadData1();
	this->loadUserData();
}

DataMgr::~DataMgr(){
	
	///	CC_SAFE_RELEASE(dataArr);
	//	CC_SAFE_RELEASE(currentAnswerStr);
	//	CC_SAFE_RELEASE(currentAnswer);
}

DataMgr* DataMgr::getInstance(){
	
	if ( instance  == NULL ) {
		instance = new DataMgr();
	}
	return instance;
}

bool DataMgr::loadData1(){
	auto File = cocos2d::FileUtils::getInstance();
	std::string sFullPath = File->fullPathForFilename("date.txt");
    std::string  Beffer = File->getStringFromFile(sFullPath);
	
	Array* totalArr = StringUtil::sharedStrUtil()->split(Beffer.c_str(), "\n");
	log( "count is:%d", totalArr->count());
	
	for(int i = 0; i< totalArr->count();i++){
		Array* dicArr = StringUtil::sharedStrUtil()->split( ((CCString*)totalArr->getObjectAtIndex(i))->_string.c_str(), ";");
		CCDictionary* dic = CCDictionary::create();
		/*
		 #define  Key_topic_title "topic_title"
		 #define  Key_resource_name  "resource_name"
		 #define  Key_m3u8_url "m3u8_url"
		 #define  Key_option2 "option2"
		 #define  Key_remark "remark"
		 #define  Key_option4 "option4"
		 #define  Key_detail_url "detail_url"
		 #define  Key_local_resource "local_resource"
		 #define  Key_option1 "option1"
		 #define  Key_guanka_index "guanka_index"
		 #define  Key_question "question"
		 #define  Key_option3 "option3"
		 #define  Key_createdAt "createdAt"
		 #define  Key_answer_index "Key_answer_index"
		 */
		
		log( "dic is:%d", dicArr->count());
		dic->setObject(dicArr->getObjectAtIndex(0), Key_guanka_index);
		dic->setObject(dicArr->getObjectAtIndex(1), Key_topic_title);
		dic->setObject(dicArr->getObjectAtIndex(2), Key_remark);
		dic->setObject(dicArr->getObjectAtIndex(3), Key_local_resource);
		dic->setObject(dicArr->getObjectAtIndex(4), Key_resource_name);
		dic->setObject(dicArr->getObjectAtIndex(5), Key_question);
		dic->setObject(dicArr->getObjectAtIndex(6), Key_m3u8_url);
		dic->setObject(dicArr->getObjectAtIndex(7), Key_detail_url);
		
		Array* answerArr = Array::create(dicArr->getObjectAtIndex(8),dicArr->getObjectAtIndex(9),dicArr->getObjectAtIndex(10),dicArr->getObjectAtIndex(11), NULL);
		
		srand((unsigned)time(0));
		int a = 1 + rand()%4;
		
//		answerArr->exchangeObjectAtIndex(0, 4-a+1);
		answerArr->exchangeObjectAtIndex(a-1, 0);
		//answerArr->exchangeObjectAtIndex(ssize_t index1, ;)
		
		CCString* astr = CCString::createWithFormat("%d", a);
		dic->setObject(astr, Key_answer_index);
		dataArr->addObject(dic);
				
		dic->setObject(answerArr->getObjectAtIndex(0), Key_option1);
		dic->setObject(answerArr->getObjectAtIndex(1), Key_option2);
		dic->setObject(answerArr->getObjectAtIndex(2), Key_option3);
		dic->setObject(answerArr->getObjectAtIndex(3), Key_option4);
		

	}
	
	if ( dataArr != NULL && dataArr->count() > 0 ) {
		
		return true;
	}
	
	return false;
}

bool DataMgr::loadUserData(){
	
	{
		return true;
	}
	
	return false;
}

CCDictionary* DataMgr::getCurrentQuestion(){
	
	if ( 0 <= UserInfoMgr::getInstance()->getFreedomLevel() && UserInfoMgr::getInstance()->getFreedomLevel() < dataArr->count() ) {
		CCDictionary* dic = (CCDictionary*)dataArr->objectAtIndex(UserInfoMgr::getInstance()->getFreedomLevel());

		return dic;
	}else if( UserInfoMgr::getInstance()->getFreedomLevel() == dataArr->count() ){
		assert( "ques finished!" );
	}
	assert("current index too big");
	return NULL;
}

//void DataMgr::reset(){
//	currnetIndex = 0;
//	UserInfoMgr::getInstance()->setFreedomLevel(currnetIndex);
//}
//bool DataMgr::isAllFinished(){
//	if ( currnetIndex >= dataArr->count() ) {
//		return true;
//	}
//	return false;
//}


//int DataMgr::getScore(){
//	return UserInfoMgr::getInstance()->getGold();
//}
int DataMgr::getCurrentQuestionIndex(){
	return UserInfoMgr::getInstance()->getFreedomLevel();
}

bool DataMgr::isBgSoundOpen(){
	return LoadBooleanFromXML( "isBgSoundOpen" );
}
void DataMgr::openBgSound(bool bOpen){
	SaveBooleanToXML("isBgSoundOpen", bOpen);
	WriteDisk;
}

