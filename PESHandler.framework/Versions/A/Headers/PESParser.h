//
//	PESParser.h
//	PESHandler
//
//	Created by Raphael Schweikert on 17.04.11.
//	Copyright 2011 Raphael Schweikert. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PESData;

@interface PESParser : NSObject {
@private
	NSData *parseData;
	NSUInteger currentPosition;
}

- (id)initWithData:(NSData *)data;
- (id)initWithFile:(NSString *)path;

- (PESData *)parse;

@end
