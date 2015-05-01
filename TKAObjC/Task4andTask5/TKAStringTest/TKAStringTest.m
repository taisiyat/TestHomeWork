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

static
void TKABlockTest();

void TKAStringTest() {
    @autoreleasepool {
        
        TKASimpleRandomString();
        TKAСomplicatedRandomString();
        TKABlockTest();
        
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

typedef void(^TKAOutputBlock)(NSString *);
typedef NSString *(^TKAStringBlock)();

void TKABlockTest(){
    TKAOutputBlock outputBlock = ^(id string) {
        NSLog(@"from block - %@",string);
    };
    
    TKAStringBlock stringFromBlock = ^() {
        return @" - string from block";
    };
    
    outputBlock(stringFromBlock());
    
    __block NSUInteger value = 0;
    
    void(^blockWithValue)() = ^() {
        value++;
        NSLog(@"%lu",value);
    };
    
    blockWithValue();
    blockWithValue();
    blockWithValue = [[blockWithValue copy] autorelease];
    blockWithValue();
//    blockWithValue = nil;
    blockWithValue();
}
                   
void TKAСomplicatedRandomString() {
    
}