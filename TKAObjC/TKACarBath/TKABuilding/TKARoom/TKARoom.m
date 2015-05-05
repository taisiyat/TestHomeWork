//
//  TKARoom.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKARoom.h"

@interface TKARoom ()
@property (nonatomic, assign)  NSMutableArray *mutableEmployees;

@end

@implementation TKARoom

@dynamic employees;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)room {
    return [self object];
}

+ (instancetype)roomWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableEmployees = nil;
    self.name = nil;

    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        self.mutableEmployees = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}

- (BOOL)isFree {
//    return 0 == [self.mutableEmployees count] ? YES : NO;
    return ![self.mutableEmployees count];
}

- (Class)classRoom {
    return [self class];
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:@" "];
    [result appendFormat:@"room name = %@   ", self.name];
    [result appendFormat:@"employees : %@", self.mutableEmployees];
 
    return [[result copy] autorelease];
}

- (void)addEmployee:(TKAEmployee *)employee {
    if (NO == [self.mutableEmployees containsObject:employee]) {
        [self.mutableEmployees addObject:employee];
    }
}

- (void)removeEmployee:(TKAEmployee *)employee {
    [self.mutableEmployees removeObject:employee];
}

@end
