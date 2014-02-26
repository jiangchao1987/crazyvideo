//
//  UserInfoMgr.cpp
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-24.
//
//


#include "UserInfoMgr.h"
#include "Tools.h"
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

#define K_FIRESTLOAD "k_firstload"
#define K_USERGOLD  "k_gold"
#define K_USERDIAMOND "k_diamond"
#define K_FREEDOMLEVEL "k_freedomlevel"

static UserInfoMgr* instance = NULL;

UserInfoMgr* UserInfoMgr::getInstance(){
	
	if ( instance  == NULL ) {
		instance = new UserInfoMgr();
	}
	return instance;
}

UserInfoMgr::UserInfoMgr(){
	bool bFirstLoad = false;
	bFirstLoad = LoadBooleanFromXML(K_FIRESTLOAD);
	if ( !bFirstLoad ) {
		this->setGold(100);
		this->setFreedomLevel(0);
		
		SaveBooleanToXML(K_FIRESTLOAD, true);
		WriteDisk;
	}
	
	if( this->getGold() <=0 ){
		this->setGold(0);
	}
}

UserInfoMgr::~UserInfoMgr(){
	
}

void UserInfoMgr::setGold(int nGold){
	SaveIntegerToXML(K_USERGOLD, nGold);
	WriteDisk;
}

void UserInfoMgr::setFreedomLevel(int nLevel){
	SaveIntegerToXML(K_FREEDOMLEVEL, nLevel);
	WriteDisk;
}
int UserInfoMgr::getGold(){
	return LoadIntegerFromXML(K_USERGOLD);
}

int UserInfoMgr::getFreedomLevel(){
	return LoadIntegerFromXML(K_FREEDOMLEVEL);
}

void UserInfoMgr::addGold( int nGold){
	this->setGold( this->getGold() + nGold );
}

bool UserInfoMgr::buyGold(int nGold){
	this->addGold(nGold);
}

bool UserInfoMgr::exchangeGold(int nGold){
	this->addGold(nGold);
}
#pragma mark --
#pragma mark -- User Logic Functions
void UserInfoMgr::answerRight(){
	this->addGold( 20 );
}
void UserInfoMgr::answerWrong(){
	this->addGold( -20 );
}
void UserInfoMgr::shareToFrientsSuccess(){
	this->addGold( 40 );
}
void UserInfoMgr::shareToQZoneSuccess(){
	this->addGold( 40 );
}

bool UserInfoMgr::canUseBomb(){
	bool bRet = false;
	if ( this->getGold() >= 20 ){
		bRet = true;
	}
	
	return bRet;
}
bool UserInfoMgr::canAnswerQuestion(){
	bool bRet = false;
	if ( this->getGold() >= 20 ){
		bRet = true;
	}
	
	return bRet;
}