//
//  TKABuilding.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKABuilding.h"

@interface TKABuilding ()
@property(nonatomic, readwrite)  NSMutableArray *mutableRooms;

@end

@implementation TKABuilding

#pragma mark -
#pragma mark Class Methods

+(instancetype)buildingWhithAddress:(NSString *)address {
    TKABuilding *building = [TKABuilding object];
    building.address = address;
//    [building.mutableRooms addObject:];
    
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

#pragma mark -
#pragma mark Public Methods

- (void)output {
    NSLog(@" Building : ");
    NSLog(@" address = %@", self.address);
    //    for (TKARoom *room in self.mutableRooms) {
    //        [room output];
    //    }
}

@end