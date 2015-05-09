//
//  TKARoom.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"

#import "NSObject+TKAExtension.h"

@interface TKARoom : NSObject
@property (nonatomic, copy)               NSString        *name;
@property (nonatomic, readonly)           NSArray         *employees;
@property (nonatomic, assign, getter=isFree)    BOOL      free;

+ (instancetype)room;
+ (instancetype)roomWithName:(NSString *)name;

- (void)addEmployee:(TKAEmployee *)employee;
- (void)removeEmployee:(TKAEmployee *)employee;

@end
