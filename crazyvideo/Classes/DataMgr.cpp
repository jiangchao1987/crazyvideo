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

//	this->loadData();
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

bool DataMgr::loadData(){
	
//	std::string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename("jishijiangli.txt");
	
	auto File = cocos2d::FileUtils::getInstance();
	std::string sFullPath = File->fullPathForFilename("jishijiangli.txt");
    std::string  Beffer = File->getStringFromFile(sFullPath);

	
	rapidjson::Document d;
    d.Parse<0>(Beffer.c_str());
    if (d.HasParseError())  //解析错误
    {
        CCLOG("GetParseError %s\n",d.GetParseError());
    }
	
	else if (d.IsObject()&&d.HasMember("data"))//这个时候要保证d.IsObject类型
    {
        const rapidjson::Value &a=d["data"];  //读取中文的数组
        if (a.IsArray())  //判断是不是数组
        {
            for(int i=0;i<a.Size();++i) //如果不是数组，这一行会报错
            {
				CCDictionary* dic = CCDictionary::create();
				
                const rapidjson::Value &val = a[i]; //得到单个对象
                if(val.HasMember(Key_topic_title)) //判断这个对象有没有id键
                {
					log(Key_topic_title);
					log(val[Key_topic_title].GetString());
					dic->setObject(CCString::create(val[Key_topic_title].GetString()), Key_topic_title);
					
//                    const rapidjson::Value &val_id = val["ID"]; //获取ID
//                    int i_id = -1;
//                    if(val_id.IsInt()) //判断ID类型
//                    {
//                        i_id = val_id.GetInt();
//                        if(i_id == key) //如果ID与传入参数相同，则读取String键的内容
//                        {
//                            if(val.HasMember("String"))
//                                if(val["String"].IsString())
//                                    return val["String"].GetString();
//                        }
//                    }
                }
				if (val.HasMember( Key_m3u8_url) ) {
					log(Key_m3u8_url);
					log(val[Key_m3u8_url].GetString());
					dic->setObject(CCString::create(val[Key_m3u8_url].GetString()), Key_m3u8_url);

				}
				if (val.HasMember(Key_option1) ) {
					log(Key_option1);
					log(val[Key_option1].GetString());
					dic->setObject(CCString::create(val[Key_option1].GetString()), Key_option1);

				}
				if (val.HasMember(Key_option2) ) {
					log(Key_option2);
					log(val[Key_option2].GetString());
					dic->setObject(CCString::create(val[Key_option2].GetString()), Key_option2);

				}
				if (val.HasMember(Key_option3) ) {
					log(Key_option3);
					log(val[Key_option3].GetString());
					dic->setObject(CCString::create(val[Key_option3].GetString()), Key_option3);

				}
				if (val.HasMember(Key_option4) ) {
					log(Key_option4);
					log(val[Key_option4].GetString());
					dic->setObject(CCString::create(val[Key_option4].GetString()), Key_option4);

				}
				if (val.HasMember(Key_remark) ) {
					log(Key_remark);
					log(val[Key_remark].GetString());
					dic->setObject(CCString::create(val[Key_remark].GetString()), Key_remark);

				}
				//local_resource
				if (val.HasMember(Key_local_resource) ) {
					log(Key_local_resource);
					log(val[Key_local_resource].GetString());
					dic->setObject(CCString::create(val[Key_local_resource].GetString()), Key_local_resource);

				}
				if (val.HasMember(Key_question) ) {
					log(Key_question);
					log(val[Key_question].GetString());
					dic->setObject(CCString::create(val[Key_question].GetString()), Key_question);

				}
				//detail_url
				if (val.HasMember(Key_detail_url) ) {
					log(Key_detail_url);
					log(val[Key_detail_url].GetString());
					dic->setObject(CCString::create(val[Key_detail_url].GetString()), Key_detail_url);

				}
				//resource_name
				if (val.HasMember(Key_resource_name) ) {
					log(Key_resource_name);
					log(val[Key_resource_name].GetString());
					dic->setObject(CCString::create(val[Key_resource_name].GetString()), Key_resource_name);

				}
				//guanka_index
				if (val.HasMember(Key_guanka_index) ) {
					log(Key_guanka_index);
					log("%d",val[Key_guanka_index].GetInt());
					dic->setObject(CCString::createWithFormat("%d", val[Key_guanka_index].GetInt()), Key_guanka_index);

				}
				
				//temp answer
				int a = 1 + arc4random()%4;
				CCString* astr = CCString::createWithFormat("%d", a);
				dic->setObject(astr, Key_answer_index);
				
				
				dataArr->addObject(dic);
            }
        }
    }
	
//	dataArr = cocos2d::CCArray::createWithContentsOfFileThreadSafe(fullpath.c_str());
	
//	Array::createWithContentsOfFile(;)
	
	if ( dataArr != NULL && dataArr->count() > 0 ) {

		return true;
	}
	
	return false;
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
		dic->setObject(dicArr->getObjectAtIndex(8), Key_option1);
		dic->setObject(dicArr->getObjectAtIndex(9), Key_option2);
		dic->setObject(dicArr->getObjectAtIndex(10), Key_option3);
		dic->setObject(dicArr->getObjectAtIndex(11), Key_option4);
		
		int a = 1 + arc4random()%4;
		CCString* astr = CCString::createWithFormat("%d", a);
		dic->setObject(astr, Key_answer_index);
		//astr->
		dataArr->addObject(dic);
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
