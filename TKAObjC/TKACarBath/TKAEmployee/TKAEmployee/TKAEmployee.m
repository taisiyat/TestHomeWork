//
//  TKAEmployee.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"

@class TKAWasher;

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
    self.delegate = nil;
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

- (void)setFinishWork:(BOOL)finishWork {
    _finishWork = finishWork;
       
    if (finishWork) {
        [self.delegate employeeShouldFinishWork:self];
    }
}

- (void)setMoney:(NSUInteger)money {
    _money = money;
        self.state = (0 == money) ? TKAEmployeeReadyToWork : TKAEmployeePerformWork;
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:@" "];
    [result appendFormat:@"name = %@ ", self.name];
//    [result appendFormat:@"free = %hhd ", self.free];
//    [result appendFormat:@"experience = %lu", self.experience];
//    [result appendFormat:@"salary = %lu ", self.salary];
    [result appendFormat:@"money = %lu", self.money];
    
    return [[result copy] autorelease];
}

- (void)performWorkWithObject:(id)object {
//    self.state = TKAEmployeePerformWork;
    [self processWithObject:object];
//    self.state = TKAEmployeeReadyToWork;
}

#pragma mark -
#pragma mark TKATransferMoneyProtocol

- (void)takeMoneyFromObject:(id<TKATransferMoneyProtocol>)object {
    self.money += object.money;
    object.money = 0;
}

#pragma mark -
#pragma mark TKAEmployeeDelegate

- (void)employeeShouldFinishWork:(TKAEmployee *)employee {
    [self performWorkWithObject:employee];
}

#pragma mark -
#pragma mark Overloaded Methods

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case TKAEmployeeReadyToWork:
            return @selector(employeeDidBecomeReadyToWork:);
        default:
            return @selector(employeeDidPerformWork:);
    }
}

@end


