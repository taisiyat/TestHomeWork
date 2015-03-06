//
//  TKAString.h
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#ifndef __TKASecondWeek__TKAString__
#define __TKASecondWeek__TKAString__

#include "TKAObject.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TKAString {
    TKAObject _object;
    
    char *_data;
    uint64_t _length;
};
typedef struct TKAString TKAString;

extern
void TKAStringSetLength(TKAString *string, uint64_t length);

extern
uint64_t TKAStringGetLength(TKAString *string);

extern
char *TKAStringGetData(TKAString *string);

extern
void TKAStringCopyData(TKAString *string, char *data, uint64_t length);

extern
void TKAStringOutput(TKAString *string);

extern
void __TKAStringDeallocate(TKAString *string);

#endif /* defined(__TKASecondWeek__TKAString__) */
