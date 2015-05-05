//
//  NSString+TKAExtensionWithAlphabet.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "NSString+TKAExtensionWithAlphabet.h"
#import "TKAAlphabet.h"

const NSUInteger kArbitrarySrtingLength = 10;

@implementation NSString (TKAExtensionWithAlphabet)

+ (instancetype)lovercaseLetterAlphabet {
    return [[TKAAlphabet alphabetWithRange:TKAMakeRange('a', 'z')] string];
}

+ (instancetype)capitalizedLetterAlphabet {
    return [[TKAAlphabet alphabetWithRange:TKAMakeRange('A', 'Z')] string];
}

+ (instancetype)numericAlphabet {
    return [[TKAAlphabet alphabetWithStrings:@[@"1234", @"567", @"890"]] string];
}

+ (instancetype)punctuationMarkAlpabet {
    return [[TKAAlphabet alphabetWithSymbols:@".!?"] string];
};


+ (instancetype)randomString {
    return [self randomStringWithLength:arc4random_uniform(kArbitrarySrtingLength)];
}

+ (instancetype)randomStringWithLength:(NSUInteger)length {
    return [self randomStringWithLength:length
                               alphabet:[TKAAlphabet alphabetWithRange:TKAMakeRange('a', 'z')]];
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
