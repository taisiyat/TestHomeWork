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
@property(nonatomic, retain) NSString *name;
@property(nonatomic, retain) TKABuilding *building;
@property(nonatomic, retain) TKADirector *director;
@property(nonatomic, retain) TKAPerson *owner;
@property(nonatomic, readonly) NSArray *staffPerson;//staff
@property(nonatomic, readonly) NSArray *financialFlows;//money
@property(nonatomic, assign) NSInteger allMoney;
@property(nonatomic, readonly) NSArray *money;

+(instancetype)enterpriseWhithName:(NSString *)name
                          director:(TKADirector *)director
                             owner:(TKAPerson *)owner
                             money:(NSInteger)allMoney;

@end
