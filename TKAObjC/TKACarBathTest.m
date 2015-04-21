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


void TKACarBathTask1() {
    @autoreleasepool {
        
        NSString *numberCar1 = @"AA2345";
        NSString *numberCar2 = @"AA6789";
        TKACar *firstCar = [TKACar carWithNumber:numberCar1 amount:50];
        TKACar *secondCar = [TKACar carWithNumber:numberCar2 amount:100];
        [firstCar output];
        [secondCar output];
        NSString *positionDirector = @"director";
        NSString *positionAccountant = @"accountant";
        NSString *positionWasher = @"washer";
        NSString *nameDirector = @"directorName";
        NSString *nameAccountant = @"accountantName";
        NSString *nameWasher1 = @"washerName1";
        NSString *nameWasher2 = @"washerName2";
        
        TKADirector *director = [TKADirector employeeWhithName:nameDirector staffPosition:positionDirector];
        TKAEnterprise *enterprice = [TKAEnterprise enterpriseWhithName:@"CarBath" director:director];
        [enterprice output];
        
//        TKAEnterprise *enterprice = [TKAEnterprise enterpriseWhithName:@"CarBath" director:nameDirector];
//        [enterprice output];
    }
}