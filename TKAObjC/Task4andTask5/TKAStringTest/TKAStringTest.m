//
//  TKAStringTest.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 01.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TKAStringTest.h"

#import "NSString+TKAExtension.h"

static
void TKASimpleRandomString();

static
void TKAСomplicatedRandomString();

void TKAStringTest() {
    @autoreleasepool {
        
        TKASimpleRandomString();
        TKAСomplicatedRandomString();
        
    }
}

void TKASimpleRandomString() {
    NSMutableString *resultString = [NSMutableString string];
    
    [resultString appendString:[NSString randomStringWithLength:1
                                                       alphabet:[NSString capitalizedLetterAlphabet]]];
    [resultString appendFormat:@"%@ ",[NSString randomStringWithLength:5
                                                              alphabet:[NSString lovercaseLetterAlphabet]]];
    [resultString appendFormat:@"%@ ",[NSString randomStringWithLength:6
                                                              alphabet:[NSString lovercaseLetterAlphabet]]];
    [resultString appendString:[NSString randomStringWithLength:7
                                                       alphabet:[NSString lovercaseLetterAlphabet]]];
    [resultString appendString:[NSString randomStringWithLength:1
                                                       alphabet:[NSString punctuationMarkAlpabet]]];
    
    NSLog(@"%@",resultString);
}

void TKAСomplicatedRandomString() {
    
}