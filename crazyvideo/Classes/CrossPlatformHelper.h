//
//  CrossPlatformHelper.h
//  knowledgegame
//
//  Created by 畅玩 on 13-10-14.
//
//

#ifndef __knowledgegame__CrossPlatformHelper__
#define __knowledgegame__CrossPlatformHelper__

#include <iostream>

void wxHelp();
void wxSendHelpByFriend();
void wxSendToFriendCircle();

void buy(int goodIndex);

void buySuccess(int goodId);

void choujiang();

std::string getUserUDID();
long long getTimestamp();
std::string getSign();
std::string getNickName();

#pragma mark --
#pragma mark -- Up Functions is Dirty

void playNetVideo(std::string url);
void playLocalVideo(std::string filename);

void X_shareToFriends();
void X_shareToFriend();
void X_shareToQQ();
void X_shareToQZone();

#endif /* defined(__knowledgegame__CrossPlatformHelper__) */
