//
//  TKATimer.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 10.06.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKATimer.h"

#import "NSObject+TKAExtension.h"

@interface TKATimer ()
@property (nonatomic, retain)       NSTimer     *timer;

@end

@implementation TKATimer

#pragma mark -
#pragma mark Class Methods

+ (instancetype)timer {
    return [self object];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.timer = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

- (BOOL)isRunning {
    return [self.timer isValid];
}

#pragma mark -
#pragma mark Public Methods

- (void)startInRunLoopWithInterval:(NSTimeInterval)interval target:(id)target selector:(SEL)selector {
    self.timer = [NSTimer scheduledTimerWithTimeInterval:interval
                                                  target:target
                                                selector:selector
                                                userInfo:nil
                                                 repeats:YES];
}

- (void)startWithInterval:(NSTimeInterval)interval target:(id)target selector:(SEL)selector {
    self.timer = [NSTimer timerWithTimeInterval:interval
                                                  target:target
                                                selector:selector
                                                userInfo:nil
                                                 repeats:YES];
}

- (void)addToCurrentRunLoop {
    [[NSRunLoop currentRunLoop] addTimer:self.timer forMode:NSRunLoopCommonModes];
}

- (void)addToMainRunLoop {
    [[NSRunLoop mainRunLoop] addTimer:self.timer forMode:NSRunLoopCommonModes];
}


- (void)stop {
    self.timer = nil;
}

@end

