//
//  TKAWasher.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAWasher.h"

@implementation TKAWasher

#pragma mark -
#pragma mark Initializations and Deallocations

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (void)processObject:(TKACar *)object {
//    @synchronized (self) {
        usleep(1000 * arc4random_uniform(10));
        NSLog(@"%@ wash %@ ", self.name, [object description]);
        object.clean = YES;
        [self takeMoneyFromObject:object];
//    }
}

- (void)workOnMainThread:(id)object {

}

@end
