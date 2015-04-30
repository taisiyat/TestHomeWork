//
//  TKAMoney.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAMoney.h"
@interface TKAMoney ()

@end

@implementation TKAMoney

#pragma mark -
#pragma mark Class Methods

+ (instancetype)moneyWithAmount:(NSUInteger)amount {
    TKAMoney *money = [TKAMoney object];
    money.amount = amount;
    
    return money;
}

#pragma mark -
#pragma mark Initializations and Deallocations

//- (void)dealloc {
//    
//    [super dealloc];
//}
//
//- (instancetype)init {
//    self = [super init];
//    if (self) {
//
//    }
//    
//    return self;
//}

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:[super description]];
    [result appendFormat:@" money = %lu", self.amount];
    
    return [[result copy] autorelease];
}

#pragma mark -
#pragma mark Private Methods

@end

