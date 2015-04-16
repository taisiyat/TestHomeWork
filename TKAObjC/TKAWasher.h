//
//  TKAWasher.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAStaff.h"
#import "TKAPerson.h"
#import "TKACar.h"
#import "TKAMoney.h"

@interface TKAWasher : TKAStaff
@property(nonatomic, retain) TKACar *car;
@property(nonatomic, retain) TKAStaff *staff;
@property(nonatomic, retain) TKAPerson *person;
@property(nonatomic, readonly) TKAMoney *money;
//@property NSArray *money;//money

+(instancetype)washerWhithPerson:(TKAPerson *)person
                           staff:(TKAStaff *)staff;

@end
