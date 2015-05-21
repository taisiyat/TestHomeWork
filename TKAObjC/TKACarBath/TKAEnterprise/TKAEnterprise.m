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

static const NSUInteger kTKACountCar = 6;
static const NSUInteger kTKACountWasher = 3;

@interface TKAEnterprise ()
@property (nonatomic, assign)       NSMutableArray  *mutableEmployees;
@property (nonatomic, assign)       NSMutableArray  *mutableCars;

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
//    [self removeObservers];
    self.name = nil;
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

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:@" "];
    [result appendString:@"\n Enterprise : "];
    [result appendFormat:@" name = %@ ", self.name];
    [result appendFormat:@"\n employees : %@ ", self.mutableEmployees];
    
    return [[result copy] autorelease];
}

- (void)prepare {
    TKADirector *director = [TKADirector employeeWithName:@"director"];
    TKAAccountant *accountant = [TKAAccountant employeeWithName:@"accountant"];
    [self addEmployee:director];
    [self addEmployee:accountant];
    [accountant  addObserver:director];
    
    NSMutableString *name = [NSMutableString string];
    for (NSUInteger iter = 1; iter <= kTKACountWasher; iter++) {
        [name setString:@"washer"];
        [name appendFormat:@"%lu", iter];
        TKAWasher *washer = [TKAWasher employeeWithName:name];
        [self addEmployee:washer];
        [washer addObserver:accountant];
    }
    
    for (NSUInteger iter = 0; iter < kTKACountCar; iter++) {
        [self.mutableCars addObject:[TKACar generateCar]];
    }
}

- (void)addEmployee:(TKAEmployee *)employee {
    if (NO == [self.mutableEmployees containsObject:employee]) {
        [self.mutableEmployees addObject:employee];
        
        if ([employee isKindOfClass:[TKAWasher class]]) {
            [employee addObserver:self];
        }
    }
}

- (void)removeEmployee:(TKAEmployee*)employee { //dismiss
    [self.mutableEmployees removeObject:employee];
}

- (void)workWithCar:(TKACar *)car {
    if (car) {
        @synchronized (self) {
            TKAWasher *washer = [self freeEmployeeOfClass:[TKAWasher class]];
            if (washer) {
                [washer performWorkWithObject:[self nextCarFromQueue]];
            }
        }
    }
}

- (TKACar *)nextCarFromQueue {
    @synchronized (self) {
        NSMutableArray *cars = self.mutableCars;
        TKACar *result = [[[cars firstObject] retain] autorelease];
        if (result) {
            [cars removeObject:result];
        }
        
        return result;
    }
}

- (id)freeEmployeeOfClass:(Class)classPosition {
    @synchronized (self) {
        for (TKAEmployee *employee in self.mutableEmployees) {
            if ([employee isKindOfClass:classPosition] && TKAEmployeeReadyToWork == employee.state) {
                return employee;
            }
        }
        
        return nil;
    }
}

- (NSMutableArray *)employeesOfClass:(Class)classPosition {
    @synchronized (self) {
        NSMutableArray *result = [NSMutableArray array];
        for (TKAEmployee *employee in self.mutableEmployees) {
            if ([employee isKindOfClass:classPosition]) {
                [result addObject:employee];
            }
        }
        
        return result;
    }
}

- (void)removeObservers {
    TKADirector *director = [[self employeesOfClass:[TKADirector class]] firstObject];
    TKAAccountant *accountant = [[self employeesOfClass:[TKAAccountant class]] firstObject];
    if (accountant && director) {
        [accountant removeObserver:director];
    }

    NSMutableArray *washers = [self employeesOfClass:[TKAWasher class]];
    for (TKAEmployee *empoyee in washers) {
        [empoyee removeObserver:accountant];
        [empoyee removeObserver:self];
    }
}
    
#pragma mark -
#pragma mark TKAEmployeeObserver

- (void)employeeDidBecomeReadyToWork:(TKAEmployee *)employee {
//    NSLog(@"%@ ready to work", employee.name);
    [employee performWorkWithObject:[self nextCarFromQueue]];
}

- (void)employeeDidPerformWork:(TKAEmployee *)employee {
//    NSLog(@"%@ perform work", employee.name);
}

@end


