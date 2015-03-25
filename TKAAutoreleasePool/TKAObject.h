//
//  TKAObject.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef __TKAAutoreleasePool__TKAObject__
#define __TKAAutoreleasePool__TKAObject__

#include <stdio.h>
#include <stdlib.h>

typedef void(*TKAObjectDeallocateCallback)(void *);

struct TKAObject {
    uint64_t _referenceCount;
    TKAObjectDeallocateCallback _deallocateCallback;
};
typedef struct TKAObject TKAObject;

extern
void *__TKAObjectCreate(size_t size, TKAObjectDeallocateCallback deallocateCallback);

#define TKAObjectCreate(type)\
        __TKAObjectCreate(sizeof(type), (TKAObjectDeallocateCallback)__##type##Deallocate)

extern
void __TKAObjectDeallocate(void *object);

extern
void *TKAObjectRetain(void *object);

extern
void TKAObjectRelease(void *object);

extern
uint64_t TKAObjectGetReferenceCount(void *object);

#endif /* defined(__TKAAutoreleasePool__TKAObject__) */
