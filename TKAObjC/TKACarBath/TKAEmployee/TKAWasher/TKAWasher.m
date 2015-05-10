//
//  TKAWasher.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAWasher.h"

@implementation TKAWasher

@synthesize money = _money;

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.car = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Acessors Methods

- (BOOL)isFree {
    return (nil == self.car && 0 == self.money);
}

//- (void)setMoney:(NSUInteger)money {
//    if (money != _money) {
//        _money = money;
//        
//        self.observableState = (0 == money && nil == self.car) ? TKAReadyToWork : TKAPerformWork;
//    }
//}

- (void)setCar:(TKACar *)car {
    if (_car != car) {
        _car.delegate = nil;
        [_car release];
        
        _car = [car retain];
        _car.delegate = self;
        self.observableState = (0 == self.money && nil == car) ? TKAReadyToWork : TKAPerformWork;
    }
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
    [result appendFormat:@" car : %@", self.car];
    
    return [[result copy] autorelease];
}

- (void)washCar:(TKACar *)car {
    self.car = car;
    NSLog(@"Washer wash car.");
    [self.car setClean:YES];
}

#pragma mark -
#pragma mark TKACarDelegate

- (void)car:(TKACar *)object shouldGiveMoney:(NSUInteger)money {
    [self takeMoneyFromSomeone:object];
    self.car = nil;
    self.finishWork = YES;
}

- (BOOL)carShouldBeClean:(TKACar *)object {
    return object.clean;
}

#pragma mark -
#pragma mark Private Methods

@end
