//
//  TKAEmployee.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAMoney.h"

#import "NSObject+TKAExtension.h"

#import "TKATransferMoneyProtocol.h"

@interface TKAEmployee : NSObject <TKATransferMoneyProtocol>
@property (nonatomic,copy)      NSString    *name;
@property (nonatomic,assign)    NSUInteger  experience;
@property (nonatomic,assign)    NSUInteger  salary;
@property (nonatomic,readonly)  NSArray     *bigMoney;
@property (nonatomic,assign, getter=isFree)   BOOL   free;

+ (instancetype)employeeWithName:(NSString *)name;

- (void)addMoney:(TKAMoney *)money;
- (void)removeMoney:(TKAMoney *)money;
- (void)countMoney;
- (BOOL)haveMoney;

- (void)takeMoneyFromSomeone:(TKAEmployee *)employee;
- (void)giveMoneyToSomeone:(TKAEmployee *)employee;
@end
