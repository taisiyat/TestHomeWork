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

void TKACarBathTask1() {
    @autoreleasepool {
        TKAEnterprise *enterprise = [TKAEnterprise enterpriseWithName:@"CarBath"];
        
        [enterprise prepare];
        NSLog(@"%@", [enterprise description]);
       
        TKACarGenerator *carGenerator = [TKACarGenerator carGenerator];
        [carGenerator carGenerationForEnterprise:enterprise];
       
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];

    }
}

void TKAPerformBlockOnMainQueue(TKABlock block) {
    if ([NSThread isMainThread]) {
        block();
    } else {
        dispatch_sync(dispatch_get_main_queue(), block);
    }
};




