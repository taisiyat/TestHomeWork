//
//  TKADirector.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKADirector.h"

@implementation TKADirector

- (void)takeProfit {
    NSUInteger sum = 0;
    for (TKAMoney *money in self.bigMoney) {
        sum += [money amount];
        [[self bigMoney] removeMoney:money];
    }
    
    TKAMoney *sumMoney = [TKAMoney moneyWithAmount:(sum*0.2) responsible:self];
    [[self bigMoney] addMoney:sumMoney];
}
@end
