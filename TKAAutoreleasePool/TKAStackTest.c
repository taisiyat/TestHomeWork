//
//  TKAStackTest.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 11.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAStackTest.h"

#pragma mark -
#pragma mark Private Declarations

static const size_t TKAStackSize = 128;

static
void TKAStackCreateTest();

static
void TKAStackBehaviorTest();

static
void TKAStackPushPopObjectsTest();

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Private Implementations

void TKAStackCreateTest() {
    TKAStack *stack = TKAStackCreateWithSize(TKAStackSize);
    
    assert(TKAStackIsEmpty(stack));
    assert(1 == TKAObjectGetReferenceCount(stack));
    
    TKAObjectRelease(stack);
}

void TKAStackBehaviorTest() {
    TKAStack *stack = TKAStackCreateWithSize(TKAStackSize);
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    
    TKAStackPushObject(stack, testObject);
    
    assert(1 == TKAObjectGetReferenceCount(stack));
    assert(false == TKAStackIsEmpty(stack));
    
    TKAStackPopObject(stack);
    
    assert(1 == TKAObjectGetReferenceCount(stack));
    assert(TKAStackIsEmpty(stack));
    
    TKAObjectRelease(testObject);
    TKAObjectRelease(stack);
}

void TKAStackPushPopObjectsTest1() {
    TKAStack *stack = TKAStackCreateWithSize(TKAStackSize);
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    
    for (uint8_t iter = 1; iter <= 16; iter++) {
        TKAStackPushObject(stack, testObject);
    }
    
    assert(1 == TKAObjectGetReferenceCount(stack));
//    assert(17 == TKAObjectGetReferenceCount(testObject));
    assert(TKAStackIsFull(stack));
    assert(false == TKAStackIsEmpty(stack));
    
    TKAStackPopType result = TKAStackPopObjects(stack);

    assert(TKAStackObjectPop == result);
    assert(1 == TKAObjectGetReferenceCount(stack));
//    assert(1 == TKAObjectGetReferenceCount(testObject));
    assert(TKAStackIsEmpty(stack));
    
    TKAObjectRelease(testObject);
    TKAObjectRelease(stack);
}

void TKAStackPushPopObjectsTest2() {
    TKAStack *stack = TKAStackCreateWithSize(TKAStackSize);
    TKAObject *testObject = TKAObjectCreate(TKAObject);

    TKAStackPushObject(stack, NULL);
    for (uint8_t iter = 1; iter <= 15; iter++) {
        TKAStackPushObject(stack, testObject);
    }
    
    assert(1 == TKAObjectGetReferenceCount(stack));
    //    assert(17 == TKAObjectGetReferenceCount(testObject));
    assert(TKAStackIsFull(stack));
    assert(false == TKAStackIsEmpty(stack));
    
    TKAStackPopType result = TKAStackPopObjects(stack);
    
    assert(TKAStackNullPop == result);
    assert(1 == TKAObjectGetReferenceCount(stack));
    //    assert(1 == TKAObjectGetReferenceCount(testObject));
    assert(TKAStackIsEmpty(stack));
    
    TKAObjectRelease(testObject);
    TKAObjectRelease(stack);
}

void TKAStackPushPopObjectsTest3() {
    TKAStack *stack = TKAStackCreateWithSize(TKAStackSize);
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    
    for (uint8_t iter = 1; iter <= 16; iter++) {
        TKAStackPushObject(stack, NULL);
    }
    
    assert(1 == TKAObjectGetReferenceCount(stack));
    //    assert(17 == TKAObjectGetReferenceCount(testObject));
    assert(TKAStackIsFull(stack));
    assert(false == TKAStackIsEmpty(stack));
    
    uint8_t testCount = 0;
    for (uint8_t iter = 1; iter <= 16; iter++) {
        if (TKAStackNullPop == TKAStackPopObject(stack)) {
            testCount++;
        }
    }

    assert(16 == testCount);
    assert(1 == TKAObjectGetReferenceCount(stack));
    //    assert(1 == TKAObjectGetReferenceCount(testObject));
    assert(TKAStackIsEmpty(stack));
    
    TKAObjectRelease(testObject);
    TKAObjectRelease(stack);
}

#pragma mark -
#pragma mark Public Implementations

void TKAStackPerformTest() {
    
//    TKAStackCreateTest();
//    TKAStackBehaviorTest();
    TKAStackPushPopObjectsTest1();
    TKAStackPushPopObjectsTest2();
    TKAStackPushPopObjectsTest3();
    
}
