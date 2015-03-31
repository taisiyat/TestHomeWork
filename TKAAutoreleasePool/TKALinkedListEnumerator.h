//
//  TKALinkedListEnumerator.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef __TKAAutoreleasePool__TKALinkedListEnumerator__
#define __TKAAutoreleasePool__TKALinkedListEnumerator__

#include <stdio.h>

#include "TKAObject.h"
#include "TKAPropertySetter.h"
#include "TKALinkedListNode.h"
#include "TKALinkedList.h"

typedef struct TKALinkedList TKALinkedList;

typedef struct TKALinkedListEnumerator {
    TKAObject _superObject;
    
    TKALinkedList *_list;
    TKALinkedListNode *_node;
    
    uint64_t _mutationCount;
    bool _isValid;
    
} TKALinkedListEnumerator;

extern
TKALinkedListEnumerator *TKALinkedLisEnumeratorCreateWithList(TKALinkedList *list);

extern
TKALinkedListNode *TKALinkedListEnumeratorNextNode(TKALinkedListEnumerator *enumerator);

extern
void __TKALinkedListEnumeratorDeallocate(TKALinkedListEnumerator *enumerator);

extern
bool TKALinkedListEnumeratorIsValid(TKALinkedListEnumerator *enumerator);

extern
void TKALinkedListEnumeratorSetValid(TKALinkedListEnumerator *enumerator);

extern
void TKALinkedListEnumeratorSetList(TKALinkedListEnumerator *enumerator, TKALinkedList *list);

extern
TKALinkedList *TKALinkedListEnumeratorGetList(TKALinkedListEnumerator *enumerator);

extern
void TKALinkedListEnumeratorSetNode(TKALinkedListEnumerator *enumerator, TKALinkedListNode *node);

extern
TKALinkedListNode *TKALinkedListEnumeratorGetNode(TKALinkedListEnumerator *enumerator);

extern
void TKALinkedListEnumeratorSetMutationCount(TKALinkedListEnumerator *enumerator);

extern
uint64_t TKALinkedListEnumeratorGetMutationCount(TKALinkedListEnumerator *enumerator);

extern
void *TKALinkedListEnumeratorGetNextObject(TKALinkedListEnumerator *enumerator);


#endif /* defined(__TKAAutoreleasePool__TKALinkedListEnumerator__) */
