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

static
void TKAStackPopAllObjects(TKAStack *stack);

#pragma mark -
#pragma mark Public Implementations

TKAStack *TKAStackCreateWithSize(size_t size) {
    if (0 == size) {
        return NULL;
    }
    
    TKAStack *stack = TKAObjectCreate(TKAStack);
    TKAStackSetSize(stack, size);
        
    return stack;
}

void __TKAStackDeallocate(TKAStack *stack) {
    TKAStackPopAllObjects(stack);
    TKAStackSetSize(stack, 0);
    
    __TKAObjectDeallocate(stack);
}

bool TKAStackIsEmpty(TKAStack *stack) {
    return (NULL != stack && 0 == TKAStackGetCurentSize(stack));
}

bool TKAStackIsFull(TKAStack *stack) {
    return (NULL != stack && TKAStackGetSize(stack) == TKAStackGetCurentSize(stack));
}

void TKAStackPushObject(TKAStack *stack, void *object) {
    if (NULL != stack && !TKAStackIsFull(stack)) {
        void **head = TKAStackGetHead(stack);
        *head = object;
        stack->_currentSize += sizeof(object);
    }
}

TKAStackPopType TKAStackPopObject(TKAStack *stack) {
    if (NULL != stack && !TKAStackIsEmpty(stack)) {
        stack->_currentSize -= sizeof(*stack->_data);
        void **head = TKAStackGetHead(stack);

        TKAStackPopType popTypeHead = (NULL != *head) ? TKAStackObjectPop : TKAStackNullPop;
    
        if (TKAStackObjectPop == popTypeHead) {
<<<<<<< HEAD
            TKAObjectRelease(head);
=======
            TKAObjectRelease(*head);
>>>>>>> feature/AutoreleasePool
            *head = NULL;
        }
    
        return popTypeHead;
    }
        
    return TKAStackNullPop;
}


TKAStackPopType TKAStackPopObjects(TKAStack *stack) {
    if (NULL != stack && !TKAStackIsEmpty(stack)) {
        while (TKAStackObjectPop == TKAStackPopObject(stack)) {
            if (TKAStackIsEmpty(stack)) {
                return TKAStackObjectPop;
            }
        }
    
        return TKAStackNullPop;
    }
    
    return TKAStackNullPop;
}


#pragma mark -
#pragma mark Private Imlementations

void TKAStackSetSize(TKAStack *stack, size_t size) {
    if (NULL != stack && stack->_size != size) {
        if (NULL != stack->_data) {
            free(stack->_data);
            stack->_data = NULL;
        }
        
        if (0 != size) {     //(size)
            stack->_data = calloc(1, size);
        }
        
        stack->_size = size;
    }
}

void TKAStackPopAllObjects(TKAStack *stack) {
    while (!TKAStackIsEmpty(stack)) {
        TKAStackPopObjects(stack);
    }
}

void **TKAStackGetHead(TKAStack *stack) {
<<<<<<< HEAD
    return (NULL != stack) ? (void **)((stack->_data) + (stack->_currentSize)) : NULL;
=======
    return (NULL != stack) ? ((void **)(ptrdiff_t)stack->_data + stack->_currentSize) : NULL;
>>>>>>> feature/AutoreleasePool
}

size_t TKAStackGetSize(TKAStack *stack) {
    return (NULL != stack) ? stack->_size : 0;
}

size_t TKAStackGetCurentSize(TKAStack *stack) {
    return (NULL != stack) ? stack->_currentSize : 0;
}
