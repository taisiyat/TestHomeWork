//
//  TKAArrayTest.c
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAArrayTest.h"
#include <assert.h>
#include <stdlib.h>


#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Declarations

static
void TKAArrayCreateTest();

static
void TKAArrayResizeTest();

static
void TKAArrayAddRemoveObjectTest();

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
//                      after releasing
//
//        after being created TKAHuman
//              array shouldnt be NULL,
//              length should be 0
//              count of child should be 0
//              objects reference count of Array should be 1
//                      after being releasing TKAHuman
//                                array deallocated

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
    //                      after releasing array deallocated
    TKAObjectRelease(testArray);

    
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
    //                                      after being releasing TKAHuman array deallocated
    TKAObjectRelease(man);
}


#define TKADEFCreateObject(number) \
    TKAHuman *child##number = TKAHumanCreateWithNameChar("child "#number" ", number, TKAMale); \

#define TKADEFAddObject(number) \
    TKAArrayAddObject(testArray, child_##number); \


#define TKADEFRemoveObject(number) \
    TKAArrayRemoveObject(testArray, child_##number);\

#define TKADEFReleaseObject(number)\
        TKAObjectRelease(child##number);\

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
    TKADEFCreateObject(0);
    TKADEFCreateObject(1);
    TKADEFCreateObject(2);
    TKADEFCreateObject(3);
    TKADEFCreateObject(4);
    TKADEFCreateObject(5);

    void *childArray[6] = { child0, child1, child2, child3, child4, child5 };
    
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
    ///////////////////////////
    TKAArrayOutputTest(testArray);

    
    //              after adding one child
    TKAArrayAddObject(testArray, childArray[0]);
    //                  array shouldn't be NULL, first element shouldn't be NULL
    assert(NULL != TKAArrayGetObjectAtIndex(testArray, 0));
    assert(childArray[0] == TKAArrayGetObjectAtIndex(testArray, 0));
    //                  length should be change, equal 2
    assert(0 != TKAArrayGetLength(testArray));
    assert(1 == TKAArrayGetLength(testArray));
    //                  count of child should equal 1
    assert(1 == TKAArrayGetObjectCount(testArray));
    //                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    assert(2 == TKAObjectGetReferenceCount(childArray[0]));
    ///////////////////////////
    TKAArrayOutputTest(testArray);
    
    //                      after adding 5 child
    for (uint16_t iter = 1; iter < 6; iter++) {
        TKAArrayAddObject(testArray, childArray[iter]);
    }
     /////////////////////////
    TKAArrayOutputTest(testArray);
    //                      after adding 5 child
    //                          array shouldn't be NULL,
    assert(childArray[0] == TKAArrayGetObjectAtIndex(testArray,0));
    assert(childArray[1] == TKAArrayGetObjectAtIndex(testArray,1));
    assert(childArray[4] == TKAArrayGetObjectAtIndex(testArray,4));
    assert(childArray[5] == TKAArrayGetObjectAtIndex(testArray,5));
    //                          length should be change equal 8
    assert(0 != TKAArrayGetLength(testArray));
    assert(8 == TKAArrayGetLength(testArray));
    //                          count of child should be be increment by 5, equal 6
    assert(6 == TKAArrayGetObjectCount(testArray));
    //                          objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    for (uint16_t iter = 0; iter < 6; iter++) {
        assert(2 == TKAObjectGetReferenceCount(childArray[iter]));
    }

//    //                              after removing 1 child
    TKAArrayRemoveObject(testArray, childArray[3]);
    ///////////////////////////
    TKAArrayOutputTest(testArray);
    //                                  array shouldnt be NULL,
    assert(childArray[2]= TKAArrayGetObjectAtIndex(testArray,2));
    assert(childArray[4]= TKAArrayGetObjectAtIndex(testArray,3));
    assert(childArray[5]= TKAArrayGetObjectAtIndex(testArray,4));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,5));
    //                                  length should be change
    assert(0 != TKAArrayGetLength(testArray));
    assert(8 == TKAArrayGetLength(testArray));
    //                                  count of child should be be decrement by 2
     assert(5 == TKAArrayGetObjectCount(testArray));
    //                                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(childArray[3]));
    
    TKAArrayRemoveObject(testArray, childArray[0]);
    ///////////////////////////
    TKAArrayOutputTest(testArray);
    //                                  array shouldnt be NULL,
    assert(childArray[1]= TKAArrayGetObjectAtIndex(testArray,0));
    assert(childArray[2]= TKAArrayGetObjectAtIndex(testArray,1));
    assert(childArray[4]= TKAArrayGetObjectAtIndex(testArray,2));
    assert(childArray[5]= TKAArrayGetObjectAtIndex(testArray,3));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,5));
    //                                  length should be change
    assert(0 != TKAArrayGetLength(testArray));
    assert(4 == TKAArrayGetLength(testArray));
    //                                  count of child should be be decrement by 2
    assert(4 == TKAArrayGetObjectCount(testArray));
    //                                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(childArray[0]));
    
    TKAArrayRemoveObject(testArray, childArray[5]);
    ///////////////////////////
    TKAArrayOutputTest(testArray);
    //                                  array shouldnt be NULL,
    assert(childArray[1]= TKAArrayGetObjectAtIndex(testArray,0));
    assert(childArray[2]= TKAArrayGetObjectAtIndex(testArray,1));
    assert(childArray[4]= TKAArrayGetObjectAtIndex(testArray,2));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,3));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,5));
    //                                  length should be change
    assert(0 != TKAArrayGetLength(testArray));
    assert(4 == TKAArrayGetLength(testArray));
    //                                  count of child should be be decrement by 2
    assert(3 == TKAArrayGetObjectCount(testArray));
    //                                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(childArray[5]));
    
    //                                      after removing ALL children
    TKAArrayRemoveAllObjects(testArray);
    ///////////////////////////////////////
    TKAArrayOutputTest(testArray);
    //                                 elements of array should be NULL,
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,0));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,1));
    assert(NULL == TKAArrayGetObjectAtIndex(testArray,2));
    //                                  length should be change,
    assert(0 != TKAArrayGetLength(testArray));
    assert(1 == TKAArrayGetLength(testArray));
    //                                  count of child should decrement, equal 0
    assert(0 == TKAArrayGetObjectCount(testArray));
    //                                  objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
    for (uint16_t iter = 0; iter < 6; iter++) {
         assert(1 == TKAObjectGetReferenceCount(childArray[iter]));
    }

    for (uint16_t iter = 0; iter < 6; iter++) {
        TKAObjectRelease(childArray[iter]);
    }
