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
#import "TKAWasher.h"
#import "TKAAdminRoom.h"
#import "TKACarBox.h"

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

//+ (instancetype)enterpriseWhithName:(NSString *)name
//                           director:(TKADirector *)director {
//    TKAEnterprise *enterprise = [TKAEnterprise object];
//    enterprise.name = name;
//    enterprise.director = director;
// //   enterprise.director = [TKADirector employeeWhithName:directorName staffPosition:@"director"];
//    [enterprise.mutableEmployees addObject:director];
//    
//    return enterprise;
//}

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
    [self.adminBuilding output];
    NSLog(@" boxesBuilding = %@", self.boxesBuilding);
    [self.boxesBuilding output];
    for (TKAEmployee *employee in self.mutableEmployees) {
        [employee output];
    }
}

// may be to director 2 metods;
-(void)addEmployee:(TKAEmployee*)employee {
    if ([TKADirector class] == [employee class] || [TKAAccountant class] == [employee class]) {
        for (TKAAdminRoom *room in [self adminBuilding]) {
            [room addEmployee:employee];
        }
    }
    
    [self.mutableEmployees addObject:employee];
    [self employees];
}

-(void)removeEmployee:(TKAEmployee*)employee {
    if ([TKADirector class] == [employee class] || [TKAAccountant class] == [employee class]) {
        for (TKAAdminRoom *room in [self adminBuilding]) {
            [room removeEmployee:employee];
        }
    }
    
    [self.mutableEmployees removeObject:employee];
    [self employees];
}

- (id)carCameWhithNumber:(NSString *)number amount:(NSUInteger)amount{
    TKACar *car = [TKACar carWithNumber:number amount:amount];
    [car setCondition:TKADirtyCar];
    return car;
}

- (void)fill {
    [self setAdminBuilding:[TKABuilding buildingWhithAddress:@"First Street1"]];
    [[self adminBuilding] addRoom:[TKAAdminRoom roomWithName:@"adminRoom1"]];
    [self setBoxesBuilding:[TKABuilding buildingWhithAddress:@"First Street2"]];
    [[self boxesBuilding] addRoom:[TKACarBox roomWithName:@"box1"]];
    
    NSString *positionDirector = @"director";
    NSString *positionAccountant = @"accountant";
    NSString *positionWasher = @"washer";
    NSString *nameDirector = @"directorName";
    NSString *nameAccountant = @"accountantName";
    NSString *nameWasher1 = @"washerName1";
    NSString *nameWasher2 = @"washerName2";
    
    if (nil == [self director]) {
        TKADirector *director = [TKADirector employeeWhithName:nameDirector staffPosition:positionDirector];
        [self addEmployee:director];
        [self setDirector:director];
    }
    
    bool boolValue = false;
    for (TKAAccountant *employeeAccountant in self.mutableEmployees) {
        boolValue = true;
    }
    
    if (false == boolValue) {
        TKAAccountant *accountant = [TKAAccountant employeeWhithName:nameAccountant staffPosition:positionAccountant];
        [self addEmployee:accountant];
    }
    
    TKAWasher *washer1 = [TKAWasher employeeWhithName:nameWasher1 staffPosition:positionAccountant];
    [self addEmployee:washer1];
}

- (void)washingCar:(TKACar *)car {
    TKACarBox *carBox = [self foundFreeCarBox];
    TKAWasher *washer = [self foundFreeWasher];
    if ([car condition] == TKADirtyCar && [[car money] amount] != 0 && nil != carBox && nil != washer) {
        [washer setCar:car];
        [carBox setCar:car];
        [carBox addEmployee:washer];
        [[washer car] condition:TKAWashingCar];
        [washer washCar];
        if ([car carIsClean]) {
            [washer takeMoney];
            [carBox setCar:nil];
            [carBox removeEmployee:washer];
        }
    }
}

- (id)foundDirector {
    return [self director];
}

- (id)foundAccountant {
    for (TKAEmployee *employee in [self employees]) {
        if ([TKAAccountant class] == [employee class]) {
            
            return employee;
        }
    }
    return nil;
}

- (id)foundFreeWasher {
    for (TKAEmployee *employee in [self employees]) {
        if ([TKAWasher class] == [employee class]) {
            if ([employee washerIsFree]) {
                
                return employee;
            }
        }
    }
    return nil;
}

- (id)foundFreeCarBox {
    for (TKACarBox *box in [self boxesBuilding]) {
        if (nil == [box car]) {
            
            return box;
        }
    }
    
    return nil;
}

#pragma mark -
#pragma mark Private Methods

@end


