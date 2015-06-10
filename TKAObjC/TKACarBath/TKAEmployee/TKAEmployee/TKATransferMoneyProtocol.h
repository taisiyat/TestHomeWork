//
//  TKAEmployeeProtocol.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 27.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TKATransferMoneyProtocol <NSObject>
@property (nonatomic, assign)    NSUInteger     money;

@optional

- (void)takeMoneyFromObject:(id<TKATransferMoneyProtocol>)object;

- (NSUInteger)giveAllMoney;
- (void)takeMoney:(NSUInteger)cash;

@end

