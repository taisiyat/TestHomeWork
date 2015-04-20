//
//  TKAEnterprise.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "TKACarBath.h"
#include "TKAPerson.h"
#include "TKAMoney.h"
#include "TKABuilding.h"
#include "TKADirector.h"
#include "TKAStaff.h"

@interface TKAEnterprise : NSObject
@property(nonatomic, copy)      NSString    *name;
@property(nonatomic, retain)    TKABuilding *building;
@property(nonatomic, retain)    TKADirector *director;
@property(nonatomic, readonly)  NSArray *staffPerson;//staff
@property(nonatomic, readonly)  NSArray *financialFlows;//money

+(instancetype)enterpriseWhithName:(NSString *)name
                          director:(TKADirector *)director;

@end
