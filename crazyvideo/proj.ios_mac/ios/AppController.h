#import <UIKit/UIKit.h>
#import "CCVideoPlayer.h"
#import "WXApi.h"
@class RootViewController;


@interface AppController : NSObject <UIApplicationDelegate,CCVideoPlayerDelegate, WXApiDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
}
- (CGSize)getWinSize;
- (void) playNetVideo_IOS:(NSString*)url;
- (void) playLocalVideo_IOS:(NSString*)filename;

- (void) shareToFriends;
- (void) shareToFriend;
- (void) shareToQQ;
- (void) shareToQZone;
@end

