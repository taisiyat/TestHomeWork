//
//  TKAGCDObject.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.06.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAGCDObject.h"

@interface TKAGCDObject ();

@end

@implementation TKAGCDObject

#pragma mark -
#pragma mark Class Methods

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.queue = NULL;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

#pragma mark -
#pragma mark Private Methods

@end

