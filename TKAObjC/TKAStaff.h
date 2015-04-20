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
@property(nonatomic, copy)      NSString   *staffPosition;
@property(nonatomic, assign)    NSUInteger experience;
@property(nonatomic, assign)    NSUInteger salary;

+(instancetype)staffWhithPosition:(NSString *)staffPosition
                           salary:(NSUInteger) salary;
@end
