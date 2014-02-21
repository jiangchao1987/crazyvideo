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
using namespace rapidjson;

DataMgr* DataMgr::instance = NULL;

DataMgr::DataMgr():currnetIndex(0), dataArr(NULL){
	
	dataArr = CCArray::create();
	dataArr->retain();

	this->loadData();
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

bool DataMgr::loadUserData(){
	
	{
//		currnetIndex = UserInfoMgr::getInstance()->getFreedomLevel();
		//		score = UserInfoMgr::getInstance()->getGold();
		return true;
	}
	
	return false;
}

CCDictionary* DataMgr::getCurrentQuestion(){
	
	if ( 0 <= currnetIndex && currnetIndex < dataArr->count() ) {
		CCDictionary* dic = (CCDictionary*)dataArr->objectAtIndex(currnetIndex);
//		currentAnswer = (CCString*)dic->objectForKey("answer");
//		currentAnswerStr = (CCString*)dic->objectForKey(currentAnswer->getCString());
//		currentQuestionStr = (CCString*)dic->objectForKey("question");
		currnetIndex ++;
	//	bIsShowRightAnswer = false;
		
	//	UserInfoMgr::getInstance()->setFreedomLevel(currnetIndex);
		
		return dic;
	}else if( currnetIndex == dataArr->count() ){
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
	return currnetIndex;
}
