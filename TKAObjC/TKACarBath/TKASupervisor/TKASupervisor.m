//
//  TKASupervisor.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 28.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKASupervisor.h"
#import "TKAQueue.h"

@interface TKASupervisor ()
@property (nonatomic, assign)     TKAQueue          *objectsInQueue;
@property (nonatomic, assign)     NSMutableArray    *mutableProcessors;

@end

@implementation TKASupervisor

@dynamic objectsForProcessing;
@dynamic processors;

#pragma mark -
#pragma mark Class Method

+ (instancetype)supervisor {
    return [[[self alloc] init] autorelease];
}

#pragma mark -
#pragma mark Initializations Deallocations

- (void)dealloc {
    self.objectsInQueue = nil;
    self.mutableProcessors = nil;
    
    [super dealloc];
}

- (instancetype)init {
    [super init];
    if (self) {
        self.objectsInQueue = [TKAQueue queue];
        self.mutableProcessors = [NSMutableArray array];
    }
    
    return self;
}
#pragma mark -
#pragma mark Acessors Methods

- (NSArray *)objectsForProcessing {
    @synchronized (self) {
        return [[self.objectsInQueue copy] autorelease];
    }
}

- (NSArray *)processors {
    @synchronized (self) {
        return [[self.mutableProcessors copy] autorelease];
    }
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:@" "];
    [result appendString:@"\n Supervisor : "];
    [result appendFormat:@"\n  : %@ ", self.objectsInQueue];
    [result appendFormat:@"\n  : %@ ", self.mutableProcessors];
    
    return [[result copy] autorelease];
}

- (void)addProcessorObjects:(id)objects {
    @synchronized (self) {
        self.mutableProcessors = objects;
    }
}

- (void)workWithObject:(id)object {
    if (object) {
        @synchronized (self) {
            TKAEmployee *processor = [self freeProcessor];
            if (processor) {
                [processor performWorkWithObject:object];
            } else {
                [self.objectsInQueue addObject:object];
            }
        }
    }
}

- (id)freeProcessor {
    @synchronized (self) {
        NSMutableSet *freeEmployees = [NSMutableSet set];
        for (TKAEmployee *employee in self.mutableProcessors) {
            if (TKAEmployeeReadyToWork == employee.state) {
                [freeEmployees addObject:employee];
            }
        }
        
        return [freeEmployees anyObject];
    }
}

#pragma mark -
#pragma mark TKAEmployeeObserver

- (void)employeeDidBecomeReadyToWork:(TKAEmployee *)employee {
    //    NSLog(@"%@ ready to work", employee.name);
    //[employee performWorkWithObject:[self.objectsForProcessing nextObjectQueue]];
    @ synchronized (self) {
        id objectForProcessing = [self.objectsInQueue nextObjectQueue];
        if (objectForProcessing)  {
            [employee performWorkWithObject:objectForProcessing];
        }
    }
}

- (void)employeeDidPerformWork:(TKAEmployee *)employee {
    //    NSLog(@"%@ perform work", employee.name);
}

- (void)employeeDidBecomeReadyToProcessing:(TKAEmployee *)employee{
   // [self performWorkWithObject:employee];
    [self workWithObject:employee];
}

@end
