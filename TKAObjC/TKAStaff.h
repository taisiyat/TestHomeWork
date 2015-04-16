//
//  TKAStaff.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAPerson.h"
#import "TKAMoney.h"

@interface TKAStaff : TKAPerson
@property(nonatomic, retain) NSString   *staffPosition;
@property(nonatomic, assign) NSString   *duties;
@property(nonatomic, assign) NSUInteger experience;
@property(nonatomic, assign) NSUInteger salary;
@property(nonatomic, assign) NSUInteger materiallyResponsible;//money

+(instancetype)staffWhithPosition:(NSString *)staffPosition
                           salary:(NSUInteger) salary;
@end
