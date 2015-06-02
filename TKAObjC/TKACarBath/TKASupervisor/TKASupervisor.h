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
@property (nonatomic, readonly)     TKAQueue    *objectsForProcessing;
@property (nonatomic, readonly)     NSArray     *processors;

+ (instancetype)supervisor;

- (void)workWithObject:(id)object;
- (id)freeProcessor;
- (void)addProcessorObjects:(id)objects;

@end

