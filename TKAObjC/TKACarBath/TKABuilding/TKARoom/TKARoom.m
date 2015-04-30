//
//  TKARoom.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKARoom.h"

@interface TKARoom ()
@property(nonatomic, readwrite)  NSMutableArray *mutableEmployees;

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

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployees = [NSMutableArray array];
    }
    
    return self;
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        self.free = YES;
        self.mutableEmployees = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
    [result appendString:@"\n"];
    [result appendFormat:@" room name = %@", self.name];
    [result appendFormat:@" employees : %@", self.mutableEmployees];
    [result appendString:@"\n"];
    
    return [[result copy] autorelease];
}

- (void)addEmployee:(TKAEmployee *)employee {
    [self.mutableEmployees addObject:employee];
}

- (void)removeEmployee:(TKAEmployee *)employee {
    [self.mutableEmployees removeObject:employee];
}

@end
