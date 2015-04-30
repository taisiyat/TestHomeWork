//
//  TKAHuman.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 14.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAHuman.h"
@interface TKAHuman ()
@property (nonatomic, readwrite) NSMutableArray *mutableChildren;

- (void)sayWithString;

@end

@implementation TKAHuman

@dynamic children;

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
    self.mutableChildren = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableChildren = [[[NSMutableArray alloc] init] autorelease];
    }
    
    return self;
}

#pragma mark - 
#pragma mark Acessors Methods

- (NSArray *)children {
    return [[self.mutableChildren copy] autorelease];
}

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
    [self.mutableChildren  addObject:child];
    [self children];
}

- (void)removeChild:(TKAHuman *)child {
    [self.mutableChildren  removeObject:child];
    [self children];
}

- (void)sayHi {
    [self sayWithString];
    for (TKAHuman *child in [self mutableChildren]) {
        [child sayHi];
    }
}

- (void)performGenderSpecificOperation {
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
    NSLog(@"name = %@", [self name] );
    NSLog(@" weight = %lu", [self weight]);
    NSLog(@" age = %lu", [self age]);
    NSLog(@" gender = %u", [self gender]);
    for (TKAHuman *child in self.mutableChildren) {
        NSLog(@"child = %@", [child name] );
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)sayWithString {
    NSLog(@"HI! My name is %@", [self name]);
}

@end
