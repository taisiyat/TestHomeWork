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
//    [result appendFormat:@"experience = %lu", self.experience];
//    [result appendFormat:@"salary = %lu ", self.salary];
    [result appendFormat:@"state = %lu ", self.state];
    [result appendFormat:@"money = %lu", self.money];
    
    return [[result copy] autorelease];
}

- (void)performWorkWithObject:(id)object {
    @synchronized (self) {
        if (object) {
            self.state = TKAEmployeePerformWork;
            [self performWorkInBackgroundWithObject:object];
        }
    }
}

- (void)performWorkInBackgroundWithObject:(id)object {
    @synchronized (self) {
        self.processedObject = object;
        [self performSelectorInBackground:@selector(processObject:) withObject:object];
        self.processedObject = nil;
        [self performSelectorOnMainThread:@selector(workWithObjectOnMainThread:)
                               withObject:object
                            waitUntilDone:NO];
    }
}

- (void)workWithObjectOnMainThread:(id)object{
    @synchronized (self) {
         self.state = TKAEmployeeReadyForProcessing;
        [self workOnMainThread:object];
    }
}

- (void)workOnMainThread:(TKAEmployee *)object {
    object.state = TKAEmployeeReadyToWork;
}

- (void)processObject:(id)object {
    [self doesNotRecognizeSelector:_cmd];
}

#pragma mark -
#pragma mark TKATransferMoneyProtocol

- (void)takeMoneyFromObject:(id<TKATransferMoneyProtocol>)object {
    @synchronized (self) {
        self.money += object.money;
        object.money = 0;
    }
}

#pragma mark -
#pragma mark Overloaded Methods

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case TKAEmployeeReadyToWork:
            return @selector(employeeDidBecomeReadyToWork:);
        case TKAEmployeeReadyForProcessing:
            return @selector(employeeDidBecomeReadyToProcessing:);
        case TKAEmployeePerformWork:
            return @selector(employeeDidPerformWork:);
        default:
            return NULL;
    }
}

#pragma mark -
#pragma mark TKAEmployeeObserver

- (void)employeeDidBecomeReadyToProcessing:(TKAEmployee *)employee{
//        NSLog(@"%@ ready to processing", employee.name);
     @synchronized (self) {
        [self performWorkWithObject:employee];
    }
}

@end


