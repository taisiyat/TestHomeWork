//
//  TKALinkedListEnumerator.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKALinkedListEnumerator.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

TKALinkedListEnumerator *TKALinkedLisEnumeratorCreateWithList(TKALinkedList *list) {
    if (NULL == list) {
        return NULL;
    }
    
    TKALinkedListEnumerator *enumerator = TKAObjectCreate(TKALinkedListEnumerator);
    TKALinkedListEnumeratorSetList(enumerator, list);
#warning set mutation
#warning set node ?????

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


bool TKALinkedListEnumeratorIsValid(TKALinkedListEnumerator *enumerator) {
    return (NULL != enumerator && NULL != TKALinkedListEnumeratorGetList(enumerator)) ? enumerator->_isValid : 0;
}

void TKALinkedListEnumeratorSetValid(TKALinkedListEnumerator *enumerator) {
    if (NULL != enumerator && NULL != TKALinkedListEnumeratorGetList(enumerator)) {
        enumerator->_isValid = (TKALinkedListGetMutationCount(TKALinkedListEnumeratorGetList(enumerator))
                                == TKALinkedListEnumeratorGetMutationCount(enumerator));
    }
}

uint64_t TKALinkedListEnumeratorGetMutationCount(TKALinkedListEnumerator *enumerator) {
    return (NULL != enumerator) ? enumerator->_mutationCount : 0;
}

void TKALinkedListEnumeratorSetMutationCount(TKALinkedListEnumerator *enumerator) {
    if (NULL != enumerator && NULL != TKALinkedListEnumeratorGetList(enumerator)) {
        enumerator->_mutationCount = TKALinkedListGetMutationCount(TKALinkedListEnumeratorGetList(enumerator));
    }
}

void *TKALinkedListEnumeratorGetNextObject(TKALinkedListEnumerator *enumerator);

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

#pragma mark -
#pragma mark Private Implementations