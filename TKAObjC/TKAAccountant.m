//
//  TKAAccountant.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAAccountant.h"

@implementation TKAAccountant

-(void)count {
    NSUInteger sum = 0;
    for (TKAMoney *money in self.bigMoney) {
        sum += [money amount];
        [[self bigMoney] removeMoney:money];
    }
    
    TKAMoney *sumMoney = [TKAMoney moneyWithAmount:sum responsible:self];
    [[self bigMoney] addMoney:sumMoney];
}

@end
