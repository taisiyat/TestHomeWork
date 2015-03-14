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
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Declarations

static
void TKAStringCreateTest();

static
void TKAStringBehaviorTest();

static
void TKAStringSetNullDataTest();

static
void TKAStringOutputTest(TKAString *string);

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
//          data should be NULL, length should be 0
//          objects reference count should be 1
//              after releasing
//                  data should be NULL, length should be 0
//                  objects reference count should be 0
//

void TKAStringCreateTest() {
    // TKAString
    //      after being created
    TKAString * stringTest = TKAObjectCreate(TKAString);
//    TKAStringOutputTest(stringTest);
    //          data should be NULL, length should be 0
    assert(NULL == TKAStringGetData(stringTest));
    assert(0 == TKAStringGetLength(stringTest));
    //          objects reference count should be 1
    assert(1 == TKAObjectGetReferenceCount(stringTest));
    
    TKAObjectRelease(stringTest);
    //                  data should be NULL, length should be 0
    assert(NULL == TKAStringGetData(stringTest));
    assert(0 == TKAStringGetLength(stringTest));
    //                  objects reference count should be 0
    assert(0 == TKAObjectGetReferenceCount(stringTest));
}

// TKAString
//      after being created
//             data should be NULL, length should be 0
//             objects reference count should  be 1
//                      after copying char data
//                          data should be not NULL, data should be equal char data
//                          length should be not 0
//                          objects reference count shouldn't change, should be equal 1
//                              after copying shorter char data, not NULL
//                                  data should be not NULL, data should be equal char data
//                                  length should decrease, should be equal length char data + 1, not 0
//                                  objects reference count shouldn't change, should be equal 1
//                                              after releasing
//                                                  data should be NULL, length should be 0
//                                                  objects reference count should be 0

void TKAStringBehaviorTest() {
    // TKAString
    //      after being created
    TKAString * stringTest = TKAObjectCreate(TKAString);
//    TKAStringOutputTest(stringTest);
    //              data should be NULL, length should be 0
    assert(NULL == TKAStringGetData(stringTest));
    assert(0 == TKAStringGetLength(stringTest));
    //              objects reference count should be 1
    assert(1 == TKAObjectGetReferenceCount(stringTest));

    //                      after copying long char data
    char *longString = "bigCharLongString";
    TKAStringSetData(stringTest, longString);
    //                          data should be not NULL, data should be equal char data
    assert(NULL != TKAStringGetData(stringTest));
    assert(0 == strcmp(longString, TKAStringGetData(stringTest)));
    //                          length should be not 0
    assert(0 != TKAStringGetLength(stringTest));
    assert(strlen(longString)+1 == TKAStringGetLength(stringTest));
    //                          objects reference count shouldn't change, should be equal 1
    assert(1 == TKAObjectGetReferenceCount(stringTest));
//    TKAStringOutputTest(stringTest);
    
    //                              after copying shorter char data, not NULL
    char *shortString = "shortString";
    TKAStringSetData(stringTest, shortString);
    //                                  data should be not NULL, data should be equal char data
    assert(NULL != TKAStringGetData(stringTest));
    assert(0 == strcmp(shortString, TKAStringGetData(stringTest)));
    //                                  length should decrease, should be equal length char data + 1, not 0
    assert(0 != TKAStringGetLength(stringTest));
    assert(strlen(shortString)+1 == TKAStringGetLength(stringTest));
    //                                  objects reference count shouldn't change, should be equal 1
    assert(1 == TKAObjectGetReferenceCount(stringTest));
//    TKAStringOutputTest(stringTest);
    
    //                                            after releasing
    TKAObjectRelease(stringTest);
    //                                                  data should be NULL, length should be 0
    assert(NULL == TKAStringGetData(stringTest));
    assert(0 == TKAStringGetLength(stringTest));
    //                                                  objects reference count should be 0
    assert(0 == TKAObjectGetReferenceCount(stringTest));
}

