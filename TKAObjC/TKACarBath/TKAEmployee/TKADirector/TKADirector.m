//
//  TKADirector.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKADirector.h"

@implementation TKADirector

- (void)processWithObject:(TKAEmployee *)object {
    @synchronized (self) {
        [self takeMoneyFromObject:object];
    //    self.money *= 0.5;
        //usleep(100*arc4random_uniform(10));
        usleep(100);
        NSLog(@"Director profit.");
    }
}

@end
