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
void TKAArraySetObjectAtIndex(TKAArray *array, TKAHuman *child, uint16_t index);

static
void TKAArrayReorderObjects(TKAArray *array, uint16_t index);

static
void TKAArrayChangeObjectCount(TKAArray *array, int8_t count);

#pragma mark -
#pragma mark Privat Implementations

uint16_t TKAArrayProposedLength(TKAArray *array){
    if (NULL == array) {
        return 0;
    }
    
    uint16_t childCount = TKAArrayGetObjectCount(array);
    uint16_t currentLength = TKAArrayGetLength(array);
    
    if (childCount == currentLength) {
        return fmax(2 * currentLength, 1);
    }
    
    if (childCount <= (currentLength / 2)) {
        return (currentLength - currentLength / 2);
    }
    
    return 0;
}

void TKAArrayResizeIfNeeded(TKAArray *array) {
    if (NULL != array) {
        uint16_t newLength = TKAArrayProposedLength(array);
        if (0 != newLength) {
            TKAArraySetLength(array, newLength);
        }
    }
}

void TKAArrayChangeObjectCount(TKAArray *array, int8_t count) {
    if (NULL != array && (abs(count) == 1 || TKAArrayGetObjectCount(array) >= abs(count))) {
        array->_childCount += count;
    }
}

void TKAArrayReorderObjects(TKAArray *array, uint16_t index) {
    uint16_t childCount = TKAArrayGetObjectCount(array);
    if (index < childCount - 1) {
        for (uint16_t iter = index; iter < childCount - 1; iter++) {
            array->_child[iter] = array->_child[iter + 1];
        }
    
        array->_child[childCount - 1] = NULL;
    }
}

void TKAArraySetLength(TKAArray *array, uint16_t length) {
    if (array->_length > length) {
        for (uint16_t iter = array->_length - 1; iter > length; iter--) {
            TKAArraySetObjectAtIndex(array, NULL, iter);
        }
    }
    
    if (array->_length != length) {
        array->_child = realloc(array->_child, length * sizeof(*array->_child));
        assert(NULL != array->_child);
        
        if (array->_length < length) {
            memset(array->_child + array->_length, 0, (length - array->_length) * sizeof(*array->_child));
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

void TKAArraySetObjectAtIndex(TKAArray *array, TKAHuman *child, uint16_t index) {
    if (NULL != array && TKAArrayReturnError != index) {
        TKAPropertyRetainSet((void *)&array->_child[index], child);
    }
}

uint16_t TKAArrayGetLength(TKAArray *array) {
    return (NULL == array) ? 0 : array->_length;
}

bool TKAArrayContainsObject(TKAArray *array, TKAHuman *child) {
    for (uint16_t iter = 0; iter < TKAArrayGetLength(array); iter ++) {
        if (TKAArrayGetObjectAtIndex(array, iter) == child) {
            return true;
        }
    }
    
    return false;
}

TKAHuman *TKAArrayGetObjectAtIndex(TKAArray *array, uint16_t index) {
    if (NULL != array && TKAArrayGetLength(array) > index && 0 <= index) {
        return array->_child[index];
    }
    
    return NULL;
}

uint16_t TKAArrayGetIndexOfObject(TKAArray *array, TKAHuman *child) {
    uint16_t childIndex = TKAArrayReturnError;
    
    if (NULL != array) {
        for (uint16_t iter = TKAArrayGetObjectCount(array) + 1; iter > 0; iter--) {   ///early was length
            if (TKAArrayGetObjectAtIndex(array, iter - 1) == child) {
                childIndex = iter - 1;
            }
        }
    }
    
    return childIndex;
}

uint16_t TKAArrayGetObjectCount(TKAArray *array) {
    return (NULL == array) ? 0 : array->_childCount;
}

void TKAArrayAddObject(TKAArray *array, TKAHuman *child) {
    if (NULL != array && !TKAArrayContainsObject(array, child)) {
        
        TKAArrayResizeIfNeeded(array);
    
        TKAArraySetObjectAtIndex(array,
                                child,
                                TKAArrayGetIndexOfObject(array, NULL));
        TKAArrayChangeObjectCount(array, 1);
    }
}

void TKAArrayRemoveObject(TKAArray *array, TKAHuman *child) {
    if (NULL != array && NULL != child && TKAArrayContainsObject(array, child)) {
        uint16_t index = TKAArrayGetIndexOfObject(array, child);
        
        TKAArraySetObjectAtIndex(array, NULL, index);
        
        TKAArrayChangeObjectCount(array, -1);
        
        TKAArrayReorderObjects(array, index);
        
        TKAArrayResizeIfNeeded(array);
    }
}

void TKAArrayRemoveAllObjects(TKAArray *array) {
    if (NULL != array) {
        uint16_t childCount = TKAArrayGetObjectCount(array);

        for (uint16_t iter = childCount; iter > 0; iter--) {
            TKAArrayRemoveObject(array,
                                TKAArrayGetObjectAtIndex(array, iter - 1));
        }
    }
}

void TKAArrayOutput(TKAArray *array) {
    if (NULL != array) {
        uint16_t childCount = TKAArrayGetObjectCount(array);

        for (uint16_t iter = 0; iter < childCount; iter++) {
            TKAHuman *child = TKAArrayGetObjectAtIndex(array, iter);
    
            if (NULL != child) {
                TKAStringOutput(TKAHumanGet(name, child));
                printf(" ");
      
            }
        }
    }
}
