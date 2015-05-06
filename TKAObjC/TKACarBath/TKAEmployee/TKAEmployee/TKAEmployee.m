//
//  TKAEmployee.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"

@implementation TKAEmployee

@synthesize money = _money;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)employeeWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
 
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        self.free = YES;
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

- (Class)classEmployee {
    return [self class];
}

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

- (void)countMoney {
    self.free = NO;
    NSLog(@"count money");
    self.free = YES;
}

//- (void)takeMoney:(NSUInteger)money FromSomeone:(id<TKATransferMoneyProtocol>)object {
//    if (object.money >= money) {
//        self.money += money;
//        object.money -= money;
//    }
//}
- (void)takeMoneyFromSomeone:(id<TKATransferMoneyProtocol>)object {
    self.money += object.money;
    object.money = 0;
}

//- (void)takeMoneyFromSomeone:(TKAEmployee *)employee {
//    self.money += employee.money;
//    employee.money = 0;
//}

//- (void)giveMoney:(NSUInteger)money ToSomeone:(id<TKATransferMoneyProtocol>)object {
////    if (self.money >= money) {
////        object.money += money;
////        self.money -= money;
////    }
//    object.money += self.money;
//    self.money = 0;
//}

//- (void)giveMoneyToSomeone:(TKAEmployee *)employee {
//    employee.money += self.money;
//    self.money = 0;
//}

#pragma mark -
#pragma mark Private Methods

@end


