//
//  TKAMoney.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "TKAPerson.h"
#include "TKACarBath.h"

@interface TKAMoney : NSObject
@property(nonatomic, assign) NSUInteger sum;
@property(nonatomic, assign) TKAMoneyPosition position;
@property(nonatomic, retain) TKAPerson *havingPerson;//responsible;

+(instancetype)moneyWhithSum:(NSUInteger)sum
                havingPerson:(TKAPerson *)person;



@end
