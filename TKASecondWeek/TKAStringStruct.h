//
//  TKAStringStruct.h
//  TKASecondWeek
//
//  Created by Taisiya on 21.02.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#ifndef __TKASecondWeek__TKAStringStruct__
#define __TKASecondWeek__TKAStringStruct__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TKAStringStruct {
    uint64_t _referenceCount;
    char *_data;
    uint64_t _length;
};
typedef struct TKAStringStruct TKAStringStruct;

extern
TKAStringStruct *TKAStringStructCreate();

extern
void TKAStringStructRetain(TKAStringStruct *string);

extern
void TKAStringStructRelease(TKAStringStruct *string);

extern
void TKAStringStructSetLength(TKAStringStruct *string, uint64_t length);

extern
uint64_t TKAStringStructGetLength(TKAStringStruct *string);

extern
char *TKAStringStructGetData(TKAStringStruct *string);

extern
void TKAStringStructCopyData(TKAStringStruct *string, char *data, uint64_t length);

extern
void TKAStringStructOutput(TKAStringStruct *string);

#endif /* defined(__TKASecondWeek__TKAStringStruct__) */
