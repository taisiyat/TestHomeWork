//
//  TKAArray.c
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAArray.h"
#include "TKAHuman.h"

#pragma mark -
#pragma mark Privat Declarations

//static
const uint16_t TKAArrayReturnError = UINT16_MAX;

static
uint16_t TKAArrayNeedToChangeLength(TKAArray *array);

#pragma mark -
#pragma mark Privat Implementations

uint16_t TKAArrayNeedToChangeLength(TKAArray *array){
    if (NULL == array) {
        return TKAArrayReturnError;
    }
    
    uint16_t tempChildCount = TKAArrayGetChildCount(array); /// with index of last Child in Array
    uint16_t tempLength = TKAArrayGetLength(array);
    
    if (tempChildCount+1 >= tempLength) {
        return (tempLength + tempLength);
    }
    
    if (tempChildCount < (tempLength / 2 - 1)) {
        return (tempLength - tempLength /2);
    }
    
    return TKAArrayReturnError;
}

void TKAArrayChangeLength(TKAArray *array) {
    if (NULL == array) {
        return;
    }
    
    if (TKAArrayReturnError == TKAArrayNeedToChangeLength(array)) {
        return;
    
    } else {
        uint16_t tempLength = TKAArrayNeedToChangeLength(array);
        TKAArraySetLength(array, tempLength);
    }
}

#pragma mark -
#pragma mark Public Implementations

void __TKAArrayDeallocate(TKAArray *array) {
    if (NULL != array->_child) {
        TKAArrayRemoveAllChildren(array);
    }
   
    __TKAObjectDeallocate(array);
}

void TKAArraySetLength(TKAArray *array, uint16_t length) {
    if (array->_length > length) {
        for (uint16_t iter = array->_length-1; iter > length; iter--) {
            TKAArrayRemoveChildAtIndex(array, iter);
        }
    }

    void *tempResult = NULL;
    if (array->_length != length) {
        tempResult = realloc(array->_child, length * sizeof(*array->_child));
        assert(NULL != tempResult);
        array->_child = tempResult;
           
        if (array->_length < length) {
             memset(array->_child + array->_length, 0, length - array->_length);
        }
            
        array->_length = length;
    }
}

uint16_t TKAArrayGetLength(TKAArray *array) {
    return (NULL == array) ? TKAArrayReturnError : array->_length;
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
    
    for (uint16_t iter = 0; iter < TKAArrayGetLength(array); iter ++) {
        if (array->_child[iter] == child) {
          
            return iter;
        }
    }

    return TKAArrayReturnError;
}

void TKAArraySetChildCount(TKAArray *array, uint16_t count) {
    if (NULL == array) {
        return ;
    }
    
    array->_childCount = count;
}

uint16_t TKAArrayGetChildCount(TKAArray *array) {
    return (NULL == array) ? TKAArrayReturnError : array->_childCount;
}

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

uint16_t TKAArrayGetIndexOfFirstNullChild(TKAArray *array) {
    if (NULL == array) {
        return TKAArrayReturnError;
    }
    
    uint16_t tempChildIndex = UINT16_MAX;
  
    for (uint16_t iter = TKAArrayGetLength(array); iter > 0; iter--) {
        if (array->_child[iter-1] == NULL) {
            tempChildIndex = iter-1;
        }
    }
    
    return tempChildIndex;
}

void TKAArraySetChild(TKAArray *array, TKAHuman *child, uint16_t index) {
    if (NULL == array) {
        return;
    }
    
    if (array->_child[index] != child) {
        if (array->_child[index] != NULL) {
            TKAObjectRelease(array->_child[index]);
        }
        
        array->_child[index] = child;

        if (NULL != array->_child[index]) {
            TKAObjectRetain(child);
        }
    }
}

void TKAArrayAddChild(TKAArray *array, TKAHuman *child) {
    if (NULL == array) {
        return;
    }
    
    if (TKAArrayReturnError == TKAArrayGetIndexOfChild(array, child)) {
        uint16_t indexOfFirstNull = TKAArrayGetIndexOfChild(array, NULL);
        uint16_t tempChildCount = TKAArrayGetChildCount(array);
        TKAArraySetChild(array, child, indexOfFirstNull);
        TKAArraySetChildCount(array, tempChildCount+1);
    }
    
}
// used only in ArrayTest
void TKAArrayAddChildAtIndex(TKAArray *array, TKAHuman *child, uint16_t index) {
    if (NULL == array) {
        return;
    }
    
 //   TKAArrayChangeLength(array);
    if (TKAArrayGetLength(array) > index && 0 <= index) {
        if (TKAArrayReturnError == TKAArrayGetIndexOfChild(array, child)) {
            if (NULL == TKAArrayGetChildAtIndex(array, index)) {
                TKAArraySetChild(array, child, index);
                uint16_t tempChildCount = TKAArrayGetChildCount(array);
                TKAArraySetChildCount(array, tempChildCount+1);
                
            }
        }
    }
}
// used only in ArrayTest and in SetLength
void TKAArrayRemoveChildAtIndex(TKAArray *array, uint16_t index) {
    if (NULL == array) {
        return;
    }

    if (TKAArrayGetLength(array) > index && 0 <= index) {
        if (NULL != TKAArrayGetChildAtIndex(array, index)) {
            TKAArraySetChild(array, NULL, index);
            uint16_t tempChildCount = TKAArrayGetChildCount(array);
            TKAArraySetChildCount(array, tempChildCount-1);
        }
    }
//    TKAArrayChangeLength(array);
}
    
void TKAArrayRemoveChild(TKAArray *array, TKAHuman *child) {
    if (NULL == array) {
        return;
    }
    
    if (NULL != child) {
        uint16_t indexOfChild = TKAArrayGetIndexOfChild(array, child);
        
        if (TKAArrayReturnError != indexOfChild) {
            TKAArraySetChild(array, NULL, indexOfChild);
            uint16_t tempChildCount = TKAArrayGetChildCount(array);
            TKAArraySetChildCount(array, tempChildCount-1);
        }
    }
}

void TKAArrayRemoveAllChildren(TKAArray *array) {
    if (NULL == array) {
        return;
    }
    
    uint16_t tempIndexOfLastChild = TKAArrayGetIndexOfLastChild(array);
    for (uint16_t iter = 0; iter <= tempIndexOfLastChild; iter++) {
        if (NULL != TKAArrayGetChildAtIndex(array, iter)) {
            TKAArraySetChild(array, NULL, iter);
            uint16_t tempChildCount = TKAArrayGetChildCount(array);
            TKAArraySetChildCount(array, tempChildCount-1);
        }
    }
}

void TKAArrayOutput(TKAArray *array) {
    if (NULL == array) {
        return;
    }
    
    uint16_t tempIndexOfLastChild = TKAArrayGetIndexOfLastChild(array);
    for (uint16_t iter = 0; iter <= tempIndexOfLastChild; iter++) {
        if (NULL != TKAArrayGetChildAtIndex(array, iter)) {
            TKAStringOutput(TKAHumanGetName(TKAArrayGetChildAtIndex(array,iter)));
            printf(" ");
      
        } else {
        
            printf(" __ ");
        }
    }
}

