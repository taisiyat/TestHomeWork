//
//  TKAArrayTest.c
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAArrayTest.h"
#include <assert.h>

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Declarations

static
void TKAArrayCreateTest();

static
void TKAArrayResizeTest();

static
void TKAArrayResizeTestOutput();


static
void TKAArrayAddRemoveObjectTest();

static
void TKAArrayAddRemoveObjectTestOutput();

static
void TKAArrayOutputTest();

#pragma mark -
#pragma mark Privat Implementations

void TKAArrayOutputTest(TKAArray *array) {
    
    TKAArrayOutput(array);
    printf("\n");
    printf(" length = %d   ", TKAArrayGetLength(array));
    printf(" count of children = %d   ", TKAArrayGetObjectCount(array));
    printf(" referense count = %llu   ", TKAObjectGetReferenceCount(array));
    printf("\n");
    printf("\n");
}

// TKAArray
//        after being created
//          array shouldnt be NULL,
//          length should be 0
//          count of child should be 0
//          objects reference count of Array should be 1
//              after check of length
//                  array shouldnt be NULL,
//                  length should be 1
//                  count of child should be 0
//                  objects reference count of Array should be 1
//                      after releasing
//                          array should be NULL,
//                          objects reference count of Array should be 0
//        after being created TKAHuman
//              array shouldnt be NULL,
//              length should be 1
//              count of child should be 0
//              objects reference count of Array should be 1
//                      after being releasing TKAHuman
//                                array shouldnt be NULL,
//                                objects reference count of Array should be 0

void TKAArrayCreateTest() {
    // TKAArray
    //        after being created
    TKAArray * testArray = TKAObjectCreate(TKAArray);
    //              array shouldnt be NULL,
    assert(NULL != testArray);
    //              length should be 0
    assert(0 == TKAArrayGetLength(testArray));
    //              count of child should be 0
    assert(0 == TKAArrayGetObjectCount(testArray));
    //              objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
//    TKAArrayOutputTest(testArray);

    //              after check of length
//    //                  array shouldnt be NULL,
//    assert(NULL != testArray);
//    //                  length should be 1
//    assert(1 == TKAArrayGetLength(testArray));
//    //                  count of child should be 0
//    assert(0 == TKAArrayGetObjectCount(testArray));
//    //                  objects reference count of Array should be 1
//    assert(1 == TKAObjectGetReferenceCount(testArray));
//    TKAArrayOutputTest(testArray);
    
    //                      after releasing
    TKAObjectRelease(testArray);
//    //                          array should be NULL,
//    assert(NULL == testArray);
//    //                          objects reference count of Array should be 0
//    assert(0 == TKAObjectGetReferenceCount(testArray));
//    TKAArrayOutputTest(testArray);

    //                              after being created TKAHuman
    TKAHuman *man = TKAHumanCreateWithNameChar("man", 35, TKAMale);
    //                                  array shouldnt be NULL,
    assert(NULL != TKAHumanGet(children, man));
    //                                  length should be 0
    assert(0 == TKAArrayGetLength(TKAHumanGet(children, man)));
    //                                  count of child should be 0
    assert(0 == TKAArrayGetObjectCount(TKAHumanGet(children, man)));
    //                                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, man)));
//    TKAArrayOutputTest(TKAHumanGet(children, man));
    
    //                                      after being releasing TKAHuman
    TKAObjectRelease(man);
}


#define TKADEFCreateObject(number) \
    TKAHuman *child_##number = TKAHumanCreateWithNameChar("child "#number" ", number, TKAMale); \

