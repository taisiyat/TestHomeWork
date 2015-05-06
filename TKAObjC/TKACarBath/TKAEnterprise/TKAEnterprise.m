//
//  TKAEnterprise.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEnterprise.h"
#import "TKACar.h"
#import "TKAAccountant.h"
#import "TKADirector.h"
#import "TKAWasher.h"
#import "TKAAdminRoom.h"
#import "TKACarBox.h"
@class TKADirector;
@class TKAWasher;
@class TKAAccountant;
@class TKACarBox;
@class TKAAdminRoom;

@interface TKAEnterprise ()
@property(nonatomic, readwrite)  NSMutableArray *mutableEmployees;

@end

@implementation TKAEnterprise

@dynamic employees;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)enterpriseWhithName:(NSString *)name {
    TKAEnterprise *enterprise = [TKAEnterprise object];
    enterprise.name = name;
    
    return enterprise;
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.name = nil;
    self.building = nil;
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

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
    [result appendString:@"\n Enterprise : "];
    [result appendFormat:@" name = %@ ", self.name];
    [result appendFormat:@"\n building : %@ ", self.building];
    [result appendFormat:@"\n employees : %@ ", self.mutableEmployees];
    
    return [[result copy] autorelease];
}

- (void)prepare {
    self.building = [TKABuilding buildingWhithAddress:@"Street"];
    [self.building addRoom:[TKAAdminRoom roomWithName:@"AdminRoom1"]];
    [self.building addRoom:[TKACarBox roomWithName:@"CarBox1"]];

    [self addEmployee:[TKADirector employeeWithName:@"directorName"]];
    [self addEmployee:[TKAAccountant employeeWithName:@"accountantName"]];
    [self addEmployee:[TKAWasher employeeWithName:@"washerName1"]];
}

- (void)addEmployee:(TKAEmployee *)employee { //recruit
    if (NO == [self.mutableEmployees containsObject:employee]) {
        [self.building addEmployee:employee];
        [self.mutableEmployees addObject:employee];
    }
}

- (void)removeEmployee:(TKAEmployee*)employee { //dismiss
    [self.building removeEmployee:employee];
    [self.mutableEmployees removeObject:employee];
}

- (void)workWithCar:(TKACar *)car {
    
    TKACarBox *carBox = [self.building freeRoomOfClass:[TKACarBox class]];
    TKAWasher *washer = [self freeEmployeeOfClass:[TKAWasher class]];
    
    if (NO == [car isClean] && 0 != car.money && nil != carBox && nil != washer) {
        [carBox addEmployee:washer];
        carBox.car = car;
        [washer washCar:car];
        if (YES == [car isClean]) {
             carBox.car = nil;
            [carBox removeEmployee:washer];
        }
    }
    
//    TKAAccountant *accountant = [self freeEmployeeOfClass:[TKAAccountant class]];
// 
//    [accountant takeMoneyFromSomeone:washer];
//    washer.free = YES;
//    [accountant countMoney];
//
//    TKADirector *director = [self freeEmployeeOfClass:[TKADirector class]];
//
//    [director takeMoneyFromSomeone:accountant];
//    [director profit];
}

- (id)freeEmployeeOfClass:(Class)classPosition {
    for (TKAEmployee *employee in self.mutableEmployees) {
        if ([classPosition class] == [employee class] && YES == [employee isFree]) {
            
            return employee;
        }
    }
    
    return nil;
}

#pragma mark -
#pragma mark Private Methods

@end


