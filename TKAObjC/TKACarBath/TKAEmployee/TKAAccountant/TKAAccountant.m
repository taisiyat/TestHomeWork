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

@synthesize delegatingObject = _delegatingObject;

@dynamic delegatingObjects;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableDelegatingObjects = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableDelegatingObjects = [NSMutableSet set];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setDelegatingObject:(TKAEmployee *)delegatingObject {
    _delegatingObject = nil;

    [self.mutableDelegatingObjects addObject:delegatingObject];
    delegatingObject.delegate = self;
}

#pragma mark -
#pragma mark Public Methods

- (void)countMoney {
    NSLog(@"Accountant count money.");
    self.finishWork = YES;
}

@end
