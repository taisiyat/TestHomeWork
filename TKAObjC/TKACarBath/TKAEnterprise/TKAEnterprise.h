//
//  TKAEnterprise.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAMoney.h"
#import "TKABuilding.h"
#import "TKADirector.h"
#import "TKACar.h"

@interface TKAEnterprise : NSObject
@property(nonatomic, copy)      NSString        *name;
@property(nonatomic, retain)    TKABuilding     *building;
@property(nonatomic, readonly)  NSArray         *employees;

+ (instancetype)enterpriseWhithName:(NSString *)name;
- (void)prepare;

- (void)addEmployee:(TKAEmployee *)emploeey;
- (void)removeEmployee:(TKAEmployee *)emploeey;

- (id)carArrivesWithNumber:(NSString *)number amount:(NSUInteger)amount;

- (id)freeEmployeeOfClass:(Class)classPosition;
//- (id)foundFreeCarBox;

- (void)performWork;

@end
