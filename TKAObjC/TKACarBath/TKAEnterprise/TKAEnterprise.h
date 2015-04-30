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

typedef enum {
    TKADirtyCar,
    TKAWashingCar,
    TKACleanCar,
} TKACarCondition;

@interface TKAEnterprise : NSObject
@property(nonatomic, copy)      NSString        *name;
@property(nonatomic, retain)    TKABuilding     *building;
@property(nonatomic, readonly)  NSArray         *employees;

+ (instancetype)enterpriseWhithName:(NSString *)name;

- (NSString *)description;

-(void)addEmployee:(TKAEmployee *)emploeey;
-(void)removeEmployee:(TKAEmployee *)emploeey;

//- (id)carWithNumber:(NSString *)number amount:(NSUInteger)amount;

- (id)carArrivesWithNumber:(NSString *)number amount:(NSUInteger)amount;
- (id)foundEmployeePosition:(Class)position;
- (id)foundFreeEmployeePosition:(Class)position;
- (id)foundFreeCarBox;

- (void)workingProcess;
- (void)washingCar:(TKACar *)car;
- (void)financialFlows;
@end
