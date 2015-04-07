//
//  TKAAutoreleasePool.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 02.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef __TKAAutoreleasePool__TKAAutoreleasePool__
#define __TKAAutoreleasePool__TKAAutoreleasePool__

#include <stdio.h>

typedef struct TKALinkedList TKALinkedList;
typedef struct TKAAutoreleasingStack TKAAutoreleasingStack;

typedef struct TKAAutoreleasePool {
    TKALinkedList *_list;
    TKAAutoreleasingStack *_stack;
} TKAAutoreleasePool;

extern
void *TKAAutoreleasePoolNew();

extern
void TKAAutoreleasePoolAddObject(TKAAutoreleasePool *pool, void *object);

extern
void TKAAutoreleasePoolDrain(TKAAutoreleasePool *pool);

#endif /* defined(__TKAAutoreleasePool__TKAAutoreleasePool__) */
