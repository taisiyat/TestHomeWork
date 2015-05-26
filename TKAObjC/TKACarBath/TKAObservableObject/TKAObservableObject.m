//
//  TKAObservableObject.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAObservableObject.h"
#import "TKAAssignReference.h"

@interface TKAObservableObject ()
@property (nonatomic, retain)     NSMutableSet       *mutableObserverSet;

@end

@implementation TKAObservableObject

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
    //return [[self.mutableObserverSet copy] autorelease];
    NSMutableSet *observerSet = self.mutableObserverSet;
    NSMutableSet *result = [NSMutableSet setWithCapacity:[observerSet count]];
    for (TKAAssignReference *reference in observerSet) {
        [result addObject:reference.target];
    }
    
    return [[result copy] autorelease];
}

- (void)setState:(NSUInteger)state {
    if (state != _state) {
        @synchronized (self) {
            _state = state;

            [self performSelectorOnMainThread:@selector(notifyOfStateChangeOnMainThread) withObject:nil waitUntilDone:NO];
        }
    }
}

#pragma mark -
#pragma mark Pablic

- (void)addObserver:(id)observer {
    @synchronized (self) {
//        [self.mutableObserverSet addObject:[TKAAssignReference referenceWithTarget:observer]];
        [self.mutableObserverSet addObject:observer];

    }
}

- (void)removeObserver:(id)observer {
    @synchronized (self) {
//        [self.mutableObserverSet removeObject:[TKAAssignReference referenceWithTarget:observer]];
        [self.mutableObserverSet removeObject:observer];

    }
}

#pragma mark -
#pragma mark Private

- (SEL)selectorForState:(NSUInteger)state {
    [self doesNotRecognizeSelector:_cmd];
    
    return NULL;
}

- (void)notifyOfStateChangeOnMainThread {
    @synchronized (self) {
        [self notifyOfStateChangeWithSelector];
    }
}

- (void)notifyOfStateChangeWithSelector {
    @synchronized (self) {
        NSMutableSet *observerSet = self.mutableObserverSet;
        SEL selector = [self selectorForState:self.state];
        for (id observer in observerSet) {
            if ([observer respondsToSelector:selector]) {
               [observer performSelector:selector withObject:self];
            }
        }
    }
}

@end


