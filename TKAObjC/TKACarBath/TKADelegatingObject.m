//
//  TKADelegatingObject.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKADelegatingObject.h"

@implementation TKADelegatingObject

- (void)setMoney:(NSUInteger)money {
    BOOL shouldChange = YES;
    id<TKADellegatingObjectDelegate> delegate = self.delegate;

    if ([delegate respondsToSelector:@selector(delegatingObjectShouldChangeSomething:)]) {
        shouldChange = [delegate delegatingObjectShouldChangeSomething:self];
    }
    
    if (shouldChange) {
         [delegate delagetingObject:self];
    }
}

@end
