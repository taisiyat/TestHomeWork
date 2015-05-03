//
//  TKAAlphabet.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 03.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAAlphabet.h"

#import "TKARangeAlphabet.h"
#import "TKAStringsAlphabet.h"
#import "TKAClusterAlphabet.h"

#import "NSString+TKAExtension.h"

NSRange TKAMakeRange(char firstValue, char secondValue) {
    char minValue = MIN(firstValue, secondValue);
    char maxValue = MAX(firstValue, secondValue);
   
    return NSMakeRange(minValue, maxValue - minValue);
}

@implementation TKAAlphabet

#pragma mark -
#pragma mark Class methods

+ (instancetype)alphabetWithRange:(NSRange)range {
    return [[[TKARangeAlphabet alloc] initWithRange:range] autorelease];
}

+ (instancetype)alphabetWithStrings:(NSArray *)strings {
    return [[[TKAStringsAlphabet alloc] initWithStrings:strings] autorelease];
}

+ (instancetype)alphabetWithSymbols:(NSString *)string {
    return [[[self alloc] initWithSymbols:string] autorelease];
}

+ (instancetype)alphabetWithAlphabets:(NSArray *)alphabets {
    return [[[TKAClusterAlphabet alloc] initWithAlphabets:alphabets] autorelease];
}

#pragma mark -
#pragma mark Initializations and Dellocations

- (void)dealloc {
    [super dealloc];
}

- (instancetype)initWithRange:(NSRange)range {
    [self release];
    
    return [[TKARangeAlphabet alloc] initWithRange:range];
}

- (instancetype)initWithStrings:(NSArray *)strings{
    [self release];
    
    return [[TKAStringsAlphabet alloc] initWithStrings:strings];
}

- (instancetype)initWithSymbols:(NSString *)string{
    return [self initWithStrings:[string symbols]];
}

- (instancetype)initWithAlphabets:(NSArray *)alphabets{
    [self release];
    
    return [[TKAClusterAlphabet alloc] initWithAlphabets:alphabets];
}

#pragma mark -
#pragma mark Public

- (NSUInteger)count {
    [self doesNotRecognizeSelector:_cmd];
    
    return 0;
}

- (NSString *)stringsAtIndex:(NSUInteger)index {
    [self doesNotRecognizeSelector:_cmd];
    
    return nil;
}

- (NSString *)string {
    NSMutableString *result = [NSMutableString stringWithCapacity:[self count]];
    for (NSString *symbol in self) {
        [result appendString:symbol];
    }
    
    return [[result copy] autorelease];
}

#pragma mark -
#pragma mark NSFastEnumeration

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id [])buffer
                                    count:(NSUInteger)len
{
    
}

@end