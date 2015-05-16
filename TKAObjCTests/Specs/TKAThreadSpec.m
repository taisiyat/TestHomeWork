//
//  TKAThreadSpec.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 15.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

//#import <Cocoa/Cocoa.h>
//#import <XCTest/XCTest.h>

#import "Kiwi.h"

#import "IDPBlockAsyncRaiseIterativeMatcher.h"

#import "TKAThreadObject.h"

SPEC_BEGIN(TKAThreadSpec)

registerMatchers(@"IDP");
registerMatchers(@"KW");

static const NSUInteger iterCount = 100;

//describe(@"TKAThreadObject", ^{
//    registerMatchers(@"BG"); // Registers BGTangentMatcher, BGConvexMatcher, etc.
//    __block TKAThreadObject *testObject = nil;
//    
//    beforeEach(^{
//        testObject = [TKAThreadObject new];
//    });
//    
//    context(@"when modified from one thread", ^{
//        it(@"shouldn't raise", ^{
//            [[theBlock(^{
//                for (NSUInteger iter = 0; iter < iterCount; iter++) {
//                    testObject.value = [NSObject new];
//                }
//            }) shouldNot] raise];
//            
//        });
//    });
//    
////    context(@"when modified from multiple threads", ^{
////        it(@"should raise", ^{
////            [[theBlock(^{
////                testObject.value = [NSObject new];
////            }) should] raiseWithIterationCount:iterCount];
////        });
////    });
//    
////    context(@"when modified from multiple threads", ^{
////        it(@"shouldnt raise", ^{
////            [[theBlock(^{
////                testObject.value = [NSObject new];
////            }) shouldNot] raise];
////        });
////    });
//});

describe(@"TKAThreadObject", ^{
    registerMatchers(@"BG"); // Registers BGTangentMatcher, BGConvexMatcher, etc.
    __block TKAThreadObject *testObject = nil;

    beforeEach(^{
        testObject = [TKAThreadObject new];
    });

    context(@"when modified from multiple threads", ^{
        it(@"shouldnt raise", ^{
            [[theBlock(^{
                testObject.value = [NSObject new];
            }) shouldNot] raiseWithIterationCount:iterCount];
        });
    });
});


SPEC_END