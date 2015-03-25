//
//  TKAObjectTest.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 25.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAObjectTest.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKAObjectBehaviorTest();

#pragma mark -
#pragma mark Public Implementations

void TKAObjectPerformTests() {
    
    TKAObjectBehaviorTest();
}

#pragma mark -
#pragma mark Private Implementations

// TKAObject
//  after being created
//      object reference count should equal 1
//          after retaining
//              object reference count should equal 2
//                  after retaining
//                      object reference count should increased by 1
//                           after releasing twice
//                              object reference count should be decreased by 2
//                                  after releasing
//                                      object should die

void TKAObjectBehaviorTest() {
    // TKAObject
    //  after being created
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    //      object reference count should be equal 1
    assert(TKAObjectGetReferenceCount(testObject) == 1);
    //          after retaining
    TKAObjectRetain(testObject);
    //              object reference count should be equal 2
    assert(TKAObjectGetReferenceCount(testObject) == 2);
    //                  after retaining twice
    TKAObjectRetain(testObject);
    //                      object reference count should be increased by 1
    assert(TKAObjectGetReferenceCount(testObject) == 3);
    //                           after releasing trice
    TKAObjectRelease(testObject);
    TKAObjectRelease(testObject);
    //                              object reference count should be decreased by 2
    assert(TKAObjectGetReferenceCount(testObject) == 1);
    //                                  after releasing
    TKAObjectRelease(testObject);
    //                                      object should die
}
