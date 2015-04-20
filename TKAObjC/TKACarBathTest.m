//
//  TKACarBathTest.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "TKACarBathTest.h"


void TKACarBathTask1() {
    NSString *numberCar1 = @"AA2345";
    NSString *numberCar2 = @"AA6789";
    TKACar *firstCar = [TKACar carWhithStateNumber:numberCar1];
    TKACar *secondCar = [TKACar carWhithStateNumber:numberCar2];
    [firstCar description];
    [secondCar description];
}