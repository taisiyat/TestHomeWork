//
//  TKACar.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "NSObject+TKAExtension.h"

#import "TKATransferMoneyProtocol.h"

@class TKACar;

@protocol TKACarDelegate <NSObject>

- (void)car:(TKACar *)object shouldGiveMoney:(NSUInteger)money; //or - (void)shouldGiveMoneyCar:(TKACar *)object;
- (BOOL)carShouldBeClean:(TKACar *)object;

@end

@interface TKACar : NSObject <TKATransferMoneyProtocol, TKACarDelegate>
@property (nonatomic, copy)     NSString    *number;
@property (nonatomic, assign)   BOOL        clean;
@property (nonatomic, assign)   id<TKACarDelegate>      delegate;

+ (instancetype)carWithNumber:(NSString *)number
                  moneyAmount:(NSUInteger)moneyAmount;

@end
