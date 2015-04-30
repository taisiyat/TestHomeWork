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
@property(nonatomic, copy)      NSString    *name;
@property(nonatomic, retain, readwrite)     NSMutableArray  *mutableEmployees;
@property(nonatomic, assign, readwrite, getter=isFree, setter=setIsFree:)   BOOL    free;

+ (instancetype)room;
+ (instancetype)roomWithName:(NSString *)name;

- (NSString *)description;

//- (void)addEmployee:(TKAEmployee *)employee;
//- (void)removeEmployee:(TKAEmployee *)employee;

@end
