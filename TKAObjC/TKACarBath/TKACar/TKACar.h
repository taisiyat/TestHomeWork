//
//  TKACar.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAMoney.h"

#import "NSObject+TKAExtension.h"

@interface TKACar : NSObject
@property(nonatomic, copy)     NSString        *number;
@property(nonatomic, retain)   TKAMoney        *money;
@property(nonatomic, assign, readwrite, getter=isClean, setter=setIsClean:)   BOOL    clean;

+ (instancetype)carWithNumber:(NSString *)number
                       amount:(NSUInteger)anount;

- (NSString *)description;

@end
