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
    
    enterprise.building = [TKABuilding buildingWhithAddress:@"Street"];
    
    NSString *nameDirector = @"directorName";
    NSString *nameAccountant = @"accountantName";
    NSString *nameWasher1 = @"washerName1";

    [enterprise addEmployee:[TKADirector employeeWithName:nameDirector]];
    [enterprise addEmployee:[TKAAccountant employeeWithName:nameAccountant]];
    [enterprise addEmployee:[TKAWasher employeeWithName:nameWasher1]];
    
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
    [result appendString:@"\n"];
    [result appendString:@" Enterprise : "];
    [result appendFormat:@" name = %@ ", self.name];
    [result appendString:@"\n"];
    [result appendFormat:@" building : %@ ", [self.building description]];
    [result appendString:@"\n"];
    [result appendFormat:@" employees : %@ ", self.mutableEmployees];
    
    return [[result copy] autorelease];
}


-(void)addEmployee:(TKAEmployee *)employee { //recruit
    [self.building addEmployee:employee];
    [self.mutableEmployees addObject:employee];
}

-(void)removeEmployee:(TKAEmployee*)employee { //dismiss
    [self.building removeEmployee:employee];
    [self.mutableEmployees removeObject:employee];
}

- (id)carArrivesWithNumber:(NSString *)number amount:(NSUInteger)amount{
    TKACar *car = [TKACar carWithNumber:number amount:amount];
    car.clean = NO;
    
    return car;
}

- (void)washingCar:(TKACar *)car {
    TKACarBox *carBox = [self.building foundFreeRoom:[TKACarBox class]];
    TKAWasher *washer = [self foundFreeEmployeePosition:[TKAWasher class]];
    
    if (nil == carBox || nil == washer) {
        NSLog(@"wait");
    }
    
    if (NO == car.clean && [car.money amount] != 0 && nil != carBox && nil != washer) {
        [washer addCar:car];
        
        [carBox addCar:car];
        [carBox addEmployee:washer];

        [washer washCar];
        if (YES == car.clean) {
            [washer takeMoneyFromCar];
            [washer removeCar:car];
            [carBox removeCar:car];
            [carBox removeEmployee:washer];
        }
    }
}

- (void)financialFlows {
    TKAAccountant *accountant = [self foundFreeEmployeePosition:[TKAAccountant class]];
    TKADirector *director = [self foundEmployeePosition:[TKADirector class]];

    for (TKAWasher *washer in self.mutableEmployees) {
        [washer giveMoneyToEmployee:accountant];
    }

    [accountant countMoney];
    [accountant giveMoneyToEmployee:director];
    [director profit];

}

- (void)workingProcess {
    TKACar *car = [self carArrivesWithNumber:@"AA9876" amount:50];
    [self washingCar:car];
    [self financialFlows];
}

- (id)foundEmployeePosition:(Class)position {
    for (TKAEmployee *employee in self.mutableEmployees) {
        if ([position class] == [employee class]) {
            
            return employee;
        }
    }
    
    return nil;
}

- (id)foundFreeEmployeePosition:(Class)position {
    for (TKAEmployee *employee in self.mutableEmployees) {
        if ([position class] == [employee class] && YES == employee.free) {
            
            return employee;
        }
    }
    
    return nil;
}

#pragma mark -
#pragma mark Private Methods

@end


