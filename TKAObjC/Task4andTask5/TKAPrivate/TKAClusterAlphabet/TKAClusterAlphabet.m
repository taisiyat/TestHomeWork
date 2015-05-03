//
//  TKAClusterAlphabet.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 03.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAClusterAlphabet.h"

@interface TKAClusterAlphabet ()
@property (nonatomic,assign)  NSArray     *alphabets;

@end

@implementation TKAClusterAlphabet

#pragma mark -
#pragma mark Initializations and Dellocations

- (void)dealloc {
    self.alphabets = nil;
    
    [super dealloc];
}

- (instancetype)initWithAlphabets:(NSArray *)alphabets {
    self = [super init];
    if (self) {
        self.alphabets = alphabets;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (NSUInteger)count {
    return [self countAllAlphabets];
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    NSUInteger countAlphabets = [self countAllAlphabets];
    if (index < countAlphabets) {
        NSUInteger iterator = 0;
        NSUInteger iteratedIndex = index;
        for (TKAAlphabet *alphabet in self.alphabets) {
            if (iterator >= index) {
                return [alphabet stringsAtIndex:iteratedIndex];
//                return alphabet[iteratedIndex];
            }
            
            iterator += [alphabet count];
            iteratedIndex -= [alphabet count];
        }
    }
    
    NSAssert(index < countAlphabets, NSRangeException);
    return nil;
}

- (NSString *)string {
    NSMutableString *result = [NSMutableString stringWithCapacity:[self countAllAlphabets]];
    for (TKAAlphabet *alphabet in self.alphabets) {
        [result appendString:[alphabet string]];
    }
    
    return [[result copy] autorelease];
}

#pragma mark -
#pragma mark Private

- (NSUInteger)countAllAlphabets {
    NSUInteger count = 0;
    for (TKAAlphabet *alphabet in self.alphabets) {
        count += [alphabet count];
    }

    return count;
}

@end
