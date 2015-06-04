//
//  TKASupervisor.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 28.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TKAEmployee.h"

@class TKAQueue;

@interface TKASupervisor : NSObject <TKAEmployeeObserver>

+ (instancetype)supervisor;

- (void)workWithObject:(id)object;

- (void)addProcessorObject:(id)object;
- (void)removeProcessorObject:(id)object;

@end

