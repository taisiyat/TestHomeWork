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
    if (nil == self.car && 0 == self.money) {
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
    self.car = car;
    NSLog(@" WashingCar ");
    self.car.clean = YES;
//    [self takeMoneyFromCar];
    [self takeMoney:self.car.money FromSomeone:car];
    self.car = nil;
}

//- (void)takeMoneyFromCar {
//    self.money += self.car.money;
//    self.car.money = 0;
//}

#pragma mark -
#pragma mark Private Methods

@end
