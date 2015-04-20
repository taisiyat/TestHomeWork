//
//  TKACar.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKACar.h"

@interface TKACar ()

@end

@implementation TKACar

#pragma mark -
#pragma mark Class Methods

+ (instancetype)carWithStateNumber:(NSString *)number {
                           // amount:(NSUInteger)amount {
    TKACar *car = [self object];
    car.number = number;
    car.condition = TKADirtyCar;
//    [car.money moneyWhithAmount:amount responsible:car];
                 
    return car;
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.number = nil;
    self.moneyCar = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
//        self.money = [TKAMoney object];
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (void)description {
    NSLog(@" number = %@", [self number]);
    NSLog(@" condition = %u", [self condition]);
    NSLog(@" money = %lu", [[self money] amount]);
   
}

#pragma mark -
#pragma mark Private Methods

@end
