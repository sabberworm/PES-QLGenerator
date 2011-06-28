#include <CoreFoundation/CoreFoundation.h>
#include <CoreServices/CoreServices.h>
#include <QuickLook/QuickLook.h>

#include <Cocoa/Cocoa.h>
#include <PESHandler/PESParser.h>
#include <PESHandler/PESData.h>
#include <PESHandler/PESColorList.h>
#include <PESHandler/PESStitchBlock.h>
#include <PESHandler/PESStitch.h>

/* -----------------------------------------------------------------------------
   Generate a preview for file

   This function's job is to create preview for designated file
   ----------------------------------------------------------------------------- */

OSStatus GeneratePreviewForURL(void *thisInterface, QLPreviewRequestRef preview, CFURLRef aUrl, CFStringRef contentTypeUTI, CFDictionaryRef options)
{
	NSURL *url = (NSURL *)aUrl;
	NSString *path = [url path];
	PESParser *parser = [[PESParser alloc] initWithFile:path];
	PESData *data = [parser parse];
	
	CGFloat imageWidth = [data imageWidth];
	CGFloat imageHeight = [data imageHeight];
	
	CGSize previewSize = CGSizeMake(800, 800*(imageHeight/imageWidth));
	
	CGFloat widthFactor = previewSize.width/imageWidth;
	CGFloat heightFactor = previewSize.height/imageHeight;
	
	CGFloat scaleFactor = MIN(widthFactor, heightFactor);
	
	CGContextRef context = QLPreviewRequestCreateContext(preview, previewSize, NO, nil);
	CGAffineTransform flipVertical = CGAffineTransformMake(1, 0, 0, -1, 0, previewSize.height);
	CGContextConcatCTM(context, flipVertical);
	CGContextSetFillColor(context, (CGFloat[]){1.0f, 1.0f, 1.0f, 1.0f});
	CGContextFillRect(context, CGRectMake(0, 0, previewSize.width, previewSize.height));
	
	CGFloat xOffset = -data.minX;
	CGFloat yOffset = -data.minY;
	
	for(PESStitchBlock *block in data.stitchBlocks) {
		
		CGColorRef color = [PESColorList CGColorWithColorNumber:block.color];
		CGContextSetStrokeColorWithColor(context, color);
		CFRelease(color);
		
		CGContextSetLineCap(context, kCGLineCapRound);
		CGContextSetLineWidth(context, 1.0f);
		
		BOOL first = YES;
		for(PESStitch *stitch in block.stitches) {
			CGFloat x = stitch.x + xOffset;
			CGFloat y = stitch.y + yOffset;
			x *= scaleFactor;
			y *= scaleFactor;
			if(first || stitch.isJumpStitch) {
				CGContextMoveToPoint(context, x, y);
				first = NO;
			} else {
				CGContextAddLineToPoint(context, x, y);
			}
		} 
		CGContextDrawPath(context, kCGPathStroke);
	}
	
	QLPreviewRequestFlushContext(preview, context);
	
	return noErr;
}

void CancelPreviewGeneration(void* thisInterface, QLPreviewRequestRef preview)
{
    // implement only if supported
}
