//
//  CrossPlatformHelper.cpp
//  knowledgegame
//
//  Created by 畅玩 on 13-10-14.
//
//

#include "CrossPlatformHelper.h"
#include "cocos2d.h"
#include "cocos-ext.h"
//#include "UserInfoMgr.h"

USING_NS_CC;
USING_NS_CC_EXT;

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include "JAVAHelper.h"
void wxHelp(){
	wxHelp_JAVA();
}
void wxSendHelpByFriend(){
	wxSendHelpByFriend_JAVA();
}
void wxSendToFriendCircle(){
	wxSendToFriendCircle_JAVA();
}
void buy(int goodIndex){
	buy_JAVA(goodIndex);
}

void choujiang(){
	
}

#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#import "IOSHelper.h"
void wxHelp(){
	wxHelp_IOS();
}
void wxSendHelpByFriend(){
	wxSendHelpByFriend_IOS();
}
void wxSendToFriendCircle(){
	wxSendToFriendCircle_IOS();
}

void buy(int goodIndex){
	// 0 - 4  金币 19000001
	// 5 - 10 智慧豆 19001001
//	if ( 0 < goodIndex && goodIndex < 5) {
//		
//		buy_IOS(  goodIndex);
//	}else if ( 5 <= goodIndex && goodIndex <9 ){
//		buy_IOS( goodIndex);
//	}else if ( goodIndex == 9 ){
//		buy_IOS( 1900100999 );
//	}
//	buy_IOS(goodIndex);
}

void buySuccess(int goodId){
	
	int zhihuidou = 0;
	int gold = 0;
	switch ( goodId ) {
		case 19000001:
			zhihuidou = 600;
			break;
		case 19000002:
			zhihuidou = 1800;
			break;
		case 19000003:
			zhihuidou = 3000;
			break;
		case 19000004:
			zhihuidou = 11800;
			break;
		case 19000005:
			zhihuidou = 19800;
			break;
		case 19001001:
			gold = 600;
			break;
		case 19001002:
			gold = 1800;
			break;
		case 19001003:
			gold = 3000;
			break;
		case 19001004:
			gold = 11800;
			break;
		case 1900100999:
			gold = 19800;
			break;

		default:
			break;
	}
	
//	GameDataMgr::getInstance()->getDetail_.set_coins( GameDataMgr::getInstance()->getDetail_.coins() + zhihuidou);
//	UserInfoMgr::getInstance()->addGold(gold);
	
	//reqGetDetail();
}


void choujiang(){
	choujiang_IOS();
}

std::string getUserUDID(){
	return getUserUDID_IOS();
}

long long getTimestamp(){
	return getTimestamp_IOS();
}

std::string getSign(){
	return getSign_IOS();
}

std::string getNickName(){
	return getNickName_IOS();
}


void playNetVideo(std::string url){
	return playNetVideo_IOS(url);
}
void playLocalVideo(std::string filename){
	return playLocalVideo_IOS(filename);
}

#endif


