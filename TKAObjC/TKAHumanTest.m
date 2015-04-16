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
#import "TKACreatureMale.h"
#import "TKACreatureFemale.h"

#pragma mark -
#pragma mark Private Declarations


#pragma mark -
#pragma mark Public Methods

void TKAHumanTask1Test() {
    @autoreleasepool {
        TKAHuman *Adam = [TKAHuman humanWithName:@"adam" gender:TKAMale];
        TKAHuman *Eva = [TKAHuman humanWithName:@"eva" gender:TKAFemale];
        TKAHuman *Child1 = [TKAHuman humanWithName:@"child1" gender:TKAMale];
        TKAHuman *Child2 = [TKAHuman humanWithName:@"child2" gender:TKAFemale];
        NSArray *humans = [NSArray arrayWithObjects:Adam, Eva, Child1, Child2, nil];
        
        [Adam addChild:Child1];
        [Eva addChild:Child1];
        [Adam addChild:Child2];
        [Eva addChild:Child2];
        [Adam removeChild:Child1];
        [Adam removeChild:Child1];
        [Child2 addChild:Child1];
            
        for (TKAHuman *human in [Adam children]) {
             [human output];
        }
        
        for (TKAHuman *human in humans) {
            [human performGenderSpecificOperation];
            [human output];
        }
           
        [Adam sayHi];
    }
}

void TKACreatureTask2Test() {
    @autoreleasepool {
        TKACreature *god = [TKACreature creatureWithName:@"God"];
        TKACreatureMale *adam = [TKACreatureMale creatureWithName:@"Adam"];
        TKACreatureFemale *eve = [TKACreatureFemale creatureWithName:@"Eve"];
        NSArray *creatures = [NSArray arrayWithObjects:adam, eve, nil];
        
        for (TKACreature *creature in creatures) {
            [creature performGenderSpecificOperation];
        }
    }
}

#pragma mark -
#pragma mark Private Methods


