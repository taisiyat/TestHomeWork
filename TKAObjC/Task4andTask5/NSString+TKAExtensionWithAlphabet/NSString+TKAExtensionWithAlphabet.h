//
//  NSString+TKAExtensionWithAlphabet.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TKAAlphabet;

@interface NSString (TKAExtensionWithAlphabet)
+ (instancetype)lovercaseLetterAlphabet;
+ (instancetype)capitalizedLetterAlphabet;
+ (instancetype)numericAlphabet;
+ (instancetype)punctuationMarkAlpabet;

//+ (id)alphabetWithRange:(NSRange)range;

+ (instancetype)randomString;
+ (instancetype)randomStringWithLength:(NSUInteger)length;
+ (instancetype)randomStringWithLength:(NSUInteger)length alphabet:(TKAAlphabet *)alphabet;

- (NSArray *)symbols;
@end
