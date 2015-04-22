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

#import "TKAEmployee+TKAExtension.h"

typedef enum {
    TKADirtyCar,
    TKAWashingCar,
    TKACleanCar,
} TKACarCondition;

@interface TKAEnterprise : NSObject
@property(nonatomic, copy)      NSString    *name;
@property(nonatomic, retain)    TKABuilding *adminBuilding;
@property(nonatomic, retain)    TKABuilding *boxesBuilding;
@property(nonatomic, retain)    TKADirector *director;
@property(nonatomic, readonly)  NSArray *employees;
//@property(nonatomic, readonly)  NSArray *financialFlows;//money

+(instancetype)enterpriseWhithName:(NSString *)name;
                        
//+(instancetype)enterpriseWhithName:(NSString *)name
//                          director:(TKADirector *)director;


-(void)addEmployee:(TKAEmployee*)emploeey;
-(void)removeEmployee:(TKAEmployee*)emploeey;

- (void)fill;
- (id)carCameWhithNumber:(NSString *)number amount:(NSUInteger)amount;

- (id)foundDirector;
- (id)foundAccountant;
- (id)foundFreeWasher;
- (id)foundFreeCarBox;

@end
