//
//  TKABuilding.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKABuilding.h"
#import "TKAAdminRoom.h"
#import "TKACarBox.h"
@class TKAAdminRoom;
@class TKACarBox;
@class TKADirector;
@class TKAWasher;
@class TKAAccountant;

@interface TKABuilding ()
@property(nonatomic, readwrite)  NSMutableArray *mutableRooms;

@end

@implementation TKABuilding

@dynamic rooms;

#pragma mark -
#pragma mark Class Methods

+(instancetype)buildingWhithAddress:(NSString *)address {
    TKABuilding *building = [TKABuilding object];
    building.address = address;
    [building.mutableRooms addObject:[TKAAdminRoom roomWithName:@"AdminRoom1"]];
    [building.mutableRooms addObject:[TKACarBox roomWithName:@"CarBox1"]];
    
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
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
//    [result appendString:@"\n"];
    [result appendFormat:@" address = %@ \n", self.address];
    [result appendFormat:@" rooms : %@ \n", self.mutableRooms];
    
    return [[result copy] autorelease];
}


- (void)addRoom:(TKARoom *)room {
    [self.mutableRooms addObject:room];
 }

- (void)removeRoom:(TKARoom *)room {
    [self.mutableRooms removeObject:room];
}

- (id)foundFreeRoom:(Class)typeRoom {
    for (TKACarBox *room in self.mutableRooms) {
        if (typeRoom == [room class] && YES == room.free) {
            
            return room;
        }
    }
    
    return nil;
}

- (void)addEmployee:(TKAEmployee *)employee {
    if ([TKADirector class] == [employee class] || [TKAAccountant class] == [employee class]) {
        for (TKAAdminRoom *room in self.mutableRooms) {
            if ([TKAAdminRoom class] == [room class]) {
                [room.mutableEmployees addObject:employee];
                room.free = NO;
            }
        }
    }
}

@end