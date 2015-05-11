//
//  TKACarBathSpec.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 10.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

#import "Kiwi.h"
#import "TKAEnterprise.h"

SPEC_BEGIN(TKACarBathSpec)

describe(@"ClassName", ^{
    registerMatchers(@"BG"); // Registers BGTangentMatcher, BGConvexMatcher, etc.
    
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