//
//  TKAEmployee+TKAExtension.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 22.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"
#import "TKAEnterprise.h"

@interface TKAEmployee (TKAExtension)

- (void)moneyFlowEmployee:(TKAEmployee *)employeeTake employee:(TKAEmployee *)employeeGive;

- (void)takeMoney:(TKAEmployee *)employee;

- (void)giveMoney:(TKAEmployee *)employee;

@end
