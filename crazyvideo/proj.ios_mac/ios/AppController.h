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

- (void) AppShareToFriends;
- (void) AppShareToFriend;
- (void) AppShareToQQ;
- (void) AppShareToQZone;
@end

