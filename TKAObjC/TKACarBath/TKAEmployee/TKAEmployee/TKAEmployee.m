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

+ (instancetype)employeeWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.mutableBigMoney = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        self.free = YES;
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
    [result appendFormat:@" name = %@ ", self.name];
    [result appendFormat:@" free = %hhd ", self.free];
    [result appendFormat:@" experience = %lu", self.experience];
    [result appendFormat:@" salary = %lu ", self.salary];
    [result appendFormat:@" money : %@", self.mutableBigMoney];
    
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
        sum += money.amount;
        [self.mutableBigMoney removeObject:money];
    }
    
    TKAMoney *sumMoney = [TKAMoney moneyWithAmount:sum];
    [self.mutableBigMoney addObject:sumMoney];
}

- (void)takeMoneyFromEmployee:(TKAEmployee *)employee {
    for (TKAMoney *money in employee.mutableBigMoney) {
        [self.mutableBigMoney addObject:money];
    }
    
    for (TKAMoney *money in employee.mutableBigMoney) {
        [employee.mutableBigMoney removeObject:money];
    }
}

- (void)giveMoneyToEmployee:(TKAEmployee *)employee {
    for (TKAMoney *money in self.mutableBigMoney) {
        [employee.mutableBigMoney addObject:money];
    }
    
    for (TKAMoney *money in self.mutableBigMoney) {
        [self.mutableBigMoney removeObject:money];
    }
}

#pragma mark -
#pragma mark Private Methods

@end

