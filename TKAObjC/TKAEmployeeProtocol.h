//
//  TKAEmployeeProtocol.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 27.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKAEmployee.h"

@protocol TKAEmployeeProtocol <NSObject>

- (void)moneyFlowEmployee:(TKAEmployee *)employeeTake employee:(TKAEmployee *)employeeGive;

- (void)takeMoney:(TKAEmployee *)employee;

- (void)giveMoney:(TKAEmployee *)employee;

@end
