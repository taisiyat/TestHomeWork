//
//  TKALinkedListEnumerator.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKALinkedListEnumerator.h"
//#include "TKALinkedListEnumeratorPrivate.h"
#include "TKALinkedList.h"
#include "TKALinkedListPrivate.h"
#include "TKALinkedListNode.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKALinkedListEnumeratorSetValid(TKALinkedListEnumerator *enumerator, bool valid);

static
void TKALinkedListEnumeratorSetList(TKALinkedListEnumerator *enumerator, TKALinkedList *list);

static
TKALinkedList *TKALinkedListEnumeratorGetList(TKALinkedListEnumerator *enumerator);

static
void TKALinkedListEnumeratorSetNode(TKALinkedListEnumerator *enumerator, TKALinkedListNode *node);

static
TKALinkedListNode *TKALinkedListEnumeratorGetNode(TKALinkedListEnumerator *enumerator);

static
void TKALinkedListEnumeratorSetMutationCount(TKALinkedListEnumerator *enumerator);

static
uint64_t TKALinkedListEnumeratorGetMutationCount(TKALinkedListEnumerator *enumerator);

static
void TKALinkedListEnumeratorCheckMutations(TKALinkedListEnumerator *enumerator);

#pragma mark -
#pragma mark Public Implementations

TKALinkedListEnumerator *TKALinkedListEnumeratorCreateWithList(TKALinkedList *list) {
    if (NULL == list) {
        return NULL;
    }
    
    TKALinkedListEnumerator *enumerator = TKAObjectCreate(TKALinkedListEnumerator);
    TKALinkedListEnumeratorSetList(enumerator, list);
    TKALinkedListEnumeratorSetMutationCount(enumerator);
    TKALinkedListEnumeratorSetValid(enumerator, true);
    
    return enumerator;
}

void __TKALinkedListEnumeratorDeallocate(TKALinkedListEnumerator *enumerator) {
    if (NULL == enumerator) {
        return;
    }
    
    TKALinkedListEnumeratorSetList(enumerator, NULL);
    TKALinkedListEnumeratorSetNode(enumerator, NULL);
    
    __TKAObjectDeallocate(enumerator);
}

void *TKALinkedListEnumeratorNextObject(TKALinkedListEnumerator *enumerator) {
    return (NULL != enumerator) ? TKALinkedListNodeGetObject(TKALinkedListEnumeratorGetNextNode(enumerator)) : NULL;
}

bool TKALinkedListEnumeratorIsValid(TKALinkedListEnumerator *enumerator) {
    return (NULL != enumerator && NULL != TKALinkedListEnumeratorGetList(enumerator) && enumerator->_isValid);
}

#pragma mark -
#pragma mark Private Implementations

TKALinkedListNode *TKALinkedListEnumeratorGetNextNode(TKALinkedListEnumerator *enumerator) {
    TKALinkedListEnumeratorCheckMutations(enumerator);
    
    if (!TKALinkedListEnumeratorIsValid(enumerator)) {
        return NULL;
    }
    
    TKALinkedListNode *node = TKALinkedListEnumeratorGetNode(enumerator);
    if (NULL == node) {
        node = TKALinkedListGetRootNode(TKALinkedListEnumeratorGetList(enumerator));
        TKALinkedListEnumeratorSetNode(enumerator, node);
        return node;
    }
    
    TKALinkedListNode *nextNode = TKALinkedListNodeGetNextNode(node);
    if (NULL == nextNode) {
        TKALinkedListEnumeratorSetValid(enumerator, false);
    }
    
    TKALinkedListEnumeratorSetNode(enumerator, nextNode);
//    return node;
    return nextNode;
}

void TKALinkedListEnumeratorCheckMutations(TKALinkedListEnumerator *enumerator) {
    if (NULL != enumerator && NULL != TKALinkedListEnumeratorGetList(enumerator)) {
        enumerator->_isValid = (TKALinkedListGetMutationCount(TKALinkedListEnumeratorGetList(enumerator))
                                == TKALinkedListEnumeratorGetMutationCount(enumerator));
        assert(enumerator->_isValid);
    }
}

void TKALinkedListEnumeratorSetValid(TKALinkedListEnumerator *enumerator, bool valid) {
    enumerator->_isValid = (NULL != enumerator && valid);
}

uint64_t TKALinkedListEnumeratorGetMutationCount(TKALinkedListEnumerator *enumerator) {
    return (NULL != enumerator) ? enumerator->_mutationCount : 0;
}

void TKALinkedListEnumeratorSetMutationCount(TKALinkedListEnumerator *enumerator) {
    if (NULL != enumerator && NULL != TKALinkedListEnumeratorGetList(enumerator)) {
        enumerator->_mutationCount = TKALinkedListGetMutationCount(TKALinkedListEnumeratorGetList(enumerator));
    }
}

void TKALinkedListEnumeratorSetList(TKALinkedListEnumerator *enumerator, TKALinkedList *list) {
    if (NULL != enumerator) {
        TKARetainSetter(&enumerator->_list, list);
    }
}

TKALinkedList *TKALinkedListEnumeratorGetList(TKALinkedListEnumerator *enumerator) {
    return (NULL != enumerator) ? enumerator->_list : NULL;
}

void TKALinkedListEnumeratorSetNode(TKALinkedListEnumerator *enumerator, TKALinkedListNode *node) {
    if (NULL != enumerator) {
        TKARetainSetter(&enumerator->_node, node);
    }
}

TKALinkedListNode *TKALinkedListEnumeratorGetNode(TKALinkedListEnumerator *enumerator) {
    return (NULL != enumerator) ? enumerator->_node : NULL;
}