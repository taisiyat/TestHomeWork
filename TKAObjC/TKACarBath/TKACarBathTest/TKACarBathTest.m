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
#import "TKADirector.h"

void TKACarBathTask1() {
    @autoreleasepool {
       
        TKAEnterprise *enterprise = [TKAEnterprise enterpriseWhithName:@"CarBath"];
        NSLog(@"%@", [enterprise description]);
  
       [enterprise workingProcess];
        
         NSLog(@"%@", [enterprise description]);

    }
}