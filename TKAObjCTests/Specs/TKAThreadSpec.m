//
//  TKAThreadSpec.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 15.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "Kiwi.h"

#import "IDPBlockAsyncRaiseIterativeMatcher.h"

#import "TKAThreadObject.h"

SPEC_BEGIN(TKACarBathSpec)

registerMatchers(@"IDP");
registerMatchers(@"KW");

describe(@"TKAThreadObject", ^{
    registerMatchers(@"BG"); // Registers BGTangentMatcher, BGConvexMatcher, etc.
    __block TKAThreadObject *testObject = nil;
    
    beforeEach(^{
        testObject = [TKAThreadObject ]
    });
    context(@"a state the component is in", ^{
        //        let(variable, ^{
        //            return [MyClass instance];
        //        });
        
        beforeAll(^{ // Occurs once
        });
        
        afterAll(^{ // Occurs once
        });
        
        beforeEach(^{ // Occurs before each enclosed "it"
        });
        
        afterEach(^{ // Occurs after each enclosed "it"
        });
        
        //        it(@"should do something", ^{
        //            [[variable should] meetSomeExpectation];
        //        });
        
        //        specify(^{
        //            [[variable shouldNot] beNil];
        //        });
        
        context(@"inner context", ^{
            it(@"does another thing", ^{
            });
            
            //            pending(@"something unimplemented", ^{
            //            });
        });
    });
});

SPEC_END