//
//  TKAHumanTest.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 14.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TKAHumanObj.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKAHumanCreateTest();

static
void TKAHumanGenderTest();

#pragma mark -
#pragma mark Public Methods

void TKAHumanTask1Test() {
    
   // TKAHumanCreateTest();
    TKAHumanGenderTest();

}

#pragma mark -
#pragma mark Private Methods

void TKAHumanCreateTest() {
     NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    TKAHumanObj *humanAdam = [[[TKAHumanObj alloc] init] autorelease];
    [humanAdam writeHuman:@"adam" weight:80 age:35 gender:TKAMale sizeArray:4];
    [humanAdam output];
    TKAHumanObj *humanEva = [[[TKAHumanObj alloc] init] autorelease];
    [humanAdam writeHuman:@"eva" weight:70 age:30 gender:TKAFemale sizeArray:4];
    [humanAdam output];
    TKAHumanObj *humanSun = [[[TKAHumanObj alloc] init] autorelease];
    [humanAdam writeHuman:@"sun" weight:60 age:15 gender:TKAMale sizeArray:4];
    [humanAdam output];
    NSArray *arrayOfHuman = [NSArray arrayWithObjects:humanAdam, humanEva, humanSun, nil];
    [pool drain];
}

void TKAHumanGenderTest() {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    TKAHumanObj *humanAdam = [[[TKAHumanObj alloc] init] autorelease];
    [humanAdam writeHuman:@"adam" weight:80 age:35 gender:TKAMale sizeArray:4];
   // [humanAdam output];
    TKAHumanObj *humanEva = [[[TKAHumanObj alloc] init] autorelease];
    [humanAdam writeHuman:@"eva" weight:70 age:30 gender:TKAFemale sizeArray:4];
   // [humanAdam output];
    TKAHumanObj *humanSun = [[[TKAHumanObj alloc] init] autorelease];
    [humanAdam writeHuman:@"sun" weight:60 age:15 gender:TKAMale sizeArray:4];
   // [humanAdam output];
    NSArray *arrayOfHuman = [NSArray arrayWithObjects:humanAdam, humanEva, humanSun, nil];
    
    uint8_t sizeArray = 3;
    
    for (uint8_t iter = 0; iter < sizeArray; iter++) {
        [[arrayOfHuman objectAtIndex:(iter)] output];
        [[arrayOfHuman objectAtIndex:(iter)] checkGender];
    }
    [pool drain];
   
}
