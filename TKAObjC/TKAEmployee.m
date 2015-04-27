//
//  TKAEmployee.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"

@interface TKAEmployee ()
@property(nonatomic, readwrite)  NSMutableArray *mutableBigMoney;

@end

@implementation TKAEmployee

@dynamic bigMoney;

#pragma mark -
#pragma mark Class Methods

+(instancetype)employeeWithName:(NSString *)name {
        TKAEmployee *employee = [TKAEmployee object];
        employee.name = name;
    
    return employee;
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.mutableBigMoney = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableBigMoney = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

- (NSArray *)bigMoney {
    return [[self.mutableBigMoney copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
    [result appendString:@"\n"];
    [result appendFormat:@" Name: %@\n", self.name];
    [result appendFormat:@" free = %hhd", self.free];
    [result appendFormat:@" experience = %lu", self.experience];
    [result appendFormat:@" salary = %lu", self.salary];
    [result appendFormat:@" money: %@\n", self.mutableBigMoney];
    
    return [[result copy] autorelease];
}

- (void)addMoney:(TKAMoney *)money {
    [self.mutableBigMoney addObject:money];
}

- (void)removeMoney:(TKAMoney *)money {
    [self.mutableBigMoney removeObject:money];
}

-(void)countMoney {
    NSUInteger sum = 0;
    for (TKAMoney *money in self.mutableBigMoney) {
        sum += [money amount];
        [self.mutableBigMoney removeObject:money];
    }
    
    TKAMoney *sumMoney = [TKAMoney moneyWithAmount:sum];
    [self.mutableBigMoney addObject:sumMoney];
}

#pragma mark -
#pragma mark Private Methods

@end


