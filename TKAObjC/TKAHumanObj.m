//
//  TKAHumanObj.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 14.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAHumanObj.h"

@implementation TKAHumanObj

#pragma mark -
#pragma mark Class Methods

+ (instancetype)humanObj {
    return [[[self alloc] init] autorelease];
}

#pragma mark - 
#pragma mark Initializations and Deallocations

#pragma mark - 
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (void)fight{
    
}

- (TKAHumanObj *)giveBirth {
    TKAHumanObj *child = [[[TKAHumanObj alloc] init] autorelease];
    [self addChild:child];
    return child;
}

- (void)addChild:(TKAHumanObj *)child {

}

- (void)removeChild:(TKAHumanObj *)child {
    
}

- (void)sayHi {
    
}

- (void)checkGender {
    if (TKAFemale == [self gender]) {
        [self fight];
    } else {
        [self giveBirth];
    }
}

- (void)writeHuman:(NSString *)string
            weight:(NSUInteger)weight
               age:(NSUInteger)age
            gender:(TKAGender)gender
         sizeArray:(NSUInteger)sizeArray {
    [self setName:string];
    [self setWeight:weight];
    [self setAge:age];
    [self setGender:gender];

//    TKAHumanObj *arrayOfChildren[sizeArray];
//    NSArray *array = [NSArray arrayWithObject:arrayOfChildren count:sizeArray];
 //   [self setChildren:array];
}

- (void)output {
    NSLog(@" name = %@", [self name]);
    NSLog(@" weight = %lu", [self weight]);
    NSLog(@" age = %lu", [self age]);
    NSLog(@" gender = %u", [self gender]);
    NSLog(@" children = %@", [self children]);
}



#pragma mark -
#pragma mark Private Methods

@end
