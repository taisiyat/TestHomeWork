//
//  TKAArray.h
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#ifndef __TKASecondWeek__TKAArray__
#define __TKASecondWeek__TKAArray__

#include "TKAObject.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "TKAHuman.h"
#include "TKAObject.h"


extern
const uint16_t TKAArrayReturnError;

typedef struct TKAHuman TKAHuman;

struct TKAArray {
    TKAObject _superObject;
    
    TKAObject **_object;
    uint16_t _objectCount;
    uint16_t _length;
};
typedef struct TKAArray TKAArray;

extern
uint16_t TKAArrayGetLength(TKAArray *array);

extern
void TKAArrayAddObject(TKAArray *array, void *object );

extern
uint16_t TKAArrayGetObjectCount(TKAArray *array);

extern
uint16_t TKAArrayGetIndexOfObject(TKAArray *array, void *object );

extern
void *TKAArrayGetObjectAtIndex(TKAArray *array, uint16_t index);

extern
void TKAArrayRemoveObject(TKAArray *array, void *object );

extern
void TKAArrayRemoveAllObjects(TKAArray *array);

extern
void __TKAArrayDeallocate(TKAArray *array);

extern
void TKAArrayOutput(TKAArray *array);

#endif /* defined(__TKASecondWeek__TKAArray__) */

