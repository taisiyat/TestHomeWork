//
//  TKACreatureFemale.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKACreatureFemale.h"

@implementation TKACreatureFemale

#pragma mark -
#pragma mark Class Methods

+ (instancetype)creatureFemale {
    TKACreatureFemale *creature = [self object];

    return creature;
}

#pragma mark -
#pragma mark Initializations and Deallocations

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (void)giveBirth {
    NSLog(@"woman is giving birth");
}

- (void)performGenderSpecificOperation {
    [self giveBirth];
}

#pragma mark -
#pragma mark Private Methods

@end


