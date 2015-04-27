//
//  TKAWasher.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"
#import "TKACar.h"
#import "TKAEmployeeProtocol.h"

@interface TKAWasher : TKAEmployee <TKAEmployeeProtocol>
@property(nonatomic, retain) TKACar *car;

- (NSString *)description;

- (void)takeMoney;
- (void)washCar;

@end
