//
//  TKAHumanTest.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 14.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKAHuman.h"
#import "TKACreature.h"

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

    for (TKAHuman *human in arrayHuman) {
        [human checkGender];
        [humanSun output];
    }
    [humanAdam removeChild:humanSun];
    [humanEva removeChild:humanSun];

    
    [humanAdam sayHi];
    
    NSLog(@"%@", arrayHuman[0]);
    [pool drain];
}

void TKACreatureTask2Test() {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    TKACreature *humanAdam = [TKACreature creatureWithName:@"adam"];
//    TKAHuman *humanEva = [TKAHuman humanWithName:@"eva" gender:TKAFemale];
//    TKAHuman *humanSun = [TKAHuman humanWithName:@"sun" gender:TKAMale];
    NSArray *creatures = [NSArray arrayWithObjects:humanAdam, nil];
    
    
//    for (TKAHuman *human in arrayHuman) {
//        [human checkGender];
//        [humanSun output];
//    }
    
    [humanAdam output];
    
   
    [pool drain];

}

#pragma mark -
#pragma mark Private Methods