#define TKADEFAddObject(number) \
    TKAArrayAddObject(testArray, child_##number); \


#define TKADEFRemoveObject(number) \
    TKAArrayRemoveObject(testArray, child_##number);\

#define TKADEFReleaseObject(number)\
        TKAObjectRelease(child_##number);\

// TKAArray
//        after being created
//          array shouldnt be NULL,
//          length should be 0
//          count of child should be 0
//          objects reference count of Array should be 1
//              Creating Children
//              after adding child
//                  array shouldn't be NULL, first element shouldn't be NULL
//                  length should be change
//                  count of child should equal 1
//                  objects reference count of Array should be 1
//                      after adding 5 child
//                          array shouldn't be NULL,
//                          length should be change
//                          count of child should be be increment by 5
//                          objects reference count of Array should be 1
//                              after removing 2 child
//                                  array shouldn't be NULL,
//                                  length should be change
//                                  count of child should be be decrement by 2
//                                  objects reference count of Array should be 1
//                                      after removing ALL children
//                                          elements of Array shouldn be NULL,
//                                          length should be change
//                                          objects reference count of Array should be 1
//                                              ObjectRelease Children
//                                              ObjectRelease Array


void TKAArrayResizeTest() {
    // TKAArray
    //        after being created
    TKAArray * testArray = TKAObjectCreate(TKAArray);
    //              array shouldnt be NULL,
    assert(NULL != testArray);
    //              length should be 0
    assert(0 == TKAArrayGetLength(testArray));
    //              count of child should be 0
    assert(0 == TKAArrayGetObjectCount(testArray));
    //              objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    //                  Creating Children
    TKADEFCreateObject(0);
    TKADEFCreateObject(1);
    TKADEFCreateObject(2);
    TKADEFCreateObject(3);
    TKADEFCreateObject(4);
    TKADEFCreateObject(5);

    //              after adding child
    TKADEFAddObject(0);
    //                  array shouldn't be NULL, first element shouldn't be NULL
    assert(NULL != TKAArrayGetObjectAtIndex(testArray, 0));
    //                  length should be change, equal 2
    assert(0 != TKAArrayGetLength(testArray));
//    assert(2 == TKAArrayGetLength(testArray));
    //                  count of child should equal 1
    assert(1 == TKAArrayGetObjectCount(testArray));
    //                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    ///////////////////////////
//    TKAArrayOutputTest(testArray);
    
    //                      after adding 5 child
    TKADEFAddObject(1);
    TKADEFAddObject(2);
    TKADEFAddObject(3);
    TKADEFAddObject(4);
    TKADEFAddObject(5);
    /////////////////////////
//    TKAArrayOutputTest(testArray);
    //                      after adding 5 child
    //                          array shouldn't be NULL,
    assert(NULL != TKAArrayGetObjectAtIndex(testArray,0));
    assert(NULL != TKAArrayGetObjectAtIndex(testArray,1));
    assert(NULL != TKAArrayGetObjectAtIndex(testArray,4));
    assert(NULL != TKAArrayGetObjectAtIndex(testArray,5));
    //                          length should be change equal 8
    assert(0 != TKAArrayGetLength(testArray));
    assert(8 == TKAArrayGetLength(testArray));
    //                          count of child should be be increment by 5, equal 6
    assert(6 == TKAArrayGetObjectCount(testArray));
    //                          objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));

    //                              after removing 2 child
    TKADEFRemoveObject(5);
    TKADEFRemoveObject(4);
    //                                  array shouldnt be NULL,
    assert(NULL != TKAArrayGetObjectAtIndex(testArray,2));
    assert(NULL != TKAArrayGetObjectAtIndex(testArray,3));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,4));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,5));
    //                                  length should be change
    assert(0 != TKAArrayGetLength(testArray));
    assert(4 == TKAArrayGetLength(testArray));
    //                                  count of child should be be decrement by 2
     assert(4 == TKAArrayGetObjectCount(testArray));
    //                                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    ///////////////////////////
//   TKAArrayOutputTest(testArray);
    //                                      after removing ALL children
    TKAArrayRemoveAllObjectss(testArray);
    //                                 elements of array should be NULL,
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,0));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,1));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,2));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,3));
    //                                  length should be change,
    assert(0 != TKAArrayGetLength(testArray));
    //                                  count of child should be be decrement, equal 0
    assert(0 == TKAArrayGetObjectCount(testArray));
    //                                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
/////////////////////////////////////
//   TKAArrayOutputTest(testArray);
    //                                              ObjectRelease Children
    TKADEFReleaseObject(5);
    TKADEFReleaseObject(4);
    TKADEFReleaseObject(3);
    TKADEFReleaseObject(2);
    TKADEFReleaseObject(1);
    TKADEFReleaseObject(0);
    //                                              ObjectRelease Array
    TKAObjectRelease(testArray);
}

