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
uint16_t TKAArrayProposedLength(TKAArray *array);

static
void TKAArraySetChildAtIndex(TKAArray *array, TKAHuman *child, uint16_t index);

static
void TKAArrayRewriteObjectsIfNeed(TKAArray *array, uint16_t index);

#pragma mark -
#pragma mark Privat Implementations

uint16_t TKAArrayProposedLength(TKAArray *array){
    if (NULL == array) {
        return 0;
    }
    
    uint16_t childCount = TKAArrayGetChildCount(array);
    uint16_t currentLength = TKAArrayGetLength(array);
    
    if (childCount == currentLength) {
        return fmax((2 * currentLength), 1);
    }
    
    if (childCount <= (currentLength / 2)) {
        return (currentLength - currentLength /2);
    }
    
    return 0;
}

void TKAArrayResizeIfNeed(TKAArray *array) {
    if (NULL != array && 0 != TKAArrayProposedLength(array)) {
        uint16_t tempLength = TKAArrayProposedLength(array);
        TKAArraySetLength(array, tempLength);
    }
}

void TKAArrayRewriteObjectsIfNeed(TKAArray *array, uint16_t index) {
 //   if (TKAArrayGetChildCount(array) <= TKAArrayGetIndexOfLastChild(array)) {
//        uint16_t indexNull = TKAArrayGetIndexOfChild(array, NULL);
        for (uint16_t iter = index; iter < TKAArrayGetIndexOfLastChild(array); iter++) {
            array->_child[iter] = array->_child[iter+1];
        }
    array->_child[TKAArrayGetIndexOfLastChild(array)] = NULL;
//    }
}

#pragma mark -
#pragma mark Public Implementations

void __TKAArrayDeallocate(TKAArray *array) {
    TKAArrayRemoveAllChildren(array);
   
    __TKAObjectDeallocate(array);
}

void TKAArraySetChildAtIndex(TKAArray *array, TKAHuman *child, uint16_t index) {
    if (NULL == array && TKAArrayReturnError == index) {
        return;
    }
    
    if (array->_child[index] != child) {
        if (array->_child[index] != NULL) {
            TKAObjectRelease(array->_child[index]);
            array->_childCount--;
        }
        
        array->_child[index] = child;
        
        if (NULL != array->_child[index]) {
            TKAObjectRetain(child);
            array->_childCount++;
        }
    }
}

void TKAArraySetLength(TKAArray *array, uint16_t length) {
    if (array->_length > length) {
        for (uint16_t iter = array->_length-1; iter > length; iter--) {
              TKAArraySetChildAtIndex(array, NULL, iter);
        }
    }

    if (array->_length != length) {
        array->_child = realloc(array->_child, length * sizeof(*array->_child));
        assert(NULL != array->_child);
        
        if (array->_length < length) {
             memset(array->_child + array->_length, 0, (length - array->_length) * sizeof(*array->_child));        //tesst!!!
        }
            
        array->_length = length;
    }
}

uint16_t TKAArrayGetLength(TKAArray *array) {
    return (NULL == array) ? 0 : array->_length;
}

bool TKAArrayIsChild(TKAArray *array, TKAHuman *child) {
    for (uint16_t iter = 0; iter < TKAArrayGetLength(array); iter ++) {
        if (TKAArrayGetChildAtIndex(array, iter) == child) {
            return true;
        }
    }
    
    return false;
}

TKAHuman *TKAArrayGetChildAtIndex(TKAArray *array, uint16_t index) {
    if (NULL == array) {
        return NULL;
    }

    if (TKAArrayGetLength(array) > index && 0 <= index) {
        return array->_child[index];
    }
    
    return NULL;
}

uint16_t TKAArrayGetIndexOfChild(TKAArray *array, TKAHuman *child) {
    if (NULL == array) {
        return TKAArrayReturnError;
    }
    
    uint16_t tempChildIndex = TKAArrayReturnError;
    
    for (uint16_t iter = TKAArrayGetLength(array); iter > 0; iter--) {
        if (TKAArrayGetChildAtIndex(array, iter-1) == child) {
            tempChildIndex = iter-1;
        }
    }
    
    return tempChildIndex;
}

uint16_t TKAArrayGetChildCount(TKAArray *array) {
    return (NULL == array) ? TKAArrayReturnError : array->_childCount;
}
//
uint16_t TKAArrayGetIndexOfLastChild(TKAArray *array) {
    if (NULL == array) {
        return TKAArrayReturnError;
    }
    
    uint16_t tempChildIndex = 0;

    for (uint16_t iter = 0; iter < TKAArrayGetLength(array); iter ++) {
        if (TKAArrayGetChildAtIndex(array, iter) != NULL) {
            tempChildIndex = iter;
        }
    }
    
    return tempChildIndex;
}

void TKAArrayAddChild(TKAArray *array, TKAHuman *child) {
    if (NULL == array || TKAArrayIsChild(array, child)) {
        return;
    }
    
    TKAArrayResizeIfNeed(array);
    
    uint16_t indexOfFirstNull = TKAArrayGetIndexOfChild(array, NULL);
    TKAArraySetChildAtIndex(array, child, indexOfFirstNull);

}

void TKAArrayRemoveChild(TKAArray *array, TKAHuman *child) {
    if (NULL != array && NULL != child && TKAArrayIsChild(array, child)) {
        uint16_t indexOfChild = TKAArrayGetIndexOfChild(array, child);
        uint16_t indexOfLastChild = TKAArrayGetIndexOfLastChild(array);
        TKAArraySetChildAtIndex(array, NULL, indexOfChild);
        if (indexOfChild < indexOfLastChild) {
            TKAArrayRewriteObjectsIfNeed(array, indexOfChild);
        }
        TKAArrayResizeIfNeed(array);
    }
}

void TKAArrayRemoveAllChildren(TKAArray *array) {
    if (NULL == array) {
        return;
    }
    
    uint16_t indexOfLastChild = TKAArrayGetIndexOfLastChild(array);
//    uint16_t childCount = TKAArrayGetChildCount(array);
 
    for (uint16_t iter = indexOfLastChild+1; iter > 0; iter--) {
        TKAHuman *childAtIndex = TKAArrayGetChildAtIndex(array, iter-1);
        TKAArrayRemoveChild(array, childAtIndex);
    }
}

void TKAArrayOutput(TKAArray *array) {
    if (NULL == array) {
        return;
    }
    
    uint16_t indexOfLastChild = TKAArrayGetIndexOfLastChild(array);
//    uint16_t childCount = TKAArrayGetChildCount(array);

    for (uint16_t iter = 0; iter <= indexOfLastChild; iter++) {
        TKAHuman *childAtIndex = TKAArrayGetChildAtIndex(array, iter);
    
        if (NULL != childAtIndex) {
            TKAStringOutput(TKAHumanGet(name, childAtIndex));
            printf(" ");
      
        } else {
        
            printf(" __ ");
        }
    }
}

