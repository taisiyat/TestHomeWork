//
//  TKAString.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 08.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef __TKAAutoreleasePool__TKAString__
#define __TKAAutoreleasePool__TKAString__

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
uint64_t TKAStringGetLength(TKAString *string);

extern
char *TKAStringGetData(TKAString *string);

extern
void TKAStringSetData(TKAString *string, char *data);

extern
void TKAStringOutput(TKAString *string);

extern
void __TKAStringDeallocate(TKAString *string);

#endif /* defined(__TKAAutoreleasePool__TKAString__) */

