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


#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.mutableEmployees = nil;
    
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

- (void)output {
    NSLog(@" Room : ");
    //    for (TKAEmployee *employee in self.mutableEmployees) {
    //        [employee output];
    //    }
}

@end
