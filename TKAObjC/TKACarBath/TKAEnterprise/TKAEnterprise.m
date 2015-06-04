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
#import "TKASupervisor.h"

#import "NSString+TKAExtensionWithAlphabet.h"

@class TKADirector;
@class TKAWasher;
@class TKAAccountant;

static const NSUInteger kTKACountWasher         = 3;
static const NSUInteger kTKACountAccountant     = 2;
static NSString * const kTKANameWasher          = @"Washer";
static NSString * const kTKANameAccountant      = @"Accountant";

@interface TKAEnterprise ()
@property (nonatomic, retain)       NSMutableArray  *mutableEmployees;
@property (nonatomic, retain)       TKASupervisor   *supervisorWasher;
@property (nonatomic, retain)       TKASupervisor   *supervisorAccountant;

@end

@implementation TKAEnterprise

@dynamic employees;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)enterpriseWithName:(NSString *)name {
    return [[[self alloc] initWithName:name] autorelease];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    [self removeObservers];
    self.name = nil;
    self.mutableEmployees = nil;
    self.mutableCars = nil;
    self.supervisorWasher = nil;
    self.supervisorAccountant = nil;

    
    [super dealloc];
}

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        self.mutableEmployees = [NSMutableArray array];
        self.mutableCars = [NSMutableArray array];
        self.supervisorWasher = [TKASupervisor supervisor];
        self.supervisorAccountant = [TKASupervisor supervisor];
    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

- (NSArray *)employees {
    @synchronized (self) {
        return [[self.mutableEmployees copy] autorelease];
    }
}

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    @synchronized (self) {
        NSMutableString *result = [NSMutableString stringWithString:@" "];
        [result appendString:@"\n Enterprise : "];
        [result appendFormat:@" name = %@ ", self.name];
        [result appendFormat:@"\n employees : %@ ", self.mutableEmployees];
        [result appendFormat:@"%@ ", self.supervisorWasher];
        [result appendFormat:@"%@ ", self.supervisorAccountant];
        
        return [[result copy] autorelease];
    }
}

- (void)prepare {
    [self addEmployee:[TKADirector employeeWithName:@"director"]];
    [self employeesWithClass:[TKAAccountant class] count:kTKACountAccountant name:kTKANameAccountant];
    [self employeesWithClass:[TKAWasher class] count:kTKACountWasher name:kTKANameWasher];
}

- (void)addEmployee:(TKAEmployee *)employee {
    @synchronized (self) {
        if (![self.mutableEmployees containsObject:employee]) {
            [self.mutableEmployees addObject:employee];
            
            if ([employee isKindOfClass:[TKAWasher class]]) {
                [employee addObserver:self];
                [employee addObserver:self.supervisorWasher];
                [self.supervisorWasher addProcessorObject:employee];
            }
            
            if ([employee isKindOfClass:[TKAAccountant class]]) {
                [employee addObserver:[[self employeesOfClass:[TKADirector class]] anyObject]];
                [employee addObserver:self.supervisorAccountant];
                [self.supervisorAccountant addProcessorObject:employee];
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
            [self.supervisorWasher workWithObject:car];
    }
}

//- (TKACar *)nextCarInQueue {
//    @synchronized (self) {
//        NSMutableArray *cars = self.mutableCars;
//        TKACar *result = [[[cars firstObject] retain] autorelease];
//        if (result) {
//            [cars removeObject:result];
//        }
//        
//        return result;
//    }
//}

//- (id)freeEmployeeOfClass:(Class)classPosition {
//    @synchronized (self) {
//        NSMutableSet *employees = [self employeesOfClass:classPosition];
//        NSMutableSet *freeEmployees = [NSMutableSet set];
//        for (TKAEmployee *employee in employees) {
//            if (TKAEmployeeReadyToWork == employee.state) {
//                [freeEmployees addObject:employee];
//            }
//        }
//        
//        return [freeEmployees anyObject];
//    }
//}

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

    NSSet *accountants = [self employeesOfClass:[TKAAccountant class]];
    for (TKAEmployee *empoyee in accountants) {
        [empoyee removeObserver:director];
        [empoyee removeObserver:self.supervisorAccountant];
    }

    NSSet *washers = [self employeesOfClass:[TKAWasher class]];
    for (TKAEmployee *empoyee in washers) {
        [empoyee removeObserver:self];
        [empoyee removeObserver:self.supervisorWasher];
    }
}

#pragma mark -
#pragma mark Private Methods

- (void)employeesWithClass:(Class)class count:(NSUInteger)count name:(NSString *)name {
    NSMutableString *nameEmployee = [NSMutableString string];
    for (NSUInteger iter = 0; iter < count; iter++) {
        [nameEmployee setString:name];
        [nameEmployee appendFormat:@"%lu", iter];
        [self addEmployee:[class employeeWithName:nameEmployee]];
    }
}

#pragma mark -
#pragma mark TKAEmployeeObserver

- (void)employeeDidBecomeReadyForProcessing:(TKAEmployee *)employee{
    @synchronized (self) {
        if (TKAEmployeeReadyForProcessing == employee.state) {
            [self.supervisorAccountant workWithObject:employee];
        }
    }
}

@end


