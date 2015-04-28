//
//  TKARoom.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKARoom.h"

@implementation TKARoom

#pragma mark -
#pragma mark Class Methods

+ (instancetype)room {
    return [TKARoom object];
}

+ (instancetype)roomWithName:(NSString *)name {
    TKARoom *room = [TKARoom object];
    room.name = name;
    
    return room;
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

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
//    [result appendString:@"\n"];
    [result appendFormat:@" room name = %@", self.name];
    [result appendFormat:@" employees : %@ \n", self.mutableEmployees];
    
    return [[result copy] autorelease];
}

//- (void)addEmployee:(TKAEmployee *)employee {
//    [self.mutableEmployees addObject:employee];
//}
//
//- (void)removeEmployee:(TKAEmployee *)employee {
//    [self.mutableEmployees removeObject:employee];
//}

@end
