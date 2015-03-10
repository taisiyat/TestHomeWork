//
//  TKAObject.h
//  TKASecondWeek
//
//  Created by Taisiya on 19.02.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#ifndef __TKASecondWeek__TKAObgect__
#define __TKASecondWeek__TKAObgect__

#include <stdio.h>
#include <stdlib.h>

typedef void(*TKADeallocateCallback)(void *);

struct TKAObject {
    uint64_t _referenceCount;
    TKADeallocateCallback _deallocateCallback;
};
typedef struct TKAObject TKAObject;

extern
void *__TKAObjectCreate(size_t objectSize, TKADeallocateCallback deallocateCallback);

#define TKAObjectCreate(type)\
    __TKAObjectCreate(sizeof(type), (TKADeallocateCallback)__##type##Deallocate)

extern
void *TKAObjectRetain(void *object);

extern
void TKAObjectRelease(void *object);

extern
uint64_t TKAObjectGetReferenceCount(void *object);

extern
void __TKAObjectDeallocate(void *object);

#endif /* defined(__TKASecondWeek__TKAObject__) */
