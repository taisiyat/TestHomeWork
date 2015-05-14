//
//  TKAEmployee.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAObservableObject.h"

#import "NSObject+TKAExtension.h"

#import "TKATransferMoneyProtocol.h"

@class TKAEmployee;

typedef NS_ENUM(NSUInteger, TKAEmployeeState) {
    TKAEmployeeReadyToWork,
    TKAEmployeePerformWork
};

@protocol TKAEmployeeDelegate <NSObject>

- (void)employeeShouldFinishWork:(TKAEmployee *)employee;

@end

@protocol TKAEmployeeObserver <NSObject>

@optional
- (void)employeeDidBecomeReadyToWork:(TKAEmployee *)employee;
- (void)employeeDidPerformWork:(TKAEmployee *)employee;

@end

@interface TKAEmployee : TKAObservableObject <TKATransferMoneyProtocol, TKAEmployeeDelegate, TKAEmployeeObserver>
@property (nonatomic, copy)         NSString        *name;
@property (nonatomic, assign)       NSUInteger      experience;
@property (nonatomic, assign)       NSUInteger      salary;
@property (nonatomic, assign)       BOOL            finishWork;
@property (nonatomic, assign)   id<TKAEmployeeDelegate>     delegate;

+ (instancetype)employeeWithName:(NSString *)name;

- (void)processWithObject:(id)object;
- (void)performWorkWithObject:(id)object;

@end
