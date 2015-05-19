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
    TKAEmployeePerformWork,
    TKAEmployeeReadyForProcessing
};

@protocol TKAEmployeeObserver <NSObject>

@optional
- (void)employeeDidBecomeReadyToWork:(TKAEmployee *)employee;
- (void)employeeDidBecomeReadyToProcessing:(TKAEmployee *)employee;
- (void)employeeDidPerformWork:(TKAEmployee *)employee;

@end

@interface TKAEmployee : TKAObservableObject <TKATransferMoneyProtocol, TKAEmployeeObserver>
@property (nonatomic, copy)         NSString        *name;
@property (nonatomic, assign)       NSUInteger      experience;
@property (nonatomic, assign)       NSUInteger      salary;

+ (instancetype)employeeWithName:(NSString *)name;

- (void)processingObject:(id)object;
- (void)performWorkWithObject:(id)object;

@end
