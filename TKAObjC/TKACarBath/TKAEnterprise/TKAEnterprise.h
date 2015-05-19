//
//  TKAEnterprise.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKABuilding.h"
#import "TKAWasher.h"

#import "TKAObservableObject.h"

@class TKACar;

@interface TKAEnterprise : NSObject <TKAEmployeeObserver>
@property (nonatomic, copy)         NSString        *name;
//@property (nonatomic, retain)       TKABuilding     *building;
@property (nonatomic, readonly)     NSArray         *employees;

+ (instancetype)enterpriseWhithName:(NSString *)name;
- (void)prepare;

- (void)addEmployeeWithName:(NSString *)name andClass:(Class)typeClass;
- (void)addEmployee:(TKAEmployee *)emploeey;
- (void)removeEmployee:(TKAEmployee *)emploeey;
- (id)freeEmployeeOfClass:(Class)classPosition;

- (void)startPerformWork;
- (void)performWork;
- (void)performWorkWithObject:(TKAEmployee *)washer;

@end
