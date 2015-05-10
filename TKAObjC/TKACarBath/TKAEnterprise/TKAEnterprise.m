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
#import "TKACarBox.h"
#import "TKAAlphabet.h"

#import "NSString+TKAExtensionWithAlphabet.h"

@class TKADirector;
@class TKAWasher;
@class TKAAccountant;
@class TKACarBox;

@interface TKAEnterprise ()
@property(nonatomic, retain)  NSMutableArray *mutableEmployees;

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
    self.washer = nil;  //-----

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

- (void)setWasher:(TKAWasher *)washer {
    if (_washer != washer) {
        [_washer removeObserver:self];
        [_washer release];
  
        _washer = [washer retain];
        [washer addObserver:self];
    }
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:@" "];
    [result appendString:@"\n Enterprise : "];
    [result appendFormat:@" name = %@ ", self.name];
    [result appendFormat:@"\n building %@ ", self.building];
    [result appendFormat:@"\n employees : %@ ", self.mutableEmployees];
    
    return [[result copy] autorelease];
}

- (void)prepare {
    self.building = [TKABuilding buildingWhithAddress:@"Street"];
    [self.building addRoom:[TKARoom roomWithName:@"AdminRoom1"]];
    [self.building addRoom:[TKACarBox roomWithName:@"CarBox1"]];

    [self addEmployee:[TKADirector employeeWithName:@"director"]];
    [self addEmployee:[TKAAccountant employeeWithName:@"accountant"]];
    NSMutableString *name = [NSMutableString string];
    for (NSUInteger iter = 1; iter < 6; iter++) {
        [name setString:@"washer"];
        [name appendFormat:@"%lu", iter];
        [self addEmployee:[TKAWasher employeeWithName:name]];
    }
}

- (void)addEmployee:(TKAEmployee *)employee {
    if (NO == [self.mutableEmployees containsObject:employee]) {
        [self.building addEmployee:employee];
        [self.mutableEmployees addObject:employee];
        if ([TKAWasher class] == employee) {
            self.washer = employee;
        }
    }
}

- (void)removeEmployee:(TKAEmployee*)employee { //dismiss
    [self.building removeEmployee:employee];
    [self.mutableEmployees removeObject:employee];
}

- (void)performWork {
    TKACar *car = [TKACar carWithNumber:@"AA1234" moneyAmount:50];
    NSMutableArray *cars = [NSMutableArray array];
    NSMutableString *number = [NSMutableString string];
    for (NSUInteger iter = 1; iter < 4; iter++) {
        [number setString:@"AA"];
        [number appendFormat:@"%lu", iter];
        [number appendString:[NSString randomStringWithLength:3 alphabet:[TKAAlphabet numericAlphabet]]];
        [cars addObject:[TKACar carWithNumber:number moneyAmount:20*iter]];
    }

    [self workWithCar:car];
    [self workWithCar:[cars objectAtIndex:0]];
    [self workWithCar:[cars objectAtIndex:1]];
    
    TKAAccountant *accountant = [self freeEmployeeOfClass:[TKAAccountant class]];
    TKADirector *director = [self freeEmployeeOfClass:[TKADirector class]];
    director.delegatingObject = accountant;
    [accountant countMoney];
    [director profit];
}

- (void)workWithCar:(TKACar *)car {
    
    TKACarBox *carBox = [self.building freeRoomOfClass:[TKACarBox class]];
    TKAWasher *washer = [self freeEmployeeOfClass:[TKAWasher class]];
  
    if (NO == car.clean && 0 != car.money && nil != carBox && nil != washer) {
        TKAAccountant *accountant = [self freeEmployeeOfClass:[TKAAccountant class]];
        accountant.delegatingObject = washer;

        [carBox addEmployee:washer];
        carBox.car = car;
        [washer washCar:car];
        if (YES == car.clean) {
            carBox.car = nil;
            [carBox removeEmployee:washer];
        }
    }
    
//    TKAAccountant *accountant = [self freeEmployeeOfClass:[TKAAccountant class]];
//    [accountant takeMoneyFromSomeone:washer];
//    washer.free = YES;
//    [accountant countMoney];
//
//    TKADirector *director = [self freeEmployeeOfClass:[TKADirector class]];
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
#pragma mark TKAWasherObserver

- (void)employeeBecomeReadyToWork:(TKAEmployee *)employee {
    if (self.washer == employee) {
        NSLog(@"ADD NEW CAR");
    }
}
- (void)employeePerformWorkNow:(TKAEmployee *)employee {
    if (self.washer == employee) {
        NSLog(@"washer perform work");
    }
}

#pragma mark -
#pragma mark Private Methods

@end


