//
//  TKADirector.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAStaff.h"
#import "TKAPerson.h"
#import "TKAMoney.h"

@interface TKADirector : TKAStaff
@property(nonatomic, retain) TKAStaff *staff;
@property(nonatomic, retain) TKAPerson *person;
@property(nonatomic, readonly) NSArray *money;//money

+(instancetype)directorWhithPerson:(TKAPerson *)person
                             staff:(TKAStaff *)staff;

@end
