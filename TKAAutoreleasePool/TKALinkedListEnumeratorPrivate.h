//
//  Header.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 30.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef TKAAutoreleasePool_Header_h
#define TKAAutoreleasePool_Header_h

typedef struct TKALinkedListNode TKALinkedListNode;
typedef struct TKALinkedList TKALinkedList;
typedef struct TKALinkedListEnumerator TKALinkedListEnumerator;

extern
TKALinkedListNode *TKALinkedListEnumeratorGetNextNode(TKALinkedListEnumerator *enumerator);

extern
void TKALinkedListEnumeratorSetValid(TKALinkedListEnumerator *enumerator, bool valid);

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
void TKALinkedListEnumeratorCheckMutations(TKALinkedListEnumerator *enumerator);

#endif
