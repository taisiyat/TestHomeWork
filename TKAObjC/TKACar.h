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

#include "NSObject+TKAExtension.h"

@interface TKACar : NSObject
//@property (nonatomic, retain)   TKAPerson       *owner;
@property (nonatomic, copy)     NSString        *number;
@property (nonatomic, assign)   TKACarCondition condition;
@property (nonatomic, retain)   TKAMoney        *moneyCar;

+ (instancetype)carWhithStateNumber:(NSString *)number;
                           // amount:(NSUInteger)anount;

- (void)description;

@end
