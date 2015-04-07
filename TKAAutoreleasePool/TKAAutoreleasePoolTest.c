//
//  TKAAutoreleasePoolTest.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 02.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAAutoreleasePoolTest.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKAAutoreleasePoolCreateDrainTest();

static
void TKAAutoreleasePoolTestWithManyObjects();

#pragma mark -
#pragma mark Public Implementations

void TKAAutoreleasePoolPerformTest() {
    TKAAutoreleasePoolCreateDrainTest();
    TKAAutoreleasePoolTestWithManyObjects();
}

#pragma mark -
#pragma mark Private Implementations

//TKAAutoreleasePool
//      after create new pool
//          after creating, retaining and adding object to pool
//              object reference count should equal 2
//                  after draining the pool
//                      object reference count should decrease, should equal 1

void TKAAutoreleasePoolCreateDrainTest() {
    //TKAAutoreleasePool
    //      after create new pool
    TKAAutoreleasePool *pool = TKAAutoreleasePoolNew();

    //          after creating, retaining and adding object to pool
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    TKAObjectRetain(testObject);
    TKAAutoreleasePoolAddObject(pool, testObject);
    
    //              object reference count should equal 2
    assert(2 == TKAObjectGetReferenceCount(testObject));
    
    //                  after draining the pool
    TKAAutoreleasePoolDrain(pool);
    
    //                      object reference count should decrease, should equal 1
    assert(1 == TKAObjectGetReferenceCount(testObject));

    TKAObjectRelease(testObject);
}

//TKAAutoreleasePool
//      after create new pool
//          after creating, retaining and adding object to pool
//              object reference count should equal 2
//                  after draining the pool
//                      object reference count should decrease, should equal 1

void TKAAutoreleasePoolTestWithManyObjects() {
    
}
