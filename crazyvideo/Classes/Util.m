//
//  Util.m
//  Util
//
//  Created by Zhang zhihui on 13-1-24.
//  Copyright (c) 2013年 Zhang zhihui. All rights reserved.
//

#import "Util.h"
#import <CommonCrypto/CommonDigest.h>

#define CC_MD5_DIGEST_LENGTH 16

NSString* strToMd5Str( NSString* aSrc )
{
    const char *cStr = [aSrc UTF8String];
    
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    
	printf("ori str is:%s", cStr);
    CC_MD5( cStr, strlen( cStr ), result );
    
	NSString* md5Str = [NSString stringWithFormat:
                        @"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
                        result[0], result[1], result[2], result[3],
                        result[4], result[5], result[6], result[7],
                        result[8], result[9], result[10], result[11],
                        result[12], result[13], result[14], result[15]];
    
	NSLog(@"md5 str is:%@", md5Str);
    return [md5Str lowercaseString];
}


@implementation Util

+ (NSString*)toMd5String:(NSString*) asrc{
	
	return strToMd5Str(asrc);
}
@end
