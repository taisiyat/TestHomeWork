//
//  TKAHuman.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 14.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum TKAGender {
    TKAMale,
    TKAFemale,
} TKAGender;

@interface TKAHuman : NSObject
@property (nonatomic, retain)      NSString     *name;
@property (nonatomic, assign)      NSUInteger   weight;
@property (nonatomic, assign)      NSUInteger   age;
@property (nonatomic, assign)      TKAGender    gender;
@property (nonatomic, readonly)    NSArray      *children;

+ (instancetype)human;
+ (instancetype)humanWithName:(NSString *)name
                       gender:(TKAGender)gender;

- (instancetype)giveBirth;

- (void)fight;
- (void)addChild:(TKAHuman *)child;
- (void)removeChild:(TKAHuman *)child;
- (void)sayHi;

- (void)checkGender;
- (void)humanWriteNewbornName:(NSString *)string
                       weight:(NSUInteger)weight
                          age:(NSUInteger)age
                       gender:(TKAGender)gender;
- (void)output;

@end
