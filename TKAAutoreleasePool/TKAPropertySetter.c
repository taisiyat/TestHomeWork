//
//  TKAPropertySetter.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKAPropertySetter.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

//void TKARetainSetterWithObject(void *object, void **field, void *objectToSet);

void TKAProprtyAssignSet(void **field, void *object) {
    if (*field != object) {
        *field = object;
    }
}

void TKAPropertyRetainSet(void **field, void *object) {
    if (*field != object) {
        if (NULL != object) {
            TKAObjectRetain(object);
        }
        
        if (NULL != *field) {
            TKAObjectRelease(*field);
        }
        
        *field = object;
    }
}

#pragma mark -
#pragma mark Private Implementations