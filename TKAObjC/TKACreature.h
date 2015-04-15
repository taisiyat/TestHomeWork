//
//  TKACreature.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 15.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TKACreature;

@interface TKACreature : NSObject

@property (nonatomic, retain)      NSString     *name;
@property (nonatomic, assign)      NSUInteger   weight;
@property (nonatomic, assign)      NSUInteger   age;
@property (nonatomic, readonly)    NSArray      *children;

+ (instancetype)creature;
+ (instancetype)creatureWithName:(NSString *)name;

- (void)performGenderSpecificOperation;

- (void)output;

@end