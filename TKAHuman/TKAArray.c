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
void TKAArraySetChild(TKAArray *array, TKAHuman *child, uint16_t index);

#pragma mark -
#pragma mark Privat Implementations

uint16_t TKAArrayProposedLength(TKAArray *array){
    if (NULL == array) {
        return 0;
    }
    
    uint16_t childCount = TKAArrayGetChildCount(array);
    uint16_t currentLength = TKAArrayGetLength(array);
    uint16_t indexOfLastChild = TKAArrayGetIndexOfLastChild(array);
    
    if (childCount == currentLength) {
        return fmax((2*currentLength), 1);
    }
    
    if (indexOfLastChild < (currentLength - currentLength /2) &&  childCount <= (currentLength / 2)) {
        //equal lastChild ? revrite child
        return (currentLength - currentLength /2);
    }
    
    return 0;
}

void TKAArrayCheckOfLength(TKAArray *array) {
    if (NULL != array && 0 != TKAArrayProposedLength(array)) {
        uint16_t tempLength = TKAArrayProposedLength(array);
        TKAArraySetLength(array, tempLength);
    }
}

#pragma mark -
#pragma mark Public Implementations

void __TKAArrayDeallocate(TKAArray *array) {
    TKAArrayRemoveAllChildren(array);
   
    __TKAObjectDeallocate(array);
}

void TKAArraySetChild(TKAArray *array, TKAHuman *child, uint16_t index) {
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
              TKAArraySetChild(array, NULL, iter);
        }
    }

    if (array->_length != length) {
        array->_child = realloc(array->_child, length * sizeof(*array->_child));
        assert(NULL != array->_child);
        
        if (array->_length < length) {
             memset(array->_child + array->_length, 0, length - array->_length);        //tesst!!!
        }
            
        array->_length = length;
    }
}

uint16_t TKAArrayGetLength(TKAArray *array) {
    return (NULL == array) ? 0 : array->_length;
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
        if (array->_child[iter-1] == child) {
            tempChildIndex = iter-1;
        }
    }
    
    return tempChildIndex;
}

uint16_t TKAArrayGetChildCount(TKAArray *array) {
    return (NULL == array) ? TKAArrayReturnError : array->_childCount;
}
// may dont ussed
uint16_t TKAArrayGetIndexOfLastChild(TKAArray *array) {
    if (NULL == array) {
        return TKAArrayReturnError;
    }
    
    uint16_t tempChildIndex = 0;

    for (uint16_t iter = 0; iter < TKAArrayGetLength(array); iter ++) {
        if (array->_child[iter] != NULL) {
            tempChildIndex = iter;
        }
    }
    
    return tempChildIndex;
}

void TKAArrayAddChild(TKAArray *array, TKAHuman *child) {
    if (NULL == array) {
        return;
    }
    
    uint16_t childCount = TKAArrayGetChildCount(array);
    if (0 == childCount) {
        TKAArrayCheckOfLength(array);
    }
    
    if (TKAArrayReturnError == TKAArrayGetIndexOfChild(array, child)) {
        uint16_t indexOfFirstNull = TKAArrayGetIndexOfChild(array, NULL);
        TKAArraySetChild(array, child, indexOfFirstNull);
        TKAArrayCheckOfLength(array);
    }
}

void TKAArrayRemoveOfChild(TKAArray *array, TKAHuman *child) {
    if (NULL != array && NULL != child) {
        uint16_t indexOfChild = TKAArrayGetIndexOfChild(array, child);
        
        if (TKAArrayReturnError != indexOfChild) {
            TKAArraySetChild(array, NULL, indexOfChild);
            TKAArrayCheckOfLength(array);
        }
    }
}

void TKAArrayRemoveAllChildren(TKAArray *array) {
    if (NULL == array) {
        return;
    }
    
    uint16_t indexOfLastChild = TKAArrayGetIndexOfLastChild(array);
//    uint16_t childCount = TKAArrayGetChildCount(array);
    
    for (uint16_t iter = 0; iter <= indexOfLastChild; iter++) {
        TKAHuman *childAtIndex = TKAArrayGetChildAtIndex(array, iter);

        if (NULL != childAtIndex) {
            TKAArrayRemoveOfChild(array, childAtIndex);
         }
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
            TKAStringOutput(TKAHumanGetName(childAtIndex));
            printf(" ");
      
        } else {
        
            printf(" __ ");
        }
    }
}

