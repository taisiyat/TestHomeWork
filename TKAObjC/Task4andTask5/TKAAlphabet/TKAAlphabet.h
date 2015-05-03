//
//  TKAAlphabet.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 03.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

extern
NSRange TKAMakeRange(char firstValue, char secondValue);

@interface TKAAlphabet : NSObject <NSFastEnumeration>
+ (instancetype)alphabetWithRange:(NSRange)range;
+ (instancetype)alphabetWithStrings:(NSArray *)strings;
+ (instancetype)alphabetWithSymbols:(NSString *)string;
+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets;

- (instancetype)initWithRange:(NSRange)range;
- (instancetype)initWithStrings:(NSArray *)strings;
- (instancetype)initWithSymbols:(NSString *)string;
- (instancetype)initWithAlphabets:(NSArray *)alphabets;

- (NSUInteger)count;
- (NSString *)stringsAtIndex:(NSUInteger)index;
- (NSString *)string;

@end