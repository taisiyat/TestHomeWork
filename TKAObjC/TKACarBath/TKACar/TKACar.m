//
//  TKACar.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKACar.h"
#import "TKAAlphabet.h"

#import "NSString+TKAExtensionWithAlphabet.h"

@implementation TKACar

@synthesize money = _money;

#pragma mark -
#pragma mark Class Methods

+ (instancetype)carWithNumber:(NSString *)number
                  moneyAmount:(NSUInteger)moneyAmount
{
    TKACar *car = [TKACar object];
    car.number = number;
    car.money = moneyAmount;
    
    return car;
}

+ (instancetype)car {
    NSMutableString *number = [NSMutableString string];
    [number setString:@"AB"];
    [number appendString:[NSString randomStringWithLength:4 alphabet:[TKAAlphabet numericAlphabet]]];
    
    return [TKACar carWithNumber:number moneyAmount:20];
}

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.number = nil;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (NSString *)description {
    NSMutableString *result = [NSMutableString stringWithString:@" "];
    [result appendFormat:@" Car number = %@", self.number];
    [result appendFormat:@" condition = %u", self.clean];
    [result appendFormat:@" money = %lu", self.money];
    
    return [[result copy] autorelease];
}
#pragma mark -
#pragma mark TKATransferMoneyProtocol

- (NSUInteger)giveAllMoney {
    @synchronized (self) {
        NSUInteger cash = self.money;
        self.money = 0;
        
        return cash;
    }
}

#pragma mark -
#pragma mark Private Methods

@end
