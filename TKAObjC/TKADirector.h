//
//  TKADirector.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"
#import "TKAEmployeeProtocol.h"

@class TKADirector;

@interface TKADirector : TKAEmployee <TKAEmployeeProtocol>

- (void)profit;

@end