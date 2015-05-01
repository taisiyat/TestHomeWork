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

- (instancetype)init {
    self = [super init];
    if (self) {
        self.free = YES;
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
    [result appendFormat:@" car = %@", self.car];
    [result appendFormat:@" free = %u", self.free];
    
    return [[result copy] autorelease];
}

- (void)addCar:(TKACar *)car {
    self.car = car;
    self.free = NO;
}

- (void)removeCar:(TKACar *)car {
    self.car = nil;
    self.free = YES;
}

@end
