//
//  TKAStack.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef __TKAAutoreleasePool__TKAStack__
#define __TKAAutoreleasePool__TKAStack__

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "TKAObject.h"

typedef enum {
    TKAStackNullPop,
    TKAStackObjectPop,
} TKAStackPopType;

struct TKAStack {
    TKAObject _superObject;
    
    void **_data;
    size_t _curentSize;
    size_t _size;
};
typedef struct TKAStack TKAStack;

extern
TKAStack *TKAStackCreateWithSize(size_t size);

extern
void __TKAStackDeallocate(TKAStack *stack);

extern
void TKAStackPushObject(TKAStack *stack, void *object);

extern
TKAStackPopType TKAStackPopObject(TKAStack *stack);

extern
TKAStackPopType TKAStackPopObjects(TKAStack *stack);

extern
bool TKAStackIsEmpty(TKAStack *stack);

extern
bool TKAStackIsFull(TKAStack *stack);

#endif /* defined(__TKAAutoreleasePool__TKAStack__) */
