//
//  TKAEnterprise.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAMoney.h"
#import "TKABuilding.h"
#import "TKADirector.h"
#import "TKACar.h"

#import "TKAEmployee+TKAExtension.h"

typedef enum {
    TKADirtyCar,
    TKAWashingCar,
    TKACleanCar,
} TKACarCondition;

@interface TKAEnterprise : NSObject
@property(nonatomic, copy)      NSString        *name;
@property(nonatomic, retain)    TKABuilding     *adminBuilding;
@property(nonatomic, retain)    TKABuilding     *boxesBuilding;
@property(nonatomic, readonly)  NSArray         *employees;

+(instancetype)enterpriseWhithName:(NSString *)name;

- (NSString *)description;

-(void)addEmployee:(TKAEmployee*)emploeey;
-(void)removeEmployee:(TKAEmployee*)emploeey;

- (void)enterpriseFilling;
- (id)carWhithNumber:(NSString *)number amount:(NSUInteger)amount;

- (id)foundDirector;
- (id)foundAccountant;
- (id)foundFreeWasher;
- (id)foundFreeCarBox;

- (void)washingCar:(TKACar *)car;

- (void)workingProcess;
- (void)financialFlows;
@end
