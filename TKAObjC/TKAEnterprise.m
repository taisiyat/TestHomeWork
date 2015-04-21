//
//  TKAEnterprise.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEnterprise.h"

@interface TKAEnterprise ()
@property(nonatomic, readwrite)  NSMutableArray *mutableEmployees;

@end

@implementation TKAEnterprise

@dynamic employees;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)enterpriseWhithName:(NSString *)name
                           director:(TKADirector *)director {
    TKAEnterprise *enterprise = [TKAEnterprise object];
    enterprise.name = name;
    enterprise.director = director;
 //   enterprise.director = [TKADirector employeeWhithName:directorName staffPosition:@"director"];
    [enterprise.mutableEmployees addObject:director];
    
    return enterprise;
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.director = nil;
    self.adminBuilding = nil;
    self.boxesBuilding = nil;
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

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (void)output {
    NSLog(@" Enterprise : ");
    NSLog(@" name = %@", self.name);
    NSLog(@" adminBuilding = %@", self.adminBuilding);
    NSLog(@" boxesBuilding = %@", self.boxesBuilding);
    [self.director output];
    for (TKAEmployee *employee in self.mutableEmployees) {
        [employee output];
    }
    
}

#pragma mark -
#pragma mark Private Methods

@end


