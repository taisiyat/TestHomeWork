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
        NSLog(@"Director profit = %lu", self.money);
}

//- (void)performWorkWithObject:(id)object {
//    [self processObject:object];
////    [self performSelectorInBackground:@selector(processObject:) withObject:object];
//}

- (void)workWithObjectOnMainThread:(id)object {
        [super workWithObjectOnMainThread:object];
        self.state = TKAEmployeeReadyToWork;
}

@end
