//
//  TKAStack.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAStack.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKAStackSetSize(TKAStack *stack, size_t size);

static
void **TKAStackGetHead(TKAStack *stack);

static
size_t TKAStackGetSize(TKAStack *stack);

static
size_t TKAStackGetCurentSize(TKAStack *stack);

#pragma mark -
#pragma mark Public Implementations

TKAStack *TKAStackCreateWithSize(size_t size) {
    assert(0 != size);
    TKAStack *stack = TKAObjectCreate(TKAStack);
    TKAStackSetSize(stack, size);
        
    return stack;
}

void __TKAStackDeallocate(TKAStack *stack) {
    TKAStackPopObjects(stack);
    TKAStackSetSize(stack, 0);
    
    __TKAObjectDeallocate(stack);
}

bool TKAStackIsEmpty(TKAStack *stack) {
    return (NULL != stack) ? (0 == TKAStackGetCurentSize(stack)) : false;
}

bool TKAStackIsFull(TKAStack *stack) {
    return (NULL != stack) ? (TKAStackGetSize(stack) == TKAStackGetCurentSize(stack)) : false ;
}

void TKAStackPushObject(TKAStack *stack, void *object) {
    if (NULL != stack && !TKAStackIsFull(stack)) {
        void **head = TKAStackGetHead(stack);
        *head = object;
        stack->_curentSize += sizeof(object);
    }
}

TKAStackPopType TKAStackPopObject(TKAStack *stack) {
    assert(NULL != stack && !TKAStackIsEmpty(stack));
    stack->_curentSize -= sizeof(*stack->_data);
    void **head = TKAStackGetHead(stack);
    TKAStackPopType resultHead = (NULL != *head) ? TKAStackObjectPop : TKAStackObjectPop;
    if (TKAStackObjectPop == resultHead) {
        TKAObjectRelease(head);
        *head = NULL;
    }
    
    return resultHead;
}

TKAStackPopType TKAStackPopObjects(TKAStack *stack) {
    assert(NULL != stack && !TKAStackIsEmpty(stack));
    while (TKAStackObjectPop == TKAStackPopObject(stack)) {
        if (TKAStackIsEmpty(stack)) {
            return TKAStackObjectPop;
        }
    }
    
    return TKAStackNullPop;
}

#pragma mark -
#pragma mark Private Imlementations

void TKAStackSetSize(TKAStack *stack, size_t size) {
    if (NULL != stack && stack->_size != size) {
        if (NULL != stack->_data) {
            free(stack);
            stack->_data = NULL;
        }
        
        if (0 != size) {     //(size)
            stack->_data = calloc(1, size);
        }
        
        stack->_size = size;
    }
}

void **TKAStackGetHead(TKAStack *stack) {
    return (NULL != stack) ? (void *)((ptrdiff_t)(stack->_data) + TKAStackGetCurentSize(stack)) : NULL;
}

size_t TKAStackGetSize(TKAStack *stack) {
    return (NULL != stack) ? stack->_size : 0;
}

size_t TKAStackGetCurentSize(TKAStack *stack) {
    return (NULL != stack) ? stack->_curentSize : 0;
}
