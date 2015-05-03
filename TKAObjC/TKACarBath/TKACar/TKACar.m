//
//  TKACar.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKACar.h"

@implementation TKACar

#pragma mark -
#pragma mark Class Methods

+ (instancetype)carWithNumber:(NSString *)number
                  moneyAmount:(NSUInteger)moneyAmount
{
    TKACar *car = [TKACar object];
    car.number = number;
    car.clean = NO;
    car.money = [TKAMoney moneyWithAmount:moneyAmount];
    
    return car;
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.number = nil;
    self.money = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:@" "];
    [result appendFormat:@" Car number = %@", self.number];
    [result appendFormat:@" condition = %u", self.clean];
    [result appendFormat:@" money : %lu", self.money.amount];
    
    return [[result copy] autorelease];
}

#pragma mark -
#pragma mark Private Methods

@end
