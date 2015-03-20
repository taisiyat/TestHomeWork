//
//  TKAArray.c
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAArray.h"
#include "TKAHuman.h"

#include "math.h"

#pragma mark -
#pragma mark Privat Declarations

const uint16_t TKAArrayReturnError = UINT16_MAX;

static
void TKAArraySetLength(TKAArray *array, uint16_t length);

static
uint16_t TKAArrayProposedLength(TKAArray *array);

static
void TKAArrayResizeIfNeeded(TKAArray *array);

static
void TKAArraySetObjectAtIndex(TKAArray *array, void *object , uint16_t index);

static
void TKAArrayReorderObjects(TKAArray *array, uint16_t index);

static
void TKAArrayChangeValueObjectCount(TKAArray *array, int8_t count);

#pragma mark -
#pragma mark Privat Implementations

uint16_t TKAArrayProposedLength(TKAArray *array){
    if (NULL == array) {
        return 0;
    }
    
    uint16_t objectCount = TKAArrayGetObjectCount(array);
    uint16_t currentLength = TKAArrayGetLength(array);
    
    if (objectCount == currentLength) {
        return fmax(2 * currentLength, 1);
    }
    
    if (objectCount <= (currentLength / 2)) {
        return (currentLength - currentLength / 2);
    }
    
    return currentLength;
}

void TKAArrayResizeIfNeeded(TKAArray *array) {
    if (NULL != array) {
        uint16_t newLength = TKAArrayProposedLength(array);

        TKAArraySetLength(array, newLength);
    }
}

void TKAArrayChangeValueObjectCount(TKAArray *array, int8_t count) {
    if (NULL != array && abs(count) == 1) {
        array->_objectCount += count;
    }
}

void TKAArrayReorderObjects(TKAArray *array, uint16_t index) {
    uint16_t objectCount = TKAArrayGetObjectCount(array);
    if (index < objectCount - 1) {
        for (uint16_t iter = index; iter < objectCount - 1; iter++) {
            array->_object[iter] = array->_object[iter + 1];
        }
    
        array->_object[objectCount - 1] = NULL;
    }
}

void TKAArraySetLength(TKAArray *array, uint16_t length) {
    if (NULL == array) {
        return;
    }
    
    if (array->_length > length) {
        for (uint16_t iter = array->_length - 1; iter > length; iter--) {
            TKAArraySetObjectAtIndex(array, NULL, iter);
        }
    }
    
    if (array->_length != length) {
        array->_object = realloc(array->_object, length * sizeof(*array->_object));
        assert(NULL != array->_object);
        
        if (array->_length < length) {
            memset(array->_object + array->_length, 0, (length - array->_length) * sizeof(*array->_object));
        }
        
        array->_length = length;
    }
}

#pragma mark -
#pragma mark Public Implementations

void __TKAArrayDeallocate(TKAArray *array) {
    TKAArrayRemoveAllObjects(array);
   
    __TKAObjectDeallocate(array);
}

void TKAArraySetObjectAtIndex(TKAArray *array, void *object , uint16_t index) {
    if (NULL != array && TKAArrayReturnError != index) {
        TKAPropertyRetainSet((void *)&array->_object[index], object);
    }
}

uint16_t TKAArrayGetLength(TKAArray *array) {
    return (NULL == array) ? 0 : array->_length;
}

bool TKAArrayContainsObject(TKAArray *array, void *object ) {
    return (NULL != array && TKAArrayReturnError != TKAArrayGetIndexOfObject(array, object));
//    for (uint16_t iter = 0; iter < TKAArrayGetLength(array); iter ++) {
//        if (TKAArrayGetObjectAtIndex(array, iter) == object) {
//            return true;
//        }
//    }
//    
//    return false;
}

void *TKAArrayGetObjectAtIndex(TKAArray *array, uint16_t index) {
    if (NULL != array && TKAArrayGetLength(array) > index && 0 <= index) {
        return array->_object[index];
    }
    
    return NULL;
}

uint16_t TKAArrayGetIndexOfObject(TKAArray *array, void *object ) {
    uint16_t childIndex = TKAArrayReturnError;
    
    if (NULL != array) {
        for (uint16_t iter = 0; iter <= TKAArrayGetObjectCount(array); iter++) {   ///early was length
            if (TKAArrayGetObjectAtIndex(array, iter) == object) {
                childIndex = iter;
            }
        }
//        for (uint16_t iter = TKAArrayGetObjectCount(array) + 1; iter > 0; iter--) {   ///early was length
//            if (TKAArrayGetObjectAtIndex(array, iter - 1) == object) {
//                childIndex = iter - 1;
//            }
//        }
    }
    
    return childIndex;
}

uint16_t TKAArrayGetObjectCount(TKAArray *array) {
    return (NULL == array) ? 0 : array->_objectCount;
}

void TKAArrayAddObject(TKAArray *array, void *object ) {
    if (NULL != array && !TKAArrayContainsObject(array, object)) {
        
        TKAArrayResizeIfNeeded(array);
    
        TKAArraySetObjectAtIndex(array,
                                 object,
                                 TKAArrayGetObjectCount(array));
//                                TKAArrayGetIndexOfObject(array, NULL));
        TKAArrayChangeValueObjectCount(array, 1);
    }
}

void TKAArrayRemoveObject(TKAArray *array, void *object ) {
    if (NULL != array && NULL != object && TKAArrayContainsObject(array, object)) {
        uint16_t index = TKAArrayGetIndexOfObject(array, object);
        
        TKAArraySetObjectAtIndex(array, NULL, index);
        
        TKAArrayChangeValueObjectCount(array, -1);
        
        TKAArrayReorderObjects(array, index);
        
        TKAArrayResizeIfNeeded(array);
    }
}

void TKAArrayRemoveAllObjects(TKAArray *array) {
    if (NULL != array) {
        uint16_t objectCount = TKAArrayGetObjectCount(array);

        for (uint16_t iter = objectCount; iter > 0; iter--) {
            TKAArrayRemoveObject(array,
                                TKAArrayGetObjectAtIndex(array, iter - 1));
        }
    }
}

void TKAArrayOutput(TKAArray *array) {
    if (NULL != array) {
        uint16_t objectCount = TKAArrayGetObjectCount(array);

        for (uint16_t iter = 0; iter < objectCount; iter++) {
            void *object  = TKAArrayGetObjectAtIndex(array, iter);
    
            if (NULL != object) {
                TKAStringOutput(TKAHumanGet(name, object));
                printf(" ");
      
            }
        }
    }
}
