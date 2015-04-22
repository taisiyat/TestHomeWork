//
//  TKACar.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEnterprise.h"
#import "TKAMoney.h"

#import "NSObject+TKAExtension.h"

@interface TKACar : NSObject
@property (nonatomic, copy)     NSString        *number;
@property (nonatomic, assign)   TKACarCondition condition;
@property (nonatomic, retain)   TKAMoney        *money;

+ (instancetype)carWithNumber:(NSString *)number
                            amount:(NSUInteger)anount;

- (void)output;
- (id)carIsClean;

@end
