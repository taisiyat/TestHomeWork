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

#import "NSObject+TKAExtension.h"

static const NSUInteger kTKACountCar                = 100;
static const NSUInteger kTKAPortionCar              = 5;
static const NSUInteger kTKARandomSleep             = 1000;
static const NSUInteger kTKATimerInterval          = 1;

@implementation TKACarGenerator

#pragma mark -
#pragma mark Class Methods

+ (instancetype)carGenerator {
    return [self object];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.timer = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
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

- (void)start {
    self.timer = [NSTimer scheduledTimerWithTimeInterval:kTKATimerInterval
                                                  target:self
                                                selector:NULL
                                                userInfo:nil
                                                 repeats:YES];
}

- (void)stop {
    self.timer = nil;
}

- (void)carGenerationForEnterprise:(TKAEnterprise *)enterprise {
    void (^blockMain)(size_t) = ^(size_t count) {
        if (0 != count && count % kTKAPortionCar == 0) {
            NSTimeInterval timeInterval = arc4random_uniform(kTKARandomSleep) * kTKATimerInterval / kTKARandomSleep;
            sleep(timeInterval);
        }
        
        [enterprise washCar:[TKACar car]];
    };

    dispatch_async(dispatch_get_global_queue(QOS_CLASS_BACKGROUND, 0), ^{
        dispatch_apply(kTKACountCar, dispatch_get_main_queue(), blockMain);
    });

}

@end
