//
//  TKAEmployee.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAMoney.h"

@protocol TKAEmployeeProtocol;

@interface TKAEmployee : NSObject <TKAEmployeeProtocol>
@property(nonatomic, copy)      NSString    *name;
@property(nonatomic, assign)    NSUInteger  experience;
@property(nonatomic, assign)    NSUInteger  salary;
@property(nonatomic, readonly)  NSArray     *bigMoney;
@property(nonatomic, assign, readwrite, getter=isFree, setter=setIsFree:)   BOOL   free;

+ (instancetype)employeeWhithName:(NSString *)name;

- (NSString *)description;

- (void)addMoney:(TKAMoney *)money;
- (void)removeMoney:(TKAMoney *)money;
- (void)countMoney;

@end
