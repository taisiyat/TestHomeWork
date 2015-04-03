//
//  TKAAutoreleasingStackTest.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 25.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAAutoreleasingStackTest.h"

#pragma mark -
#pragma mark Private Declarations

static
const size_t TKAAutoreleasingStackSize = 64;

static
void TKAAutoreleasingStackBehaviorTest();

static
void TKAAutoreleasingStackPushPopObjectsTest();

#pragma mark -
#pragma mark Public Implementations

void TKAAutoreleasingStackPerformTest() {
    TKAAutoreleasingStackBehaviorTest();
    TKAAutoreleasingStackPushPopObjectsTest();
}

#pragma mark -
#pragma mark Private Implementations

// TKAAutoreleasingStack
//      after creating stack and object
//          stack should be Empty
//          stack reference count should be 1
//          object reference count should be 1
//              after retaining and pushing object to stack
//                  stack shouldn't be Empty
//                  object reference count stack should be 1
//                  object reference count object should be 1
//                          after poping object from stack
//                              stack should be Empty
//                              stack PopType should equal TKAAutoreleasingStackObjectPop
//                              object reference count stack should be 1
//                              object reference count object should be 1
//                                      after releasing
//                                          stack and odject should be deallocate

void TKAAutoreleasingStackBehaviorTest() {
    //      after creating stack and object
    TKAAutoreleasingStack *stack = TKAAutoreleasingStackCreateWithSize(TKAAutoreleasingStackSize);
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    //          stack should be Empty
    assert(TKAAutoreleasingStackIsEmpty(stack));
    //           object reference count stack should be 1
    assert(1 == TKAObjectGetReferenceCount(stack));
    //           object reference count object should be 1
    assert(1 == TKAObjectGetReferenceCount(testObject));
    //              after pushing object to stack
    TKAObjectRetain(testObject);
    TKAAutoreleasingStackPushObject(stack, testObject);
    //                  stack shouldn't be Empty
    assert(!TKAAutoreleasingStackIsEmpty(stack));
    //                  stack reference count should be 1
    assert(1 == TKAObjectGetReferenceCount(stack));
    //                  object reference count should be 2
    assert(2 == TKAObjectGetReferenceCount(testObject));
    //                          after poping object from stack
    //                              stack PopType should equal TKAAutoreleasingStackObjectPop
    assert(TKAAutoreleasingStackObjectPop == TKAAutoreleasingStackPopObject(stack));
    //                              stack should be Empty
    assert(TKAAutoreleasingStackIsEmpty(stack));
    //                              object reference count stack should be 1
    assert(1 == TKAObjectGetReferenceCount(stack));
    //                              object reference count object should be 1
    assert(1 == TKAObjectGetReferenceCount(testObject));
    //                                      after releasing
    TKAObjectRelease(testObject);
    TKAObjectRelease(stack);
    //                                          stack and odject should be deallocate
}

// TKAAutoreleasingStack
//      after creating stack and object
//          stack should be Empty
//          object reference count should be 1
//              after 8 times object retainig and 8 pushing object to stack
//                  stack should be Full
//                  object reference count should increment by 8, should equal 9
//                          after poping object from stack
//                              result of poping object should be TKAAutoreleasingStackObjectPop
//                              stack should be Empty
//                              object reference count should decrement by 8, should equal 1
//                after pushing NULL to stack
//                      stack shouldn't be Empty
//                          after 7 times object retainig and 7 pushing object to stack
//                              stack should be Full
//                              object reference count should increment by 7, should equal 8
//                                  after poping All objects from stack
//                                      result of poping objects should be equl TKAAutoreleasingStackNULLPop
//                                      stack should be Empty
//                                      object reference count should decrement by 7, should equal 1
//                after pushing 8 NULL to stack
//                      stack should be Full
//                             after poping objects from stack
//                                 result of poping objects should be equl TKAAutoreleasingStackNULLPop 8 times
//                                 stack should be Empty
//                                          after releasing
//                                              stack and odject should be deallocated

void TKAAutoreleasingStackPushPopObjectsTest() {
    //    after creating stack and object
    TKAAutoreleasingStack *stack = TKAAutoreleasingStackCreateWithSize(TKAAutoreleasingStackSize);
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    //    stack should be Empty
    assert(TKAAutoreleasingStackIsEmpty(stack));
    //    object reference count should be 1
    assert(TKAObjectGetReferenceCount(testObject) == 1);
    //    after 8 pushing and retaining object to stack
    for (uint8_t iter = 1; iter <= 8; iter++) {
        TKAObjectRetain(testObject);
        TKAAutoreleasingStackPushObject(stack, testObject);
    }
    //    stack should be Full
    assert(TKAAutoreleasingStackIsFull(stack));
    //    object reference count should be 9
    assert(TKAObjectGetReferenceCount(testObject) == 9);
    //    after poping object from stack
    TKAAutoreleasingStackPopType result = TKAAutoreleasingStackPopObjects(stack);
    //    result of poping object should be TKAAutoreleasingStackObjectPop
    assert(TKAAutoreleasingStackObjectPop == result);
    //    stack should be Empty
    assert(TKAAutoreleasingStackIsEmpty(stack));
    //    object reference count should decrement by 8, should equal 1
    assert(TKAObjectGetReferenceCount(testObject) == 1);
    //    after pushing NULL to stack
    TKAAutoreleasingStackPushObject(stack, NULL);
    //    stack shouldn't be Empty
        assert(!TKAAutoreleasingStackIsEmpty(stack));
    
    //    after 7 pushing object to stack
    for (uint8_t iter = 1; iter <= 7; iter++) {
        TKAObjectRetain(testObject);
        TKAAutoreleasingStackPushObject(stack, testObject);
    }
    //    stack should be Full
    assert(TKAAutoreleasingStackIsFull(stack));
    //    object reference count should be 8
    assert(TKAObjectGetReferenceCount(testObject) == 8);
    //    after poping object from stack
    result = TKAAutoreleasingStackPopObjects(stack);
    //    result of poping objects should be equl TKAAutoreleasingStackNULLPop
    assert(TKAAutoreleasingStackNullPop == result);
    //    stack should be Empty
    assert(TKAAutoreleasingStackIsEmpty(stack));
    //    object reference count should decrement by 7, should equal 1
    assert(TKAObjectGetReferenceCount(testObject) == 1);
    
    //    after pushing 8 NULL to stack
    for (uint8_t iter = 1; iter <= 8; iter++) {
        TKAAutoreleasingStackPushObject(stack, NULL);
    }
    //    stack should be Full
    assert(TKAAutoreleasingStackIsFull(stack));
    //    after poping objects from stack
    uint8_t testCount = 0;
    for (uint8_t iter = 1; iter <= 8; iter++) {
        if (TKAAutoreleasingStackNullPop == TKAAutoreleasingStackPopObject(stack)) {
            testCount++;
        }
    }
    //    result of poping objects should be equl TKAAutoreleasingStackNULLPop 8 times
    assert(8 == testCount);
    //    stack should be Empty
    assert(TKAAutoreleasingStackIsEmpty(stack));
    //    after releasing
    TKAObjectRelease(testObject);
    TKAObjectRelease(stack);
    //    stack and odject should be free
}


