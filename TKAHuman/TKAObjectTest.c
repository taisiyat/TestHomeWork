//
//  TKAObjectTest.c
//  TKAHuman
//
//  Created by Taisiya on 13.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAObjectTest.h"

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Declarations

static
void TKAObjectCreateTest();

static
void TKAObjectBehaviorTest();

#pragma mark -
#pragma mark Privat Implementations

// TKAObject
//  after being created
//      objects reference count should be equal 1
//           after releasing
//               objects reference count should be 0
//
//


// TKAObject
//  after being created
//      objects reference count should be equal 1
//          after retaining
//              objects reference count should be equal 2
//                  after retaining twice
//                      objects reference count should be increased by 2
//                           after releasing trice
//                              objects reference count should be decreased by 3
//                                  after releasing
//                                      objects reference count should be 0


void TKAObjectCreateTest() {
    // TKAObject
    //  after being created
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    //      objects reference count should be equal 1
    assert(TKAObjectGetReferenceCount(testObject) == 1);
    //           after releasing
    TKAObjectRelease(testObject);
    //               objects reference count should be 0
    assert(TKAObjectGetReferenceCount(testObject) == 0);
}

void TKAObjectBehaviorTest() {
    // TKAObject
    //  after being created
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    //      objects reference count should be equal 1
    assert(TKAObjectGetReferenceCount(testObject) == 1);
    //          after retaining
    TKAObjectRetain(testObject);
    //              objects reference count should be equal 2
    assert(TKAObjectGetReferenceCount(testObject) == 2);
    //                  after retaining twice
    TKAObjectRetain(testObject);
    TKAObjectRetain(testObject);
    //                      objects reference count should be increased by 2
    assert(TKAObjectGetReferenceCount(testObject) == 4);
    //                           after releasing trice
    TKAObjectRelease(testObject);
    TKAObjectRelease(testObject);
    TKAObjectRelease(testObject);
    //                              objects reference count should be decreased by 3
    assert(TKAObjectGetReferenceCount(testObject) == 1);
    //                                  after releasing
    TKAObjectRelease(testObject);
    //                                      objects reference count should be 0
    assert(TKAObjectGetReferenceCount(testObject) == 0);
}

#pragma mark -
#pragma mark Public Implementations

void TKAObjectPerformTests() {
    
    TKAObjectCreateTest();
    TKAObjectBehaviorTest();
    
}