//
//  TKAPropertySetter.c
//  TKAHuman
//
//  Created by Taisiya on 16.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAPropertySetter.h"

#pragma mark -
#pragma mark Public Implementations

void TKAPropertyRetainSet(void **humanField, void *human) {
    if (*humanField != human) {
        if (NULL != *humanField) {
            TKAObjectRelease(*humanField);
        }
 
        *humanField = human;
        
        if (NULL != *humanField) {
            TKAObjectRetain(human);
        }
    }
}

void TKAPropertyAssignSet(void **humanField, void *human) {
    if (*humanField != human) {
        *humanField = human;
    }
}