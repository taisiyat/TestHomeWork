//
//  TKAHuman.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 14.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAHuman.h"
@interface TKAHuman ()

- (void)sayWithString;

@end

@implementation TKAHuman

//@dynamic children;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)human {
    return [[[self alloc] init] autorelease];
}

+ (instancetype)humanWithName:(NSString *)name
                       gender:(TKAGender)gender {
    TKAHuman *human = [[[self alloc] init] autorelease];
    human.name = name;
    human.gender = gender;
    return human;
}

#pragma mark - 
#pragma mark Initializations and Deallocations

-(void)dealloc {
    self.name = nil;

    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
//        [self.children array];
    }
    
    return self;
}

#pragma mark - 
#pragma mark Acessors Methods

//- (NSArray *)array {
//    return [[[[[NSMutableArray alloc] initWithObjects:[[NSObject new] autorelease], nil] autorelease] copy] autorelease];
//}

#pragma mark -
#pragma mark Public Methods

- (void)fight {
    NSLog(@"man goes to war");
}

- (TKAHuman *)giveBirth {
    NSLog(@"woman is giving birth");
    
    return [TKAHuman human];
}

- (void)addChild:(TKAHuman *)child {
//        [[self children] addObject:child];
//    NSMutableArray *mutableChildren = [NSMutableArray array];
//    [mutableChildren setArray:self.array];
//    [mutableChildren addObject:child];
//    [[self.array initWithArray:mutableChildren] autorelease];
}

- (void)removeChild:(TKAHuman *)child {
//    [[self children] removeObject:child];
//    NSMutableArray *mutableChildren = [NSMutableArray array];
//    [mutableChildren setArray:self.array];
//    [mutableChildren removeObject:child];
//    [[self.array initWithArray:mutableChildren] autorelease];
}

- (void)sayHi {
    [self sayWithString];
    for (TKAHuman *child in [self children]) {
        [child sayWithString];
    }
}

- (void)checkGender {
    if (TKAMale == [self gender]) {
        [self fight];
    } else {
        [self addChild:[self giveBirth]];
    }
}

- (void)humanWriteNewbornName:(NSString *)string
            weight:(NSUInteger)weight
               age:(NSUInteger)age
            gender:(TKAGender)gender{
    [self setName:string];
    [self setWeight:weight];
    [self setAge:0];
    [self setGender:gender];
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

- (void)sayWithString {
    NSLog(@"HI! My name is %@", [self name]);
}

@end
