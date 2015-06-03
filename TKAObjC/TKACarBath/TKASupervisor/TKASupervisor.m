//
//  TKASupervisor.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 28.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKASupervisor.h"
#import "TKAQueue.h"
#import "TKAWasher.h"

@interface TKASupervisor ()
@property (nonatomic, retain)     TKAQueue        *processingQueue;
@property (nonatomic, retain)     NSMutableSet    *mutableProcessors;

@end

@implementation TKASupervisor

#pragma mark -
#pragma mark Class Method

+ (instancetype)supervisor {
    return [[[self alloc] init] autorelease];
}

#pragma mark -
#pragma mark Initializations Deallocations

- (void)dealloc {
    self.processingQueue = nil;
    self.mutableProcessors = nil;
    
    [super dealloc];
}

- (instancetype)init {
    [super init];
    if (self) {
        self.processingQueue = [TKAQueue queue];
        self.mutableProcessors = [NSMutableSet set];
    }
    
    return self;
}
#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:@" "];
    [result appendString:@"\n Supervisor : "];
    [result appendFormat:@"\n %@ ", self.processingQueue];
    [result appendFormat:@"\n %@ ", self.mutableProcessors];
    
    return [[result copy] autorelease];
}

- (void)processorObjects:(id)objects {
    @synchronized (self) {
        self.mutableProcessors = objects;
    }
}

- (void)addProcessorObject:(id)object {
    @synchronized (self) {
        [self.mutableProcessors addObject:object];
    }
}

- (void)removeProcessorObject:(id)object {
    @synchronized (self) {
        [self.mutableProcessors removeObject:object];
    }
}

- (void)workWithObject:(id)object {
    @synchronized (self) {
            [self.processingQueue addObject:object];
            TKAEmployee *processor = [self freeProcessor];
            if (processor) {
                [processor performWorkWithObject:[self.processingQueue nextObjectQueue]];
            }
        }
}

#pragma mark -
#pragma mark Privat Methods

- (id)freeProcessor {
    @synchronized (self) {
        for (TKAEmployee *employee in self.mutableProcessors) {
            if (TKAEmployeeReadyToWork == employee.state) {
                return employee;            }
        }
        
        return nil;
    }
}

#pragma mark -
#pragma mark TKAEmployeeObserver

- (void)employeeDidBecomeReadyToWork:(TKAEmployee *)employee {
    @ synchronized (employee) {
        if (TKAEmployeeReadyToWork == employee.state ) {
            id objectForProcessing = [self.processingQueue nextObjectQueue];
            if (objectForProcessing)  {
                [employee performWorkWithObject:objectForProcessing];
            }
        }
    }
}

@end
