//
//  TKAArrayStruct.c
//  TKASecondWeek
//
//  Created by Taisiya on 21.02.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAArrayStruct.h"
#include "TKAHumanStruct.h"

#pragma mark -
#pragma mark Privat Declarations

static
void TKAArrayStructDealloc(TKAArrayStruct *array);

#pragma mark -
#pragma mark Privat Implementations

void TKAArrayStructDealloc(TKAArrayStruct *array) {
    if (NULL != array->_child) {

        for (uint16_t iter = 0; iter < array->_length; iter++) {
            TKAArrayStructAddChildIndex(array, NULL, iter);
//            if (NULL != array->_child[iter]) {
//                TKAHumanStructRelease(array->_child[iter]);
//            }
       
        }
    }
    free(array);
}

#pragma mark -
#pragma mark Public Implementations

TKAArrayStruct *TKAArrayStructCreate() {
    TKAArrayStruct *array = calloc(1, sizeof(*array));
    array->_referenceCount = 1;
    
    return array;
}

void TKAArrayStructRetain(TKAArrayStruct *array) {
    array->_referenceCount++;
}

void TKAArrayStructRelease(TKAArrayStruct *array) {
    array->_referenceCount--;
    
    if (0 == array->_referenceCount) {
        TKAArrayStructDealloc(array);
    }
    
}

void TKAArrayStructSetLength(TKAArrayStruct *array, uint16_t length) {
    if (array->_length != length) {
        array->_child = realloc(array->_child, length * sizeof(*array->_child));
        
        if (array->_length < length) {
            memset(array->_child + array->_length, 0, length - array->_length);
        }
        
        array->_length = length;
    }
}

uint16_t TKAArrayStructGetLength(TKAArrayStruct *array) {
    
    return array->_length;
}

void TKAArrayStructAddChild(TKAArrayStruct *array, TKAHumanStruct *child) {
    bool addFlag = false;

    for (uint16_t iter = 0; iter < array->_length; iter ++) {
        if (array->_child[iter] != child) {
            if (array->_child[iter] == NULL) {
                
                array->_child[iter] = child;
                if (NULL != array->_child[iter]) {
                    TKAHumanStructRetain(child);
                }
                
                addFlag = true;
            }
        }
    }
    
    if (false == addFlag) {
        uint16_t shortLength = TKAArrayStructGetLength(array);
        TKAArrayStructSetLength(array, shortLength + 1);
        
        array->_child[array->_length -1] = child;
        if (NULL != array->_child[array->_length - 1]) {
            TKAHumanStructRetain(child);
        }
        
        addFlag=true;
    }
}

void *TKAArrayStructGetArrayOfChild(TKAArrayStruct *array) {
    
    return array->_child;
}

TKAHumanStruct *TKAArrayStructGetChildIndex(TKAArrayStruct *array, uint16_t index) {
    
    if (array->_length > index) {
       
        return array->_child[index];
    }
    //void metod or assert or exit;
    return NULL;
}

void TKAArrayStructAddChildIndex(TKAArrayStruct *array, void *child, uint16_t index) {
    if (array->_length <= index) {
        TKAArrayStructSetLength(array, index + 1);
    }
    
    if (array->_length > index) {
        if (array->_child[index] != child) {
         
            if (array->_child[index] != NULL) {
                TKAHumanStructRelease(array->_child[index]);
            }
            
            array->_child[index] = child;
            if (NULL != array->_child[index]) {
                TKAHumanStructRetain(child);
            }
            
        }
    }

}

void TKAArrayStructOutput(TKAArrayStruct *array) {
    
    for (uint16_t iter = 0; iter < array->_length; iter++) {
        
        if (array->_child[iter] != NULL) {
            TKAStringStructOutput(TKAHumanStructGetName(array->_child[iter]));
            printf(" ");
        }
        
    }
}
    
    


