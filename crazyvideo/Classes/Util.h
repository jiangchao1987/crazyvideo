//
//  Util.h
//  Util
//
//  Created by Zhang zhihui on 13-1-24.
//  Copyright (c) 2013年 Zhang zhihui. All rights reserved.
//

#import <Foundation/Foundation.h>

NSString* strToMd5Str( NSString* aSrc );

@interface Util : NSObject{
	

}

+ (NSString*)toMd5String:(NSString*) asrc;
@end
