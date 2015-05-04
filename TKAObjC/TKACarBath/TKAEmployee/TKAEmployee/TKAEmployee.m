//
//  TKAEmployee.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"

@class TKACar;

@interface TKAEmployee ()
//@property (nonatomic, readwrite)  NSMutableArray *mutableBigMoney;

@end

@implementation TKAEmployee

//@dynamic bigMoney;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)employeeWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
//    self.mutableBigMoney = nil;
    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        self.free = YES;
//        self.mutableBigMoney = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

//- (NSArray *)bigMoney {
//    return [[self.mutableBigMoney copy] autorelease];
//}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:@" "];
    [result appendFormat:@"name = %@ ", self.name];
    [result appendFormat:@"free = %hhd ", self.free];
//    [result appendFormat:@"experience = %lu", self.experience];
//    [result appendFormat:@"salary = %lu ", self.salary];
    [result appendFormat:@"money : %lu", self.money];
    return [[result copy] autorelease];
}

- (BOOL)haveMoney {
    
    return self.money;
}

- (void)countMoney {
    self.free = NO;
    NSLog(@"count money");
    self.free = YES;
}

//- (void)takeMoney:(NSUInteger)money FromSomeone:(id<TKATransferMoneyProtocol>)object {
//    NSUInteger moneyObject = [object money];
//    if (moneyObject >= money) {
//        self.money += money;
//        [object money] = moneyObject - money;
//    }
//}
- (void)takeMoneyFromSomeone:(TKAEmployee *)employee {
    self.money += employee.money;
    employee.money = 0;
//    for (TKAMoney *money in employee.mutableBigMoney) {
//        [self.mutableBigMoney addObject:money];
//    }
//    
//    for (TKAMoney *money in employee.mutableBigMoney) {
//        [employee.mutableBigMoney removeObject:money];
//    }
}

//- (void)giveMoney:(NSUInteger)money ToSomeone:(id<TKATransferMoneyProtocol>)object {
//    if (self.money >= money) {
//        object.money += money;
//        self.money -= money;
//    }
//}

- (void)giveMoneyToSomeone:(TKAEmployee *)employee {
    employee.money += self.money;
    self.money = 0;

//    for (TKAMoney *money in self.mutableBigMoney) {
//        [employee.mutableBigMoney addObject:money];
//    }
//    
//    for (TKAMoney *money in self.mutableBigMoney) {
//        [self.mutableBigMoney removeObject:money];
//    }
}

#pragma mark -
#pragma mark Private Methods

@end


