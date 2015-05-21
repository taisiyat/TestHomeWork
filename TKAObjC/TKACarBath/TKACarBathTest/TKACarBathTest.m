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

void TKACarBathTask1() {
    @autoreleasepool {
            TKAEnterprise *enterprise = [TKAEnterprise enterpriseWhithName:@"CarBath"];
            [enterprise prepare];
            NSLog(@"%@", [enterprise description]);
            [enterprise workWithCar:[enterprise nextCarFromQueue]];
            NSLog(@"%@", [enterprise description]);
            
            NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
            [runLoop run];
    }
}