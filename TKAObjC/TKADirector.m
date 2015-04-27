//
//  TKADirector.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKADirector.h"

@implementation TKADirector

- (void)profit {
    [self countMoney];

    for (TKAMoney *money in self.bigMoney) {
        money.amount = money.amount * 0.7;
    }
}

@end