//                            ObjectRelease Array
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
    TKADEFCreateObject(0);
    TKADEFCreateObject(1);
    TKADEFCreateObject(2);
    TKADEFCreateObject(3);
    TKADEFCreateObject(4);
    TKADEFCreateObject(5);
    
    void *childArray[6] = { child0, child1, child2, child3, child4, child5 };

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
   
    //                  after removing child from array with 0 length
    TKAArrayRemoveObject(testArray, childArray[2]);
    ///////////////////
//    TKAArrayOutputTest(testArray);
    //                      array shouldn't be NULL
    assert(NULL != testArray);
    //                      length shouldnt be change
    assert(0 == TKAArrayGetLength(testArray));
    //                      count of child shouldnt be change
     assert(0 == TKAArrayGetObjectCount(testArray));
    //                      objects reference count of Child should be 1 , dont change
     assert(1 == TKAObjectGetReferenceCount(childArray[2]));
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
    assert(0 == TKAArrayGetLength(testArray));
    //                                                  count of child shouldnt be change
    assert(0 == TKAArrayGetObjectCount(testArray));
    //                                                   objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));
////////////////////////////
//   TKAArrayOutputTest(testArray);
    
    //                  after adding 3 child
    for (uint16_t iter = 0; iter < 4; iter++) {
        TKAArrayAddObject(testArray, childArray[iter]);
    }
    //                      array shouldn't be NULL,
    assert(NULL != testArray);
    //                      3 elements of array shouldn't be NULL
    assert(childArray[0] == TKAArrayGetObjectAtIndex(testArray, 0));
    assert(childArray[1] == TKAArrayGetObjectAtIndex(testArray, 1));
    assert(childArray[2] == TKAArrayGetObjectAtIndex(testArray, 2));
    //                      length should be change, should be >=3
    assert(4 <= TKAArrayGetLength(testArray));
    //                      count of child should be be increment by 3, should equal 3
    assert(4 == TKAArrayGetObjectCount(testArray));
    //                      objects reference count of Child in Array should be 2
    for (uint16_t iter = 0; iter < 4; iter++) {
        assert(2 == TKAObjectGetReferenceCount(childArray[iter]));
    }
    //                      objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));

    //                              after adding 1 child, whot alredy in Array
    //                                  array shouldn't changeL,
    //                                  length shouldnt be change
    //                                  count of child shouldnt be change
    //                                  objects reference count of Child in Array shouldn't be change
    //                                  objects reference count of Array should be 1
    TKAArrayAddObject(testArray, childArray[1]);
    assert(NULL != testArray);
    assert(childArray[1] == TKAArrayGetObjectAtIndex(testArray, 1));
    assert(4 <= TKAArrayGetLength(testArray));
    assert(4 == TKAArrayGetObjectCount(testArray));
    assert(2 == TKAObjectGetReferenceCount(childArray[1]));
    assert(1 == TKAObjectGetReferenceCount(testArray));
    //////////////////////////////
    TKAArrayOutputTest(testArray);

    //                                      after removing NULL from array with not 0 count
    //                                          array shouldn't be NULL
    //                                          length shouldnt be change
    //                                          count of child shouldnt be change
    //                                          objects reference count of Array should be 1
    TKAArrayRemoveObject(testArray, NULL);
    assert(NULL != testArray);
    assert(4 <= TKAArrayGetLength(testArray));
    assert(4 == TKAArrayGetObjectCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(testArray));
