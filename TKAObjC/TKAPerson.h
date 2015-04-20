//
//  TKAPerson.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TKAPerson : NSObject
@property(nonatomic, copy)      NSString   *name;

+ (instancetype)personWhithName:(NSString *)name;

@end
