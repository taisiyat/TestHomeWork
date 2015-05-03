//
//  TKARangeAlphabet.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 03.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKARangeAlphabet.h"

@interface TKARangeAlphabet()
@property (nonatomic, assign)   NSRange     range;

@end

@implementation TKARangeAlphabet

#pragma mark -
#pragma mark Initializations and Dellocations

- (instancetype)initWithRange:(NSRange)range {
    self = [super init];
    if (self) {
        self.range = range;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public

- (NSUInteger)count {
    return self.range.length;
}

- (NSString *)stringAtIndex:(NSUInteger)index {
    return index < self.range.length ? [NSString stringWithFormat:@"%c",(char)(self.range.location + index)] : nil;
}

@end

