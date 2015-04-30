//
//  NSObject+TKACategory.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "NSObject+TKACategory.h"

@implementation NSObject (TKACategory)

+ (id)object {
    return [[[self alloc] init] autorelease];
}

@end
