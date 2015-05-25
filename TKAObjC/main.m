//
//  main.m
//  TKAObjC
//
//  Created by Taisiya on 14.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKAHumanTest.h"
#import "TKACarBathTest.h"
#import "TKAStringTest.h"
#import "TKAThreadTest.h"

#import "TKAEnterprise.h"
#import "TKACar.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        //TKAHumanTask1Test();
        //TKACreatureTask2Test();
        TKACarBathTask1();
        //TKAStringTest();
        //TKAThreadTestFirst();
        
//        TKAEnterprise *enterprise = [TKAEnterprise enterpriseWhithName:@"CarBath"];
//        
//        [enterprise prepare];
//        NSLog(@"%@", [enterprise description]);
//        
//        [enterprise washCar:[TKACar generateCar]];
//
//        NSRunLoop *runLoop = [NSRunLoop mainRunLoop];
//        [runLoop run];
        
     
        NSLog(@"Hello, World!");
    }
    return 0;
}
           