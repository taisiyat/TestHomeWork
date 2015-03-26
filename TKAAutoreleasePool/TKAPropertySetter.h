//
//  TKAPropertySetter.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef __TKAAutoreleasePool__TKAPropertySetter__
#define __TKAAutoreleasePool__TKAPropertySetter__

#include <stdio.h>

#include "TKAObject.h"

extern
void TKARetainSetterWithObject(void *object, void **field, void *objectToSet);

extern
void TKAPropertyAssignSet(void **field, void *object);

extern
void TKAPropertyRetainSet(void **field, void *object);

#endif /* defined(__TKAAutoreleasePool__TKAPropertySetter__) */
