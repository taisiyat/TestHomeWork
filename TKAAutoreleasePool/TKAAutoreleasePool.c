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
static
const size_t TKAAutoreleasingStackSize                   = 4096;

static
const uint8_t TKACountOfStackToDeflation    = 2;

static
void *__TKAAutoreleasePool = NULL;

static
void TKAAutoreleasePoolSet(TKAAutoreleasePool *pool);

static
void *TKAAutoreleasePoolGet();

static
void __TKAAutoreleasePoolDeallocate(TKAAutoreleasePool *pool);

static
void TKAAutoreleasePoolSetList(TKAAutoreleasePool *pool, TKALinkedList *list);

static
TKALinkedList *TKAAutoreleasePoolGetList(TKAAutoreleasePool *pool);

static
void TKAAutoreleasePoolSetObject(TKAAutoreleasePool *pool, void *oject);

static
TKAAutoreleasingStack  *TKAAutoreleasePoolGetObject(TKAAutoreleasePool *pool);

static
void TKAAutoreleasePoolDeflateIfNeeded(TKAAutoreleasePool *pool);

static
bool TKAAutoreleasePoolShouldDeflate(TKAAutoreleasePool *pool);

#pragma mark -
#pragma mark Public Implementations

void __TKAAutoreleasePoolDeallocate(TKAAutoreleasePool *pool) {
    if (NULL != pool) {
        TKAAutoreleasePoolSetList(pool, NULL);
        TKAAutoreleasePoolSetObject(pool, NULL);
        
        free(pool);
        TKAAutoreleasePoolSet(NULL);
    }
}

void *TKAAutoreleasePoolCreateWithListAndStack() {
    TKAAutoreleasePool *pool = TKAAutoreleasePoolGet();
    
    if (NULL == pool) {
        
        pool = calloc(1, sizeof(TKAAutoreleasePool));
        TKAAutoreleasePoolSet(pool);
    
        TKALinkedList *list = TKAObjectCreate(TKALinkedList);
        TKAAutoreleasePoolSetList(pool, list);
        TKAObjectRelease(list);
    }
    
    TKAAutoreleasePoolSetObject(pool, NULL);
    
    return __TKAAutoreleasePool;
}

void TKAAutoreleasePoolAddObject(TKAAutoreleasePool *pool, void *object) {
    if (NULL != pool) {
        TKALinkedList *list = TKAAutoreleasePoolGetList(pool);
        TKAAutoreleasingStack *stack = TKAAutoreleasePoolGetObject(pool);
        
        if (NULL != list && (NULL == stack || TKAAutoreleasingStackIsFull(stack))) {
            TKAAutoreleasingStack *stack = TKAAutoreleasingStackCreateWithSize(TKAAutoreleasingStackSize);
            TKAAutoreleasePoolSetObject(pool, stack);
            TKAObjectRelease(stack);
            TKALinkedListAddObject(list, stack);
        }
        
        TKAAutoreleasingStackPushObject(stack, object);
    }
}

void TKAAutoreleasePoolDrain(TKAAutoreleasePool *pool) {
    if (NULL == pool) {
        return;
    }
    
    TKALinkedList *list = TKAAutoreleasePoolGetList(pool);
    TKAAutoreleasingStack *stack = TKAAutoreleasePoolGetObject(pool);
    
    while (TKAAutoreleasingStackPopObject(stack) == TKAAutoreleasingStackObjectPop) {
        if (TKAAutoreleasingStackIsEmpty(stack)) {
            TKAAutoreleasePoolDeflateIfNeeded(pool);
            
            TKALinkedListEnumerator *enumerator = TKALinkedListEnumeratorCreateWithList(list);
            while (TKALinkedListEnumeratorIsValid(enumerator)
                   && stack != TKALinkedListEnumeratorNextObject(enumerator))
            {

            }
            
            stack = TKALinkedListEnumeratorNextObject(enumerator);
            TKAObjectRelease(enumerator);
            
            TKAAutoreleasePoolSetObject(pool, stack);
        }
    }
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
        TKAAutoreleasingStack *stack = TKAAutoreleasePoolGetObject(pool);

        if (stack != TKALinkedListGetFirstObject(list)
            && TKACountOfStackToDeflation <= TKALinkedListGetCount(list))
        {
            uint64_t stackCount = 0;
            TKAAutoreleasingStack *stackTemp = NULL;
            TKALinkedListEnumerator *enumerator = TKALinkedListEnumeratorCreateWithList(list);
            
            while (TKALinkedListEnumeratorIsValid(enumerator)) {
                stackTemp = TKALinkedListEnumeratorNextObject(enumerator);
                
                if (!TKAAutoreleasingStackIsEmpty(stackTemp) || stack == stackTemp) {
                    break;
                }
                
                stackCount++;
            }
            
            TKAObjectRelease(enumerator);
            
            assert(stack == stackTemp);
            
            return stackCount >= TKACountOfStackToDeflation;
    
        }
    }
    
    return false;
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

void TKAAutoreleasePoolSetObject(TKAAutoreleasePool *pool, void *object) {
    if (NULL != pool) {
        TKARetainSetter(&pool->_stack, object);
    }
}

TKAAutoreleasingStack  *TKAAutoreleasePoolGetObject(TKAAutoreleasePool *pool) {
    return (NULL != pool) ? pool->_stack : NULL;
}
