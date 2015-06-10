//
//  TKACarGenerator.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 09.06.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TKAEnterprise;
@class TKATimer;

@interface TKACarGenerator : NSObject
@property (nonatomic, retain) TKATimer *timer;

+ (instancetype)carGenerator;

- (void)carGenerationForEnterprise:(TKAEnterprise *)enterprise;

@end