// TKAString
//      after being created
//            data should be NULL, length should be 0
//            objects reference count should  be 1
//                 after seting NULL data
//                     data should be NULL
//                     length should be 0
//                     objects reference count shouldn't change, should be equal 1
//                          after set char data not NULL
//                              data should be not NULL, data should be equal char data
//                              length should be not 0
//                              objects reference count shouldn't change, should be equal 1
//                                  after copying char data equal ""
//                                      data should be not NULL, data should be equal char data ""
//                                      length should decrease, should be equal length char data + 1, should be equal 1, not 0
//                                      objects reference count shouldn't change, should be equal 1
//                                          after seting NULL data
//                                              data should be NULL,
//                                              length should be equal 0
//                                              objects reference count shouldn't change, should be equal 1
//                                                  after releasing
//                                                      data should be NULL, length should be 0
//                                                      objects reference count should be 0


void TKAStringSetNullDataTest() {
    // TKAString
    //      after being created
    TKAString * stringTest = TKAObjectCreate(TKAString);
    //              data should be NULL, length should be 0
    assert(NULL == TKAStringGetData(stringTest));
    assert(0 == TKAStringGetLength(stringTest));
    //              objects reference count should be 1
    assert(1 == TKAObjectGetReferenceCount(stringTest));
    
    //                  after seting NULL data
    char *nullString = NULL;
    TKAStringSetData(stringTest, nullString);
    //                      data should be NULL, length should be 0
    assert(NULL == TKAStringGetData(stringTest));
    assert(0 == TKAStringGetLength(stringTest));
    //                      objects reference count should be 1
    assert(1 == TKAObjectGetReferenceCount(stringTest));
    
    //                              after set char data not NULL
    char *notNullString = "scharString";
    TKAStringSetData(stringTest, notNullString);
    //                                  data should be not NULL, data should be equal char data
    assert(NULL != TKAStringGetData(stringTest));
    assert(0 == strcmp(notNullString, TKAStringGetData(stringTest)));
    //                                  length should be equal length char data + 1, not 0
    assert(0 != TKAStringGetLength(stringTest));
    assert(strlen(notNullString)+1 == TKAStringGetLength(stringTest));
    //                                  objects reference count shouldn't change, should be equal 1
    assert(1 == TKAObjectGetReferenceCount(stringTest));
//    TKAStringOutputTest(stringTest);

    //                                       after copying char data equal ""
    char *zeroString = "";
    TKAStringSetData(stringTest, zeroString);
//    TKAStringOutputTest(stringTest);
    //                                          data should be not NULL, data should be equal char data ""
    assert(NULL != TKAStringGetData(stringTest));
    assert(0 == strcmp(zeroString, TKAStringGetData(stringTest)));
    //                                          length should decrease, should be equal length char data + 1, should be equal 1, not 0
    assert(0 != TKAStringGetLength(stringTest));
    assert(strlen(zeroString)+1 == TKAStringGetLength(stringTest));
    //                                          objects reference count shouldn't change, should be equal 1
    assert(1 == TKAObjectGetReferenceCount(stringTest));
    

    //                                              after seting NULL data
    TKAStringSetData(stringTest, nullString);
    //                      data should be NULL, length should be 0
    assert(NULL == TKAStringGetData(stringTest));
    assert(0 == TKAStringGetLength(stringTest));
    //                      objects reference count should be 1
    assert(1 == TKAObjectGetReferenceCount(stringTest));
    
    //                                            after releasing
    TKAObjectRelease(stringTest);
    //                                                  data should be NULL, length should be 0
    assert(NULL == TKAStringGetData(stringTest));
    assert(0 == TKAStringGetLength(stringTest));
    //                                                  objects reference count should be 0
    assert(0 == TKAObjectGetReferenceCount(stringTest));
}

#pragma mark -
#pragma mark Public Implementations

void TKAStringTest() {
    
    TKAStringCreateTest();

    TKAStringBehaviorTest();
    
    TKAStringSetNullDataTest();

}



