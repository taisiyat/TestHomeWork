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

static
void TKALinkedListEnumeratorTest();

#pragma mark -
#pragma mark Public Implementations

void TKALinkedListPerformTest() {
    TKALinkedListAddRemoveTest();
    TKALinkedListInsertRemoveTest();
    TKALinkedListEnumeratorTest();
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
//                                                                              after removing NULL object
//                                                                                  list count should  equal 4

//                                                                                      after adding testObject3
//                                                                                          list count should  equal 5
//                                                                                          testObject3 reference count should equal 3
//                                                                                          when enumaraiting, the order in list should be testObject3, testObject2, testObject3, testObject1, testObject5
//                                                                                              after removing all objects
//                                                                                                  count of list should be equal 0
//                                                                                                  list shouldn't contain any of testObjects
//                                                                                                  testObject reference count should decrease by 1, should equal 1
//                                                                                                          Release tesstObject, list

void TKALinkedListInsertRemoveTest() {
    //    TKALinkedList
    //    after creating list
    TKALinkedList *list = TKAObjectCreate(TKALinkedList);
    
    //    list count should  equal 0
    assert(0 == TKALinkedListGetCount(list));
    //    list reference count should equal 1
    assert(1 == TKAObjectGetReferenceCount(list));
    //    list shouldn't contain NULL
    assert(!TKALinkedListContainsObject(list, NULL));
    
    //    after adding NULL to list
    TKALinkedListAddObject(list, NULL);
    
    //    list count should  equal 0
    assert(0 == TKALinkedListGetCount(list));
    //    list shouldn't contain NULL
    assert(!TKALinkedListContainsObject(list, NULL));
    //    after ctreating testObjects
    
    TKAObject *testObject[6];
    for (uint8_t iter = 0; iter <= 5; iter++) {
        testObject[iter] = TKAObjectCreate(TKAObject);
    }
    
    //    after adding objects testObject1, testObject2 to list
    for (uint8_t iter = 0; iter <= 1; iter++) {
        TKALinkedListAddObject(list, testObject[iter]);
    }
    
    //    list count should  equal 2
    assert(2 == TKALinkedListGetCount(list));
    //    list should contain testObject1, testObject2
    for (uint8_t iter = 0; iter <= 1; iter++) {
        assert(TKALinkedListContainsObject(list, testObject[iter]));
    }
    //    each testObjects reference count should equal 2
    for (uint8_t iter = 0; iter <= 1; iter++) {
        assert(2 == TKAObjectGetReferenceCount(testObject[iter]));
    }
    
    //    when enumaraiting, the order in list should be testObject2, testObject1
    TKAObject *object = NULL;
    TKAObject *objects[2] = {testObject[1], testObject[0]};
    uint8_t iter = 0;
    
    TKALinkedListEnumerator *enumerator = TKALinkedListEnumeratorCreateWithList(list);
    while (TKALinkedListEnumeratorIsValid(enumerator)
           && (object = TKALinkedListEnumeratorNextObject(enumerator))) {
        assert(objects[iter] == object);
        iter++;
    }
    TKAObjectRelease(enumerator);
    
    //    after adding object NULL to list before testObject1, testObject2
    for (uint8_t iter = 0; iter <= 1; iter++) {
        TKALinkedListInsertBeforeObject(list, testObject[iter], NULL);
    }
    
    //    list count shouldn't change, should equal 2
    assert(2 == TKALinkedListGetCount(list));
    //    list shouldn't contain NULL
    assert(!TKALinkedListContainsObject(list, NULL));
    
    //    after adding object NULL to list after testObject1, testObject2
    for (uint8_t iter = 0; iter <= 1; iter++) {
        TKALinkedListInsertAfterObject(list, testObject[iter], NULL);
    }
    
    //    list count shouldn't change, should equal 2
    assert(2 == TKALinkedListGetCount(list));
    //    list shouldn't contain NULL
    assert(!TKALinkedListContainsObject(list, NULL));
    
    //    after adding objects testObject3, testObject4 to list before testObject1, testObject2
    for (uint8_t iter = 0; iter <= 1; iter++) {
        TKALinkedListInsertBeforeObject(list, testObject[iter], testObject[iter+2]);
    }
    
    //    list count should  equal 4
    assert(4 == TKALinkedListGetCount(list));
    //    list should contain testObject3, testObject4
    for (uint8_t iter = 2; iter <= 3; iter++) {
        assert(TKALinkedListContainsObject(list, testObject[iter]));
    }
    //    each testObjects of list reference count should equal 2
    for (uint8_t iter = 0; iter <= 3; iter++) {
        assert(2 == TKAObjectGetReferenceCount(testObject[iter]));
    }
    
    //    when enumaraiting, the order in list should be testObject4, testObject2, testObject3, testObject1
    object = NULL;
    TKAObject *objects1[4] = {testObject[3], testObject[1], testObject[2], testObject[0]};
    iter = 0;
    
    TKALinkedListEnumerator *enumerator1 = TKALinkedListEnumeratorCreateWithList(list);
    while (TKALinkedListEnumeratorIsValid(enumerator1)
           && (object = TKALinkedListEnumeratorNextObject(enumerator1))) {
        assert(objects1[iter] == object);
        iter++;
    }
    TKAObjectRelease(enumerator1);
    
    //    after adding objects testObject5, testObject6 to list after testObject1, testObject2
    for (uint8_t iter = 0; iter <= 1; iter++) {
        TKALinkedListInsertAfterObject(list, testObject[iter], testObject[iter+4]);
    }
    
    //    list count should  equal 6
    assert(6 == TKALinkedListGetCount(list));
    //    list should contain testObject5, testObject6
    for (uint8_t iter = 4; iter <= 5; iter++) {
        assert(TKALinkedListContainsObject(list, testObject[iter]));
    }
    //    each of testObjects of list reference count should equal 2
    for (uint8_t iter = 0; iter <= 5; iter++) {
        assert(2 == TKAObjectGetReferenceCount(testObject[iter]));
    }

    //    when enumaraiting, the order in list should be testObject4, testObject2, testObject6, testObject3, testObject1, testObject5
    object = NULL;
    TKAObject *objects2[6] = {testObject[3], testObject[1], testObject[5], testObject[2], testObject[0], testObject[4]};
    iter = 0;
    
    TKALinkedListEnumerator *enumerator2 = TKALinkedListEnumeratorCreateWithList(list);
    while (TKALinkedListEnumeratorIsValid(enumerator1)
           && (object = TKALinkedListEnumeratorNextObject(enumerator2))) {
        assert(objects2[iter] == object);
        iter++;
    }
    TKAObjectRelease(enumerator2);
   
    //    after removing object testObject6
    TKALinkedListRemoveObject(list, testObject[5]);
    
    //    list count should  equal 5
    assert(5 == TKALinkedListGetCount(list));
    //    list shouldn't contain testObject6
    assert(!TKALinkedListContainsObject(list, testObject[5]));
    //    each of testObjects of list reference count should equal 2
    for (uint8_t iter = 0; iter <= 4; iter++) {
        assert(2 == TKAObjectGetReferenceCount(testObject[iter]));
    }
    //    testObject6 reference count should equal 1
    assert(1 == TKAObjectGetReferenceCount(testObject[5]));
    //    when enumaraiting, the order in list should be testObject4, testObject2, testObject3, testObject1, testObject5
    
    //    after removing first object
    TKALinkedListRemoveFirstObject(list);
    
    //    list count should  equal 4
    assert(4 == TKALinkedListGetCount(list));
    //    list shouldn't contain testObject4
    assert(!TKALinkedListContainsObject(list, testObject[3]));
    //    testObject4 reference count should equal 2
    assert(1 == TKAObjectGetReferenceCount(testObject[3]));
    
    //    when enumaraiting, the order in list should be testObject2, testObject3, testObject1, testObject5
    
    //    after removing NULL object
    TKALinkedListRemoveObject(list, NULL);
    
    //    list count should  equal 4
    assert(4 == TKALinkedListGetCount(list));
    //    when enumaraiting, the order in list should be testObject2, testObject3, testObject1, testObject5
    
    //    after adding testObject3
    TKALinkedListAddObject(list, testObject[2]);
    
    //    list count should  equal 5
    assert(5 == TKALinkedListGetCount(list));
    //    list should contain testObject3
     assert(TKALinkedListContainsObject(list, testObject[2]));
    //    testObject3 reference count should equal 3
    assert(3 == TKAObjectGetReferenceCount(testObject[2]));
    //    when enumaraiting, the order in list should be testObject2, testObject2, testObject3, testObject1, testObject5
    
    //    after removing all objects
    TKALinkedListRemoveAllObjects(list);
    
    //    count of list should be equal 0
    assert(0 == TKALinkedListGetCount(list));
    //    list shouldn't contain any of testObjects
    for (uint8_t iter = 0; iter <= 5; iter++) {
        assert(!TKALinkedListContainsObject(list, testObject[iter]));
    }
    //    testObject reference count should decrease by 1, should equal 1
    for (uint8_t iter = 0; iter <= 5; iter++) {
        assert(1 == TKAObjectGetReferenceCount(testObject[iter]));
    }
    //    Release tesstObject, list
    for (uint8_t iter = 0; iter <= 5; iter++) {
        TKAObjectRelease(testObject[iter]);
    }
    TKAObjectRelease(list);
}

//TKALinkedList
//      after creating list
//          list count should  equal 0
//          list reference count should equal 1
//                      after ctreating and adding objects testObject3, testObject2, testObject1, testObject0 to list
//                          list count should  equal 4
//                          list should contain testObject3, testObject2, testObject1, testObject0
//                          each testObjects reference count should equal 2
//                          list reference count should equal 1
//                                when enumaraiting testObject3, testObject2, testObject1, testObject0
//                                should create enumerator for list
//                                    enumerator reference count should equal 1
//                                    enumerator should be Valid
//                                    list reference count should increase by 1, should equal 2
//                                          after calling EnumeratorNextNode 5 times
//                                          enumerator should return objects testObject0, testObject1, testObject2, testObject3, NULL
//                                                  after releasing enumerator
//                                                  list reference count should decrease by 1, should equal 1
//                                                           after removing all objects
//                                                                   count of list should be equal 0
//                                                                   list shouldn't contain any of testObjects
//                                                                   testObject reference count should decrease by 1, should equal 1
//                                                                          release testObjects, list
//

void TKALinkedListEnumeratorTest() {
    //    TKALinkedList
    //    after creating list
    TKALinkedList *list = TKAObjectCreate(TKALinkedList);
    
    //    list count should  equal 0
    assert(0 == TKALinkedListGetCount(list));
    //    list reference count should equal 1
    assert(1 == TKAObjectGetReferenceCount(list));
    
    //    after ctreating and adding objects testObject3, testObject2, testObject1, testObject0 to list
    TKAObject *testObject[4];
    for (uint8_t iter = 0; iter <= 3; iter++) {
        testObject[iter] = TKAObjectCreate(TKAObject);
    }
    for (uint8_t iter = 4; iter > 0; iter--) {
        TKALinkedListAddObject(list, testObject[iter-1]);
    }
    
    //    list count should  equal 4
    assert(4 == TKALinkedListGetCount(list));
    //    list should contain testObject3, testObject2, testObject1, testObject0
    for (uint8_t iter = 0; iter <= 3; iter++) {
        assert(TKALinkedListContainsObject(list, testObject[iter]));
    }
    //    each testObjects reference count should equal 2
    for (uint8_t iter = 0; iter <= 3; iter++) {
        assert(2 == TKAObjectGetReferenceCount(testObject[iter]));
    }
    //    list reference count should equal 1
    assert(1 == TKAObjectGetReferenceCount(list));
    
    //    when enumaraiting testObject3, testObject2, testObject1, testObject0
    //    should create enumerator for list
    TKALinkedListEnumerator *enumerator = TKALinkedListEnumeratorCreateWithList(list);
    
    //    enumerator reference count should equal 1
    assert(1 == TKAObjectGetReferenceCount(enumerator));
    //    enumerator should be Valid
    assert(TKALinkedListEnumeratorIsValid(enumerator));
    //    list reference count should increase by 1, should equal 2
    assert(2 == TKAObjectGetReferenceCount(list));
    
    //    after calling EnumeratorNextNode 5 times
    //    enumerator should return objects testObject0, testObject1, testObject2, testObject3, NULL
    for (uint8_t iter = 0; iter <= 3; iter++) {
        assert(testObject[iter] == TKALinkedListEnumeratorNextObject(enumerator));
    }
    assert(NULL == TKALinkedListEnumeratorNextObject(enumerator));
    
    //    after releasing enumerator
    TKAObjectRelease(enumerator);
    
    //    list reference count should decrease by 1, should equal 1
    assert(1 == TKAObjectGetReferenceCount(list));
    
    //    after removing all objects
    TKALinkedListRemoveAllObjects(list);
    
    //    count of list should be equal 0
    assert(0 == TKALinkedListGetCount(list));
    //    list shouldn't contain any of testObjects
    for (uint8_t iter = 0; iter <= 3; iter++) {
        assert(!TKALinkedListContainsObject(list, testObject[iter]));
    }
    //    testObject reference count should decrease by 1, should equal 1
    for (uint8_t iter = 0; iter <= 3; iter++) {
        assert(1 == TKAObjectGetReferenceCount(testObject[iter]));
    }
    //    Release tesstObject, list
    for (uint8_t iter = 0; iter <= 3; iter++) {
        TKAObjectRelease(testObject[iter]);
    }
    TKAObjectRelease(list);
}