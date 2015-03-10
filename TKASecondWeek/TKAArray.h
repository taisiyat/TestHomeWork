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
#include "TKAHuman.h"
#include "TKAObject.h"

typedef struct TKAHuman TKAHuman;

struct TKAArray {
    TKAObject _object;
    
    uint16_t _length;
    TKAHuman **_child;
};
typedef struct TKAArray TKAArray;

extern
void TKAArraySetLength(TKAArray *array, uint16_t length);

extern
uint16_t TKAArrayGetLength(TKAArray *array);

extern
void TKAArrayAddChild(TKAArray *array, TKAHuman *child);

extern
void *TKAArrayGetChild(TKAArray *array);

extern
uint16_t TKAArrayGetChildCount(TKAArray *array);

extern
uint16_t TKAArrayGetIndexOfFirstNullChild(TKAArray *array);

extern
uint16_t TKAArrayGetIndexOfLastChild(TKAArray *array);

extern
uint16_t TKAArrayGetIndexOfChild(TKAArray *array, TKAHuman *child);

extern
TKAHuman *TKAArrayGetChildAtIndex(TKAArray *array, uint16_t index);

extern
void TKAArrayAddChildAtIndex(TKAArray *array, TKAHuman *data, uint16_t index);

extern
void TKAArrayRemoveChildAtIndex(TKAArray *array, uint16_t index);

extern
void TKAArrayRemoveChild(TKAArray *array, TKAHuman *child);

extern
void TKAArrayOutput(TKAArray *array);

extern
void TKAArrayRemoveAllChild(TKAArray *array);

extern
void __TKAArrayDeallocate(TKAArray *array);

#endif /* defined(__TKASecondWeek__TKAArray__) */

