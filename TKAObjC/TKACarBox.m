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

#pragma mark -
#pragma mark Public Methods

- (void)output {
    NSLog(@" car = %@ ", self.car);
}

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
    [result appendString:@"\n"];
    [result appendFormat:@" car = %@\n", self.car];
    [result appendFormat:@" free = %u\n", self.free];
    
    return [[result copy] autorelease];
}


- (void)addCar:(TKACar *)car {
    self.car = car;
    self.free = false;
}

- (void)removeCar:(TKACar *)car {
    self.car = nil;
    self.free = true;
}

@end
