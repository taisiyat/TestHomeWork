//
//  TKAMoney.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "TKACarBath.h"

#include "NSObject+TKAExtension.h"

@interface TKAMoney : NSObject
@property(nonatomic, assign)    NSUInteger  amount;
@property(nonatomic, retain)    NSObject    *responsible;

+(instancetype)moneyWhithAmount:(NSUInteger)amount
                    responsible:(NSObject *)responsible;

- (void)description;

@end
