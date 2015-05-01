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

- (void)washCar{
    NSLog(@" WashingCar ");
    [self.car setIsClean:YES];
}

- (void)takeMoneyFromCar {
    [self addMoney:[self.car money]];
    [self.car setMoney:nil];
}

- (void)addCar:(TKACar *)car {
    self.car = car;
    self.free = NO;
}

- (void)removeCar:(TKACar *)car {
    self.car = nil;
    self.free = YES;
}

#pragma mark -
#pragma mark Private Methods

@end
