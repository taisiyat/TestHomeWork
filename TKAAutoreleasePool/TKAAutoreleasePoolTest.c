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
void TKAAutoreleasePoolTestEasy();

static
void TKAAutoreleasePoolTest();

#pragma mark -
#pragma mark Public Implementations

void TKAAutoreleasePoolPerformTest() {
    TKAAutoreleasePoolTestEasy();
    TKAAutoreleasePoolTest();
}

#pragma mark -
#pragma mark Private Implementations

//TKAAutoreleasePool
//      after create new pool
//          after creating, retaining and adding object to pool
//              object reference count should equal 2
//                  after draining the pool
//                      object reference count should decrease, should equal 1

void TKAAutoreleasePoolTestEasy() {
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
    __TKAAutoreleasePoolDeallocate(pool);
}

//TKAAutoreleasePool
//      after calling new pool and receiving pool
//          after creating, retaining and adding object to pool 20 times
//              object reference count should equal 20+1
//                  after calling new pool and receiving pool1
//                      pool1 should be equal pool
//                          after retaining and adding object to pool 10 times
//                              object reference count should equal 30+1
//                                  after calling new pool and receiving pool2
//                                      pool2 should be equal pool
//                                          after calling new pool and receiving pool3
//                                              pool3 should be equal pool
//                                                   after retaining and adding object to pool 5 times
//                                                   object reference count should equal 35+1
//                                                          after draining pool3
//                                                          object reference count should decrease, should equal 30+1
//                                                              after draining pool2
//                                                                  object reference count should not decrease, should equal 30+1
//                                                                      after draining pool1
//                                                                          object reference count should decrement, should equal 20+1
//                                                                              after draining pool
//                                                                                  object reference count should decrement, should equal 1
//                  after draining the pool
//                      object reference count should decrease, should equal 1

void TKAAutoreleasePoolTest() {
    //    TKAAutoreleasePool
    //    after calling new pool and receiving pool
    TKAAutoreleasePool *pool = TKAAutoreleasePoolNew();
    
    //    after creating, retaining and adding object to pool 20 times
    
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    for (uint8_t iter = 1; iter <=20; iter++) {
    TKAObjectRetain(testObject);
    TKAAutoreleasePoolAddObject(pool, testObject);
    }
    
    //    object reference count should equal 20+1
    assert(20 + 1 == TKAObjectGetReferenceCount(testObject));
    
    //    after calling new pool and receiving pool1
    TKAAutoreleasePool *pool1 = TKAAutoreleasePoolNew();
    
    //    pool1 should be equal pool
    assert(pool == pool1);
    
    //    after retaining and adding object to pool 10 times
    TKAObject *testObject2 = TKAObjectCreate(TKAObject);
    for (uint8_t iter = 1; iter <=10; iter++) {
        TKAObjectRetain(testObject2);
        TKAAutoreleasePoolAddObject(pool1, testObject2);
    }
    
    //    object reference count should equal 30+1
    assert(21 == TKAObjectGetReferenceCount(testObject));
      assert(11 == TKAObjectGetReferenceCount(testObject2));

    //    after calling new pool and receiving pool2
    TKAAutoreleasePool *pool2 = TKAAutoreleasePoolNew();
    
    //    pool2 should be equal pool
    assert(pool == pool2);
    
    //    after calling new pool and receiving pool3
    TKAAutoreleasePool *pool3 = TKAAutoreleasePoolNew();
    
    //    pool3 should be equal pool
    assert(pool == pool3);
    
    //    after retaining and adding object to pool 5 times
    for (uint8_t iter = 1; iter <=5; iter++) {
        TKAObjectRetain(testObject);
        TKAAutoreleasePoolAddObject(pool3, testObject);
    }
    
    //    object reference count should equal 35+1
    assert(26 == TKAObjectGetReferenceCount(testObject));
 
    //    after draining pool3
    TKAAutoreleasePoolDrain(pool2);
    
    //    object reference count should decrease by 5, should equal 30+1
    assert(21 == TKAObjectGetReferenceCount(testObject));
    assert(11 == TKAObjectGetReferenceCount(testObject2));
    
    //    after draining pool2
    TKAAutoreleasePoolDrain(pool1);
    
    //    object reference count shouldn't decrease, should equal 30+1
    assert(21 == TKAObjectGetReferenceCount(testObject));
    
    //    after draining pool1
    TKAAutoreleasePoolDrain(pool3);
    
    //    object reference count should decrease by 10, should equal 20+1
    assert(21 == TKAObjectGetReferenceCount(testObject));
    assert(1 == TKAObjectGetReferenceCount(testObject2));
    
    //    after draining pool
    TKAAutoreleasePoolDrain(pool);
    
    //    object reference count should decrease, should equal 1
    assert(1 == TKAObjectGetReferenceCount(testObject));
    
    TKAObjectRelease(testObject);
    TKAObjectRelease(testObject2);
    __TKAAutoreleasePoolDeallocate(pool);
}


