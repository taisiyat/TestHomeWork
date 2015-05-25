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

static const NSUInteger kTKACountCar        = 10;

void TKACarBathTask1() {
    @autoreleasepool {
        TKAEnterprise *enterprise = [TKAEnterprise enterpriseWhithName:@"CarBath"];
        
        [enterprise prepare];
        NSLog(@"%@", [enterprise description]);
        
        NSMutableArray *cars = [NSMutableArray array];
        for (NSUInteger iter = 0; iter < kTKACountCar; iter++) {
            [cars addObject:[TKACar generateCar]];
        }
        
        [enterprise washCar:cars];
        
        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
        [runLoop run];

        NSLog(@"%@", [enterprise description]);
        
    }
}