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
#include "TKAStack.h"
#include "TKAPropertySetter.h"

#pragma mark -
#pragma mark Private Declarations
static
const size_t TKAStackSize = 4096;

static
void *__TKAAutoreleasePull = NULL;

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
TKAStack  *TKAAutoreleasePoolGetObject(TKAAutoreleasePool *pool);

static
void TKAAutoreleasePoolDaflateIfNeeded(TKAAutoreleasePool *pool);

#pragma mark -
#pragma mark Public Implementations

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
    
    return __TKAAutoreleasePull;
}

void TKAAutoreleasePoolAddObject(TKAAutoreleasePool *pool, void *object) {
    if (NULL != pool) {
        TKALinkedList *list = TKAAutoreleasePoolGetList(pool);
        TKAStack *stack = TKAAutoreleasePoolGetObject(pool);
        
        if (NULL != list && (NULL == stack || TKAStackIsFull(stack))) {
            TKAStack *stack = TKAStackCreateWithSize(TKAStackSize);
            TKAAutoreleasePoolSetObject(pool, stack);
            TKAObjectRelease(stack);
            TKALinkedListAddObject(list, stack);
        }
        
        TKAStackPushObject(stack, object);
    }
}

void TKAAutoreleasePoolDrain(TKAAutoreleasePool *pool) {
    
}

#pragma mark -
#pragma mark Private Implementations

void TKAAutoreleasePoolDaflateIfNeeded(TKAAutoreleasePool *pool) {
    
}

void TKAAutoreleasePoolSet(TKAAutoreleasePool *pool) {
    __TKAAutoreleasePull = pool;
}

void *TKAAutoreleasePoolGet() {
    return __TKAAutoreleasePull;
}

void __TKAAutoreleasePoolDeallocate(TKAAutoreleasePool *pool) {
    if (NULL != pool) {
        TKAAutoreleasePoolSetList(pool, NULL);
        TKAAutoreleasePoolSetObject(pool, NULL);
    }
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

TKAStack  *TKAAutoreleasePoolGetObject(TKAAutoreleasePool *pool) {
    return (NULL != pool) ? pool->_stack : NULL;
}
