//
//  TKADelegate.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKADelegate.h"

@implementation TKADelegate

#pragma mark -
#pragma mark Class Methods

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.delegatingObject = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Acessors Methods
- (void)setDelegatingObject:(TKADelegatingObject *)delegatingObject {
    if (_delegatingObject != delegatingObject) {
        _delegatingObject.delegate = nil;
        [_delegatingObject release];
        
        _delegatingObject = [delegatingObject retain];
        _delegatingObject.delegate = self;
    }
}


#pragma mark -
#pragma mark Public Methods

#pragma mark -
#pragma mark TKADelegatingObjectDelegate

- (void)delagetingObject:(TKADelegatingObject *)object /*shouldChangeSomething:(NSUInteger)money */{
    //car give money to washer
}

- (BOOL)delegatingObjectShouldChangeSomething:(TKADelegatingObject *)object {
    return YES; //car is clean
}

@end
