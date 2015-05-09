//
//  TKABuilding.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKABuilding.h"
#import "TKACarBox.h"
#import "TKADirector.h"
#import "TKAAccountant.h"
@class TKADirector;
@class TKAAccountant;

@interface TKABuilding ()
@property (nonatomic, assign)   NSMutableArray   *mutableRooms;

@end

@implementation TKABuilding

@dynamic rooms;

#pragma mark -
#pragma mark Class Methods

+(instancetype)buildingWhithAddress:(NSString *)address {
    TKABuilding *building = [TKABuilding object];
    building.address = address;
    
    return building;
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.address = nil;
    self.mutableRooms = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableRooms = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

- (NSArray *)rooms {
    return [[self.mutableRooms copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:@" "];
    [result appendFormat:@" address = %@ ", self.address];
    [result appendFormat:@"\n rooms : %@ ", self.mutableRooms];
    
    return [[result copy] autorelease];
}

- (void)addRoom:(TKARoom *)room {
    if (NO == [self.mutableRooms containsObject:room]) {
        [self.mutableRooms addObject:room];
    }
}

- (void)removeRoom:(TKARoom *)room {
    [self.mutableRooms removeObject:room];
}

- (id)freeRoomOfClass:(Class)classRoom {
    for (TKARoom *room in self.mutableRooms) {
        if (classRoom == [room class] && YES == [room isFree]) {
            return room;
        }
    }
    
    return nil;
}

- (void)addEmployee:(TKAEmployee *)employee {
    if ([TKADirector class]  == [employee class] || [TKAAccountant class] == [employee class]) {
        for (TKARoom *room in self.mutableRooms) {
            if ([TKACarBox class] != [room class]) {
                [room addEmployee:employee];
                
                break;
            }
        }
    }
}

- (void)removeEmployee:(TKAEmployee*)employee {
    for (TKARoom *room in self.mutableRooms) {
        [room removeEmployee:employee];
    }
}

@end