//
//  TKALinkedListTest.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 25.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKALinkedListTest.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKALinkedListAddRemoveTest();

static
void TKALinkedListInsertRemoveTest();

#pragma mark -
#pragma mark Public Implementations

void TKALinkedListPerformTest() {
    TKALinkedListAddRemoveTest();
    TKALinkedListInsertRemoveTest();
}

#pragma mark -
#pragma mark Private Implementations

//TKALinkedList
//      after creating list
//          list count should be equal 0
//          list reference count should equal 1
//              after ctreating and adding object testObject to list
//                  list count should be equal 1
//                  list should contain testObject
//                  testObject reference count should increase by 1, should equal 2
//                      after adding object NULL to list
//                          list count should be equal 1
//                          list shouldn't contain NULL
//                              after adding object testObject to list
//                                  count of list should be equal 2
//                                  list should contain testObject twice
//                                  testObject reference count should increase by 1, should equal 3
//                                      after removing object tesstObject from list twice
//                                          list count should be equal 0
//                                          list shouldn't contain testObject
//                                          testObject reference count should decrease by 2, should equal 1
//                                              Release tesstObject, list

void TKALinkedListAddRemoveTest() {
    //    TKALinkedList
    //    after creating list
    TKALinkedList *list = TKAObjectCreate(TKALinkedList);
    
    //    count of list should be equal 0
    assert(0 == TKALinkedListGetCount(list));
    //    list reference count should equal 1
    assert(1 == TKAObjectGetReferenceCount(list));
    
    //    after ctreating and adding object testObject to list
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    TKALinkedListAddObject(list, testObject);
    
    //    count of list should be equal 1
    assert(1 == TKALinkedListGetCount(list));
    //    list should contain testObject
    assert(TKALinkedListContainsObject(list, testObject));
    //    testObject reference count should increasse by 1, should equal 2
    assert(2 == TKAObjectGetReferenceCount(testObject));
    
    //    after adding object NULL to list
    TKALinkedListAddObject(list, NULL);
    //    count of list shouldn't change, should be equal 1
    assert(1 == TKALinkedListGetCount(list));
    //    list shouldn't contain NULL
    assert(!TKALinkedListContainsObject(list, NULL));
    
    //    after adding object testObject to list
    TKALinkedListAddObject(list, testObject);
    
    //    count of list should be equal 2
    assert(2 == TKALinkedListGetCount(list));
    //    list should contain testObject
    assert(TKALinkedListContainsObject(list, testObject));
    //    testObject reference count should increasse by 1, should equal 3
    assert(3 == TKAObjectGetReferenceCount(testObject));
    
    //    after removing object tesstObject from list twice
    TKALinkedListRemoveObject(list, testObject);
    TKALinkedListRemoveObject(list, testObject);
    //    list count should be equal 0
    assert(0 == TKALinkedListGetCount(list));
    //    list shouldn't contain testObject
    assert(!TKALinkedListContainsObject(list, testObject));
    //    testObject reference count should decrease by 2, should equal 1
    assert(1 == TKAObjectGetReferenceCount(testObject));
    
    TKAObjectRelease(testObject);
    TKAObjectRelease(list);
}

