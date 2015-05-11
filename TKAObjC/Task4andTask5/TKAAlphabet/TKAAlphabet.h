//
//  TKAAlphabet.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 03.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

extern
NSRange TKAMakeRange(unichar firstValue, unichar secondValue);

@interface TKAAlphabet : NSObject <NSFastEnumeration>
+ (instancetype)lovercaseLetterAlphabet;
+ (instancetype)capitalizedLetterAlphabet;
+ (instancetype)numericAlphabet;
+ (instancetype)punctuationMarkAlpabet;

+ (instancetype)alphabetWithRange:(NSRange)range;
+ (instancetype)alphabetWithStrings:(NSArray *)strings;
+ (instancetype)alphabetWithSymbols:(NSString *)string;
+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets;

- (instancetype)initWithRange:(NSRange)range;
- (instancetype)initWithStrings:(NSArray *)strings;
- (instancetype)initWithSymbols:(NSString *)string;
- (instancetype)initWithAlphabets:(NSArray *)alphabets;

- (NSUInteger)count;
- (NSString *)stringAtIndex:(NSUInteger)index;
- (NSString *)string;
- (NSString *)objectAtIndexedSubscript:(NSUInteger)index;

@end
