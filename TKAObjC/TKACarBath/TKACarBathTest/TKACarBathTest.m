//
//  TKACarBathTest.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKACarBathTest.h"
#import "TKAEnterprise.h"
#import "TKACar.h"
#import "TKAGCDObject.h"

static const NSUInteger kTKACountCar                = 100;
static const NSUInteger kTKAPortionCar              = 5;
static const NSUInteger kTKARandomSleep             = 1000;
static const NSUInteger kTKARandomSleepInterval     = 1;

void TKACarBathTask1() {
    @autoreleasepool {
        TKAEnterprise *enterprise = [TKAEnterprise enterpriseWithName:@"CarBath"];
        
        [enterprise prepare];
        NSLog(@"%@", [enterprise description]);
       
//        for (NSUInteger iter = 0; iter < kTKACountCar; iter++) {
//        //    [enterprise washCar:[TKACar car]];
//            [enterprise performSelectorInBackground:@selector(washCar:) withObject:[TKACar car]];
//        }
     
        void (^blockMain)(size_t) = ^(size_t count) {
            if (0 != count && count % kTKAPortionCar == 0) {
                NSTimeInterval timeInterval = arc4random_uniform(kTKARandomSleep) * kTKARandomSleepInterval / kTKARandomSleep;
                sleep(timeInterval);
            }
            
            [enterprise washCar:[TKACar car]];
        };
       
        dispatch_queue_t queue = dispatch_get_global_queue(QOS_CLASS_UTILITY, 0);
        enterprise.queue = queue;
        dispatch_release(queue);

        dispatch_async(enterprise.queue, ^{
            dispatch_apply(kTKACountCar, enterprise.queue, blockMain);
        });
        
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];
    }
}



