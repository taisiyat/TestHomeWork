//
//  TKALinkedList.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKALinkedList.h"
#include "TKALinkedListPrivate.h"
#include "TKALinkedListNode.h"
#include "TKALinkedListEnumerator.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKALinkedListMutate(TKALinkedList *list);

static
void TKALinkedListSetCount(TKALinkedList *list, int count);

#pragma mark -
#pragma mark Public Implementations

void __TKALinkedListDeallocate(TKALinkedList *list) {
    if (NULL == list) {
        return;
    }
    TKALinkedListRemoveAllObjects(list);
    
    __TKAObjectDeallocate(list);
}

void TKALinkedListAddObject(TKALinkedList *list, void *object) {
    if (NULL != list && NULL != object) {

        TKALinkedListNode *rootNode = TKALinkedListGetRootNode(list);
        TKALinkedListNode *node = TKALinkedListNodeCreateWithNextNodeAndObject(rootNode, object);
        TKALinkedListSetRootNode(list, node);
        
        TKAObjectRelease(node);
        
        TKALinkedListMutate(list);
        TKALinkedListSetCount(list, 1);

    }
}

void TKALinkedListRemoveObject(TKALinkedList *list, void *object) {
    if (NULL != list && NULL != object && 0 != TKALinkedListGetCount(list)) {
        TKALinkedListContext context = TKALinkedListGetContextOfObject(list, object);
        if (NULL == context._currentNode) {
            return;
        }

        if (TKALinkedListGetRootNode(list) == context._currentNode) {
            TKALinkedListRemoveFirstObject(list);
        } else {
            TKALinkedListNodeSetNextNode(context._previousNode, TKALinkedListNodeGetNextNode(context._currentNode));
        
            TKALinkedListSetCount(list, -1);
            TKALinkedListMutate(list);
        }
    }
}

void TKALinkedListRemoveAllObjects(TKALinkedList *list) {
    if (NULL != list && 0 != TKALinkedListGetCount(list)) {
        while (TKALinkedListGetCount(list)) {
            TKALinkedListRemoveFirstObject(list);
        }
    }
}

void TKALinkedListRemoveFirstObject(TKALinkedList *list) {
    if (NULL != list && 0 != TKALinkedListGetCount(list)) {
        TKALinkedListNode *rootNode = TKALinkedListGetRootNode(list);
        TKALinkedListNode *newRootNode = TKALinkedListNodeGetNextNode(rootNode);
        TKALinkedListSetRootNode(list, newRootNode);

        TKALinkedListSetCount(list, -1);
        TKALinkedListMutate(list);
    }
}

void TKALinkedListInsertBeforObject(TKALinkedList *list, void *pointObject, void *insertedObject) {
    if (NULL != list && NULL != pointObject && NULL != insertedObject) {
     
        TKALinkedListContext context = TKALinkedListGetContextOfObject(list, pointObject);
        if (NULL == context._currentNode) {
            return;
        }
        
        if (TKALinkedListGetRootNode(list) == context._currentNode) {
            TKALinkedListAddObject(list,insertedObject);
        } else {
            TKALinkedListNode *insertedNode = TKALinkedListNodeCreateWithNextNodeAndObject(context._currentNode,
                                                                                           insertedObject);
            TKALinkedListNodeSetNextNode(context._previousNode, insertedNode);
            
            TKAObjectRelease(insertedNode);
            
            TKALinkedListSetCount(list, 1);
            TKALinkedListMutate(list);
        }

    }
}

void TKALinkedListInsertAfterObject(TKALinkedList *list, void *pointObject, void *insertedObject) {
    if (NULL != list && NULL != pointObject && NULL != insertedObject) {
        
        TKALinkedListContext context = TKALinkedListGetContextOfObject(list, pointObject);
        if (NULL == context._currentNode) {
            return;
        }
        
        if (NULL != TKALinkedListNodeGetNextNode(context._currentNode)) {
           TKALinkedListNode *insertedNode = TKALinkedListNodeCreateWithNextNodeAndObject(TKALinkedListNodeGetNextNode(context._currentNode),
                                                                                          insertedObject);
            TKALinkedListNodeSetNextNode(context._currentNode, insertedNode);
            
            TKAObjectRelease(insertedNode);
            
            TKALinkedListSetCount(list, 1);
            TKALinkedListMutate(list);
        }

    }

}

void TKALinkedListSetRootNode(TKALinkedList *list, TKALinkedListNode *node) {
    if (NULL == list) {
        return;
    }
    
    TKARetainSetter(&list->_rootNode, node);
}

TKALinkedListNode *TKALinkedListGetRootNode(TKALinkedList *list) {
    return (NULL != list) ? list->_rootNode : NULL;
}

uint64_t TKALinkedListGetCount(TKALinkedList *list) {
    return (NULL != list) ? list->_count : 0;
}

uint64_t TKALinkedListGetMutationCount(TKALinkedList *list) {
    return (NULL != list) ? list->_mutationCount : 0;
}

#pragma mark -
#pragma mark Private Implementations

TKALinkedListContext TKALinkedListGetContextOfObject(TKALinkedList *list, void *object) {
    TKALinkedListContext context;
    memset(&context, 0, sizeof(context));
    context._object = object;
    context._currentNode = NULL;
    context._previousNode = NULL;
    
    if (NULL != list && NULL != object ) {
        context._currentNode = TKALinkedListFindNodeOfObject(list,
                                                             &TKALinkedListNodeContainsObject,
                                                             &context);
    }
    
    return context;
}

TKALinkedListNode *TKALinkedListFindNodeOfObject(TKALinkedList *list,
                                                 TKALinkedListComparisonFunction  comparisonFunction,
                                                 void *contextTest) {
    if (NULL == list || NULL == contextTest || 0 == TKALinkedListGetCount(list)) {
        return NULL;
    }
    
    TKALinkedListEnumerator *enumerator = TKALinkedLisEnumeratorCreateWithList(list);
    TKALinkedListNode *resultNode = NULL;
    
    while ((resultNode = TKALinkedListEnumeratorNextNode(enumerator))) {
        if (comparisonFunction(resultNode, contextTest)) {
            break;
        }
    }
    
    TKAObjectRelease(enumerator);
    return resultNode;
}

bool TKALinkedListNodeContainsObject(void *node, void *contextTest) {
    if (NULL == node || NULL == contextTest) {
        return false;
    }
    
    TKALinkedListContext *context = contextTest;
    context->_previousNode = context->_currentNode;
    context->_currentNode = node;
    
    return TKALinkedListNodeGetObject(node) == context->_object;
}

void TKALinkedListMutate(TKALinkedList *list) {
    if (NULL != list) {
        list->_mutationCount ++;
    }
}

void TKALinkedListSetCount(TKALinkedList *list, int count) {
    if (NULL == list) {
        return;
    }
    
    list->_count += count;
}

