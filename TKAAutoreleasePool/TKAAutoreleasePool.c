//
//  TKAAutoreleasePool.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 02.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAAutoreleasePool.h"
#include "TKALinkedList.h"
#include "TKALinkedListEnumerator.h"
#include "TKAAutoreleasingStack.h"
#include "TKAPropertySetter.h"

#pragma mark -
#pragma mark Private Declarations

static const size_t TKAAutoreleasingStackSize      = 32;

static const uint8_t TKACountOfStackToDeflation    = 2;

static
void *__TKAAutoreleasePool = NULL;

static
void TKAAutoreleasePoolSet(TKAAutoreleasePool *pool);

static
void TKAAutoreleasePoolSetList(TKAAutoreleasePool *pool, TKALinkedList *list);

static
TKALinkedList *TKAAutoreleasePoolGetList(TKAAutoreleasePool *pool);

static
void TKAAutoreleasePoolSetStack(TKAAutoreleasePool *pool, void *oject);

static
TKAAutoreleasingStack  *TKAAutoreleasePoolGetStack(TKAAutoreleasePool *pool);

static
void TKAAutoreleasePoolDeflateIfNeeded(TKAAutoreleasePool *pool);

static
bool TKAAutoreleasePoolShouldDeflate(TKAAutoreleasePool *pool);

static
void TKAAutoreleasePoolInsertObject(TKAAutoreleasePool *pool, void *object);

static
void TKAAutoreleasePoolValidate(TKAAutoreleasePool *pool);

#pragma mark -
#pragma mark Public Implementations

void __TKAAutoreleasePoolDeallocate(TKAAutoreleasePool *pool) {
    if (NULL != pool) {
        TKAAutoreleasePoolSetList(pool, NULL);
        TKAAutoreleasePoolSetStack(pool, NULL);
        
        free(pool);
        TKAAutoreleasePoolSet(NULL);
    }
}

void *TKAAutoreleasePoolNew() {
    TKAAutoreleasePool *pool = TKAAutoreleasePoolGet();
    
    if (NULL == pool) {
        
        pool = calloc(1, sizeof(TKAAutoreleasePool));
        TKAAutoreleasePoolSet(pool);
    
        TKALinkedList *list = TKAObjectCreate(TKALinkedList);
        TKAAutoreleasePoolSetList(pool, list);
        TKAObjectRelease(list);
    }
    
    TKAAutoreleasePoolInsertObject(pool, NULL);
    
    return pool;
}

void TKAAutoreleasePoolAddObject(TKAAutoreleasePool *pool, void *object) {
    if (NULL != pool && NULL != object) {
        TKAAutoreleasePoolValidate(pool);
        TKAAutoreleasePoolInsertObject(pool, object);
    }
}

void TKAAutoreleasePoolDrain(TKAAutoreleasePool *pool) {
    if (NULL == pool) {
        return;
    }
    
    TKALinkedList *list = TKAAutoreleasePoolGetList(pool);
    TKAAutoreleasingStack *stack = TKAAutoreleasePoolGetStack(pool);
    TKAAutoreleasingStackPopType popType;
    
    do {
        popType = TKAAutoreleasingStackPopObjects(stack);
        if (TKAAutoreleasingStackIsEmpty(stack)) {
            TKAAutoreleasePoolDeflateIfNeeded(pool);
            TKALinkedListEnumerator *enumerator = TKALinkedListEnumeratorCreateWithList(list);
            while (TKALinkedListEnumeratorIsValid(enumerator)
                   && stack != TKALinkedListEnumeratorNextObject(enumerator))
            {
            }
            stack = TKALinkedListEnumeratorNextObject(enumerator);
            TKAObjectRelease(enumerator);
            TKAAutoreleasePoolSetStack(pool, stack);
        }
    } while (TKAAutoreleasingStackObjectPop == popType);
}

#pragma mark -
#pragma mark Private Implementations

