//
//  TKADirector.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKADirector.h"

@implementation TKADirector

- (void)processObject:(TKAEmployee *)object {
        [self takeMoneyFromObject:object];
        NSLog(@"Director profit = %lu %@", self.money, object.name);
        object.state = TKAEmployeeReadyToWork;
}

- (void)performWorkWithObject:(id)object {
    @synchronized (self) {
        [self processObject:object];
    }
}

@end
