//
//  TKAObservableObject.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAObservableObject.h"

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
    return [[self.mutableObserverSet copy] autorelease];
}

- (void)setState:(NSUInteger)state {
    if (state != _state) {
        _state = state;
//        [self notifyOfStateChangeWithSelector:[self selectorForState:state]];
        [self notifyOfStateChangeWithSelector];
//        [self performSelectorOnMainThread:@selector(notifyOfStateChangeWithSelector)
//                               withObject:nil
//                            waitUntilDone:NO];
    }
}

#pragma mark -
#pragma mark Pablic

- (void)addObserver:(id)observer {
    [self.mutableObserverSet addObject:observer];
}

- (void)removeObserver:(id)observer {
    [self.mutableObserverSet removeObject:observer];
}

- (BOOL)isObservedObject:(id)observer {
    return [self.mutableObserverSet containsObject:observer];
}

#pragma mark -
#pragma mark Private

- (SEL)selectorForState:(NSUInteger)state {
    [self doesNotRecognizeSelector:_cmd];
    
    return NULL;
}

- (void)notifyOfStateChangeWithSelector {
        NSMutableSet *observerSet = self.mutableObserverSet;
        for (id observer in observerSet) {
            if ([observer respondsToSelector:[self selectorForState:self.state]]) {
               [observer performSelector:[self selectorForState:self.state] withObject:self];
            }
    }
}
//- (void)notifyOfStateChangeWithSelector:(SEL)selector {
//    NSMutableSet *observerSet = self.mutableObserverSet;
//    for (id observer in observerSet) {
//        if ([observer respondsToSelector:selector]) {
//            [observer performSelector:selector withObject:self];
//        }
//    }
//}
@end