void TKAAutoreleasePoolDeflateIfNeeded(TKAAutoreleasePool *pool) {
    if (NULL != pool && TKAAutoreleasePoolShouldDeflate(pool)) {
        TKALinkedListRemoveFirstObject(TKAAutoreleasePoolGetList(pool));
    }
}

bool TKAAutoreleasePoolShouldDeflate(TKAAutoreleasePool *pool) {
    if (NULL != pool) {
        TKALinkedList *list = TKAAutoreleasePoolGetList(pool);
        TKAAutoreleasingStack *stack = TKAAutoreleasePoolGetStack(pool);
        
        if (stack != TKALinkedListGetFirstObject(list)
            && TKALinkedListGetCount(list) >= TKACountOfStackToDeflation) {
            
            uint64_t stackCount = 0;
            TKAAutoreleasingStack *stackTemp = NULL;
            TKALinkedListEnumerator *enumerator = TKALinkedListEnumeratorCreateWithList(list);
            
            while (TKALinkedListEnumeratorIsValid(enumerator)
               && (stackTemp = TKALinkedListEnumeratorNextObject(enumerator))) {
                if (TKAAutoreleasingStackIsEmpty(stackTemp) && stackTemp != stack) {
                    stackCount++;
                }
            }
            
            TKAObjectRelease(enumerator);
        
            return stackCount >= TKACountOfStackToDeflation;
        }
    }
    
    return false;
}

void TKAAutoreleasePoolValidate(TKAAutoreleasePool *pool) {
    if (NULL != pool) {
        TKALinkedList *list = TKAAutoreleasePoolGetList(pool);
        TKAAutoreleasingStack *stack = NULL;
        TKALinkedListEnumerator *enumerator = TKALinkedListEnumeratorCreateWithList(list);
        
        while ((stack = TKALinkedListEnumeratorNextObject(enumerator))) {
            if (!TKALinkedListEnumeratorIsValid(enumerator)) {
                assert(!TKAAutoreleasingStackIsEmpty(stack));
            }
        }
        TKAObjectRelease(enumerator);
    }
}

void TKAAutoreleasePoolInsertObject(TKAAutoreleasePool *pool, void *object) {
    if (NULL != pool) {
        TKALinkedList *list = TKAAutoreleasePoolGetList(pool);
        TKAAutoreleasingStack *currentStack = TKAAutoreleasePoolGetStack(pool);
        
        if (NULL !=list && (NULL == currentStack || TKAAutoreleasingStackIsFull(currentStack))) {
            TKAAutoreleasingStack *stack = TKAAutoreleasingStackCreateWithSize(TKAAutoreleasingStackSize);
            TKAAutoreleasePoolSetStack(pool, stack);
            TKAObjectRelease(stack);
            TKALinkedListAddObject(list, stack);
            currentStack = stack;
        }
        
        TKAAutoreleasingStackPushObject(currentStack, object);
    }
}

void TKAAutoreleasePoolSet(TKAAutoreleasePool *pool) {
    __TKAAutoreleasePool = pool;
}

void *TKAAutoreleasePoolGet() {
    return __TKAAutoreleasePool;
}

void TKAAutoreleasePoolSetList(TKAAutoreleasePool *pool, TKALinkedList *list) {
    if (NULL != pool) {
        TKARetainSetter(&pool->_list, list);
    }
}

TKALinkedList *TKAAutoreleasePoolGetList(TKAAutoreleasePool *pool) {
    return (NULL != pool) ? pool->_list : NULL;
}

void TKAAutoreleasePoolSetStack(TKAAutoreleasePool *pool, void *object) {
    if (NULL != pool) {
        TKARetainSetter(&pool->_stack, object);
    }
}

TKAAutoreleasingStack  *TKAAutoreleasePoolGetStack(TKAAutoreleasePool *pool) {
    return (NULL != pool) ? pool->_stack : NULL;
}