void TKAArrayResizeTestOutput() {
    // TKAArray
    //        after being created
    TKAArray * testArray = TKAObjectCreate(TKAArray);
    //              array shouldnt be NULL,
    assert(NULL != testArray);
    //              length should be 0
    assert(0 == TKAArrayGetLength(testArray));
    //              count of child should be 0
    assert(0 == TKAArrayGetObjectCount(testArray));
    //              objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    //                  Creating Children
    TKADEFCreateObject(0);
    TKADEFCreateObject(1);
    TKADEFCreateObject(2);
    TKADEFCreateObject(3);
    TKADEFCreateObject(4);
    TKADEFCreateObject(5);
    TKAArrayOutputTest(testArray);
    //              after adding child
    TKADEFAddObject(0);
    //                  array shouldn't be NULL, first element shouldn't be NULL
    assert(NULL != TKAArrayGetObjectAtIndex(testArray, 0));
    //                  length should be change, equal 2
    assert(0 != TKAArrayGetLength(testArray));
    //    assert(2 == TKAArrayGetLength(testArray));
    //                  count of child should equal 1
    assert(1 == TKAArrayGetObjectCount(testArray));
    //                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    ///////////////////////////
    //    TKAArrayOutputTest(testArray);
    
    //                      after adding 5 child
    TKADEFAddObject(1);
    TKADEFAddObject(2);
    TKADEFAddObject(3);
    TKADEFAddObject(4);
    TKADEFAddObject(5);
    /////////////////////////
   TKAArrayOutputTest(testArray);
    //                      after adding 5 child
    //                          array shouldn't be NULL,
    assert(NULL != TKAArrayGetObjectAtIndex(testArray,0));
    assert(NULL != TKAArrayGetObjectAtIndex(testArray,1));
    assert(NULL != TKAArrayGetObjectAtIndex(testArray,4));
    assert(NULL != TKAArrayGetObjectAtIndex(testArray,5));
    //                          length should be change equal 8
    assert(0 != TKAArrayGetLength(testArray));
    assert(8 == TKAArrayGetLength(testArray));
    //                          count of child should be be increment by 5, equal 6
    assert(6 == TKAArrayGetObjectCount(testArray));
    //                          objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    
    //                              after removing 2 child
    TKADEFRemoveObject(5);
    TKADEFRemoveObject(4);
//    //                                  array shouldnt be NULL,
//    assert(NULL != TKAArrayGetObjectAtIndex(testArray,2));
//    assert(NULL != TKAArrayGetObjectAtIndex(testArray,3));
//    assert(NULL == TKAArrayGetObjectAtIndex(testArray,4));
//    assert(NULL == TKAArrayGetObjectAtIndex(testArray,5));
//    //                                  length should be change
//    assert(0 != TKAArrayGetLength(testArray));
//    assert(4 == TKAArrayGetLength(testArray));
//    //                                  count of child should be be decrement by 2
//    assert(4 == TKAArrayGetObjectCount(testArray));
//    //                                  objects reference count of Array should be 1
//    assert(1 == TKAObjectGetReferenceCount(testArray));
    ///////////////////////////
  TKAArrayOutputTest(testArray);
    //                                      after removing ALL children
    TKAArrayRemoveAllObjects(testArray);
    //                                 elements of array should be NULL,
//    assert(NULL == TKAArrayGetObjectAtIndex(testArray,0));
//    assert(NULL == TKAArrayGetObjectAtIndex(testArray,1));
//    assert(NULL == TKAArrayGetObjectAtIndex(testArray,2));
//    assert(NULL == TKAArrayGetObjectAtIndex(testArray,3));
    //                                  length should be change,
//    assert(0 != TKAArrayGetLength(testArray));
//    //                                  count of child should be be decrement, equal 0
//    assert(0 == TKAArrayGetObjectCount(testArray));
//    //                                  objects reference count of Array should be 1
//    assert(1 == TKAObjectGetReferenceCount(testArray));
    /////////////////////////////////////
   TKAArrayOutputTest(testArray);
    //                                              ObjectRelease Children
    TKADEFReleaseObject(5);
    TKADEFReleaseObject(4);
    TKADEFReleaseObject(3);
    TKADEFReleaseObject(2);
    TKADEFReleaseObject(1);
    TKADEFReleaseObject(0);
    //                                              ObjectRelease Array
    TKAObjectRelease(testArray);
}


