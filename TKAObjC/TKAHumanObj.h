//
//  TKAHumanObj.h
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

@interface TKAHumanObj : NSObject {

}

@property (nonatomic, retain)      NSString *name;
@property (nonatomic, retain)      NSArray *children;
@property (nonatomic, assign)      NSUInteger weight;
@property (nonatomic, assign)      NSUInteger age;
@property (nonatomic, assign)      TKAGender gender;

+ (instancetype)human;

- (void)fight;
- (TKAHumanObj *)giveBirth;
- (void)addChild:(TKAHumanObj *)children;
- (void)removeChild:(TKAHumanObj *)children;
- (void)sayHi;

- (void)writeHuman:(NSString *)string
            weight:(NSUInteger)weight
               age:(NSUInteger)age
            gender:(TKAGender)gender
         sizeArray:(NSUInteger)sizeArray;
- (void)output;

@end
