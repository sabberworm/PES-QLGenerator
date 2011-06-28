//
//	PESStitch.h
//	PESHandler
//
//	Created by Raphael Schweikert on 17.04.11.
//	Copyright 2011 Raphael Schweikert. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface PESStitch : NSObject <NSCoding> {
@private
	NSInteger x;
	NSInteger y;
	BOOL isJumpStitch;
}

@property(nonatomic, assign) NSInteger x;
@property(nonatomic, assign) NSInteger y;
@property(nonatomic, assign) BOOL isJumpStitch;

@end
