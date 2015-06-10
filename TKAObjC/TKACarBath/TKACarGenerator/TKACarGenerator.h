//
//  TKACarGenerator.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 09.06.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TKAEnterprise;

@interface TKACarGenerator : NSObject

+ (instancetype)carGenerator;

- (void)carGenerationForEnterprise:(TKAEnterprise *)enterprise;

@end
