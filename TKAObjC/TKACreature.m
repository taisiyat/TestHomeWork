//
//  TKACreature.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 15.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKACreature.h"

@implementation TKACreature


#pragma mark -
#pragma mark Class Methods

+ (instancetype)creature {
    return [[[self alloc] init] autorelease];
}

+ (instancetype)creatureWithName:(NSString *)name {
    TKACreature *creature = [[[self alloc] init] autorelease];
    creature.name = name;
    
    return creature;
}

#pragma mark -
#pragma mark Initializations and Deallocations

-(void)dealloc {
    self.name = nil;
    [super dealloc];
}

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

- (void)sayHi {
    [self sayWithString];
}

- (void)performGenderSpecificOperation {
    
}

- (void)output {
    NSLog(@"%@", [[self name] description]);
//    NSLog(@" name = %@", [self name]);
//    NSLog(@" weight = %lu", [self weight]);
//    NSLog(@" age = %lu", [self age]);
//    NSLog(@" children = %@", [self children]);
}

#pragma mark -
#pragma mark Private Methods

- (void)sayWithString {
    NSLog(@"HI! My name is %@", [self name]);
}

@end

