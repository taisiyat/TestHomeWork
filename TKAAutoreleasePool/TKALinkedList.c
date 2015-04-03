//
//  TKALinkedList.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKALinkedList.h"
<<<<<<< HEAD
=======
#include "TKALinkedListPrivate.h"
#include "TKALinkedListNode.h"
#include "TKALinkedListEnumerator.h"
>>>>>>> feature/AutoreleasePool

#pragma mark -
#pragma mark Private Declarations

<<<<<<< HEAD
#pragma mark -
#pragma mark Public Implementations

#pragma mark -
#pragma mark Private Implementations
=======
static
void TKALinkedListMutate(TKALinkedList *list);

static
void TKALinkedListAddValueToCount(TKALinkedList *list, int count);

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
        TKALinkedListAddValueToCount(list, 1);

    }
}

void TKALinkedListRemoveObject(TKALinkedList *list, void *object) {
    if (NULL != list && NULL != object && 0 != TKALinkedListGetCount(list)) {
        TKALinkedListMutate(list);
        
        TKALinkedListContext context = TKALinkedListGetContextForObject(list, object);
        if (NULL == context.currentNode) {
            return;
        }

        if (TKALinkedListGetRootNode(list) == context.currentNode) {
            TKALinkedListRemoveFirstObject(list);
        } else {
            TKALinkedListNodeSetNextNode(context.previousNode, TKALinkedListNodeGetNextNode(context.currentNode));
            TKALinkedListAddValueToCount(list, -1);
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
        TKALinkedListMutate(list);
        
        TKALinkedListNode *rootNode = TKALinkedListGetRootNode(list);
        TKALinkedListNode *newRootNode = TKALinkedListNodeGetNextNode(rootNode);
        TKALinkedListSetRootNode(list, newRootNode);

        TKALinkedListAddValueToCount(list, -1);
    }
}

void TKALinkedListInsertBeforeObject(TKALinkedList *list, void *pointObject, void *insertedObject) {
    if (NULL != list && NULL != pointObject && NULL != insertedObject) {
        TKALinkedListMutate(list);
        
        TKALinkedListContext context = TKALinkedListGetContextForObject(list, pointObject);
        if (NULL == context.currentNode) {
            return;
        }
        
        if (TKALinkedListGetRootNode(list) == context.currentNode) {
            TKALinkedListAddObject(list,insertedObject);
        } else {
            TKALinkedListNode *insertedNode = TKALinkedListNodeCreateWithNextNodeAndObject(context.currentNode,
                                                                                           insertedObject);
            TKALinkedListNodeSetNextNode(context.previousNode, insertedNode);
            TKAObjectRelease(insertedNode);
            TKALinkedListAddValueToCount(list, 1);
        }
    }
}

void TKALinkedListInsertAfterObject(TKALinkedList *list, void *pointObject, void *insertedObject) {
    if (NULL != list && NULL != pointObject && NULL != insertedObject) {
        TKALinkedListMutate(list);
        
        TKALinkedListContext context = TKALinkedListGetContextForObject(list, pointObject);
        if (NULL == context.currentNode) {
            return;
        }
        
        if (NULL != TKALinkedListNodeGetNextNode(context.currentNode)) {
           TKALinkedListNode *insertedNode = TKALinkedListNodeCreateWithNextNodeAndObject(TKALinkedListNodeGetNextNode(context.currentNode),
                                                                                          insertedObject);
            TKALinkedListNodeSetNextNode(context.currentNode, insertedNode);
            TKAObjectRelease(insertedNode);
            TKALinkedListAddValueToCount(list, 1);
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

TKALinkedListContext TKALinkedListGetContextForObject(TKALinkedList *list, void *object) {
    TKALinkedListContext context;
    memset(&context, 0, sizeof(context));
    context.object = object;
    context.currentNode = NULL;
    context.previousNode = NULL;
    
    if (NULL != list && NULL != object ) {
        context.currentNode = TKALinkedListFindNodeForObject(list,
                                                             &TKALinkedListNodeContainsObject,
                                                             &context);
    }
    
    return context;
}

TKALinkedListNode *TKALinkedListFindNodeForObject(TKALinkedList *list,
                                                 TKALinkedListComparisonFunction  comparisonFunction,
                                                 void *context) {
    if (NULL == list || NULL == context || 0 == TKALinkedListGetCount(list)) {
        return NULL;
    }
    
    TKALinkedListEnumerator *enumerator = TKALinkedLisEnumeratorCreateWithList(list);
    TKALinkedListNode *resultNode = NULL;
    
    while ((resultNode = TKALinkedListEnumeratorNextNode(enumerator))) {
        if (comparisonFunction(resultNode, context)) {
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
    context->previousNode = context->currentNode;
    context->currentNode = node;
    
    return TKALinkedListNodeGetObject(node) == context->object;
}

void TKALinkedListMutate(TKALinkedList *list) {
    if (NULL != list) {
        list->_mutationCount ++;
    }
}

void TKALinkedListAddValueToCount(TKALinkedList *list, int count) {
    if (NULL == list) {
        return;
    }
    
    list->_count += count;
}

>>>>>>> feature/AutoreleasePool