// TKAArray
//        after being created
//          elementss of array should be NULL,
//          length should be 0
//          count of child should be 0
//          objects reference count of Array should be 1
//              Creating Children
//                  after removing child from array with 0 length
//                      array shouldn't be NULL
//                      length shouldnt be change
//                      count of child shouldnt be change
//                      objects reference count of Child should be 1 , dont change
//                      objects reference count of Array should be 1
//                          after removing NULL from array with 0 length
//                              array shouldn't be NULL
//                              length shouldnt be change
//                              count of child shouldnt be change
//                              objects reference count of Array should be 1
//                                  after adding NULL to array with 0 length
//                                      array shouldn't be NULL
//                                      length should be change
//                                      count of child shouldnt be change
//                                      objects reference count of Array should be 1
//               after adding 3 child
//                      array shouldn't be NULL,
//                      3 elements of array shouldn't be NULL
//                      length should be change, should be >=3
//                      count of child should be be increment by 3, should equal 3
//                      objects reference count of Child in Array should be 2
//                      objects reference count of Array should be 1
//                           after adding 1 child, whot alredy in Array
//                                  array shouldn't changeL,
//                                  length shouldnt be change
//                                  count of child shouldnt be change
//                                  objects reference count of Child in Array shouldn't be change
//                                  objects reference count of Array should be 1
//                                      after removing NULL from array with 0 length
//                                          array shouldn't be NULL
//                                          length shouldnt be change
//                                          count of child shouldnt be change
//                                          objects reference count of Array should be 1
//                                              after adding NULL to array with 0 length
//                                                  array shouldn't be NULL
//                                                  length shouldnt be change
//                                                  count of child shouldnt be change
//                                                   objects reference count of Array should be 1
//                                                          after removing 1 child, whot not in Array
//                                                              array shouldn't changeL,
//                                                              length shouldnt be change
//                                                              count of child shouldnt be change
//                                                              objects reference count of Child in Array shouldn't be change
//                                                              objects reference count of Array should be 1
//                                                                     after removing 3 child
//                                                                          array shouldn't be NULL,
//                                                                          length shouldnt be change
//                                                                          count of child shouldnt be change, equal 0
//                                                                          objects reference count of Child in Array should be change, equal 1
//                                                                          objects reference count of Array should be 1
//                                                                                  ObjectRelease Children
//                                                                                  ObjectRelease Array

