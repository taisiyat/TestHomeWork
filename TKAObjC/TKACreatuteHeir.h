//
//  TKACretuteWithGender.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 15.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKACreature.h"

typedef enum TKAGender {
    TKAMale,
    TKAFemale,
} TKAGender;

@interface TKACreatuteHeir : TKACreature
@property (nonatomic, assign)   TKAGender   gender;


- (void)giveBirth;
- (void)fight;

- (void)checkGender;

@end
