//
//  TKATimer.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 10.06.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TKATimer : NSObject

+ (instancetype)timer;

- (void)addToCurrentRunLoop;
- (void)addToMainRunLoop;
- (void)startWithInterval:(NSTimeInterval)interval target:(id)target selector:(SEL)selector;
- (void)startInRunLoopWithInterval:(NSTimeInterval)interval target:(id)target selector:(SEL)selector;
- (void)stop;

@end