void TKAArrayAddRemoveObjectTest() {
    // TKAArray
    //        after being created
    TKAArray * testArray = TKAObjectCreate(TKAArray);
    ///////////////////////
//    TKAArrayOutputTest(testArray);
    //              array shouldn't be NULL,
    assert(NULL != testArray);
    //              length should be 0
    assert(0 == TKAArrayGetLength(testArray));
    //              count of child should be 0
    assert(0 == TKAArrayGetObjectCount(testArray));
    //              objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));

    //                  Creating Children
    TKADEFCreateObject(0);
    TKADEFCreateObject(1);
    TKADEFCreateObject(2);
    TKADEFCreateObject(3);
    TKADEFCreateObject(4);
    TKADEFCreateObject(5);
    TKADEFCreateObject(7);
    
    //                  after removing child from array with 0 length
       TKADEFRemoveObject(2);
    ///////////////////
//    TKAArrayOutputTest(testArray);
    //                      array shouldn't be NULL
    assert(NULL != testArray);
    //                      length shouldnt be change
    assert(0 == TKAArrayGetLength(testArray));
    //                      count of child shouldnt be change
     assert(0 == TKAArrayGetObjectCount(testArray));
    //                      objects reference count of Child should be 1 , dont change
     assert(1 == TKAObjectGetReferenceCount(child_2));
    //                      objects reference count of Array should be 1
     assert(1 == TKAObjectGetReferenceCount(testArray));

    //                          after removing NULL from array with 0 length
    TKAArrayRemoveObject(testArray, NULL);
    //                              array shouldn't be NULL
    assert(NULL != testArray);
    //                              length shouldnt be change
     assert(0 == TKAArrayGetLength(testArray));
    //                              count of child shouldnt be change
    assert(0 == TKAArrayGetObjectCount(testArray));
    //                              objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    /////////////////////////
//    TKAArrayOutputTest(testArray);

    //                                              after adding NULL to array with 0 length
    TKAArrayAddObject(testArray, NULL);
    //                                                  array shouldn't be NULL
    assert(NULL != testArray);
    //                                                  length should be change
    assert(1 == TKAArrayGetLength(testArray));
    //                                                  count of child shouldnt be change
    assert(0 == TKAArrayGetObjectCount(testArray));
    //                                                   objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
////////////////////////////
//    TKAArrayOutputTest(testArray);
    
    //                  after adding 3 child
    TKADEFAddObject(0);
    TKADEFAddObject(1);
    TKADEFAddObject(2);
    //                      array shouldn't be NULL,
    assert(NULL != testArray);
    //                      3 elements of array shouldn't be NULL
    assert(child_0 == TKAArrayGetObjectAtIndex(testArray, 0));
    assert(child_1 == TKAArrayGetObjectAtIndex(testArray, 1));
    assert(child_2 == TKAArrayGetObjectAtIndex(testArray, 2));
    //                      length should be change, should be >=3
    assert(3 <= TKAArrayGetLength(testArray));
    //                      count of child should be be increment by 3, should equal 3
    assert(3 == TKAArrayGetObjectCount(testArray));
    //                      objects reference count of Child in Array should be 2
    assert(2 == TKAObjectGetReferenceCount(child_0));
    assert(2 == TKAObjectGetReferenceCount(child_1));
    assert(2 == TKAObjectGetReferenceCount(child_2));
    //                      objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));

    //                              after adding 1 child, whot alredy in Array
    //                                  array shouldn't changeL,
    //                                  length shouldnt be change
    //                                  count of child shouldnt be change
    //                                  objects reference count of Child in Array shouldn't be change
    //                                  objects reference count of Array should be 1
    TKADEFAddObject(0);
    assert(NULL != testArray);
    assert(child_0 == TKAArrayGetObjectAtIndex(testArray, 0));
    assert(3 <= TKAArrayGetLength(testArray));
    assert(3 == TKAArrayGetObjectCount(testArray));
    assert(2 == TKAObjectGetReferenceCount(child_0));
    assert(1 == TKAObjectGetReferenceCount(testArray));
    //////////////////////////////
//    TKAArrayOutputTest(testArray);

    //                                      after removing NULL from array with not 0 length
    //                                          array shouldn't be NULL
    //                                          length shouldnt be change
    //                                          count of child shouldnt be change
    //                                          objects reference count of Array should be 1
    TKAArrayRemoveObject(testArray, NULL);
    assert(NULL != testArray);
    assert(3 <= TKAArrayGetLength(testArray));
    assert(3 == TKAArrayGetObjectCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(testArray));
//////////////////////////////////
//   TKAArrayOutputTest(testArray);

    //                                              after adding NULL to array with 0 length
    //                                                  array shouldn't be NULL
    //                                                  length shouldnt be change
    //                                                  count of child shouldnt be change
    //                                                   objects reference count of Array should be 1
    TKAArrayAddObject(testArray, NULL);
    TKAArrayRemoveObject(testArray, NULL);
    assert(NULL != testArray);
    assert(3 <= TKAArrayGetLength(testArray));
    assert(3 == TKAArrayGetObjectCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(testArray));
//////////////////////////////////
//    TKAArrayOutputTest(testArray);
    
    //                                                          after removing 1 child, whot not in Array
    //                                                              array shouldn't changeL,
    //                                                              length shouldnt be change
    //                                                              count of child shouldnt be change
    //                                                              objects reference count of Child in Array shouldn't be change
    //                                                              objects reference count of Array should be 1
    TKADEFRemoveObject(5);
    assert(NULL != testArray);
    assert(3 <= TKAArrayGetLength(testArray));
    assert(3 == TKAArrayGetObjectCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(child_5));
    assert(1 == TKAObjectGetReferenceCount(testArray));
/////////////////////////////////////
//    TKAArrayOutputTest(testArray);
    
    //                                                                     after removing 3 child
    //                                                                          array shouldn't be NULL,
    //                                                                          length shouldnt be change
    //                                                                          count of child shouldnt be change, equal 0
    //                                                                          objects reference count of Child in Array should be change, equal 1
    //                                                                          objects reference count of Array should be 1
    TKADEFRemoveObject(1);
    TKADEFRemoveObject(2);
    TKADEFRemoveObject(0);
    assert(NULL != testArray);
    //                      3 elements of array should be NULL
    assert(NULL == TKAArrayGetObjectAtIndex(testArray, 0));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray, 1));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray, 2));
    //                      length should be change, should be <3
    assert(3 > TKAArrayGetLength(testArray));
    //                      count of child should be be decrement by 3, should equal 0
    assert(0 == TKAArrayGetObjectCount(testArray));
    //                      objects reference count of Child in Array should be 1
    assert(1 == TKAObjectGetReferenceCount(child_0));
    assert(1 == TKAObjectGetReferenceCount(child_1));
    assert(1 == TKAObjectGetReferenceCount(child_2));
    //                      objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));

