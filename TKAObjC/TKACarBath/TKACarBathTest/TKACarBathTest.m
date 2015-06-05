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

static const NSUInteger kTKACountCar            = 1000;
static const NSUInteger kTKAPortionCar          = 10;
static const NSUInteger kTKARandomSleep         = 1000;
static const NSUInteger kTKARandomSleepInterval     = 1;
static NSString * const kTKANameQueueMain   = @"TKAQueueMain";


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
                sleep(arc4random_uniform(kTKARandomSleep * kTKARandomSleepInterval) / kTKARandomSleep);
            }
            
            [enterprise washCar:[TKACar car]];
        };

        TKAGCDObject *gcdMain = [[TKAGCDObject new] autorelease];
        dispatch_queue_t queue = dispatch_queue_create([kTKANameQueueMain cStringUsingEncoding:NSUTF8StringEncoding],
                                                       DISPATCH_QUEUE_CONCURRENT);
        gcdMain.queue = queue;
        dispatch_release(queue);
        
        dispatch_async(gcdMain.queue, ^{
            dispatch_apply(kTKACountCar, gcdMain.queue, blockMain);
        });
        
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];
    }
}



