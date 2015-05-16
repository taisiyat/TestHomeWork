//
//  TKAThreadTestObject.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 15.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAThreadObject.h"

@implementation TKAThreadObject

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.lock = nil;
    self.value = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {
//        self.lock = [[NSLock new] autorelease];
         self.lock = [[NSRecursiveLock new] autorelease];
    }
    
    return self;
}

#pragma mark -
#pragma mark Accessors

- (void)setValue:(id)value {
//    @synchronized (self) {
//        if (value != _value) {
//            NSUInteger callCount = self.callCount + 1;
//            self.callCount = callCount;
//            [_value release];
//            _value = [value retain];
//
//            NSLog(@"sleep");
//            NSLog(@"----------------%lu-----------", callCount);
//            usleep(10000 * arc4random_uniform(10));
//            NSLog(@"wake up");
//            if (_value != value) {
//                [NSException raise:NSGenericException format:nil];
//                NSLog(@"Exception");
//            }
//        }
//    }
    
//    NSLock *testLock = self.lock;
//    [testLock lock];
//                if (value != _value) {
//                    NSUInteger callCount = self.callCount + 1;
//                    self.callCount = callCount;
//                    [_value release];
//                    _value = [value retain];
//        
//                    NSLog(@"sleep");
//                    NSLog(@"----------------%lu-----------", callCount);
//                    usleep(10000 * arc4random_uniform(10));
//                    NSLog(@"wake up");
//                    if (_value != value) {
//                        [NSException raise:NSGenericException format:nil];
//                        NSLog(@"Exception");
//                    }
//                }
//    [testLock unlock];
    
    id<NSLocking> testLock = self.lock;
    [testLock lock];
    [self print];
    
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
    
    [testLock unlock];
}

-(void)print {
    id<NSLocking> testLock = self.lock;
    [testLock lock];
    NSLog(@"print-----------");
    [testLock unlock];
}

@end
