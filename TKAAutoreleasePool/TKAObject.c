//
//  TKAObject.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 10.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAObject.h"

#pragma mark -
#pragma mark Public Implementation

void *__TKAObjectCreate(size_t objectSize, TKADeallocateCallback deallocateCallback) {
    TKAObject *object = calloc(1, objectSize);
    object->_referenceCount = 1;
    object->_deallocateCallback = deallocateCallback;
    
    return object;
}

void *TKAObjectRatain(void *object) {
    if (NULL != object) {
        ((TKAObject *)object)->_referenceCount++;
    }
    
    return object;
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


uint64_t TKAObjectGetReferenceCount(void *object) {
    return (NULL == object) ? 0 : ((TKAObject *)object)->_referenceCount;
}

extern
void __TKAObjectDeallocate(void *object) {
    free(object);
}
