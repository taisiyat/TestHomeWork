//
//  TKAEmployee.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"
#import "NSObject+TKAExtension.h"

@interface TKAEmployee ()
@property(nonatomic, readwrite)  NSMutableArray *mutableBigMoney;

@end

@implementation TKAEmployee

@dynamic bigMoney;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)employeeWithName:(NSString *)name {
//    TKAEmployee *employee = [TKAEmployee object];
//    employee.name = name;
//    employee.free = YES;
    
    return [[[self alloc] initWithName:name] autorelease];//employee;
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
//    [result appendString:@"\n"];
    [result appendFormat:@" name = %@ ", self.name];
    [result appendFormat:@" free = %hhd \n", self.free];
    [result appendFormat:@" experience = %lu", self.experience];
    [result appendFormat:@" salary = %lu \n", self.salary];
    [result appendFormat:@" money : %@\n", self.mutableBigMoney];
    
    return [[result copy] autorelease];
}

- (void)addMoney:(TKAMoney *)money {
    [self.mutableBigMoney addObject:money];
}
//
//- (void)removeMoney:(TKAMoney *)money {
//    [self.mutableBigMoney removeObject:money];
//}

-(void)countMoney {
    NSUInteger sum = 0;
    for (TKAMoney *money in self.mutableBigMoney) {
        sum += money.amount;
        [self.mutableBigMoney removeObject:money];
    }
    
    TKAMoney *sumMoney = [TKAMoney moneyWithAmount:sum];
    [self.mutableBigMoney addObject:sumMoney];
}

//- (void)moneyFlowEmployee:(TKAEmployee *)employeeGive employee:(TKAEmployee *)employeeTake {
//    for (TKAMoney *money in [employeeGive bigMoney]) {
//        [employeeTake addMoney:money];
//        [money setResponsible:employeeTake];
//    }
//    
//    for (TKAMoney *money in [employeeGive bigMoney]) {
//        [employeeTake removeMoney:money];
//    }
//}

- (void)takeMoney:(TKAEmployee *)employee {
    for (TKAMoney *money in employee.mutableBigMoney) {
        [self.mutableBigMoney addObject:money];
    }
    
    for (TKAMoney *money in employee.mutableBigMoney) {
        [self.mutableBigMoney removeObject:money];
    }
    
}

- (void)giveMoney:(TKAEmployee *)employee {
    for (TKAMoney *money in self.mutableBigMoney) {
        [employee.mutableBigMoney addObject:money];
    }
    
    for (TKAMoney *money in self.mutableBigMoney) {
        [employee.mutableBigMoney removeObject:money];
    }
}


#pragma mark -
#pragma mark Private Methods

@end


