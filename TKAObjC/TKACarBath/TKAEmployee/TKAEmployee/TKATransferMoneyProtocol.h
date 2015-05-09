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

- (void)takeMoneyFromSomeone:(id<TKATransferMoneyProtocol>)object;
//- (void)takeMoney:(NSUInteger)money FromSomeone:(id<TKATransferMoneyProtocol>)object;

@end

