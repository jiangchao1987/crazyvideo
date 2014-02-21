//
//  IOSHelper.cpp
//  knowledgegame
//
//  Created by 畅玩 on 13-9-13.
//
//

#include "IOSHelper.h"
#include "RootViewController.h"
//#import "OpenUDID.h"
#include "Util.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#import "CrossPlatformHelper.h"

#import "AppController.h"

USING_NS_CC;
USING_NS_CC_EXT;

void wxHelp_IOS(){
	[[RootViewController Instance] showActionSheet];
}
void wxSendHelpByFriend_IOS(){
	CCNotificationCenter::sharedNotificationCenter()->postNotification("wxSendHelpByFriend");
}
void wxSendToFriendCircle_IOS(){
	
}

#pragma mark --
#pragma mark 购买商品

void buyLogic( int goodId, int goodPrice){
	/*
	NSLog(@"goodid is is%d", goodId);
	NSLog(@"price is is%d", goodPrice);
	
	NSArray *products = [IAPShare sharedHelper].iap.products;
	
	[[IAPShare sharedHelper].iap buyProduct:products[goodId] onCompletion:^(SKPaymentTransaction *transcation) {
		

		NSLog(@"-- error %@ %@",transcation,transcation.error);
		NSString *content = [[[NSString alloc] initWithData:transcation.transactionReceipt encoding:NSUTF8StringEncoding] autorelease];
		
		if ( transcation.error != nil ) {
			NSString* errstr = transcation.error.description;

			BOOL bShow = FALSE;
			NSString* errStr = nil;
			if (transcation.error.code == SKErrorPaymentCancelled)
			{
				bShow = FALSE;
				
			}else if ( transcation.error.code == SKErrorClientInvalid ){
				bShow = TRUE;
				errStr = [NSString stringWithFormat:@"客户端类型不支持"];
			}else if ( transcation.error.code == SKErrorPaymentNotAllowed){
				bShow = TRUE;
				errStr = [NSString stringWithFormat:@"禁止购买"];
			}else if ( transcation.error.code == SKErrorStoreProductNotAvailable ){
				bShow = TRUE;
				errStr = [NSString stringWithFormat:@"所购商品不存在"];
			}else{
				bShow = TRUE;
				errStr = [NSString stringWithFormat:@"未知错误"];
			}
			
			UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"购买失败" message:errstr delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil, nil];
			if ( bShow ) {
				[alert show];
			}
		}else{
	
			
			int goodiiiii = 0;
			
			if ( 0 <= goodId && goodId < 5) {
				goodiiiii = 19000001 + goodId;
			}else if ( 5 <= goodId && goodId <9 ){
				goodiiiii = 19001001 + goodId - 5;
			}else if ( goodId == 9 ){
				goodiiiii = 1900100999;
			}
			
			int64_t uid = GameDataMgr::getInstance()->getDetail_.user_id();
			
			NSLog(@"user id is:%lld", uid);
			
			NSString* key = @"5RzJj8ydRN3xpyaO";
			
			NSString* str = [NSString stringWithFormat:@"amount=%d&client=%@&cooperation=%@&count=%@&goods_id=%d&receipt=%@&user_id=%lld&key=%@",goodPrice,@"ios_phone",@"changwan", @"1", goodiiiii, content, uid,key];

		 
			NSString* sign =   [Util toMd5String:str];
			
			NSString* strurl = [NSString stringWithFormat:@"%@",@"http://pay.g.candou.com/kaixincidian/appstore/create_full_order.php"];
			
			NSURL* url = [NSURL URLWithString:[strurl stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding]];
			
			NSLog(@"url is:%@", url);
			

			__block ASIFormDataRequest* r = [[[ASIFormDataRequest alloc] initWithURL:url] autorelease];
			[r setRequestMethod:@"POST"];
			[r setPostValue:content forKey:@"receipt"];
			[r setPostValue:@"changwan" forKey:@"cooperation"];
			[r setPostValue:@"ios_phone" forKey:@"client"];
			[r setPostValue:@"1" forKey:@"count"];
			[r setPostValue:[NSString stringWithFormat:@"%d", goodPrice] forKey:@"amount"];
			[r setPostValue:[NSString stringWithFormat:@"%d", goodiiiii] forKey:@"goods_id"];
			[r setPostValue:[NSString stringWithFormat:@"%lld", uid] forKey:@"user_id"];
			[r setPostValue:sign forKey:@"sign"];
			[r setPostValue:@"debug_kxcd" forKey:@"debug"];
			//debug=debug_kxcd

			NSLog( @"%@", [r postBody]);
			
			[r setCompletionBlock:^{
				NSString* res = [r responseString];
				
				NSLog(@"%@", res);
				NSDictionary* resdic = (NSDictionary*)[res JSONValue];
				
				NSString* mes = nil;
				if ( [[resdic objectForKey:@"result"] isEqualToString:@"success"] ) {
					if (  [[resdic objectForKey:@"result"] isEqualToString:@"success"] ) {
						mes = [NSString stringWithFormat:@"恭喜，支付成功"];
					}else{
						mes = [NSString stringWithFormat:@"恭喜，已经支付成功"];
					}
					
					buySuccess_IOS(goodId);
				
					UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"支付成功" message:mes delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:@"取消", nil];
					[alert show];
					
				}else{
					NSString* errstr = [resdic objectForKey:@"reason"];
					UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"购买失败" message:errstr delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:@"取消", nil];
					[alert show];
				}
				
			}];
			[r setFailedBlock:^{
				
				UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"充值失败" message:@"请联系客服人员查找原因！" delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:@"取消", nil];
				[alert show];
				
			}];
			
			[r startAsynchronous];
		}
	}];
}

NSArray* loadLocalProducts(){
    NSString *productInfo = [[NSBundle mainBundle] pathForResource:@"Products.plist" ofType:nil];
    return [NSArray arrayWithContentsOfFile:productInfo];
}

void buy_IOS(int goodId){
	
	int goodPrice = 0;
	
	if(![IAPShare sharedHelper].iap) {
        
		NSArray* _itemsInfo = loadLocalProducts();
        NSMutableSet *productSet = [[[NSMutableSet alloc] init] autorelease];
        for (NSDictionary *productInfo in _itemsInfo){
            [productSet addObject:productInfo[@"product_id"]];
			
        }
//		NSDictionary* productInfo = [_itemsInfo objectAtIndex:goodId];
//		goodPrice = [productInfo[@"price"] integerValue];
		
        [IAPShare sharedHelper].iap = [[IAPHelper alloc] initWithProductIdentifiers:productSet];
    }
	
	NSArray* _itemsInfo = loadLocalProducts();
	NSDictionary* productInfo = [_itemsInfo objectAtIndex:goodId];
	goodPrice = [productInfo[@"price"] integerValue];
	
	NSLog(@"price info is:%@", productInfo[@"price"]);
	NSLog(@"price is is%d", goodPrice);
    
    [IAPShare sharedHelper].iap.production = YES;
	
	if (  [IAPShare sharedHelper].iap.products == nil ) {
		[[IAPShare sharedHelper].iap requestProductsWithCompletion:^(SKProductsRequest* request,SKProductsResponse* response)
		 {
			 
			 buyLogic( goodId, goodPrice );
		 }];
	}else{
		buyLogic( goodId, goodPrice );
	}
	 */
}