//    TKAArrayOutputTest(testArray);
    //                                                                                  ObjectRelease Children
    TKADEFReleaseObject(7);
    TKADEFReleaseObject(5);
    TKADEFReleaseObject(4);
    TKADEFReleaseObject(3);
    TKADEFReleaseObject(2);
    TKADEFReleaseObject(1);
    //                                                                                  ObjectRelease Array
    TKAObjectRelease(testArray);
}
void TKAArrayAddRemoveObjectTestOutput() {
    // TKAArray
    //        after being created
    TKAArray * testArray = TKAObjectCreate(TKAArray);
    ///////////////////////
     TKAArrayOutputTest(testArray);
    //              array shouldn't be NULL,
    assert(NULL != testArray);
    //              length should be 0
    assert(0 == TKAArrayGetLength(testArray));
    //              count of child should be 0
    assert(0 == TKAArrayGetObjectCount(testArray));
    //              objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    
    //                  Creating Children
    TKADEFCreateObject(0);
    TKADEFCreateObject(1);
    TKADEFCreateObject(2);
    TKADEFCreateObject(3);
    TKADEFCreateObject(4);
    TKADEFCreateObject(5);
    TKADEFCreateObject(7);
    
    //                  after removing child from array with 0 length
    TKADEFRemoveObject(2);
    ///////////////////
       TKAArrayOutputTest(testArray);
    //                      array shouldn't be NULL
//    assert(NULL != testArray);
//    //                      length shouldnt be change
//    assert(0 == TKAArrayGetLength(testArray));
//    //                      count of child shouldnt be change
//    assert(0 == TKAArrayGetObjectCount(testArray));
//    //                      objects reference count of Child should be 1 , dont change
//    assert(1 == TKAObjectGetReferenceCount(child_2));
//    //                      objects reference count of Array should be 1
//    assert(1 == TKAObjectGetReferenceCount(testArray));
    
    //                          after removing NULL from array with 0 length
    TKAArrayRemoveObject(testArray, NULL);
//    //                              array shouldn't be NULL
//    assert(NULL != testArray);
//    //                              length shouldnt be change
//    assert(0 == TKAArrayGetLength(testArray));
//    //                              count of child shouldnt be change
//    assert(0 == TKAArrayGetObjectCount(testArray));
//    //                              objects reference count of Array should be 1
//    assert(1 == TKAObjectGetReferenceCount(testArray));
    /////////////////////////
    TKAArrayOutputTest(testArray);
    
    //                                              after adding NULL to array with 0 length
//    TKAArrayAddObject(testArray, NULL);
//    //                                                  array shouldn't be NULL
//    assert(NULL != testArray);
//    //                                                  length should be change
//    assert(1 == TKAArrayGetLength(testArray));
//    //                                                  count of child shouldnt be change
//    assert(0 == TKAArrayGetObjectCount(testArray));
//    //                                                   objects reference count of Array should be 1
//    assert(1 == TKAObjectGetReferenceCount(testArray));
    ////////////////////////////
   TKAArrayOutputTest(testArray);
    
    //                  after adding 3 child
    TKADEFAddObject(0);
    TKADEFAddObject(1);
    TKADEFAddObject(2);
    //                      array shouldn't be NULL,
//    assert(NULL != testArray);
//    //                      3 elements of array shouldn't be NULL
//    assert(child_0 == TKAArrayGetObjectAtIndex(testArray, 0));
//    assert(child_1 == TKAArrayGetObjectAtIndex(testArray, 1));
//    assert(child_2 == TKAArrayGetObjectAtIndex(testArray, 2));
//    //                      length should be change, should be >=3
//    assert(3 <= TKAArrayGetLength(testArray));
//    //                      count of child should be be increment by 3, should equal 3
//    assert(3 == TKAArrayGetObjectCount(testArray));
//    //                      objects reference count of Child in Array should be 2
//    assert(2 == TKAObjectGetReferenceCount(child_0));
//    assert(2 == TKAObjectGetReferenceCount(child_1));
//    assert(2 == TKAObjectGetReferenceCount(child_2));
//    //                      objects reference count of Array should be 1
//    assert(1 == TKAObjectGetReferenceCount(testArray));
       TKAArrayOutputTest(testArray);
    
    //                              after adding 1 child, whot alredy in Array
    //                                  array shouldn't changeL,
    //                                  length shouldnt be change
    //                                  count of child shouldnt be change
    //                                  objects reference count of Child in Array shouldn't be change
    //                                  objects reference count of Array should be 1
    TKADEFAddObject(0);
//    assert(NULL != testArray);
//    assert(child_0 == TKAArrayGetObjectAtIndex(testArray, 0));
//    assert(3 <= TKAArrayGetLength(testArray));
//    assert(3 == TKAArrayGetObjectCount(testArray));
//    assert(2 == TKAObjectGetReferenceCount(child_0));
//    assert(1 == TKAObjectGetReferenceCount(testArray));
    //////////////////////////////
   TKAArrayOutputTest(testArray);
    
    //                                      after removing NULL from array with not 0 length
    //                                          array shouldn't be NULL
    //                                          length shouldnt be change
    //                                          count of child shouldnt be change
    //                                          objects reference count of Array should be 1
    TKAArrayRemoveObject(testArray, NULL);
//    assert(NULL != testArray);
//    assert(3 <= TKAArrayGetLength(testArray));
//    assert(3 == TKAArrayGetObjectCount(testArray));
//    assert(1 == TKAObjectGetReferenceCount(testArray));
    //////////////////////////////////
       TKAArrayOutputTest(testArray);
    
    //                                              after adding NULL to array with 0 length
    //                                                  array shouldn't be NULL
    //                                                  length shouldnt be change
    //                                                  count of child shouldnt be change
    //                                                   objects reference count of Array should be 1
    TKAArrayAddObject(testArray, NULL);
    TKAArrayRemoveObject(testArray, NULL);
//    assert(NULL != testArray);
//    assert(3 <= TKAArrayGetLength(testArray));
//    assert(3 == TKAArrayGetObjectCount(testArray));
//    assert(1 == TKAObjectGetReferenceCount(testArray));
    //////////////////////////////////
   TKAArrayOutputTest(testArray);
    
    //                                                          after removing 1 child, whot not in Array
    //                                                              array shouldn't changeL,
    //                                                              length shouldnt be change
    //                                                              count of child shouldnt be change
    //                                                              objects reference count of Child in Array shouldn't be change
    //                                                              objects reference count of Array should be 1
    TKADEFRemoveObject(5);
//    assert(NULL != testArray);
//    assert(3 <= TKAArrayGetLength(testArray));
//    assert(3 == TKAArrayGetObjectCount(testArray));
//    assert(1 == TKAObjectGetReferenceCount(child_5));
//    assert(1 == TKAObjectGetReferenceCount(testArray));
    /////////////////////////////////////
   TKAArrayOutputTest(testArray);
    
    //                                                                     after removing 3 child
    //                                                                          array shouldn't be NULL,
    //                                                                          length shouldnt be change
    //                                                                          count of child shouldnt be change, equal 0
    //                                                                          objects reference count of Child in Array should be change, equal 1
    //                                                                          objects reference count of Array should be 1
    TKADEFRemoveObject(1);
    TKADEFRemoveObject(2);
    TKADEFRemoveObject(0);
//    assert(NULL != testArray);
//    //                      3 elements of array should be NULL
//    assert(NULL == TKAArrayGetObjectAtIndex(testArray, 0));
//    assert(NULL == TKAArrayGetObjectAtIndex(testArray, 1));
//    assert(NULL == TKAArrayGetObjectAtIndex(testArray, 2));
//    //                      length should be change, should be <3
//    assert(3 > TKAArrayGetLength(testArray));
//    //                      count of child should be be decrement by 3, should equal 0
//    assert(0 == TKAArrayGetObjectCount(testArray));
//    //                      objects reference count of Child in Array should be 1
//    assert(1 == TKAObjectGetReferenceCount(child_0));
//    assert(1 == TKAObjectGetReferenceCount(child_1));
//    assert(1 == TKAObjectGetReferenceCount(child_2));
//    //                      objects reference count of Array should be 1
//    assert(1 == TKAObjectGetReferenceCount(testArray));
    
    TKAArrayOutputTest(testArray);
    //                                                                                  ObjectRelease Children
    TKADEFReleaseObject(7);
    TKADEFReleaseObject(5);
    TKADEFReleaseObject(4);
    TKADEFReleaseObject(3);
    TKADEFReleaseObject(2);
    TKADEFReleaseObject(1);
    //                                                                                  ObjectRelease Array
    TKAObjectRelease(testArray);
}


