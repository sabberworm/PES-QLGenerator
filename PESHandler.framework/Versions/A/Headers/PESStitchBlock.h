//
//	PESStitchBlock.h
//	PESHandler
//
//	Created by Raphael Schweikert on 17.04.11.
//	Copyright 2011 Raphael Schweikert. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PESStitch;

@interface PESStitchBlock : NSObject <NSCoding> {
@private
	NSUInteger color;
	NSMutableArray *stitches;
}

@property(nonatomic, assign) NSUInteger color;
@property(nonatomic, readonly) NSMutableArray *stitches;

- (void) addStitch:(PESStitch *) stitch;

#if TARGET_OS_MAC
- (NSBezierPath *) pathFromBlockWithScale:(CGFloat)scale;
- (NSBezierPath *) pathFromBlockXOffset:(NSUInteger)xOffset yOffset:(NSInteger) yOffset andScale:(CGFloat)scale;
- (NSBezierPath *) pathFromBlockXOffset:(NSUInteger)xOffset yOffset:(NSInteger) yOffset scale:(CGFloat)scale ignoringJumps:(BOOL)ignoringJumps;
#elif TARGET_OS_IPHONE
- (UIBezierPath *) pathFromBlockWithScale:(CGFloat)scale;
- (UIBezierPath *) pathFromBlockXOffset:(NSUInteger)xOffset yOffset:(NSInteger) yOffset andScale:(CGFloat)scale;
- (UIBezierPath *) pathFromBlockXOffset:(NSUInteger)xOffset yOffset:(NSInteger) yOffset scale:(CGFloat)scale ignoringJumps:(BOOL)ignoringJumps;
#endif

@end
