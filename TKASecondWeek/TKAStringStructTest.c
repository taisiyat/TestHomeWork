//
//  TKAStringStructTest.c
//  TKASecondWeek
//
//  Created by Taisiya on 28.02.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAStringStructTest.h"

#pragma mark -
#pragma mark Privat Declarations

static
void TKAStringStructTest();

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

void TKAStringStructTest() {
    
    TKAStringStruct *stringOne = TKAStringStructCreateTest("testone");
    TKAStringStructOutput(stringOne);
    printf (" %llu ", TKAStringStructGetLength(stringOne));
    printf("\n");
    
    TKAStringStructCopyData(stringOne, "testsecond", strlen("testsecond"));
    TKAStringStructOutput(stringOne);
    printf (" %llu ", TKAStringStructGetLength(stringOne));
    printf("\n");
    
    TKAStringStructCopyData(stringOne, "", strlen(""));
    TKAStringStructOutput(stringOne);
    printf (" %llu ", TKAStringStructGetLength(stringOne));
    printf("\n");

    TKAStringStructCopyData(stringOne, "z", strlen("z"));
    TKAStringStructOutput(stringOne);
    printf (" %llu ", TKAStringStructGetLength(stringOne));
    printf("\n");
    
    TKAStringStructKillTest(stringOne);
}

#pragma mark -
#pragma mark Public Implementations

TKAStringStruct *TKAStringStructCreateTest(char *string) {
    TKAStringStruct *stringTest = TKAStringStructCreate();
    TKAStringStructCopyData(stringTest, string, strlen(string));
    
    return stringTest;
}

void TKAStringStructKillTest(TKAStringStruct *stringTest) {
    TKAStringStructRelease(stringTest);
}

void TKAStringStructTestMain() {
    
    TKAStringStructTest();
}