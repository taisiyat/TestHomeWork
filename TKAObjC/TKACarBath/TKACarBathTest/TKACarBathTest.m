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
#import "TKACarGenerator.h"
#import "TKATimer.h"

void TKACarBathTask1() {
    @autoreleasepool {
        TKAEnterprise *enterprise = [TKAEnterprise enterpriseWithName:@"CarBath"];
        
        [enterprise prepare];
        NSLog(@"%@", [enterprise description]);
       
        TKACarGenerator *carGenerator = [TKACarGenerator carGenerator];
        [carGenerator carGenerationForEnterprise:enterprise];

        [carGenerator.timer startInRunLoopWithInterval:10 target:enterprise selector:@selector(washCar:)];
        
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];

    }
}

void TKAPerformBlockOnMainThread(TKABlock block) {
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_sync(dispatch_get_global_queue(QOS_CLASS_USER_INITIATED, 0), block);
    }
};




