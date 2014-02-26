//
//  UserInfoMgr.h
//  crazyvideo
//
//  Created by zhangzhihh123 on 14-2-24.
//
//

#ifndef __crazyvideo__UserInfoMgr__
#define __crazyvideo__UserInfoMgr__

class UserInfoMgr {
	
public:
	
	UserInfoMgr();
	~UserInfoMgr();
	static UserInfoMgr* getInstance();
	
	void setGold(int nGold);
	void setFreedomLevel(int nLevel);
	
	int getGold();
	int getFreedomLevel();
	
	void answerRight();
	void answerWrong();
	void shareToFrientsSuccess();
	void shareToQZoneSuccess();
	
	bool canUseBomb();
	bool canAnswerQuestion();
	
private:
	void addGold( int nGold);
};


#endif /* defined(__crazyvideo__UserInfoMgr__) */