//TKALinkedList
//      after creating list
//          list count should  equal 0
//          list reference count should equal 1
//              after adding NULL to list
//                  list count should  equal 0
//                  list reference count should equal 1
//                  list shouldn't contain NULL
//                      after ctreating and adding objects testObject1, testObject2 to list
//                          list count should  equal 2
//                          list should contain testObject11, testObject12
//                          each testObjects reference count should equal 2
//                              after adding object NULL to list before testObject1, testObject2
//                                  list count shouldn't change, should equal 2
//                                  list shouldn't contain NULL
//                                      after adding object NULL to list after testObject1, testObject2
//                                          list count shouldn't change, should equal 2
//                                          list shouldn't contain NULL
//                                          when enumaraiting, the order in list should be testObject2, testObject1
//                                              after adding objects testObject3, testObject4 to list before testObject1, testObject2
//                                                  list count should  equal 4
//                                                  list should contain testObject3, testObject4
//                                                  each testObjects of list reference count should equal 2
//                                                  when enumaraiting, the order in list should be testObject4, testObject2, testObject3, testObject1
//                                                      after adding objects testObject5, testObject6 to list after testObject1, testObject2
//                                                          list count should  equal 6
//                                                          list should contain testObject5, testObject6
//                                                          each of testObjects of list reference count should equal 2
//                                                          when enumaraiting, the order in list should be testObject4, testObject2, testObject6, testObject3, testObject1, testObject5
//                                                              after removing object testObject6
//                                                                  list count should  equal 5
//                                                                  list shouldn't contain testObject6
//                                                                  each of testObjects of list reference count should equal 2
//                                                                  testObject6 reference count should equal 2
//                                                                  when enumaraiting, the order in list should be testObject4, testObject2, testObject3, testObject1, testObject5
//                                                                      after removing first object
//                                                                          list count should  equal 4
//                                                                          list shouldn't contain testObject4
//                                                                          each of testObjects of list reference count should equal 2
//                                                                          testObject4 reference count should equal 2
//                                                                          when enumaraiting, the order in list should be testObject2, testObject3, testObject1, testObject5
//                                                                       after removing NULL object
//                                                                          list count should  equal 4
//                                                                          list shouldn't contain testObject4
//                                                                          each of testObjects of list reference count should equal 2
//                                                                          testObject4 reference count should equal 2
//                                                                          when enumaraiting, the order in list should be testObject2, testObject3, testObject1, testObject5
//                                                                              after adding testObject3
//                                                                                  list count should  equal 4
//                                                                                  list shouldn't contain testObject4
//                                                                                  each of testObjects of list reference count should equal 2
//                                                                                  testObject4 reference count should equal 2
//                                                                                  when enumaraiting, the order in list should be testObject2, testObject3, testObject1, testObject5
//                                                                                      after removing all objects
//                                                                                          count of list should be equal 0
//                                                                                          list shouldn't contain any of testObjects
//                                                                                          testObject reference count should decrease by 1, should equal 1
//                                                                                                      Release tesstObject, list

void TKALinkedListInsertRemoveTest() {
    //    TKALinkedList
    //    after creating list
    TKALinkedList *list = TKAObjectCreate(TKALinkedList);
    
    //    count of list should be equal 0
    assert(0 == TKALinkedListGetCount(list));
    //    list reference count should equal 1
    assert(1 == TKAObjectGetReferenceCount(list));
    
    //    after ctreating and adding object testObject to list
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    TKALinkedListAddObject(list, testObject);
    
    //    count of list should be equal 1
    assert(1 == TKALinkedListGetCount(list));
    //    list should contain testObject
    assert(TKALinkedListContainsObject(list, testObject));
    //    testObject reference count should increasse by 1, should equal 2
    assert(2 == TKAObjectGetReferenceCount(testObject));
    
    //    after adding object NULL to list
    TKALinkedListAddObject(list, NULL);
    //    count of list shouldn't change, should be equal 1
    assert(1 == TKALinkedListGetCount(list));
    //    list shouldn't contain NULL
    assert(!TKALinkedListContainsObject(list, NULL));
    
    //    after adding object testObject to list
    TKALinkedListAddObject(list, testObject);
    
    //    count of list should be equal 2
    assert(2 == TKALinkedListGetCount(list));
    //    list should contain testObject
    assert(TKALinkedListContainsObject(list, testObject));
    //    testObject reference count should increasse by 1, should equal 3
    assert(3 == TKAObjectGetReferenceCount(testObject));
    
    //    after removing object tesstObject from list twice
    TKALinkedListRemoveObject(list, testObject);
    TKALinkedListRemoveObject(list, testObject);
    //    list count should be equal 0
    assert(0 == TKALinkedListGetCount(list));
    //    list shouldn't contain testObject
    assert(!TKALinkedListContainsObject(list, testObject));
    //    testObject reference count should decrease by 2, should equal 1
    assert(1 == TKAObjectGetReferenceCount(testObject));
    
    TKAObjectRelease(testObject);
    TKAObjectRelease(list);
}