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

- (void)setState:(NSUInteger)state;
- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;
- (void)isObservedObject:(id)observer;

- (SEL)selectorForState:(NSUInteger)state;

@end

