//
//  TKAObservableObject.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TKAObservableObject : NSObject
@property (nonatomic, readonly)     NSSet       *observerSet;
@property (nonatomic, assign)       NSUInteger  state;

- (void)addObserver:(id)observer;
- (void)removeObserver:(id)observer;

- (SEL)selectorForState:(NSUInteger)state;

@end
