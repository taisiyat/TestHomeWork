//
//  TKACarBathTest.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKACarBathTest.h"
#import "TKACar.h"
#import "TKAMoney.h"
#import "TKAEnterprise.h"
#import "TKABuilding.h"
#import "TKADirector.h"
#import "TKAAccountant.h"
#import "TKAWasher.h"
#import "TKAAdminRoom.h"
#import "TKACarBox.h"


void TKACarBathTask1() {
    @autoreleasepool {
       
        TKAEnterprise *enterprise = [TKAEnterprise enterpriseWhithName:@"CarBath"];
        [enterprise fill];
        
        [enterprise output];
        
        TKACar *firstCar = [enterprise carCameWhithNumber:@"AA1234" amount:50];
        TKACar *secondCar = [enterprise carCameWhithNumber:@"AA5678" amount:100];
        [firstCar output];
        [secondCar output];
        
        [enterprise output];

    }
}