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

static const NSUInteger kTKACountAllCars        = 100;
static const NSUInteger kTKACountWasher         = 3;

@interface TKAEnterprise ()
@property (nonatomic, assign)       NSMutableArray  *mutableEmployees;

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
    [self removeObservers];
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
    [self addEmployee:[TKADirector employeeWithName:@"director"]];
    [self addEmployee:[TKAAccountant employeeWithName:@"accountant"]];

    NSMutableString *name = [NSMutableString string];
    for (NSUInteger iter = 1; iter <= kTKACountWasher; iter++) {
        [name setString:@"washer"];
        [name appendFormat:@"%lu", iter];
        [self addEmployee:[TKAWasher employeeWithName:name]];
    }
    
    for (NSUInteger iter = 0; iter < kTKACountAllCars; iter++) {
        [self.mutableCars addObject:[TKACar carRegister]];
    }
}

- (void)addEmployee:(TKAEmployee *)employee {
    @synchronized (self) {
        if (NO == [self.mutableEmployees containsObject:employee]) {
            [self.mutableEmployees addObject:employee];
            
            if ([employee isKindOfClass:[TKAWasher class]]) {
                [employee addObserver:self];
                [employee addObserver:[[self employeesOfClass:[TKAAccountant class]] anyObject]];
            }
            if ([employee isKindOfClass:[TKAAccountant class]]) {
                [employee addObserver:[[self employeesOfClass:[TKADirector class]] anyObject]];
            }
        }
    }
}

- (void)removeEmployee:(TKAEmployee*)employee { //dismiss
    @synchronized (self) {
        [self.mutableEmployees removeObject:employee];
    }
}

- (void)washCar:(TKACar *)car {
    if (car) {
        @synchronized (self) {
            TKAWasher *washer = [self freeEmployeeOfClass:[TKAWasher class]];
            if (washer) {
                [[car retain] autorelease];
                [self.mutableCars removeObject:car];
                [washer performWorkWithObject:car];
            } else {
            }
            
        }
    }
}

- (TKACar *)nextCarInQueue {
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
        NSMutableSet *employees = [self employeesOfClass:classPosition];
        NSMutableSet *freeEmployees = [NSMutableSet set];
        for (TKAEmployee *employee in employees) {
            if (TKAEmployeeReadyToWork == employee.state) {
                [freeEmployees addObject:employee];
            }
        }
        
        return [freeEmployees anyObject];
    }
}

- (NSMutableSet *)employeesOfClass:(Class)classPosition {
    @synchronized (self) {
        NSMutableSet *result = [NSMutableSet set];
        for (TKAEmployee *employee in self.mutableEmployees) {
            if ([employee isKindOfClass:classPosition]) {
                [result addObject:employee];
            }
        }
        
        return [[result mutableCopy] autorelease];
    }
}

- (void)removeObservers {
    TKADirector *director = [[self employeesOfClass:[TKADirector class]] anyObject];
    TKAAccountant *accountant = [[self employeesOfClass:[TKAAccountant class]] anyObject];
    if (accountant && director) {
        [accountant removeObserver:director];
    }

    NSSet *washers = [self employeesOfClass:[TKAWasher class]];
    for (TKAEmployee *empoyee in washers) {
        [empoyee removeObserver:accountant];
        [empoyee removeObserver:self];
    }
}
    
#pragma mark -
#pragma mark TKAEmployeeObserver

- (void)employeeDidBecomeReadyToWork:(TKAEmployee *)employee {
//    NSLog(@"%@ ready to work", employee.name);
    [employee performWorkWithObject:[self nextCarInQueue]];
}

- (void)employeeDidPerformWork:(TKAEmployee *)employee {
//    NSLog(@"%@ perform work", employee.name);
}

@end


