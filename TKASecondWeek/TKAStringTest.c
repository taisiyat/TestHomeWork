//
//  TKAStringTest.c
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAStringTest.h"
#include <assert.h>

#pragma mark -
#pragma mark Privat Declarations

static
void TKAStringTest();

static
void TKAStringOutputTest(TKAString *string);

static
void TKAStringCreateWithNULLTest();

static
void TKAStringCopyLongerLengthTest();

static
void TKAStringCopyShorterLengthTest();

static
void TKAStringCopyNULLTest();

static
void TKAStringNULLCopyNULLTest();


#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

void TKAStringOutputTest(TKAString *string) {
    TKAStringOutput(string);
    printf ("  length = %llu, ", TKAStringGetLength(string));
    printf("referenceCount = %llu ", TKAObjectGetReferenceCount(string));
    printf("\n");
}

// TKAString
//      after being created
//             data should be NULL, length should be 0
//                  objects reference count should 1

void TKAStringCreateWithNULLTest() {
    TKAString * stringTest = TKAObjectCreate(TKAString);
    TKAStringOutputTest(stringTest);
    
    assert(NULL == TKAStringGetData(stringTest));
    assert(0 == TKAStringGetLength(stringTest));
    assert(1 == TKAObjectGetReferenceCount(stringTest));
    
    TKAObjectRelease(stringTest);
    TKAStringOutputTest(stringTest);
}

// TKAString
//      after being created
//             data should be NULL, length should be not 0
//                  objects reference count shouldn't change
//                      after copying data
//                          data should be not NULL, length should be not 0
//                              objects reference count shouldn't change
//
void TKAStringCopyLongerLengthTest() {
    TKAString * stringTest = TKAObjectCreate(TKAString);
    TKAStringOutputTest(stringTest);

    char *charString = "bigsizezzzzzzzzzz";
    TKAStringSetData(stringTest, charString);
    assert(0 == strcmp(charString, TKAStringGetData(stringTest)));
    assert(strlen(charString)+1 == TKAStringGetLength(stringTest));
    assert(1 == TKAObjectGetReferenceCount(stringTest));
    TKAStringOutputTest(stringTest);
    
    TKAObjectRelease(stringTest);
    TKAStringOutputTest(stringTest);
}

void TKAStringCopyShorterLengthTest() {
    TKAString * stringTest = TKAObjectCreate(TKAString);
    
    char *charString1 = "bigsizezzzzzzzzzzzzzzzz";
    TKAStringSetData(stringTest, charString1);
    assert(0 == strcmp(charString1, TKAStringGetData(stringTest)));
    assert(strlen(charString1)+1 == TKAStringGetLength(stringTest));
    assert(1 == TKAObjectGetReferenceCount(stringTest));
    TKAStringOutputTest(stringTest);
    
    char *charString2 = "smallsize";
    TKAStringSetData(stringTest, charString2);
    assert(0 == strcmp(charString2, TKAStringGetData(stringTest)));
    assert(strlen(charString2)+1 == TKAStringGetLength(stringTest));
    assert(1 == TKAObjectGetReferenceCount(stringTest));
    TKAStringOutputTest(stringTest);

    TKAObjectRelease(stringTest);
}

void TKAStringCopyNULLTest() {
    TKAString * stringTest = TKAObjectCreate(TKAString);
    
    char *charString1 = "bigsizezzzzzzzzzzzzzzzz";
    TKAStringSetData(stringTest, charString1);
    assert(0 == strcmp(charString1, TKAStringGetData(stringTest)));
    assert(strlen(charString1)+1 == TKAStringGetLength(stringTest));
    assert(1 == TKAObjectGetReferenceCount(stringTest));
    TKAStringOutputTest(stringTest);
    
    char *charString2 = NULL;
    TKAStringSetData(stringTest, charString2);
    TKAStringOutputTest(stringTest);
    
    TKAObjectRelease(stringTest);
}

void TKAStringNULLCopyNULLTest() {
    TKAString * stringTest = TKAObjectCreate(TKAString);
    TKAStringOutputTest(stringTest);
  
    char *charString2 = NULL;
    TKAStringSetData(stringTest, charString2);
    assert(NULL == TKAStringGetData(stringTest));
    assert(0 == TKAStringGetLength(stringTest));
    assert(1 == TKAObjectGetReferenceCount(stringTest));
    TKAStringOutputTest(stringTest);
    
    TKAObjectRelease(stringTest);
}


void TKAStringTest() {
    TKAStringCreateWithNULLTest();
    printf("\n");
    TKAStringCopyLongerLengthTest();
    printf("\n");
    TKAStringCopyShorterLengthTest();
    printf("\n");
    TKAStringCopyNULLTest();
    printf("\n");
    TKAStringNULLCopyNULLTest();
}

#pragma mark -
#pragma mark Public Implementations

TKAString *TKAStringCreateTest(char *string) {
    TKAString * stringTest = TKAObjectCreate(TKAString);
    TKAStringSetData(stringTest, string);
    
    return stringTest;
}

void TKAStringTestMain() {
    
    TKAStringTest();
}

