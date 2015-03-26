//
//  TKAStackTest.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 25.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAStackTest.h"

#pragma mark -
#pragma mark Private Declarations

static
const size_t TKAStackSize = 64;

//static
//void TKAStackCreateTest();

static
void TKAStackBehaviorTest();

static
void TKAStackPushPopObjectsTest();

#pragma mark -
#pragma mark Public Implementations

void TKAStackPerformTest() {
//    TKAStackCreateTest();
    TKAStackBehaviorTest();
    TKAStackPushPopObjectsTest();
}

#pragma mark -
#pragma mark Private Implementations

//// TKAStack
////      after creating stack
////          stack should be Empty
////          object reference count should be 1
////              after releasing
////                  stack should die
//
//void TKAStackCreateTest() {
//    //    after creating stack
//    TKAStack *stack = TKAStackCreateWithSize(TKAStackSize);
//    //    stack should be Empty
//    assert(TKAStackIsEmpty(stack));
//    //    object reference count should be 1
//    assert(1 == TKAObjectGetReferenceCount(stack));
//    //    after releasing
//    TKAObjectRelease(stack);
//    //    stack should die}
//}

// TKAStack
//      after creating stack and object
//          stack should be Empty
//          object reference count stack should be 1
//          object reference count object should be 1
//              after pushing object to stack
//                  stack shouldn't be Empty
//                  object reference count stack should be 1
//                  object reference count object should be 1
//                          after poping object from stack
//                              stack should be Empty
//                              object reference count stack should be 1
//                              object reference count object should be 1
//                                      after releasing
//                                          stack and odject should be free

void TKAStackBehaviorTest() {
    //      after creating stack and object
    TKAStack *stack = TKAStackCreateWithSize(TKAStackSize);
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    //          stack should be Empty
    assert(TKAStackIsEmpty(stack));
    //           object reference count stack should be 1
    assert(1 == TKAObjectGetReferenceCount(stack));
    //           object reference count object should be 1
    assert(1 == TKAObjectGetReferenceCount(testObject));
    //              after pushing object to stack
    TKAStackPushObject(stack, testObject);
    //                  stack shouldn't be Empty
    assert(!TKAStackIsEmpty(stack));
    //                  object reference count stack should be 1
    assert(1 == TKAObjectGetReferenceCount(stack));
    //                  object reference count object should be 1
    assert(1 == TKAObjectGetReferenceCount(testObject));
    //                          after poping object from stack
    TKAStackPopObject(stack);
    //                              stack should be Empty
    assert(TKAStackIsEmpty(stack));
    //                              object reference count stack should be 1
    assert(1 == TKAObjectGetReferenceCount(stack));
    //                              object reference count object should be 1
    assert(1 == TKAObjectGetReferenceCount(testObject));
    //                                      after releasing
    TKAObjectRelease(testObject);
    TKAObjectRelease(stack);
    //                                          stack and odject should be free
}

// TKAStack
//      after creating stack and object
//          stack should be Empty
//              after 8 pushing object to stack
//                  stack should be Full
//                          after poping object from stack
//                              result of poping object should be TKAStackObjectPop
//                              stack should be Empty
//                after pushing NULL to stack
//                      stack shouldn't be Empty
//                          after 7 pushing object to stack
//                              stack should be Full
//                                  after poping All objects from stack
//                                      result of poping objects should be equl TKAStackNULLPop
//                                      stack should be Empty
//                after pushing 8 NULL to stack
//                      stack should be Full
//                             after poping objects from stack
//                                 result of poping objects should be equl TKAStackNULLPop 8 times
//                                 stack should be Empty
//                                          after releasing
//                                              stack and odject should be free

//    TKAStack
//    after creating stack and object
//    stack should be Empty
//    after 8 pushing object to stack
//    stack should be Full
//    after poping object from stack
//    result of poping object should be TKAStackObjectPop
//    stack should be Empty
//    after pushing NULL to stack
//    stack shouldn't be Empty
//    after 7 pushing object to stack
//    stack should be Full
//    after poping object from stack
//    result of poping objects should be equl TKAStackNULLPop
//    stack should be Empty
//    after pushing 8 NULL to stack
//    stack should be Full
//    after poping objects from stack
//    result of poping objects should be equl TKAStackNULLPop 8 times
//    stack should be Empty
//    after releasing
//    stack and odject should be free


void TKAStackPushPopObjectsTest() {
    //    after creating stack and object
    TKAStack *stack = TKAStackCreateWithSize(TKAStackSize);
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    //    stack should be Empty
    assert(TKAStackIsEmpty(stack));
    
    //    after 8 pushing object to stack
    for (uint8_t iter = 1; iter <= 8; iter++) {
        TKAStackPushObject(stack, testObject);
    }
    //    stack should be Full
    assert(TKAStackIsFull(stack));
    //    after poping object from stack
    TKAStackPopType result = TKAStackPopObjects(stack);
    //    result of poping object should be TKAStackObjectPop
    assert(TKAStackObjectPop == result);
    //    stack should be Empty
    assert(TKAStackIsEmpty(stack));
    //    after pushing NULL to stack
    TKAStackPushObject(stack, NULL);
    //    stack shouldn't be Empty
        assert(!TKAStackIsEmpty(stack));
    
    //    after 7 pushing object to stack
    for (uint8_t iter = 1; iter <= 7; iter++) {
        TKAStackPushObject(stack, testObject);
    }
    //    stack should be Full
    assert(TKAStackIsFull(stack));
    //    after poping object from stack
    result = TKAStackPopObjects(stack);
    //    result of poping objects should be equl TKAStackNULLPop
    assert(TKAStackNullPop == result);
    //    stack should be Empty
    assert(TKAStackIsEmpty(stack));
    
    //    after pushing 8 NULL to stack
    for (uint8_t iter = 1; iter <= 8; iter++) {
        TKAStackPushObject(stack, NULL);
    }
    //    stack should be Full
    assert(TKAStackIsFull(stack));
    //    after poping objects from stack
    uint8_t testCount = 0;
    for (uint8_t iter = 1; iter <= 8; iter++) {
        if (TKAStackNullPop == TKAStackPopObject(stack)) {
            testCount++;
        }
    }
    //    result of poping objects should be equl TKAStackNULLPop 8 times
    assert(8 == testCount);
    //    stack should be Empty
    assert(TKAStackIsEmpty(stack));
    //    after releasing
    TKAObjectRelease(testObject);
    TKAObjectRelease(stack);
    //    stack and odject should be free
}


