//
//  TKAEnterprise.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"

@class TKACar;

@interface TKAEnterprise : NSObject <TKAEmployeeObserver>
@property (nonatomic, copy)         NSString        *name;
@property (nonatomic, readonly)     NSArray         *employees;

+ (instancetype)enterpriseWhithName:(NSString *)name;
- (void)prepare;

- (void)washCar:(TKACar *)car;
- (TKACar *)nextCarInQueue;

@end
