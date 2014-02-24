#import "AppController.h"
#import "EAGLView.h"
#import "cocos2d.h"
#import "AppDelegate.h"
#import "RootViewController.h"

using namespace cocos2d;
@implementation AppController

#pragma mark -
#pragma mark Application lifecycle

// cocos2d application instance
static AppDelegate s_sharedApplication;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {    
    
    // Override point for customization after application launch.

    // Add the view controller's view to the window and display.
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    
    // Init the CCEAGLView
    CCEAGLView *__glView = [CCEAGLView viewWithFrame: [window bounds]
                                     pixelFormat: kEAGLColorFormatRGB565
                                     depthFormat: GL_DEPTH24_STENCIL8_OES
                              preserveBackbuffer: NO
                                      sharegroup: nil
                                   multiSampling: NO
                                 numberOfSamples: 0];

    // Use RootViewController manage CCEAGLView 
    viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
    viewController.wantsFullScreenLayout = YES;
    viewController.view = __glView;

    // Set RootViewController to window
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        // warning: addSubView doesn't work on iOS6
        [window addSubview: viewController.view];
    }
    else
    {
        // use this method on ios6
        [window setRootViewController:viewController];
    }
    
    [window makeKeyAndVisible];
    
    [[UIApplication sharedApplication] setStatusBarHidden:true];
    
    cocos2d::Application::getInstance()->run();
	

	if ( [WXApi registerApp:@"wx31e942829d9eb144"] ) {
		CCLOG("register wx right");
	}else{
		CCLOG("register wx wrong");
	}
	
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
    cocos2d::Director::getInstance()->pause();
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
    cocos2d::Director::getInstance()->resume();
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
     If your application supports background execution, called instead of applicationWillTerminate: when the user quits.
     */
    cocos2d::Application::getInstance()->applicationDidEnterBackground();
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    /*
     Called as part of  transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
     */
    cocos2d::Application::getInstance()->applicationWillEnterForeground();
}

- (void)applicationWillTerminate:(UIApplication *)application {
    /*
     Called when the application is about to terminate.
     See also applicationDidEnterBackground:.
     */
}


#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
    /*
     Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
     */
}


- (void)dealloc {
    [window release];
    [super dealloc];
}

#pragma mark --
#pragma mark Fuck WinXin

- (BOOL)application:(UIApplication *)application handleOpenURL:(NSURL *)url{
	return [WXApi handleOpenURL:url delegate:self];
}

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation{
	return [WXApi handleOpenURL:url delegate:self];
}

#pragma mark --
#pragma mark -- Share Functions

- (void) AppShareToFriends{
	
	// 发送内容给微信
	WXMediaMessage *message = [WXMediaMessage message];
	message.title = @"江湖救急";
	message.description = @"偶的神啊！答不上来了，谁能告诉我正确答案啊！";
	[message setThumbImage:[[UIImage imageNamed:@"Default.png"] resizedImage:CGSizeMake(320, 480) interpolationQuality:kCGInterpolationNone]];
	
	WXImageObject *ext = [WXImageObject object];
//	ext.imageData = [[UIImage imageNamed:@"Default.png"] ]//data;
//	ext.imageData = [[UIImage imageNamed:@"Default.png"] ];
	
	UIImage* image = [UIImage imageNamed:@"Default.png"];
	NSData *imageData = UIImagePNGRepresentation(image);

	ext.imageData = imageData;
	message.mediaObject = ext;
	
	SendMessageToWXReq* req = [[[SendMessageToWXReq alloc] init]autorelease];
	req.bText = NO;
	req.message = message;
	
	/*
	 scene = WXSceneSession;
	 wxSendHelpByFriend();
	 break;
	 case 1:
	 scene = WXSceneTimeline;
	 */
	req.scene = WXSceneTimeline;
	
	BOOL isSuccess = [WXApi sendReq:req];
	if ( isSuccess ) {
		NSLog(@"sadfsa");
	}else {
		NSLog(@"fuckingi");
	}
}
- (void) AppShareToFriend{
	
}
- (void) AppShareToQQ{
	
}
- (void) AppShareToQZone{
	
}

#pragma mark --
#pragma mark -- WXApiDelegate <NSObject>

/*! @brief 收到一个来自微信的请求，处理完后调用sendResp
 *
 * 收到一个来自微信的请求，异步处理完成后必须调用sendResp发送处理结果给微信。
 * 可能收到的请求有GetMessageFromWXReq、ShowMessageFromWXReq等。
 * @param req 具体请求内容，是自动释放的
 */
-(void) onReq:(BaseReq*)req{
	BaseReq*  reqaa = req;
	
}

/*! @brief 发送一个sendReq后，收到微信的回应
 *
 * 收到一个来自微信的处理结果。调用一次sendReq后会收到onResp。
 * 可能收到的处理结果有SendMessageToWXResp、SendAuthResp等。
 * @param resp具体的回应内容，是自动释放的
 */
-(void) onResp:(BaseResp*)resp{
	
	BaseResp* qq = resp;
	
	switch ( qq.errCode) {
		case 0:
			;
			break;
		case 1:
			;
			break;
		case 2:
			;
			break;
		default:
			break;
	}
	
}


#pragma mark --
#pragma mark -- Video;

- (void) movieStartsPlaying{
	NSLog(@"start play");
}
- (void) moviePlaybackFinished{
	NSLog(@"end play");
}
- (CGSize)getWinSize{
	CGSize winSize = CGSizeMake(Director::getInstance()->getVisibleSize().width, Director::getInstance()->getVisibleSize().height);  //[ [CCDirector sharedDirector] winSize];
	return winSize;
}
- (void) playNetVideo_IOS:(NSString*)url{
	CCSize size = Director::getInstance()->getWinSize();
//	[CCVideoPlayer setScrrenSize:CGSizeMake(size.width-400, size.height-300)];
	[CCVideoPlayer setNoSkip:true];
//	[CCVideoPlayer playMovieWithFile:@"xcm.mp4"];
	[CCVideoPlayer playMovieWithFile:url];
}
- (void) playLocalVideo_IOS:(NSString*)filename{
	
	NSString* f1 = [NSString stringWithFormat:@"%@.mp4", filename];
	CCSize size = Director::getInstance()->getWinSize();
//	[CCVideoPlayer sets:CGSizeMake(size.width-400, size.height-300)];
	[CCVideoPlayer setNoSkip:true];
	[CCVideoPlayer playMovieWithFile:f1];
}

-(void)playVideo
{
//	CCSize size = Director::getInstance()->getWinSize();
////	[CCVideoPlayer setScrrenSize:CGSizeMake(size.width-400, size.height-300)];
//	[CCVideoPlayer setNoSkip:true];
//	[CCVideoPlayer playMovieWithFile:@"xcm.mp4"];
//	//  播放网络视频
	// [viewController playURLVideo];
}

@end
