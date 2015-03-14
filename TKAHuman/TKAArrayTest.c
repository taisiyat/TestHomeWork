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
void TKAArrayAddRemoveChildTest();

static
void TKAArrayOutputTest();

#pragma mark -
#pragma mark Privat Implementations

void TKAArrayOutputTest(TKAArray *array) {
    
    TKAArrayOutput(array);
    printf("\n");
    printf(" length = %d   ", TKAArrayGetLength(array));
    printf(" count of children = %d   ", TKAArrayGetChildCount(array));
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
    assert(0 == TKAArrayGetChildCount(testArray));
    //              objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
//    TKAArrayOutputTest(testArray);

    //              after check of length
    TKAArrayCheckOfLength(testArray);
    //                  array shouldnt be NULL,
    assert(NULL != testArray);
    //                  length should be 1
    assert(1 == TKAArrayGetLength(testArray));
    //                  count of child should be 0
    assert(0 == TKAArrayGetChildCount(testArray));
    //                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
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
    assert(NULL != TKAHumanGetChildren(man));
    //                                  length should be 0
    assert(0 == TKAArrayGetLength(TKAHumanGetChildren(man)));
    //                                  count of child should be 0
    assert(0 == TKAArrayGetChildCount(TKAHumanGetChildren(man)));
    //                                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGetChildren(man)));
//    TKAArrayOutputTest(TKAHumanGetChildren(man));
    
    //                                      after being releasing TKAHuman
    TKAObjectRelease(man);
    //                                          array should be NULL,
    assert(NULL == TKAHumanGetChildren(man));
    //                                          objects reference count of Array should be 0
    assert(0 == TKAObjectGetReferenceCount(TKAHumanGetChildren(man)));
}


#define TKADEFCreateChild(number) \
    TKAHuman *child_##number = TKAHumanCreateWithNameChar("child "#number" ", number, TKAMale); \

