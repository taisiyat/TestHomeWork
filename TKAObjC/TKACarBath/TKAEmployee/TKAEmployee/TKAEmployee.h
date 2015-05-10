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
    TKAReadyToWork,
    TKAPerformWork
};

@protocol TKAEmployeeDelegate <NSObject>

- (void)employee:(TKAEmployee *)employee shouldGiveMoney:(NSUInteger)money; //or - (void)shouldGiveMoneyEmployee:(TKAEmployee *)employee;
//- (BOOL)employeeShouldTakeMoney:(TKAEmployee *)employee;
- (BOOL)employeeShouldFinishWork:(TKAEmployee *)employee;

@end

@protocol TKAEmployeeObserver <NSObject>

@optional
- (void)employeeBecomeReadyToWork:(TKAEmployee *)employee;
- (void)employeePerformWorkNow:(TKAEmployee *)employee;

@end

@interface TKAEmployee : NSObject <TKATransferMoneyProtocol, TKAEmployeeDelegate, TKAEmployeeObserver>
@property (nonatomic, copy)         NSString        *name;
@property (nonatomic, assign)       NSUInteger      experience;
@property (nonatomic, assign)       NSUInteger      salary;
@property (nonatomic, retain)       TKAEmployee     *delegatingObject;
@property (nonatomic, assign)       BOOL            finishWork;
@property (nonatomic, assign)    TKAEmployeeState   observableState;
@property (nonatomic, assign, getter=isFree) BOOL   free;
@property (nonatomic, assign)   id<TKAEmployeeDelegate>     delegate;

+ (instancetype)employeeWithName:(NSString *)name;

@end