//////////////////////////////////
//   TKAArrayOutputTest(testArray);

    //                                              after adding NULL to array with 0 length
    //                                                  array shouldn't be NULL
    //                                                  length shouldnt be change
    //                                                  count of child shouldnt be change
    //                                                   objects reference count of Array should be 1
    TKAArrayAddObject(testArray, NULL);
    assert(NULL != testArray);
    assert(4 <= TKAArrayGetLength(testArray));
    assert(4 == TKAArrayGetObjectCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(testArray));
//////////////////////////////////
//    TKAArrayOutputTest(testArray);
    
    //                                                          after removing 1 child, whot not in Array
    //                                                              array shouldn't changeL,
    //                                                              length shouldnt be change
    //                                                              count of child shouldnt be change
    //                                                              objects reference count of Child in Array shouldn't be change
    //                                                              objects reference count of Array should be 1
    TKAArrayRemoveObject(testArray, childArray[5]);
    assert(NULL != testArray);
    assert(4 <= TKAArrayGetLength(testArray));
    assert(4 == TKAArrayGetObjectCount(testArray));
    assert(1 == TKAObjectGetReferenceCount(childArray[5]));
    assert(1 == TKAObjectGetReferenceCount(testArray));
/////////////////////////////////////
//    TKAArrayOutputTest(testArray);
    
    //                                                                     after removing 3 child
    //                                                                          array shouldn't be NULL,
    //                                                                          length shouldnt be change
    //                                                                          count of child shouldnt be change, equal 0
    //                                                                          objects reference count of Child in Array should be change, equal 1
    //                                                                          objects reference count of Array should be 1
    for (uint16_t iter = 0; iter < 4  ; iter++) {
        TKAArrayRemoveObject(testArray, childArray[iter]);
        TKAArrayOutputTest(testArray);
    }
    TKAArrayOutputTest(testArray);
    assert(NULL != testArray);
    //                      3 elements of array should be NULL
    
    assert(NULL == TKAArrayGetObjectAtIndex(testArray, 0));
    //                      length should be change, should be <3
    assert(3 > TKAArrayGetLength(testArray));
    //                      count of child should be be decrement by 3, should equal 0
    assert(0 == TKAArrayGetObjectCount(testArray));
    //                      objects reference count of Child in Array should be 1
    for (uint16_t iter = 0; iter < 4; iter++) {
        assert(1 == TKAObjectGetReferenceCount(childArray[iter]));
    }
    //                      objects reference count of Array should be 1
    assert(1 == TKAObjectGetReferenceCount(testArray));

    TKAArrayOutputTest(testArray);
    //                                                                                  ObjectRelease Children
    for (uint16_t iter = 0; iter < 6; iter++) {
        TKAObjectRelease(childArray[iter]);
    }
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
    
     TKAArrayResizeTest();

     TKAArrayAddRemoveObjectTest();
 
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