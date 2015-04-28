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
    NSString *nameWasher2 = @"washerName2";

//    TKADirector *director = [TKADirector employeeWhithName:nameDirector];
  //  [enterprise.mutableEmployees addObject:director];
//    [enterprise.mutableEmployees addObject:[TKAAccountant employeeWhithName:nameAccountant]];
//    
//    for (TKAAdminRoom *room in [enterprise.building rooms]) {
//        for (TKAEmployee *employee in enterprise.mutableEmployees) {
//            if ([TKADirector class] == [employee class]
//                || [TKADirector class] == [employee class]) {
//                [room.mutableEmployees addObject:employee];
//            }
//        }
//    }
    //    [enterprise.mutableEmployees addObject:[TKAWasher employeeWhithName:nameWasher1]];
    
//    [enterprise addEmployee:[TKADirector employeeWhithName:nameDirector]];
//    [enterprise addEmployee:[TKAAccountant employeeWhithName:nameAccountant]];
//    [enterprise addEmployee:[TKAWasher employeeWhithName:nameWasher1]];
    
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
    [result appendFormat:@" name = %@ \n", self.name];
    [result appendFormat:@" building : %@ \n", [self.building description]];
    [result appendFormat:@" employees : %@ \n", self.mutableEmployees];
    
    return [[result copy] autorelease];
}


-(void)addEmployee:(TKAEmployee *)employee {
    if ([TKADirector class] == [employee class] || [TKAAccountant class] == [employee class]) {
        for (TKAAdminRoom *room in [self.building rooms]) {
            [room.mutableEmployees addObject:employee];
        }
    }
    
    [self.mutableEmployees addObject:employee];
}

-(void)removeEmployee:(TKAEmployee*)employee {
    if ([TKADirector class] == [employee class] || [TKAAccountant class] == [employee class]) {
        for (TKAAdminRoom *room in [self.building rooms]) {
            for (employee in room.mutableEmployees)
            [room.mutableEmployees removeObject:employee];
        }
    }
    
    if ([TKAWasher class] == [employee class]) {
        for (TKACarBox *room in [self.building rooms]) {
            for (employee in room.mutableEmployees)
                [room.mutableEmployees removeObject:employee];
        }
    }
    
    [self.mutableEmployees removeObject:employee];
}

- (id)carCameWhithNumber:(NSString *)number amount:(NSUInteger)amount{
    TKACar *car = [TKACar carWithNumber:number amount:amount];
    car.clean = NO;
    
    return car;
}

- (void)washingCar:(TKACar *)car {
    TKACarBox *carBox = [self foundFreeCarBox];
    TKAWasher *washer = [self foundFreeEmployeePosition:[TKAWasher class]];
    if (NO == car.clean && [car.money amount] != 0 && nil != carBox && nil != washer) {
        washer.car = car;
        washer.free = NO;
        [carBox addCar:car];
        [carBox.mutableEmployees addObject:washer];
        [washer washCar];
        if (YES == car.clean) {
            [washer takeMoney];
            [carBox removeCar:car];
            [carBox.mutableEmployees removeObject:washer];
        }
    }
}

- (void)financialFlows {
    TKAAccountant *accountant = [self foundFreeEmployeePosition:[TKAAccountant class]];
    TKADirector *director = [self foundEmployeePosition:[TKADirector class]];
    for (TKAWasher *washer in self.mutableEmployees) {
        [washer giveMoney:accountant];
    }
        
    [accountant countMoney];
    [accountant giveMoney:director];
    [director profit];

}

- (void)workingProcess {
    TKACar *car = [self carCameWhithNumber:@"AA9876" amount:50];
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

- (id)foundFreeCarBox {
    for (TKACarBox *box in [self.building rooms]) {
        if (YES == box.free) {
            
            return box;
        }
    }
    
    return nil;
}

#pragma mark -
#pragma mark Private Methods

@end


