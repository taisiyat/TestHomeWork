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

- (void)dealloc {
    self.delegatingObject = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Accessors

- (void)setDelegatingObject:(TKAWasher *)delegatingObject {
    if (_delegatingObject != delegatingObject) {
        
        _delegatingObject.delegate = nil;
        [_delegatingObject release];
        
        _delegatingObject = [delegatingObject retain];
        _delegatingObject.delegate = self;
    }
}

#pragma mark -
#pragma mark TKAWasherDelegate

- (void)washer:(TKAWasher *)object shouldGiveMoney:(NSUInteger)money {
    [self takeMoneyFromSomeone:object];
    object.free = YES;
}

- (BOOL)washerShouldFinishWork:(TKAWasher *)object {
    return (object.finishWork);
}

@end
