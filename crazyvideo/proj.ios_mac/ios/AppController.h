#import <UIKit/UIKit.h>
#import "CCVideoPlayer.h"

@class RootViewController;


@interface AppController : NSObject <UIApplicationDelegate,CCVideoPlayerDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
}
- (CGSize)getWinSize;

- (void) playNetVideo_IOS:(NSString*)url;//(std::string url);
- (void) playLocalVideo_IOS:(NSString*)filename;//(std::string filename);
@end

