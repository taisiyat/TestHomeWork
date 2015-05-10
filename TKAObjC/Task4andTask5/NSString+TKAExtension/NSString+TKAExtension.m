//
//  NSString+TKAExtension.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 01.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "NSString+TKAExtension.h"
static const NSUInteger kArbitrarySrtingLength = 10;

@implementation NSString (TKAExtension)

+ (id)lovercaseLetterAlphabet {
    return [self alphabetWithRange:NSMakeRange('a', 'z' - 'a' + 1)];
}

+ (id)capitalizedLetterAlphabet {
    return [self alphabetWithRange:NSMakeRange('A', 'Z' - 'A' + 1)];
}

+ (id)numericAlphabet {
    return [self alphabetWithRange:NSMakeRange('0', '9' - '0' + 1)];
}

+ (id)punctuationMarkAlpabet {
    return [self stringWithString:@".!?"];
};

+ (id)alphabetWithRange:(NSRange)range {
    NSMutableString *result = [NSMutableString stringWithCapacity:range.length];
    for (char symbol = range.location; symbol < NSMaxRange(range); symbol++) {
        [result appendFormat:@"%c",symbol];
    }
    
    return [self stringWithString:result];
}

+ (instancetype)randomString {
    return [self randomStringWithLength:arc4random_uniform(kArbitrarySrtingLength)];
}

+ (id)randomStringWithLength:(NSUInteger)length {
    return [self randomStringWithLength:length alphabet:[self lovercaseLetterAlphabet]];
}

+ (id)randomStringWithLength:(NSUInteger)length
                    alphabet:(NSString *)alphabet
{
    NSMutableString *result = [NSMutableString stringWithCapacity:length];
    
    for (NSUInteger index = 0; index < length; index++) {
        char symbol = [alphabet characterAtIndex:arc4random_uniform((uint32_t)[alphabet length])];
        [result appendFormat:@"%c",symbol];
    }
    
    return [self stringWithString:result];
}

- (NSArray *)symbols {
    NSUInteger length = [self length];
    NSMutableArray *result = [NSMutableArray arrayWithCapacity:length];
    
    for (NSUInteger index = 0; index < length; index++) {
        [result addObject:[NSString stringWithFormat:@"%c",[self characterAtIndex:index]]];
    }
    
    return [[result copy] autorelease];
}

@end
