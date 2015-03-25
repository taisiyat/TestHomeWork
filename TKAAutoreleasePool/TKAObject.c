//
//  TKAObject.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAObject.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

void *__TKAObjectCreate(size_t size, TKAObjectDeallocateCallback deallocateCallback) {
    TKAObject *object = calloc(1, size);
    object->_referenceCount = 1;
    object->_deallocateCallback = deallocateCallback;
    
    return object;
}

void __TKAObjectDeallocate(void *object) {
    if (NULL != object) {
        free(object);
    }
}

void *TKAObjectRetain(void *voidObject) {
    if (NULL != voidObject) {
        ((TKAObject *)voidObject)->_referenceCount++;
    }
    
    return voidObject;
}

void TKAObjectRelease(void *voidObject) {
    if (NULL == voidObject) {
        return;
    }
    
    TKAObject *object = (TKAObject *)voidObject;
    object->_referenceCount--;

    if (0 == object->_referenceCount) {
        object->_deallocateCallback(object);
    }
}

uint64_t TKAObjectGetReferenceCount(void *voidObject) {
    return (NULL != voidObject) ? ((TKAObject *)voidObject)->_referenceCount : 0;
}

#pragma mark -
#pragma mark Private Implementations
