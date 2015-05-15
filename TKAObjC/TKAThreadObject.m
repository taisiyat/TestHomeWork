//
//  TKAThreadTestObject.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 15.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAThreadObject.h"

@implementation TKAThreadObject

- (void)setValue:(id)value {
    if (value != _value) {
        NSUInteger callCount = self.callCount + 1;
        self.callCount = callCount;
        [_value release];
        _value = [value retain];

        NSLog(@"sleep");
        NSLog(@"----------------%lu-----------", callCount);
        usleep(10000 * arc4random_uniform(10));
        NSLog(@"wake up");
        if (_value != value) {
            [NSException raise:NSGenericException format:nil];
            NSLog(@"Exception");
        }
        
    }
}

@end
