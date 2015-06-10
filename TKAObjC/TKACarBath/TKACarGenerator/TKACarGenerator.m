//
//  TKACarGenerator.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 09.06.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKACarGenerator.h"
#import "TKACar.h"
#import "TKAEnterprise.h"
#import "TKATimer.h"

#import "NSObject+TKAExtension.h"

static const NSUInteger kTKACountCar                = 100;
static const NSUInteger kTKAPortionCar              = 5;
static const NSUInteger kTKARandomSleep             = 100;
static const NSUInteger kTKATimerInterval           = 1;

@interface TKACarGenerator ()
//@property (nonatomic, retain) NSTimer *timer;

@end

@implementation TKACarGenerator

#pragma mark -
#pragma mark Class Methods

+ (instancetype)carGeneratorWithTimerWithTarget:(id)target selector:(SEL)selector {
    return [[[self alloc] initWithTimerWithTarget:target selector:selector] autorelease];
}
+ (instancetype)carGenerator {
    return [[[self alloc] initWithTimer] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self stop];
    
    [super dealloc];
}

- (instancetype)initWithTimerWithTarget:(id)target selector:(SEL)selector {
    self = [super init];
    if (self) {
        [self startWithTimerWithTarget:(id)target selector:(SEL)selector];
    }
    
    return self;
}

- (instancetype)initWithTimer {
    self = [super init];
    if (self) {
        [self start];
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

- (void)setTimer:(NSTimer *)timer {
    if (_timer != timer) {
        if ([_timer isValid]) {
            [_timer invalidate];
        }

        if ([timer isValid]) {
            _timer = timer;
        }
    }
}

- (BOOL)isRunning {
    return [self.timer isValid];
}

#pragma mark -
#pragma mark Public Methods

- (void)carGenerationForEnterprise:(TKAEnterprise *)enterprise {
    void (^blockMain)(size_t) = ^(size_t count) {
//        if (0 != count && count % kTKAPortionCar == 0) {
//            NSTimeInterval timeInterval = arc4random_uniform(kTKARandomSleep) * kTKATimerInterval / kTKARandomSleep;
//            sleep(timeInterval);
//        }
        
        [enterprise washCar:[TKACar car]];
    };

    dispatch_async(dispatch_get_global_queue(QOS_CLASS_DEFAULT, 0), ^{
        dispatch_apply(kTKACountCar, dispatch_get_global_queue(QOS_CLASS_BACKGROUND, 0), blockMain);
    });
}

- (void)start {
    self.timer = [NSTimer scheduledTimerWithTimeInterval:kTKATimerInterval
                                                  target:self
                                                selector:@selector(carGenerationForEnterprise:)
                                                userInfo:nil
                                                 repeats:YES];
}

- (void)startWithTimerWithTarget:(id)target selector:(SEL)selector  {
    self.timer = [NSTimer scheduledTimerWithTimeInterval:kTKATimerInterval
                                                  target:target
                                                selector:selector
                                                userInfo:nil
                                                 repeats:YES];

//    self.timer = [NSTimer timerWithTimeInterval:kTKATimerInterval
//                                                  target:self
//                                                selector:@selector(washCar:)
//                                                userInfo:nil
//                                                 repeats:YES];
//    [[NSRunLoop currentRunLoop] addTimer:self.timer forMode:NSDefaultRunLoopMode];
}

- (void)stop {
    self.timer = nil;
}

@end
