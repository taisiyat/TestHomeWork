//
//  TKAArrayStruct.h
//  TKASecondWeek
//
//  Created by Taisiya on 21.02.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#ifndef __TKASecondWeek__TKAArrayStruct__
#define __TKASecondWeek__TKAArrayStruct__

#include <stdio.h>
#include <stdlib.h>
//#include "TKAHumanStruct.h"

typedef struct TKAHumanStruct TKAHumanStruct;

struct TKAArrayStruct {
    uint64_t _referenceCount;
    uint16_t _length;
    TKAHumanStruct **_child;
};

typedef struct TKAArrayStruct TKAArrayStruct;

extern
TKAArrayStruct *TKAArrayStructCreate();

extern
void TKAArrayStructRetain(TKAArrayStruct *array);

extern
void TKAArrayStructRelease(TKAArrayStruct *array);

extern
void TKAArrayStructSetLength(TKAArrayStruct *array, uint16_t length);

extern
uint16_t TKAArrayStructGetLength(TKAArrayStruct *array);

extern
void TKAArrayStructAddChild(TKAArrayStruct *array, TKAHumanStruct *child);

extern
void *TKAArrayStructGetChild(TKAArrayStruct *array);

extern
TKAHumanStruct *TKAArrayStructGetChildIndex(TKAArrayStruct *array, uint16_t index);
   
extern
void TKAArrayStructAddChildIndex(TKAArrayStruct *array, void *data, uint16_t index);

extern
void TKAArrayStructOutput(TKAArrayStruct *array); 

#endif /* defined(__TKASecondWeek__TKAArrayStruct__) */
