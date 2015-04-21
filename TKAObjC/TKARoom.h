//
//  TKARoom.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NSObject+TKAExtension.h"

@interface TKARoom : NSObject
@property(nonatomic, assign, readwrite) NSMutableArray *mutableEmployees;

+ (instancetype)room;
- (void)output;

@end
