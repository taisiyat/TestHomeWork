//
//  TKAEmployee.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAMoney.h"

@interface TKAEmployee : NSObject
@property(nonatomic, copy)      NSString   *name;
@property(nonatomic, copy)      NSString   *staffPosition;
@property(nonatomic, assign)    NSUInteger experience;
@property(nonatomic, assign)    NSUInteger salary;
@property(nonatomic, readonly)  NSArray *bigMoney;

+(instancetype)employeeWhithName:(NSString *)name staffPosition:(NSString *)staffPosition;

+(void)output;

@end
