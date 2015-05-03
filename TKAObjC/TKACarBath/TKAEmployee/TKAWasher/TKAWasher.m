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
#pragma mark Acessors Methods

- (BOOL)isFree {
    if (nil == self.car && NO == [self haveMoney]) {
        return YES;
    }
    
    return NO;
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
    [result appendFormat:@" car: %@", self.car];
    
    return [[result copy] autorelease];
}

- (void)washCar:(TKACar *)car {
    self.free = NO;
    self.car = car;
    NSLog(@" WashingCar ");
    self.car.clean = YES;
    [self takeMoneyFromCar];
    self.car = nil;
}

- (void)takeMoneyFromCar {
    [self addMoney:[self.car money]];
    [self.car setMoney:nil];
}

#pragma mark -
#pragma mark Private Methods

@end
