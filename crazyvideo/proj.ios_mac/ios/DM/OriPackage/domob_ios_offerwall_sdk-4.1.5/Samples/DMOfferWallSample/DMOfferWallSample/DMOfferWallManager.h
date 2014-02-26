//
//  DMOfferWallManager.h
//  DomobOfferWallSDK
//
//  Created by wangxijin on 13-11-22.
//  Copyright (c) 2013年 domob. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DMOfferWallManagerDelegate.h"

@interface DMOfferWallManager : NSObject {
    
    id<DMOfferWallManagerDelegate> _delegate;
}

@property(nonatomic,assign)id<DMOfferWallManagerDelegate> delegate;

- (id)initWithPublishId:(NSString *)publishId;

- (id)initWithPublishId:(NSString *)publishId userId:(NSString *)userId;

- (void)requestOnlineConsumeWithPoint:(NSUInteger)pointToConsume;

- (void)requestOnlinePointCheck;

- (void)checkOfferWallEnableState;

@end