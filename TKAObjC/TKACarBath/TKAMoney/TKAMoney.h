//
//  TKAMoney.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "NSObject+TKAExtension.h"

@interface TKAMoney : NSObject
@property (nonatomic, assign)    NSUInteger  amount;

+ (instancetype)moneyWithAmount:(NSUInteger)amount;

@end
