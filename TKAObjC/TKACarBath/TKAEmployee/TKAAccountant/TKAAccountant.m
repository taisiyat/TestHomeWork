//
//  TKAAccountant.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAAccountant.h"

@implementation TKAAccountant

#pragma mark -
#pragma mark Initializations and Deallocations

#pragma mark -
#pragma mark Accessors

#pragma mark -
#pragma mark Public Methods

- (void)processWithObject:(TKAEmployee *)object {
    [self takeMoneyFromObject:object];
    NSLog(@"Accountant count money.");
    self.state = TKAEmployeeReadyToProcessing;
}

@end
