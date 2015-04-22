//
//  TKARoom.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKAEmployee.h"

#import "NSObject+TKAExtension.h"

@interface TKARoom : NSObject
@property(nonatomic, copy) NSString *name;
@property(nonatomic, assign, readwrite) NSMutableArray *mutableEmployees;

+ (instancetype)room;
+ (instancetype)roomWithName:(NSString *)name;

- (void)output;

- (void)addEmployee:(TKAEmployee *)employee;
- (void)removeEmployee:(TKAEmployee *)employee;

@end
