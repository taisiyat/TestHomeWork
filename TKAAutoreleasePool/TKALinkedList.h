//
//  TKALinkedList.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef __TKAAutoreleasePool__TKALinkedList__
#define __TKAAutoreleasePool__TKALinkedList__

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "TKAObject.h"

typedef struct TKALinkedListNode TKALinkedListNode;
typedef struct TKALinkedListEnumerator TKALinkedListEnumerator;

typedef struct TKALinkedList {
    TKAObject _superObject;
    
    TKALinkedListNode *_rootNode;
    
    uint64_t _count;
    uint64_t _mutationCount;
    
} TKALinkedList;

extern
void __TKALinkedListDeallocate(TKALinkedList *list);

extern
void TKALinkedListAddObject(TKALinkedList *list, void *object);

extern
void TKALinkedListRemoveObject(TKALinkedList *list, void *object);

extern
void TKALinkedListRemoveAllObjects(TKALinkedList *list);

extern
void *TKALinkedListGetFirstObject(TKALinkedList *list);

extern
void TKALinkedListRemoveFirstObject(TKALinkedList *list);

extern
void TKALinkedListInsertBeforeObject(TKALinkedList *list, void *pointObject, void *insertedObject);

extern
void TKALinkedListInsertAfterObject(TKALinkedList *list, void *pointObject, void *insertedObject);

extern
uint64_t TKALinkedListGetCount(TKALinkedList *list);

extern
bool TKALinkedListContainsObject(TKALinkedList *list, void *object);
#endif /* defined(__TKAAutoreleasePool__TKALinkedList__) */
