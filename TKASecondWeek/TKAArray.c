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

#pragma mark -
#pragma mark Privat Implementations

#pragma mark -
#pragma mark Public Implementations

void __TKAArrayDeallocate(TKAArray *array) {
    if (NULL != array->_child) {
        TKAArrayRemoveAllChild(array);
    }
   
    __TKAObjectDeallocate(array);
}

void TKAArraySetLength(TKAArray *array, uint16_t length) {
//    if (array->_length > length) {
//        for (uint16_t iter = array->_length-1; iter > length; iter--) {
//            TKAArrayRemoveChildAtIndex(array, iter);
//        }
//    }
//    
//    if (array->_length != length) {
//    //void *tempResult = NULL;
//      //  tempResult = realloc(array->_child, length * sizeof(*array->_child));
//        //  if (0 != tempResult) {
//        array->_child = realloc(array->_child, length * sizeof(*array->_child));
//       // }
//        if (array->_length < length) {
//            memset(array->_child + array->_length, 0, length - array->_length);
//        }
//        
//        array->_length = length;
//    }
 
    array->_child = realloc(array->_child, length * sizeof(*array->_child));
  
            if (array->_length < length) {
                memset(array->_child + array->_length, 0, length - array->_length);
            }

    array->_length = length;
}

uint16_t TKAArrayGetLength(TKAArray *array) {
    if (NULL == array) {
        return UINT16_MAX;
    }
    
    return array->_length;
}

// ?? dont used
void *TKAArrayGetArrayChild(TKAArray *array) {
    if (NULL == array) {
        return NULL;
    }
    
    return array->_child;
}

TKAHuman *TKAArrayGetChildAtIndex(TKAArray *array, uint16_t index) {
    if (NULL == array) {
        return NULL;
    }

    if (array->_length > index && 0 <= index) {
        return array->_child[index];
    }
    
    //void metod or assert or exit;
    return NULL;
}

uint16_t TKAArrayGetIndexOfChild(TKAArray *array, TKAHuman *child) {
    if (NULL == array) {
        return UINT16_MAX;
    }
    
    for (uint16_t iter = 0; iter < array->_length; iter ++) {
        if (array->_child[iter] == child) {
          
            return iter;
        }
    }

    return UINT16_MAX;
}

uint16_t TKAArrayGetChildCount(TKAArray *array) {
    if (NULL == array) {
        return UINT16_MAX;
    }
    
    uint16_t tempChildCount = 0;
    for (uint16_t iter = 0; iter < array->_length; iter ++) {
        if (array->_child[iter] != NULL) {
            tempChildCount ++;
        }
       
    }
    
    return tempChildCount;
}

uint16_t TKAArrayGetIndexOfLastChild(TKAArray *array) {
    if (NULL == array) {
        return UINT16_MAX;
    }
    
    uint16_t tempChildIndex = 0;
    for (uint16_t iter = 0; iter < array->_length; iter ++) {
        if (array->_child[iter] != NULL) {
            tempChildIndex = iter;
        }
        
    }
    
    return tempChildIndex;
}

uint16_t TKAArrayGetIndexOfFirstNullChild(TKAArray *array) {
    if (NULL == array) {
        return UINT16_MAX;
    }
    
    uint16_t tempChildIndex = UINT16_MAX;
    for (uint16_t iter = array->_length; iter > 0; iter--) {
        
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
    
    if (UINT16_MAX == TKAArrayGetIndexOfChild(array, child)) {
        uint16_t indexOfNull = TKAArrayGetIndexOfChild(array, NULL);
        if (NULL == TKAArrayGetChildAtIndex(array, indexOfNull)) {
            TKAArraySetChild(array, child, indexOfNull);
        }

    }
    
}

void TKAArrayAddChildAtIndex(TKAArray *array, TKAHuman *child, uint16_t index) {
    if (NULL == array) {
        return;
    }
    
    if (array->_length > index && 0 <= index) {
        if (NULL == TKAArrayGetChildAtIndex(array, index)) {
            TKAArraySetChild(array, child, index);
        }
    }

}

void TKAArrayRemoveChildAtIndex(TKAArray *array, uint16_t index) {
    if (NULL == array) {
        return;
    }
    
    if (array->_length > index && 0 <= index) {
        if (NULL != TKAArrayGetChildAtIndex(array, index)) {
             TKAArraySetChild(array, NULL, index);
        }
    }

}
    
void TKAArrayRemoveChild(TKAArray *array, TKAHuman *child) {
    if (NULL == array) {
        return;
    }
    
    if (NULL != child) {
        uint16_t index = TKAArrayGetIndexOfChild(array, child);
        TKAArraySetChild(array, NULL, index);
    }

}

void TKAArrayRemoveAllChild(TKAArray *array) {
    if (NULL == array) {
        return;
    }

    for (uint16_t iter = 0; iter < TKAArrayGetLength(array); iter++) {
        if (NULL != TKAArrayGetChildAtIndex(array, iter)) {
            TKAArraySetChild(array, NULL, iter);
        }
    }
    
}

void TKAArrayOutput(TKAArray *array) {
    if (NULL == array) {
        return;
    }
    
    for (uint16_t iter = 0; iter < array->_length; iter++) {

        if (NULL != TKAArrayGetChildAtIndex(array, iter)) {
            TKAStringOutput(TKAHumanGetName(TKAArrayGetChildAtIndex(array,iter)));
            printf(" ");
        } else {
            printf(" __ ");
        }
        
    }
}

