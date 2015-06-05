//
//  TKAEmployee.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"

@class TKAWasher;

@interface TKAEmployee ()
@property (nonatomic, assign)       id     processedObject;

@end

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
    @synchronized (self) {
        NSMutableString *result = [NSMutableString stringWithString:@" "];
        [result appendFormat:@"name = %@ ", self.name];
        [result appendFormat:@"state = %lu ", self.state];
        [result appendFormat:@"money = %lu", self.money];
        
        return [[result copy] autorelease];
    }
}

- (void)performWorkWithObject:(id)object {
    if (object) {
        @synchronized (self) {
            if (TKAEmployeeReadyToWork == self.state) {
                self.state = TKAEmployeePerformWork;
                self.processedObject = object;
                
                [self performSelectorInBackground:@selector(performWorkWithObjectInBackground:)
                                       withObject:object];
            }
        }
    }
}

- (void)performWorkWithObjectInBackground:(id)object {
    [self processObject:object];
    
    usleep(1000 * arc4random_uniform(10));
    
    [self performSelectorOnMainThread:@selector(workWithObjectOnMainThread:)
                               withObject:object
                            waitUntilDone:NO];
}

- (void)workWithObjectOnMainThread:(id)object {
    self.processedObject = nil;
    self.state = TKAEmployeeReadyForProcessing;
    
    [self workOnMainThread:object];
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
    [self takeMoney:[object giveAllMoney]];
}

- (NSUInteger)giveAllMoney {
    @synchronized (self) {
        NSUInteger cash = self.money;
        self.money = 0;
        
        return cash;
    }
}

- (void)takeMoney:(NSUInteger)cash {
    @synchronized (self) {
        self.money += cash;
    }
}

#pragma mark -
#pragma mark Overloaded Methods

- (SEL)selectorForState:(NSUInteger)state {
    switch (state) {
        case TKAEmployeeReadyToWork:
            return @selector(employeeDidBecomeReadyToWork:);
        case TKAEmployeeReadyForProcessing:
            return @selector(employeeDidBecomeReadyForProcessing:);
        case TKAEmployeePerformWork:
            return @selector(employeeDidPerformWork:);
        default:
            return [super selectorForState:state];
    }
}

#pragma mark -
#pragma mark TKAEmployeeObserver

- (void)employeeDidBecomeReadyForProcessing:(TKAEmployee *)employee {
        [self performWorkWithObject:employee];
}

@end


