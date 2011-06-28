//
//	PESData.h
//	PESHandler
//
//	Created by Raphael Schweikert on 17.04.11.
//	Copyright 2011 Raphael Schweikert. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PESStitchBlock;

@interface PESData : NSObject <NSCoding> {
@private
	NSMutableArray *stitchBlocks;
	NSInteger minX;
	NSInteger maxX;
	NSInteger minY;
	NSInteger maxY;
	NSUInteger width;
	NSUInteger height;
	NSUInteger colorCount;
}

@property(nonatomic, assign) NSUInteger width;
@property(nonatomic, assign) NSUInteger height;
@property(nonatomic, assign) NSUInteger colorCount;

@property(nonatomic, assign) NSInteger minX;
@property(nonatomic, assign) NSInteger maxX;
@property(nonatomic, assign) NSInteger minY;
@property(nonatomic, assign) NSInteger maxY;

@property(nonatomic, readonly) NSMutableArray *stitchBlocks;

- (NSUInteger) imageWidth;
- (NSUInteger) imageHeight;

- (void) recalculate;

- (void) addStitchBlock:(PESStitchBlock *)block;

@end
