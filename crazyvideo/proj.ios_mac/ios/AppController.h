#import <UIKit/UIKit.h>
#import "CCVideoPlayer.h"
#import "WXApi.h"
#import "DMAdView.h"

@class RootViewController;


@interface AppController : NSObject <UIApplicationDelegate,CCVideoPlayerDelegate, WXApiDelegate, DMAdViewDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
	
	DMAdView* _dmAdView;

}
- (CGSize)getWinSize;
- (void) playNetVideo_IOS:(NSString*)url;
- (void) playLocalVideo_IOS:(NSString*)filename;

- (void) AppShareToFriends;
- (void) AppShareToFriend;
- (void) AppShareToQQ;
- (void) AppShareToQZone;

- (void)showBannerAdd:(BOOL) bShow;
- (void)showLeftAd:(BOOL) bShow;
- (void)showRightAd:(BOOL) bShow;

@end

