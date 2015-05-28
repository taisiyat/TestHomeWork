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

static const NSUInteger kTKACountCar        = 100;

void TKACarBathTask1() {
    @autoreleasepool {
        TKAEnterprise *enterprise = [TKAEnterprise enterpriseWhithName:@"CarBath"];
        
        [enterprise prepare];
        NSLog(@"%@", [enterprise description]);
       
        for (NSUInteger iter = 0; iter < kTKACountCar; iter++) {
            [enterprise washCar:[TKACar car]];
        }
       
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];

        NSLog(@"%@", [enterprise description]);
        
    }
}