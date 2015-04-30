//
//  TKACreatureMale.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKACreatureMale.h"

@implementation TKACreatureMale
#pragma mark -
#pragma mark Class Methods

+ (instancetype)creatureMale {
    TKACreatureMale *creature = [self object];
    
    return creature;
}

#pragma mark -
#pragma mark Initializations and Deallocations

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (void)fight {
    NSLog(@"man goes to war");
}

- (void)performGenderSpecificOperation {
    [self fight];
}

#pragma mark -
#pragma mark Private Methods

@end
