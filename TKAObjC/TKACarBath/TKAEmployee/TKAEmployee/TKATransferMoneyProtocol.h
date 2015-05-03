//
//  TKAEmployeeProtocol.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 27.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TKATransferMoneyProtocol <NSObject>

- (void)takeMoneyFromSomeone:(id<TKATransferMoneyProtocol>)object;

- (void)giveMoneyToSomeone:(id<TKATransferMoneyProtocol>)object;

@end
