//
//  TKAHumanTest.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 14.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKAHuman.h"

#pragma mark -
#pragma mark Private Declarations


#pragma mark -
#pragma mark Public Methods

void TKAHumanTask1Test() {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    TKAHuman *humanAdam = [TKAHuman humanWithName:@"adam" gender:TKAMale];
    TKAHuman *humanEva = [TKAHuman humanWithName:@"eva" gender:TKAFemale];
    TKAHuman *humanSun = [TKAHuman humanWithName:@"sun" gender:TKAMale];
    NSArray *arrayHuman = [NSArray arrayWithObjects:humanAdam, humanEva, humanSun, nil];
    
    
    [humanAdam addChild:humanSun];
    [humanEva addChild:humanSun];
    [humanAdam removeChild:humanSun];
    [humanEva removeChild:humanSun];

    for (TKAHuman *human in arrayHuman) {
        [human checkGender];
        [humanSun output];
    }
    
    [humanAdam sayHi];
    
    NSLog(@"%@", arrayHuman[0]);
    [pool drain];
}

#pragma mark -
#pragma mark Private Methods


