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
#include <stdbool.h>

#include "TKAObject.h"

typedef struct TKALinkedListNode TKALinkedListNode;
typedef struct TKALinkedList TKALinkedList;

typedef struct TKALinkedListEnumerator {
    TKAObject _superObject;
    
    TKALinkedList *_list;
    TKALinkedListNode *_node;
    
    uint64_t _mutationCount;
    bool _isValid;
    
} TKALinkedListEnumerator;

extern
TKALinkedListEnumerator *TKALinkedListEnumeratorCreateWithList(TKALinkedList *list);

extern
void __TKALinkedListEnumeratorDeallocate(TKALinkedListEnumerator *enumerator);

extern
TKALinkedListNode *TKALinkedListEnumeratorNextNode(TKALinkedListEnumerator *enumerator);

extern
void *TKALinkedListEnumeratorNextObject(TKALinkedListEnumerator *enumerator);

extern
bool TKALinkedListEnumeratorIsValid(TKALinkedListEnumerator *enumerator);

#endif /* defined(__TKAAutoreleasePool__TKALinkedListEnumerator__) */
