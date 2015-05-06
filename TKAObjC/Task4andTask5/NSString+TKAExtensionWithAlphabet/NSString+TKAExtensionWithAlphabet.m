//
//  NSString+TKAExtensionWithAlphabet.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "NSString+TKAExtensionWithAlphabet.h"
#import "TKAAlphabet.h"

const NSUInteger kArbitrarySrtingLengthWithAlphabet = 10;

@implementation NSString (TKAExtensionWithAlphabet)

+ (instancetype)randomString {
    return [self randomStringWithLength:arc4random_uniform(kArbitrarySrtingLengthWithAlphabet)];
}

+ (instancetype)randomStringWithLength:(NSUInteger)length {
    return [self randomStringWithLength:length
                               alphabet:[TKAAlphabet lovercaseLetterAlphabet]];
}

+ (instancetype)randomStringWithLength:(NSUInteger)length
                    alphabet:(TKAAlphabet *)alphabet
{
    NSMutableString *result = [NSMutableString stringWithCapacity:length];
    
    for (NSUInteger index = 0; index < length; index++) {
        NSString *symbol = [alphabet stringAtIndex:arc4random_uniform((u_int32_t)[alphabet count])];
        [result appendString:symbol];
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
