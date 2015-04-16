//
//  TKACar.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "TKACarBath.h"
#include "TKAPerson.h"
#include "TKAMoney.h"

@interface TKACar : NSObject
@property (nonatomic, retain)   TKAPerson       *owner;
@property (nonatomic, retain)   NSString        *stateNumber;
@property (nonatomic, assign)   TKACarCondition condition;
@property (nonatomic, retain)   TKAMoney        *money;

+(instancetype)carWhithStateNumber:(NSString *)stateNumber
                             owner:(TKAPerson *)owner;



@end