#undef TKADEFCreateObject
#undef TKADEFAddObject
#undef TKADEFRemoveObject
#undef TKADEFReleaseObject

#pragma mark -
#pragma mark Public Implementations

void TKAArrayTestMain() {
    
     TKAArrayCreateTest();
    
     TKAArrayResizeTestOutput();

     TKAArrayAddRemoveObjectTestOutput();
 
}

// TKAArray
//        after being created
//          array should be NULL, length should be 0
//          objects reference count of Array should be 1
//              after adding 5 child
//                  array shouldn't be NULL, length should be increment by 5
//                  objects reference count of child should be increment by 5
//                  objects reference count of Array should be 1
//                         after removing ALL children
//                              array shouldn be NULL, length should be decrement by 5
//                              objects reference count of child should be decrement by 5
//                              objects reference count of Array should be 1
//                                  ObjectRelease Array
//
// TKAArray
//        after being created
//          array should be NULL, length should be 0
//          objects reference count of Array should be 1
//              after adding 1 child by index 3
//                  array shouldn't be NULL, length should be increment by 3
//                  objects reference count of child should be increment by 1
//                  objects reference count of Array should be 1
//                         after removing ALL children
//                              array should be NULL, length should be 0
//                              objects reference count of child should be decrement by 1
//                              objects reference count of Array should be 1
//                                  ObjectRelease Array
//
// TKAArray
//        after being created
//          array should be NULL, length should be 0
//          objects reference count of Array should be 1
//              after adding 1 child by pointer
//                  array shouldn't be NULL, length should be increment by 1
//                  objects reference count of child should be increment by 1
//                  objects reference count of Array should be 1
//                      after removing ALL children
//                              array should be NULL, length should be  0
//                              objects reference count of child should be decrement by 1
//                              objects reference count of Array should be 1
////                                  ObjectRelease Array
//
//TKAArray
//        after being created
//           after adding 3 child
//                          array shouldn't be NULL, length should be increment by 3
//                          objects reference count of child should be increment by 3
//                          objects reference count of Array should be 1
//                              after removing 1 child by index 2
//                                  array shouldn't be NULL, length shouldn't change
//                                  objects reference count of child should be decrement by 1
//                                  objects reference count of Array should be 1
//                                         after removing ALL child
//                                          array should be NULL, length should be 0
//                                          objects reference count of child should be decrement by 2
//                                          objects reference count of Array should be 1
//                                              ObjectRelease Array
//
//      