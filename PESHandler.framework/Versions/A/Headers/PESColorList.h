//
//  PESColorList.h
//  PESHandler
//
//  Created by Raphael Schweikert on 17.04.11.
//  Copyright 2011 Raphael Schweikert. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface PESColorList : NSObject {
@private
    
}

+ (CGColorRef) CGColorWithColorNumber:(NSUInteger)num;

#if TARGET_OS_MAC
+ (NSColor *) colorWithColorNumber:(NSUInteger)num;
#endif
#if TARGET_OS_IPHONE
+ (UIColor *) colorWithColorNumber:(NSUInteger)num;
#endif

@end
