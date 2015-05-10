//
//  TKAAccountant.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAAccountant.h"

@class TKAAccountant;

@interface TKAAccountant ()
@property (nonatomic, assign) NSMutableSet *mutableDelegatingObjects;

@end

@implementation TKAAccountant

@dynamic delegatingObjects;

#pragma mark -
#pragma mark Initializations and Deallocations

#pragma mark -
#pragma mark Accessors

#pragma mark -
#pragma mark Public Methods

- (void)countMoney {
    NSLog(@"Accountant count money.");
    self.finishWork = YES;
}

@end
