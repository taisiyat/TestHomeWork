//
//  TKAObservableObject.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAObservableObject.h"
#import "TKAAssignReference.h"
#import "TKACarBathTest.h"

@interface TKAObservableObject ()
@property (nonatomic, retain)     NSMutableSet       *mutableObserverSet;

@end

@implementation TKAObservableObject

@synthesize state = _state;
@dynamic observerSet;

#pragma mark -
#pragma mark Initializations and Dealocations

- (void)dealloc {
    self.mutableObserverSet = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableObserverSet = [NSMutableSet set];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accesssors

- (NSSet *)observerSet {
    @synchronized (self) {
        NSMutableSet *observerSet = self.mutableObserverSet;
        NSMutableSet *result = [NSMutableSet setWithCapacity:[observerSet count]];
        for (TKAReference *reference in observerSet) {
            [result addObject:reference.target];
        }
        
        return [[result copy] autorelease];
    }
}

- (void)setState:(NSUInteger)state {
    @synchronized (self) {
        if (state != _state) {
            _state = state;
            
            void(^blockNotify)() = ^() {
                [self notifyOfStateChangeWithSelector];
            };
            
            TKAPerformBlockOnMainQueue(blockNotify);
        }
    }
}

- (NSUInteger)state {
    @synchronized (self) {
        return _state;
    }
}

#pragma mark -
#pragma mark Pablic

- (void)addObserver:(id)observer {
    @synchronized (self) {
        [self.mutableObserverSet addObject:[TKAAssignReference referenceWithTarget:observer]];
    }
}

- (void)removeObserver:(id)observer {
    @synchronized (self) {
        [self.mutableObserverSet removeObject:[TKAAssignReference referenceWithTarget:observer]];
    }
}

#pragma mark -
#pragma mark Private

- (SEL)selectorForState:(NSUInteger)state {
    return NULL;
}

- (void)notifyOfStateChangeWithSelector {
    NSMutableSet *observerSet = self.mutableObserverSet;
    SEL selector = [self selectorForState:_state];
    for (TKAReference *reference in observerSet) {
        if ([reference.target respondsToSelector:selector]) {
           [reference.target performSelector:selector withObject:self];
        }
    }
}

@end


