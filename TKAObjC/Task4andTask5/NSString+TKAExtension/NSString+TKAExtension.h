//
//  NSString+TKAExtension.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 01.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (TKAExtension)

+ (id)lovercaseLetterAlphabet;
+ (id)capitalizedLetterAlphabet;
+ (id)numericAlphabet;
+ (id)punctuationMarkAlpabet;

+ (id)alphabetWithRange:(NSRange)range;

+ (id)randomString;
+ (id)randomStringWithLength:(NSUInteger)length;
+ (id)randomStringWithLength:(NSUInteger)length alphabet:(NSString *)alphabet;

@end

