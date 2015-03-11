//
//  TKAStack.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 10.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAStack.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKAStackSetSize(TKAStack *stack, size_t ssize);

static
size_t TKAStackGetCurentSize(TKAStack *stack);

static
size_t TKAStackGetSize(TKAStack *stack);

static
void **TKAStackGetHead(TKAStack *stack);

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Private Implementations

void TKAStackSetSize(TKAStack *stack, size_t size) {
    if (stack->_size != size) {
        if (NULL != stack->_data) {
            free(stack->_data);
            stack->_data = NULL;
            
        }
        
        stack->_size = size;
        
        if (size) {
            stack->_data = calloc(1, size);
        }
    }
}

size_t TKAStackGetCurentSize(TKAStack *stack) {
    return stack->_currentSize;
}

size_t TKAStackGetSize(TKAStack *stack) {
    return stack->_size;
}

void **TKAStackGetHead(TKAStack *stack) {
    return stack->_data + TKAStackGetCurentSize(stack);
}

#pragma mark - 
#pragma mark Public Implementations

TKAStack *TKAStackCreateWithSize(size_t size) {
    assert (size != 0);
    
    TKAStack *stack = TKAObjectCreate(TKAStack);
    TKAStackSetSize(stack, size);
    
    return stack;
}

void __TKAStackDeallocate(TKAStack *stack) {
    TKAStackSetSize(stack, 0);
    
    __TKAObjectDeallocate(stack);
}

bool TKAStackIsEmpty(TKAStack *stack) {
    return 0 == stack->_currentSize;
}

bool TKAStackIsFull(TKAStack *stack) {
    return stack->_size == stack->_currentSize;
}

void TKAStackPushObject(TKAStack *stack, void *object) {
    assert( !TKAStackIsFull(stack) );
   
    void **head = TKAStackGetHead(stack);

    *head = object;
    stack->_currentSize = stack->_currentSize + sizeof(object);
}

TKAStackPopType TKAStackPopObject(TKAStack *stack) {
    assert( !TKAStackIsEmpty(stack));
    
    stack->_currentSize = stack->_currentSize - sizeof(*stack->_data);
    void **head = TKAStackGetHead(stack);
    TKAStackPopType result = (NULL != *head) ? TKAStackObjectPop : TKAStackNullPop;
    
    if (TKAStackObjectPop == result) {
        TKAObjectRelease(*head);
        *head = NULL;
    }
    
    return result;
}

TKAStackPopType TKAStackPopObjects(TKAStack *stack) {
    while (TKAStackObjectPop == TKAStackPopObject(stack)) {
        if (TKAStackIsEmpty(stack)) {
            return TKAStackObjectPop;
        }
    }
    
    return TKAStackNullPop;
}



