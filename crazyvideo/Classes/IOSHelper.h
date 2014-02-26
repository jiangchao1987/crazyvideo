//
//  IOSHelper.h
//  knowledgegame
//
//  Created by 畅玩 on 13-9-13.
//
//

#include <string>
void wxHelp_IOS();
void wxSendHelpByFriend_IOS();
void wxSendToFriendCircle_IOS();
//void buy_IOS(int goodId);
void buySuccess_IOS(int goodId);
void choujiang_IOS();


std::string getUserUDID_IOS();
long long getTimestamp_IOS();
std::string getSign_IOS();
std::string getNickName_IOS();

void playNetVideo_IOS(std::string url);
void playLocalVideo_IOS(std::string filename);

void shareToFriends_IOS();
void shareToFriend_IOS();
void shareToQQ_IOS();
void shareToQZone_IOS();

void showOffWall_IOS();
void showLevelAdBanner_IOS( bool bShow);
void showLevelLeftAd_IOS();
void showLevelRightAd_IOS();
