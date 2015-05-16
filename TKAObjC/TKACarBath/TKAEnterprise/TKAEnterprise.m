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

static const NSUInteger kTKACountCar = 4;
static const NSUInteger kTKACountWasher = 3;

@interface TKAEnterprise ()
@property (nonatomic, assign)       NSMutableArray  *mutableEmployees;
@property (nonatomic, assign)       NSMutableArray  *mutableCars;

@end

@implementation TKAEnterprise

@dynamic employees;
@dynamic cars;

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
//    self.building = nil;
    self.mutableEmployees = nil;
    self.mutableCars = nil;

    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.mutableEmployees = [NSMutableArray array];
        self.mutableCars = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

- (NSArray *)employees {
    return [[self.mutableEmployees copy] autorelease];
}

- (NSArray *)cars {
    return [[self.mutableCars copy] autorelease];
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:@" "];
    [result appendString:@"\n Enterprise : "];
    [result appendFormat:@" name = %@ ", self.name];
//    [result appendFormat:@"\n building %@ ", self.building];
    [result appendFormat:@"\n employees : %@ ", self.mutableEmployees];
    [result appendFormat:@"\n cars : %@ ", self.cars];
    
    return [[result copy] autorelease];
}

- (void)prepare {
    [self addEmployee:[TKADirector employeeWithName:@"director"]];
    [self addEmployee:[TKAAccountant employeeWithName:@"accountant"]];

    NSMutableString *name = [NSMutableString string];
    for (NSUInteger iter = 1; iter < kTKACountWasher; iter++) {
        [name setString:@"washer"];
        [name appendFormat:@"%lu", iter];
        [self addEmployee:[TKAWasher employeeWithName:name]];
    }
    
    TKAAccountant *accountant = [self freeEmployeeOfClass:[TKAAccountant class]];
    TKADirector *director = [self freeEmployeeOfClass:[TKADirector class]];
    
    for (TKAEmployee *employee in self.employees) {
        if ([employee isKindOfClass:[TKAWasher class]]) {
            [employee  addObserver:accountant];
        }
        if ([employee isKindOfClass:[TKAAccountant class]]) {
            [employee  addObserver:director];
        }
    }
    
    for (NSUInteger iter = 0; iter < kTKACountCar; iter++) {
        NSMutableString *number = [NSMutableString string];
        [number setString:@"AB"];
        [number appendString:[NSString randomStringWithLength:4 alphabet:[TKAAlphabet numericAlphabet]]];
        
        [self.mutableCars addObject:[TKACar carWithNumber:number moneyAmount:20]];
    }
}

- (void)addEmployeeWithName:(NSString *)name andClass:(Class)typeClass {
   [self addEmployee:[[typeClass class] employeeWithName:name]];
}

- (void)addEmployee:(TKAEmployee *)employee {
    if (NO == [self.mutableEmployees containsObject:employee]) {
        [self.mutableEmployees addObject:employee];
        [employee addObserver:self];
    }
}

- (void)removeEmployee:(TKAEmployee*)employee { //dismiss
    [self.mutableEmployees removeObject:employee];
    [employee removeObserver:self];
}

- (void)startPerformWork {
    @synchronized (self) {
        for (TKAEmployee *employee in self.mutableEmployees) {
            if ([employee isKindOfClass:[TKAWasher class]]) {
                employee.state = TKAEmployeePerformWork;
                employee.state = TKAEmployeeReadyToWork;
            }
        }
    }
}


//- (void)performWork {
//    TKAWasher *washer = [self freeEmployeeOfClass:[TKAWasher class]];
//    for (NSUInteger iter = 0; iter < kTKACountCar; iter++) {
////        [washer performWorkWithObject:[cars objectAtIndex:iter]];
//        [washer performWorkInBackgroundWithObject:[self.cars objectAtIndex:iter]];
//        NSLog(@"----------------------------------------");
//    }
//}

- (id)freeEmployeeOfClass:(Class)classPosition {
    for (TKAEmployee *employee in self.mutableEmployees) {
        if ([employee isKindOfClass:classPosition] && TKAEmployeeReadyToWork == employee.state) {
            return employee;
        }
    }
    
    return nil;
}

#pragma mark -
#pragma mark TKAEmployeeObserver

- (void)employeeDidBecomeReadyToWork:(TKAEmployee *)employee {
    NSLog(@"%@ ready to work", employee.name);
    @synchronized (employee) {
        if ([employee isKindOfClass:[TKAWasher class]]) {
            for (NSUInteger iter = 0; iter < kTKACountCar; iter++) {
                if (nil != [self.mutableCars objectAtIndex:iter] && NO == [[self.mutableCars objectAtIndex:iter] clean]) {
     //               [employee performWorkWithObject:[self.mutableCars objectAtIndex:iter]];
                    [employee performSelectorInBackground:@selector(performWorkWithObject:) withObject:[self.mutableCars objectAtIndex:iter]];
                    NSLog(@"----------------------------------------");
                    break;
                }
            }
        }
    }
}

- (void)employeeDidPerformWork:(TKAEmployee *)employee {
    NSLog(@"%@ perform work", employee.name);
}

@end


