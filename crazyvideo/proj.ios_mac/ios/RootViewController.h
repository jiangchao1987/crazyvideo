#import <UIKit/UIKit.h>
#import <MessageUI/MFMailComposeViewController.h>

@interface RootViewController : UIViewController<MFMailComposeViewControllerDelegate>{
//	DMAdView* _dmAdView;
}
- (BOOL) prefersStatusBarHidden;


- (void)sendMailInApp;
- (void)displayMailPicker;
- (void)alertWithMessage:(NSString*) msg;
@end
