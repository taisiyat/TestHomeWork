//
//  TKABuilding.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TKADirector.h"
#import "TKAEmployee.h"

@interface TKABuilding : NSObject
@property(nonatomic, copy) NSString *address;
@property(nonatomic, readonly) NSArray *rooms;//AdminRoom //CarBathBox

+ (instancetype)buildingWhithAddress:(NSString *)address;

- (void)output;

@end
