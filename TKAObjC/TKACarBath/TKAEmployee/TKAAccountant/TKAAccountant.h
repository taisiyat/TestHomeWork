//
//  TKAAccountant.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"

@interface TKAAccountant : TKAEmployee
@property (nonatomic ,readonly) NSSet *delegatingObjects;

- (void)countMoney;

@end
