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
    
    [super dealloc];
}

#pragma mark -
#pragma mark Acessors Methods

- (BOOL)isFree {
    return (nil == self.car && 0 == self.money);
}

- (void)setCar:(TKACar *)car {
    if (_car != car) {
        
        _car.delegate = nil;
        [_car release];
        
        _car = [car retain];
        _car.delegate = self;
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
    NSLog(@"%@ wash car %@ with money %lu.", self.name, self.car.number, self.car.money);
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

@end
