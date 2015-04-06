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

typedef bool(*TKALinkedListComparisonFunction) (void *object, void *context);

typedef struct TKALinkedListContext {
    void *object;
    TKALinkedListNode *previousNode;
    TKALinkedListNode *currentNode;
} TKALinkedListContext;

#pragma mark -
#pragma mark Private Declarations

extern
TKALinkedListContext TKALinkedListGetContextForObject(TKALinkedList *list, void *object);

extern
TKALinkedListNode *TKALinkedListFindNodeForObject(TKALinkedList *list,
                                                 TKALinkedListComparisonFunction comparisonFunction,
                                                 void *context);

extern
bool TKALinkedListNodeContainsObject(void *node, void *contextTest);

extern
uint64_t TKALinkedListGetMutationCount(TKALinkedList *list);

extern
TKALinkedListNode *TKALinkedListGetRootNode(TKALinkedList *list);

extern
void TKALinkedListSetRootNode(TKALinkedList *list, TKALinkedListNode *node);

extern
void TKALinkedListMutate(TKALinkedList *list);

extern
void TKALinkedListAddValueToCount(TKALinkedList *list, int count);

extern
TKALinkedListNode *TKALinkedListGetNodeForObject(TKALinkedList *list, void *object);

#endif
