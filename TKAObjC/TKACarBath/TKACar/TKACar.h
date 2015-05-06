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

//- (void)carShouldGiveMoney:(TKACar *)object; //should give money car   ?? uncorrect name
//- (BOOL)carWhenCleanShouldGiveMoney:(TKACar *)object; // if clean then YES

- (void)car:(TKACar *)object shouldGiveMoney:(NSUInteger)money;
- (BOOL)carShouldBeClean:(TKACar *)object;

@end

@interface TKACar : NSObject <TKATransferMoneyProtocol, TKACarDelegate>
@property (nonatomic, copy)                     NSString        *number;
@property (nonatomic, assign)                   NSUInteger      money;
@property (nonatomic, assign, getter=isClean, setter=setIsClean:)   BOOL            clean;
@property (nonatomic, assign)                   id<TKACarDelegate>      delegate;

+ (instancetype)carWithNumber:(NSString *)number
                  moneyAmount:(NSUInteger)moneyAmount;

@end
