//
//  TKAAutoreleasingStack.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAAutoreleasingStack.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKAAutoreleasingStackSetSize(TKAAutoreleasingStack *stack, size_t size);

static
void **TKAAutoreleasingStackGetHead(TKAAutoreleasingStack *stack);

static
size_t TKAAutoreleasingStackGetSize(TKAAutoreleasingStack *stack);

static
size_t TKAAutoreleasingStackGetCurentSize(TKAAutoreleasingStack *stack);

static
void TKAAutoreleasingStackPopAllObjects(TKAAutoreleasingStack *stack);

#pragma mark -
#pragma mark Public Implementations

TKAAutoreleasingStack *TKAAutoreleasingStackCreateWithSize(size_t size) {
    if (0 == size) {
        return NULL;
    }
    
    TKAAutoreleasingStack *stack = TKAObjectCreate(TKAAutoreleasingStack);
    TKAAutoreleasingStackSetSize(stack, size);
        
    return stack;
}

void __TKAAutoreleasingStackDeallocate(TKAAutoreleasingStack *stack) {
    TKAAutoreleasingStackPopAllObjects(stack);
    TKAAutoreleasingStackSetSize(stack, 0);
    
    __TKAObjectDeallocate(stack);
}

bool TKAAutoreleasingStackIsEmpty(TKAAutoreleasingStack *stack) {
    return (NULL != stack && 0 == TKAAutoreleasingStackGetCurentSize(stack));
}

bool TKAAutoreleasingStackIsFull(TKAAutoreleasingStack *stack) {
    return (NULL != stack && TKAAutoreleasingStackGetSize(stack) == TKAAutoreleasingStackGetCurentSize(stack));
}

void TKAAutoreleasingStackPushObject(TKAAutoreleasingStack *stack, void *object) {
    if (NULL != stack && !TKAAutoreleasingStackIsFull(stack)) {
        void **head = TKAAutoreleasingStackGetHead(stack);
        *head = object;
        stack->_currentSize += sizeof(object);
    }
}

TKAAutoreleasingStackPopType TKAAutoreleasingStackPopObject(TKAAutoreleasingStack *stack) {
    if (NULL != stack && !TKAAutoreleasingStackIsEmpty(stack)) {
        stack->_currentSize -= sizeof(*stack->_data);
        void **head = TKAAutoreleasingStackGetHead(stack);

        TKAAutoreleasingStackPopType popTypeHead = (NULL != *head) ? TKAAutoreleasingStackObjectPop : TKAAutoreleasingStackNullPop;
    
        if (TKAAutoreleasingStackObjectPop == popTypeHead) {
            TKAObjectRelease(*head);
            *head = NULL;
        }
    
        return popTypeHead;
    }
        
    return TKAAutoreleasingStackNullPop;
}


TKAAutoreleasingStackPopType TKAAutoreleasingStackPopObjects(TKAAutoreleasingStack *stack) {
    if (NULL != stack && !TKAAutoreleasingStackIsEmpty(stack)) {
        while (TKAAutoreleasingStackObjectPop == TKAAutoreleasingStackPopObject(stack)) {
            if (TKAAutoreleasingStackIsEmpty(stack)) {
                return TKAAutoreleasingStackObjectPop;
            }
        }
    
        return TKAAutoreleasingStackNullPop;
    }
    
    return TKAAutoreleasingStackNullPop;
}


#pragma mark -
#pragma mark Private Imlementations

void TKAAutoreleasingStackSetSize(TKAAutoreleasingStack *stack, size_t size) {
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

void TKAAutoreleasingStackPopAllObjects(TKAAutoreleasingStack *stack) {
    while (!TKAAutoreleasingStackIsEmpty(stack)) {
        TKAAutoreleasingStackPopObjects(stack);
    }
}

void **TKAAutoreleasingStackGetHead(TKAAutoreleasingStack *stack) {
    return (NULL != stack) ? (stack->_data + stack->_currentSize/sizeof(void *)) : NULL;
}

size_t TKAAutoreleasingStackGetSize(TKAAutoreleasingStack *stack) {
    return (NULL != stack) ? stack->_size : 0;
}

size_t TKAAutoreleasingStackGetCurentSize(TKAAutoreleasingStack *stack) {
    return (NULL != stack) ? stack->_currentSize : 0;
}
