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

+(instancetype)moneyWithAmount:(NSUInteger)amount
                    responsible:(NSObject *)responsible {
    TKAMoney *money = [TKAMoney object];
    money.amount = amount;
    money.responsible = responsible;
    
    return money;
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.responsible = nil;
    
    [super dealloc];
}

- (instancetype)init {
    self = [super init];
    if (self) {

    }
    
    return self;
}

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (void)output {
    NSLog(@" Money : ");
    NSLog(@" number = %lu", self.amount);
    NSLog(@" condition = %@", self.responsible);
}

#pragma mark -
#pragma mark Private Methods

@end

