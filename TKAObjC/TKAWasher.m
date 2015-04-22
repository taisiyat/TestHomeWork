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

- (void)washCar:(TKACar *)car {
    NSLog(@" WashingCar ");
}

- (id)washerIsFree {
    return (nil == [self car]) ? true : false;
}

- (void)takeMoney {
    [self addMoney:[[self car] money]];
    [[self car] setMoney:nil];
    [self setCar:nil];
}

#pragma mark -
#pragma mark Private Methods

@end