#define TKADEFAddChild(number) \
    TKAArrayAddChild(testArray, child_##number); \


#define TKADEFRemoveChild(number) \
    TKAArrayRemoveOfChild(testArray, child_##number);\

#define TKADEFReleaseChild(number)\
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
    assert(0 == TKAArrayGetChildCount(testArray));
    //              objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    //                  Creating Children
    TKADEFCreateChild(0);
    TKADEFCreateChild(1);
    TKADEFCreateChild(2);
    TKADEFCreateChild(3);
    TKADEFCreateChild(4);
    TKADEFCreateChild(5);

    //              after adding child
    TKADEFAddChild(0);
    //                  array shouldn't be NULL, first element shouldn't be NULL
    assert(NULL != TKAArrayGetChildAtIndex(testArray,0));
    //                  length should be change, equal 2
    assert(0 != TKAArrayGetLength(testArray));
    assert(2 == TKAArrayGetLength(testArray));
    //                  count of child should equal 1
    assert(1 == TKAArrayGetChildCount(testArray));
    //                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
//    TKAArrayOutputTest(testArray);
    
    //                      after adding 5 child
    TKADEFAddChild(1);
    TKADEFAddChild(2);
    TKADEFAddChild(3);
    TKADEFAddChild(4);
    TKADEFAddChild(5);
//    TKAArrayOutputTest(testArray);
    //                      after adding 5 child
    //                          array shouldn't be NULL,
    assert(NULL != TKAArrayGetChildAtIndex(testArray,0));
    assert(NULL != TKAArrayGetChildAtIndex(testArray,1));
    assert(NULL != TKAArrayGetChildAtIndex(testArray,4));
    assert(NULL != TKAArrayGetChildAtIndex(testArray,5));
    //                          length should be change equal 8
    assert(0 != TKAArrayGetLength(testArray));
    assert(8 == TKAArrayGetLength(testArray));
    //                          count of child should be be increment by 5, equal 6
    assert(6 == TKAArrayGetChildCount(testArray));
    //                          objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));

    //                              after removing 2 child
    TKADEFRemoveChild(5);
    TKADEFRemoveChild(4);
    //                                  array shouldnt be NULL,
    assert(NULL != TKAArrayGetChildAtIndex(testArray,2));
    assert(NULL != TKAArrayGetChildAtIndex(testArray,3));
    assert(NULL == TKAArrayGetChildAtIndex(testArray,4));
    assert(NULL == TKAArrayGetChildAtIndex(testArray,5));
    //                                  length should be change
    assert(0 != TKAArrayGetLength(testArray));
    assert(4 == TKAArrayGetLength(testArray));
    //                                  count of child should be be decrement by 2
     assert(4 == TKAArrayGetChildCount(testArray));
    //                                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    
    //                                      after removing ALL children
    TKAArrayRemoveAllChildren(testArray);
    //                                 elements of array should be NULL,
    assert(NULL == TKAArrayGetChildAtIndex(testArray,0));
    assert(NULL == TKAArrayGetChildAtIndex(testArray,1));
    assert(NULL == TKAArrayGetChildAtIndex(testArray,2));
    assert(NULL == TKAArrayGetChildAtIndex(testArray,3));
    //                                  length should be change,
    assert(0 != TKAArrayGetLength(testArray));
    //                                  count of child should be be decrement, equal 0
    assert(0 == TKAArrayGetChildCount(testArray));
    //                                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));

//   TKAArrayOutputTest(testArray);
    //                                              ObjectRelease Children
    TKADEFReleaseChild(5);
    TKADEFReleaseChild(4);
    TKADEFReleaseChild(3);
    TKADEFReleaseChild(2);
    TKADEFReleaseChild(1);
    TKADEFReleaseChild(0);
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

void TKAArrayAddRemoveChildTest() {
    // TKAArray
    //        after being created
    TKAArray * testArray = TKAObjectCreate(TKAArray);
//    TKAArrayOutputTest(testArray);
    //              array shouldn't be NULL,
    assert(NULL != testArray);
    //              length should be 0
    assert(0 == TKAArrayGetLength(testArray));
    //              count of child should be 0
    assert(0 == TKAArrayGetChildCount(testArray));
    //              objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));

    //                  Creating Children
    TKADEFCreateChild(0);
    TKADEFCreateChild(1);
    TKADEFCreateChild(2);
    TKADEFCreateChild(3);
    TKADEFCreateChild(4);
    TKADEFCreateChild(5);
    TKADEFCreateChild(7);
    
    //                  after removing child from array with 0 length
       TKADEFRemoveChild(2);
//    TKAArrayOutputTest(testArray);
    //                      array shouldn't be NULL
    assert(NULL != testArray);
    //                      length shouldnt be change
    assert(0 == TKAArrayGetLength(testArray));
    //                      count of child shouldnt be change
     assert(0 == TKAArrayGetChildCount(testArray));
    //                      objects reference count of Child should be 1 , dont change
     assert(1 == TKAObjectGetReferenceCount(child_2));
    //                      objects reference count of Array should be 1
     assert(1 == TKAObjectGetReferenceCount(testArray));

    //                          after removing NULL from array with 0 length
    TKAArrayRemoveOfChild(testArray, NULL);
    //                              array shouldn't be NULL
    assert(NULL != testArray);
    //                              length shouldnt be change
     assert(0 == TKAArrayGetLength(testArray));
    //                              count of child shouldnt be change
    assert(0 == TKAArrayGetChildCount(testArray));
    //                              objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
//    printf("Remove NULL \n");
//    TKAArrayOutputTest(testArray);

    //                                              after adding NULL to array with 0 length
    TKAArrayAddChild(testArray, NULL);
    //                                                  array shouldn't be NULL
    assert(NULL != testArray);
    //                                                  length should be change
    assert(1 == TKAArrayGetLength(testArray));
    //                                                  count of child shouldnt be change
    assert(0 == TKAArrayGetChildCount(testArray));
    //                                                   objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
//    printf("ADD NULL \n");
//    TKAArrayOutputTest(testArray);
    
    //                  after adding 3 child
    TKADEFAddChild(0);
    TKADEFAddChild(1);
    TKADEFAddChild(2);
    //                      array shouldn't be NULL,
    assert(NULL != testArray);
    //                      3 elements of array shouldn't be NULL
    assert(child_0 == TKAArrayGetChildAtIndex(testArray, 0));
    assert(child_1 == TKAArrayGetChildAtIndex(testArray, 1));
    assert(child_2 == TKAArrayGetChildAtIndex(testArray, 2));
    //                      length should be change, should be >=3
    assert(3 <= TKAArrayGetLength(testArray));
    //                      count of child should be be increment by 3, should equal 3
    assert(3 == TKAArrayGetChildCount(testArray));
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
    TKADEFAddChild(0);
    assert(NULL != testArray);
    assert(child_0 == TKAArrayGetChildAtIndex(testArray, 0));
    assert(3 <= TKAArrayGetLength(testArray));
    assert(3 == TKAArrayGetChildCount(testArray));
    assert(2 == TKAObjectGetReferenceCount(child_0));
    assert(1 == TKAObjectGetReferenceCount(testArray));
//    TKAArrayOutputTest(testArray);

    //                                      after removing NULL from array with not 0 length
    //                                          array shouldn't be NULL
    //                                          length shouldnt be change
    //                                          count of child shouldnt be change
    //                                          objects reference count of Array should be 1
    TKAArrayRemoveOfChild(testArray, NULL);
    assert(NULL != testArray);
    assert(3 <= TKAArrayGetLength(testArray));
    assert(3 == TKAArrayGetChildCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(testArray));
//    printf("Remove NULL \n");
//    TKAArrayOutputTest(testArray);

    //                                              after adding NULL to array with 0 length
    //                                                  array shouldn't be NULL
    //                                                  length shouldnt be change
    //                                                  count of child shouldnt be change
    //                                                   objects reference count of Array should be 1
    TKAArrayAddChild(testArray, NULL);
    TKAArrayRemoveOfChild(testArray, NULL);
    assert(NULL != testArray);
    assert(3 <= TKAArrayGetLength(testArray));
    assert(3 == TKAArrayGetChildCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(testArray));
//    printf("ADD NULL \n");
//    TKAArrayOutputTest(testArray);
    
    //                                                          after removing 1 child, whot not in Array
    //                                                              array shouldn't changeL,
    //                                                              length shouldnt be change
    //                                                              count of child shouldnt be change
    //                                                              objects reference count of Child in Array shouldn't be change
    //                                                              objects reference count of Array should be 1
    TKADEFRemoveChild(5);
    assert(NULL != testArray);
    assert(3 <= TKAArrayGetLength(testArray));
    assert(3 == TKAArrayGetChildCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(child_5));
    assert(1 == TKAObjectGetReferenceCount(testArray));
//    printf("Remove child is apsend \n");
//    TKAArrayOutputTest(testArray);
    
    //                                                                     after removing 3 child
    //                                                                          array shouldn't be NULL,
    //                                                                          length shouldnt be change
    //                                                                          count of child shouldnt be change, equal 0
    //                                                                          objects reference count of Child in Array should be change, equal 1
    //                                                                          objects reference count of Array should be 1
    TKADEFRemoveChild(1);
    TKADEFRemoveChild(2);
    TKADEFRemoveChild(0);
    assert(NULL != testArray);
    //                      3 elements of array should be NULL
    assert(NULL == TKAArrayGetChildAtIndex(testArray, 0));
    assert(NULL == TKAArrayGetChildAtIndex(testArray, 1));
    assert(NULL == TKAArrayGetChildAtIndex(testArray, 2));
    //                      length should be change, should be <3
    assert(3 > TKAArrayGetLength(testArray));
    //                      count of child should be be decrement by 3, should equal 0
    assert(0 == TKAArrayGetChildCount(testArray));
    //                      objects reference count of Child in Array should be 1
    assert(1 == TKAObjectGetReferenceCount(child_0));
    assert(1 == TKAObjectGetReferenceCount(child_1));
    assert(1 == TKAObjectGetReferenceCount(child_2));
    //                      objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));

//    TKAArrayOutputTest(testArray);
    //                                                                                  ObjectRelease Children
    TKADEFReleaseChild(7);
    TKADEFReleaseChild(5);
    TKADEFReleaseChild(4);
    TKADEFReleaseChild(3);
    TKADEFReleaseChild(2);
    TKADEFReleaseChild(1);
    //                                                                                  ObjectRelease Array
    TKAObjectRelease(testArray);
}

#undef TKADEFCreateChild
#undef TKADEFAddChild
#undef TKADEFRemoveChild
#undef TKADEFReleaseChild

#pragma mark -
#pragma mark Public Implementations

void TKAArrayTestMain() {
    
     TKAArrayCreateTest();
    
     TKAArrayResizeTest();

     TKAArrayAddRemoveChildTest();
 
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