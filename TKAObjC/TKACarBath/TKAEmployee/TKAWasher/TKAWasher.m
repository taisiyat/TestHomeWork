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
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.car = nil;
    self.delegate = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Acessors Methods

- (BOOL)isFree {
    if (nil == self.car && 0 == self.money) {
        return YES;
    }
    
    return NO;
}

- (void)setCar:(TKACar *)car {
    if (_car != car) {
        _car.delegate = nil;
        [_car release];
        
        _car = [car retain];
        _car.delegate = self;
    }
}

//- (void)setMoney:(NSUInteger)money {
////    BOOL shouldChange = YES;
//    id<TKAWasherDelegate> delegate = self.delegate;
//
//    if ([delegate washerShouldHaveMoney:self]) {
////        _money = money;
//        
//        [delegate washer:self shouldGiveMoney:self.money];
//    }
//}


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
    [self.car setClean:YES];

    NSLog(@" WashingCar ");
}

#pragma mark -
#pragma mark TKACarDelegate

- (void)car:(TKACar *)object shouldGiveMoney:(NSUInteger)money {
    [self takeMoneyFromSomeone:object];
    self.car = nil;
}

- (BOOL)carShouldBeClean:(TKACar *)object {
    if (YES == [object isClean]) {
        return YES;
    }
    
    return NO;
}

#pragma mark -
#pragma mark Private Methods

@end
