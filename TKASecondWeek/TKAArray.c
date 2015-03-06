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

const uint16_t uint16ReturnError  = 65535;

#pragma mark -
#pragma mark Privat Implementations

#pragma mark -
#pragma mark Public Implementations

void __TKAArrayDeallocate(TKAArray *array) {
    if (NULL != array->_child) {
//        for (uint16_t iter = 0; iter < array->_length; iter++) {
//            TKAArrayAddChildIndex(array, NULL, iter);
//        }
        TKAArrayRemoveAllChildren(array);
    }
   
    __TKAObjectDeallocate(array);
}

void TKAArraySetLength(TKAArray *array, uint16_t length) {
    if (array->_length > length) {
        for (uint16_t iter = array->_length-1; iter > length; iter--) {
            TKAArrayRemoveChildIndex(array, iter);
        }
    }
    
    if (array->_length != length) {
        array->_child = realloc(array->_child, length * sizeof(*array->_child));
        
        if (array->_length < length) {
            memset(array->_child + array->_length, 0, length - array->_length);
        }
        
        array->_length = length;
    }
}

uint16_t TKAArrayGetLength(TKAArray *array) {
    return array->_length;
}

void TKAArrayAddChild(TKAArray *array, TKAHuman *child) {
    bool addFlag = false;
    
    for (uint16_t iter = 0; iter < array->_length; iter ++) {
        if (array->_child[iter] != child) {
            if (array->_child[iter] == NULL) {
                TKAArrayAddChildIndex(array, child, iter);
         
                addFlag = true;
            }
        }
    }
    
    if (false == addFlag) {
        uint16_t shortLength = TKAArrayGetLength(array);
        TKAArraySetLength(array, shortLength + 1);
        TKAArrayAddChildIndex(array, child, shortLength);
        
        addFlag=true;
    }
    
//    return addFlag;
}


// ?? dont used
void *TKAArrayGetArrayChild(TKAArray *array) {
    return array->_child;
}

TKAHuman *TKAArrayGetChildIndex(TKAArray *array, uint16_t index) {
    
    if (array->_length > index) {
        return array->_child[index];
    }
    
    //void metod or assert or exit;
    return NULL;
}

void TKAArrayAddChildIndex(TKAArray *array, TKAHuman *child, uint16_t index) {
    bool addFlag = false;
    
    if (array->_length <= index) {
        TKAArraySetLength(array, index + 1);
    }
    
    if (array->_length > index) {
        if (array->_child[index] != child) {
            
            if (array->_child[index] != NULL) {
                TKAObjectRelease(array->_child[index]);
            }
            
            array->_child[index] = child;
            if (NULL != array->_child[index]) {
                TKAObjectRetain(child);
                addFlag = true;
            }
            
        }
    }
    
//    return addFlag;
}

void TKAArrayRemoveChildIndex(TKAArray *array, uint16_t index) {
    bool removeFlag = false;
    
    if (array->_length > index) {
        TKAArrayAddChildIndex(array, NULL, index);
        removeFlag = true;
    }
    
//    return removeFlag;
}

void TKAArrayRemoveChild(TKAArray *array, TKAHuman *child) {
    bool removeFlag = false;
    
    if (NULL != child) {
        
       for (uint16_t iter = 0; iter < TKAArrayGetLength(array); iter++) {
           if (array->_child[iter] == child) {
               TKAArrayAddChildIndex(array, NULL, iter);
               removeFlag = true;
           }
       }
        
    }
    
//    return removeFlag;
}

void TKAArrayRemoveAllChildren(TKAArray *array) {
    bool removeFlag = false;
    
    for (uint16_t iter = 0; iter < TKAArrayGetLength(array); iter++) {
        if (NULL != array->_child[iter]) {
           TKAArrayRemoveChildIndex(array, iter);
        }
    }
    //    return removeFlag;
}

void TKAArrayOutput(TKAArray *array) {
    
    for (uint16_t iter = 0; iter < array->_length; iter++) {
        
        if (array->_child[iter] != NULL) {
            TKAStringOutput(TKAHumanGetName(array->_child[iter]));
            printf(" ");
        }
        
    }
}

