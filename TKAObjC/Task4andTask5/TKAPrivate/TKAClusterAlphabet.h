//
//  TKAClusterAlphabet.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 03.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAAlphabet.h"

@interface TKAClusterAlphabet : TKAAlphabet
@property (nonatomic,readonly)  NSArray     *alphabets;

- (instancetype)initWithAlphabets:(NSArray *)alphabets;

@end
