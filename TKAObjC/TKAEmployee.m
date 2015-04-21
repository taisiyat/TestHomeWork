//
//  TKAEmployee.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"


@interface TKAEmployee ()
@property(nonatomic, readwrite)  NSMutableArray *mutableBigMoney;

@end

@implementation TKAEmployee

#pragma mark -
#pragma mark Class Methods

+(instancetype)employeeWhithName:(NSString *)name
                   staffPosition:(NSString *)staffPosition {
        TKAEmployee *employee = [TKAEmployee object];
        employee.name = name;
        employee.staffPosition = staffPosition;
    
    return employee;
}


#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.staffPosition = nil;
    self.mutableBigMoney = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableBigMoney = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (void)output {
    NSLog(@" %@ : ", self.staffPosition);
    NSLog(@" name = %@", self.name);
    NSLog(@" experience = %lu", self.experience);
    NSLog(@" salary = %lu", self.salary);
    //    for (TKAMoney *money in self.mutableBigMoney) {
    //        [money output];
    //    }
    
}

#pragma mark -
#pragma mark Private Methods

@end


