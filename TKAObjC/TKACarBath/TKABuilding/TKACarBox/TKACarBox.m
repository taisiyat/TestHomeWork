//
//  TKACarBox.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKACarBox.h"

@implementation TKACarBox

#pragma mark -
#pragma mark Class Methods

#pragma mark -
#pragma mark Initializations and Deallocations

#pragma mark -
#pragma mark Acessors Methods

- (BOOL)isFree {
    if ([super isFree] && nil == self.car) {
        
        return YES;
    }
    
    return NO;
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
    [result appendFormat:@" car = %@", self.car];
    [result appendFormat:@" free = %u", [self isFree]];
    
    return [[result copy] autorelease];
}

@end
