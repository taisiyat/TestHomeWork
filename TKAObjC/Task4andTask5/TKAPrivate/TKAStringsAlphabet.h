//
//  TKAStringsAlphabet.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 03.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAAlphabet.h"

@interface TKAStringsAlphabet : TKAAlphabet
@property (nonatomic,readonly)  NSArray     *strings;

- (instancetype)initWithStrings:(NSArray *)strings;

@end
