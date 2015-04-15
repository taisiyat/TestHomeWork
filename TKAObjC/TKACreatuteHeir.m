//
//  TKACretuteWithGender.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 15.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKACreatuteHeir.h"

@implementation TKACreatuteHeir
#pragma mark -
#pragma mark Class Methods

+ (instancetype)creature {
    return [[[self alloc] init] autorelease];
}

+ (instancetype)creatureWithGender:(TKAGender)gender {
    TKACreatuteHeir *creature = [[[self alloc] init] autorelease];
    creature.gender = gender;
    
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

- (void)giveBirth {
    NSLog(@"woman is giving birth");
}

- (void)checkGender {
    if (TKAMale == [self gender]) {
        [self fight];
    } else {
        [self giveBirth];
    }
}
#pragma mark -
#pragma mark Private Methods

@end