void buySuccess_IOS(int goodId){
	
	buySuccess( goodId );
}

#pragma mark --
#pragma mark 购买结束

void choujiang_IOS(){
	
	[[RootViewController Instance] showChoujiangView:true];
}

std::string getUserUDID_IOS(){
	
	NSString* str = @"sfs";//[OpenUDID value];
	const char* str1 = [str UTF8String];
	
	return str1;
}

long long getTimestamp_IOS(){
#warning gettime need to do
	return 1293120;
}


std::string getSign_IOS(){
	//changwan+timestamp+udid+guest
	std::string udid = getUserUDID_IOS();
	NSString* nnsString = [NSString stringWithUTF8String:udid.c_str()];

	NSString* cooperation = [NSString stringWithFormat:@"changwan"];
	NSString* timestamp = [NSString stringWithFormat:@"%lld", getTimestamp_IOS()];

//	NSString* cooperation_key = [NSString stringWithFormat:@"guest"];
	NSString* cooperation_key = [NSString stringWithFormat:@"dtiK21l9tlgDfthg"];

	NSString* signOri = [NSString stringWithFormat:@"%@&%@&%@&%@", cooperation, timestamp, nnsString, cooperation_key];
	
	NSString* signDes =  [Util toMd5String:signOri];
	
	return [signDes UTF8String];
}

std::string getNickName_IOS(){
	return [[[UIDevice currentDevice] name] UTF8String];
}

void playNetVideo_IOS(std::string url){
	
	AppController *app = (AppController*) [[UIApplication sharedApplication] delegate];

	NSString* str = [NSString stringWithFormat:@"%s",url.c_str()];
	[app playLocalVideo_IOS:str];
}

void playLocalVideo_IOS(std::string filename){
	AppController *app = (AppController*) [[UIApplication sharedApplication] delegate];
	
	NSString* str = [NSString stringWithFormat:@"%s",filename.c_str()];
	[app playLocalVideo_IOS:str];
}

