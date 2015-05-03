//
//  TKACar.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAMoney.h"

#import "NSObject+TKAExtension.h"
#import "TKATransferMoneyProtocol.h"

@interface TKACar : NSObject <TKATransferMoneyProtocol>
@property (nonatomic,copy)     NSString        *number;
@property (nonatomic,assign)   TKAMoney        *money;
@property (nonatomic,assign, getter=isClean)    BOOL    clean;

+ (instancetype)carWithNumber:(NSString *)number
                  moneyAmount:(NSUInteger)moneyAmount;

@end
