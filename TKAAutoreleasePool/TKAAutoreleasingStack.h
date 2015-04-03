//
//  TKAAutoreleasingStack.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef __TKAAutoreleasePool__TKAAutoreleasingStack__
#define __TKAAutoreleasePool__TKAAutoreleasingStack__

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "TKAObject.h"

typedef enum {
    TKAAutoreleasingStackNullPop,
    TKAAutoreleasingStackObjectPop,
} TKAAutoreleasingStackPopType;

struct TKAAutoreleasingStack {
    TKAObject _superObject;
    
    void **_data;
    size_t _currentSize;
    size_t _size;
};
typedef struct TKAAutoreleasingStack TKAAutoreleasingStack;

extern
TKAAutoreleasingStack *TKAAutoreleasingStackCreateWithSize(size_t size);

extern
void __TKAAutoreleasingStackDeallocate(TKAAutoreleasingStack *stack);

extern
void TKAAutoreleasingStackPushObject(TKAAutoreleasingStack *stack, void *object);

extern
TKAAutoreleasingStackPopType TKAAutoreleasingStackPopObject(TKAAutoreleasingStack *stack);

extern
TKAAutoreleasingStackPopType TKAAutoreleasingStackPopObjects(TKAAutoreleasingStack *stack);

extern
bool TKAAutoreleasingStackIsEmpty(TKAAutoreleasingStack *stack);

extern
bool TKAAutoreleasingStackIsFull(TKAAutoreleasingStack *stack);

#endif /* defined(__TKAAutoreleasePool__TKAAutoreleasingStack__) */
