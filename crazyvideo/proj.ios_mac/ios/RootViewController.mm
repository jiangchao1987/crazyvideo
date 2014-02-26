#import "RootViewController.h"
#import "cocos2d.h"
#import "EAGLView.h"

@implementation RootViewController


 // The designated initializer.  Override if you create the controller programmatically and want to perform customization that is not appropriate for viewDidLoad.
- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    if ((self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil])) {
        // Custom initialization
	
		
    }
    return self;
}



// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView {
//	_dmAdView.delegate = self;
//	_dmAdView.rootViewController = self;
//	[self.view addSubview:_dmAdView];
//	[_dmAdView loadAd];
}



// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad {
    [super viewDidLoad];
//	
//	_dmAdView.delegate = self;
//	_dmAdView.rootViewController = self;
//	[self.view addSubview:_dmAdView];
//	[_dmAdView loadAd];

}

- (void)viewDidUnload{
	[super viewDidUnload];
//	[_dmAdView removeFromSuperview];
	
}

- (void)dealloc {
	
//	_dmAdView.delegate = nil;
//	_dmAdView.rootViewController = nil;
//	[_dmAdView release];
    [super dealloc];
}
 

// Override to allow orientations other than the default portrait orientation.
// This method is deprecated on ios6
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    return UIInterfaceOrientationIsLandscape( interfaceOrientation );
}

// For ios6, use supportedInterfaceOrientations & shouldAutorotate instead
- (NSUInteger) supportedInterfaceOrientations{
#ifdef __IPHONE_6_0
    return UIInterfaceOrientationMaskAllButUpsideDown;
#endif
}

- (BOOL) shouldAutorotate {
    return YES;
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation {
	[super didRotateFromInterfaceOrientation:fromInterfaceOrientation];

	CGSize s = CGSizeMake([[CCEAGLView sharedEGLView] getWidth], [[CCEAGLView sharedEGLView] getHeight]);

	cocos2d::Application::getInstance()->applicationScreenSizeChanged((int) s.width, (int) s.height);
}

//fix not hide status on ios7
- (BOOL)prefersStatusBarHidden
{
    return YES;
}

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}


- (void)showBannerAdd:(BOOL) bShow{
//	_dmAdView.hidden = bShow;
}
- (void)showLeftAdL:(BOOL) bShow{
	
}
- (void)showRightAd:(BOOL) bShow{
	
}



//#pragma mark --
//#pragma mark -- DMAdViewDelegate <NSObject>
//// Sent when an ad request success to loaded an ad
//- (void)dmAdViewSuccessToLoadAd:(DMAdView *)adView{
//	NSLog(@"%@",__FUNCTION__);
//}
//// Sent when an ad request fail to loaded an ad
//- (void)dmAdViewFailToLoadAd:(DMAdView *)adView withError:(NSError *)error{
//	NSLog(@"%s",__FUNCTION__);
//
//}
//// Sent when the ad view is clicked
//- (void)dmAdViewDidClicked:(DMAdView *)adView{
//	NSLog(@"%s",__FUNCTION__);
//
//}
//// Sent just before presenting the user a modal view
//- (void)dmWillPresentModalViewFromAd:(DMAdView *)adView{
//	NSLog(@"%s",__FUNCTION__);
//
//}
//// Sent just after dismissing the modal view
//- (void)dmDidDismissModalViewFromAd:(DMAdView *)adView{
//	NSLog(@"%s",__FUNCTION__);
//
//}
//// Sent just before the application will background or terminate because the user's action
//// (Such as the user clicked on an ad that will launch App Store).
//- (void)dmApplicationWillEnterBackgroundFromAd:(DMAdView *)adView{
//	NSLog(@"%s",__FUNCTION__);
//
//}
@end
