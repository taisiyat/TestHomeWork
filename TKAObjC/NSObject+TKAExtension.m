//
//  NSObject+TKAExtension.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 20.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "NSObject+TKAExtension.h"

@implementation NSObject (TKAExtension)

- (id)object {
    return [[[self alloc] init] autorelease];
}

@end
