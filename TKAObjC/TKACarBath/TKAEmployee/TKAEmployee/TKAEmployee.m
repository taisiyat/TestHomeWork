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
    @synchronized (object) {
        self.state = TKAEmployeePerformWork;
        [self processWithObject:object];
//        [self performSelectorInBackground:@selector(processWithObject:) withObject:object];
        self.state = TKAEmployeeReadyToWork;
    }
}

- (void)processWithObject:(id)object {
    [self doesNotRecognizeSelector:_cmd];
}

#pragma mark -
#pragma mark TKATransferMoneyProtocol

- (void)takeMoneyFromObject:(id<TKATransferMoneyProtocol>)object {
    self.money += object.money;
    object.money = 0;
}

#pragma mark -
#pragma mark Overloaded Methods

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case TKAEmployeeReadyToWork:
            return @selector(employeeDidBecomeReadyToWork:);
        case TKAEmployeeReadyToProcessing:
            return @selector(employeeDidBecomeReadyToProcessing:);
        default:
            return @selector(employeeDidPerformWork:);
    }
}

#pragma mark -
#pragma mark TKAEmployeeObserver

- (void)employeeDidBecomeReadyToProcessing:(TKAEmployee *)employee{
//        NSLog(@"%@ ready to processing", employee.name);
        [self performWorkWithObject:employee];
//        [self performSelectorInBackground:@selector(performWorkWithObject:) withObject:employee];
}

@end


