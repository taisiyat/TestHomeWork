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
    self.delegatingObject = nil;
 
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

- (void)setDelegatingObject:(TKAEmployee *)delegatingObject {
    if (_delegatingObject != delegatingObject) {
        
        _delegatingObject.delegate = nil;
        [_delegatingObject release];
        
        _delegatingObject = [delegatingObject retain];
        _delegatingObject.delegate = self;
    }
}

- (void)setFinishWork:(BOOL)finishWork {
    _finishWork = finishWork;
    id<TKAEmployeeDelegate> delegate = self.delegate;
    
    if ([delegate employeeShouldFinishWork:self]) {
        [delegate employee:self shouldGiveMoney:self.money];
    }
}

- (void)setMoney:(NSUInteger)money {
    _money = money;
    
    if ([TKAWasher class] == [self class]) {
        self.state = (0 == money) ? TKAReadyToWash : TKAPerformWork;
    } else {
        self.state = (0 == money) ? TKAReadyToWork : TKAPerformWork;
    }
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

- (void)takeMoneyFromSomeone:(id<TKATransferMoneyProtocol>)object {
    self.money += object.money;
    object.money = 0;
}

#pragma mark -
#pragma mark TKAEmployeeDelegate

- (void)employee:(TKAEmployee *)employee shouldGiveMoney:(NSUInteger)money {
    [self takeMoneyFromSomeone:employee];
    employee.free = YES;
}

- (BOOL)employeeShouldFinishWork:(TKAEmployee *)employee {
    return (employee.finishWork);
}

#pragma mark -
#pragma mark Overloaded Methods

- (SEL)selectorForState:(NSUInteger)state {
    switch (state)
    {
        case TKAReadyToWash:
            return @selector(employeeBecomeReadyToWash:);
            
        case TKAReadyToWork:
            return @selector(employeeBecomeReadyToWork:);
        
        default:
            return @selector(employeePerformWorkNow:);
    }
}

@end


