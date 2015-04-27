//
//  TKABuilding.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TKAEmployee.h"
#import "TKARoom.h"

@interface TKABuilding : NSObject
@property(nonatomic, copy) NSString *address;
@property(nonatomic, readonly) NSArray *rooms;

+ (instancetype)buildingWhithAddress:(NSString *)address;

- (NSString *)description;

- (void)addRoom:(TKARoom *)room;
- (void)removeRoom:(TKARoom *)room;

@end