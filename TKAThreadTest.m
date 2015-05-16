//
//  TKAThreadTest.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 15.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKAThreadTest.h"
#import "TKAThreadObject.h"
#import "NSObject+TKAExtension.h"

static const NSUInteger kTKAExecuteCount    = 100;

void TKAThreadTestFirst() {
    @autoreleasepool {
        TKAThreadObject *testObject = [TKAThreadObject object];
//        for (NSUInteger iter = 0; iter < kTKAExecuteCount; iter++) {
//            testObject.value = [[NSObject new] autorelease];
//        }
        for (NSUInteger iter = 0; iter < kTKAExecuteCount; iter++) {
            [testObject performSelectorInBackground:@selector(setValue:) withObject:[[NSObject new] autorelease]];
        }
        
        while (true) {
            
        }
    }
}