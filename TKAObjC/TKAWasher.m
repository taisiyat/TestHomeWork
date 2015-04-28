//
//  TKAWasher.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAWasher.h"

@implementation TKAWasher

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
    [result appendFormat:@" car: %@\n", self.car];
    
    return [[result copy] autorelease];
}

- (void)washCar:(TKACar *)car {
    NSLog(@" WashingCar ");
    [self.car setIsClean:YES];
}

- (void)takeMoney {
    //[self.bigMoney addObject:[self.car money]];
    [self addMoney:[self.car money]];
    [self.car setMoney:nil];
    self.car = nil;
}

#pragma mark -
#pragma mark Private Methods

@end
