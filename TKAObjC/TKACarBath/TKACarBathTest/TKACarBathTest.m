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

static const NSUInteger kTKACountCar        = 100;

void TKACarBathTask1() {
    @autoreleasepool {
        TKAEnterprise *enterprise = [TKAEnterprise enterpriseWithName:@"CarBath"];
        
        [enterprise prepare];
        NSLog(@"%@", [enterprise description]);
       
//        for (NSUInteger iter = 0; iter < kTKACountCar; iter++) {
//            [enterprise washCar:[TKACar car]];
//        //    [enterprise performSelectorInBackground:@selector(washCar:) withObject:[TKACar car]];
//        }
       
//        void (^blockMain)(size_t) = ^(size_t count) {
//            [enterprise washCar:[TKACar car]];
//            printf("ID = %lu, iteration count\n", count);
//        };
        
        void (^blockMain)() = ^() {
            [enterprise washCar:[TKACar car]];
        };
        
       
        TKAGCDObject *gcdMain = [[TKAGCDObject new] autorelease];
        
//        void (^block)() = ^() {
//            [enterprise washCar:[TKACar car]];
//        };
//        
//        void (^blockMain)() = ^(){
//            dispatch_queue_t queue = dispatch_get_global_queue(QOS_CLASS_UTILITY, 0);
//            gcdMain.queue = queue;
//            
//            dispatch_sync (queue, ^{
//                dispatch_apply(kTKACountCar, queue, block);
//            });
//        };
        
        [gcdMain executeSerialBlock:blockMain];
        
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];

    }
}



