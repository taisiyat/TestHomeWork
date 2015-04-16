//
//  TKACreature.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 15.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKACreature.h"
#import "NSObject+TKACategory.h"

@implementation TKACreature

#pragma mark -
#pragma mark Class Methods

+ (instancetype)creatureWithName:(NSString *)name {
    TKACreature *creature = [self object];
    creature.name = name;
    
    return creature;
}

#pragma mark -
#pragma mark Initializations and Deallocations

-(void)dealloc {
    self.name = nil;
    
    [super dealloc];
}

-(id)init {
    [super init];
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods


- (void)sayHi {
    [self sayWithString];
}

- (void)performGenderSpecificOperation {

}

- (void)output {
    NSLog(@" name = %@", [self name]);
    NSLog(@" weight = %lu", [self weight]);
    NSLog(@" age = %lu", [self age]);
}

#pragma mark -
#pragma mark Private Methods

- (void)sayWithString {
    NSLog(@"HI! My name is %@", [self name]);
}

@end

