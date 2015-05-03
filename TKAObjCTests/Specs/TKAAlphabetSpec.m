//
//  TKAAlphabetSpec.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 03.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//


#import "Kiwi.h"

#import "TKAAlphabet.h"
#import "TKARangeAlphabet.h"

SPEC_BEGIN(TKAAlphabetSpec)

describe(@"TKAAlphabet", ^{
    __strong __block TKAAlphabet *alphabet = nil;
    
    afterAll(^{
        alphabet = nil;
    });
    
    context(@"when initialized with +alfabetWithRange: 'a'-'b'", ^{
     
        beforeAll(^{
            alphabet = [TKAAlphabet alphabetWithRange:TKAMakeRange('a','b')];
        });
        
//        afterAll(^{ // Occurs once
//        });
//        
//        beforeEach(^{ // Occurs before each enclosed "it"
//        });
//        
//        afterEach(^{ // Occurs after each enclosed "it"
//        });
        
        it(@"should be of class TKARangeAlphabet", ^{
            [[alphabet should] beKindOfClass:[TKARangeAlphabet class]];
        });
        
//        specify(^{
////            [[variable shouldNot] beNil];
//        });
        
//        context(@"inner context", ^{
//            it(@"does another thing", ^{
//            });
//            
//            pending(@"something unimplemented", ^{
//            });
//        });
    });
});

SPEC_END