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
//#include "TKALinkedListEnumeratorPrivate.h"

#pragma mark -
#pragma mark Private Declarations

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
        
        TKALinkedListNode *pointNode =TKALinkedListGetNodeForObject(list, pointObject);
        if (NULL == pointNode) {
            return;
        }
        
        TKALinkedListNode *insertedNode = NULL;

        insertedNode = TKALinkedListNodeCreateWithNextNodeAndObject(TKALinkedListNodeGetNextNode(pointNode), insertedObject);
        TKALinkedListNodeSetNextNode(pointNode, insertedNode);
        TKAObjectRelease(insertedNode);
        TKALinkedListAddValueToCount(list, 1);
    }
}

uint64_t TKALinkedListGetCount(TKALinkedList *list) {
    return (NULL != list) ? list->_count : 0;
}

void *TKALinkedListGetFirstObject(TKALinkedList *list) {
    return (NULL != list) ? TKALinkedListNodeGetObject(TKALinkedListGetRootNode(list)) : NULL;
}

bool TKALinkedListContainsObject(TKALinkedList *list, void *object) {
    return (NULL != list && NULL != TKALinkedListGetNodeForObject(list, object));
}

#pragma mark -
#pragma mark Private Implementations

TKALinkedListContext TKALinkedListGetContextForObject(TKALinkedList *list, void *object) {
    TKALinkedListContext context;
    memset(&context, 0, sizeof(context));
    context.object = object;
    
    if (NULL != list && NULL != object ) {
        context.currentNode = TKALinkedListFindNodeForObject(list,
                                                             TKALinkedListNodeContainsObject,
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
    
    TKALinkedListEnumerator *enumerator = TKALinkedListEnumeratorCreateWithList(list);
    TKALinkedListNode *resultNode = NULL;
    
    while ((resultNode = TKALinkedListEnumeratorGetNextNode(enumerator))) {
        if (comparisonFunction(resultNode, context)) {
            break;
        }
    }
    
//    while ((resultNode = TKALinkedListEnumeratorGetNextNode(enumerator))) {
//        if (comparisonFunction(resultNode, context)) {
//            break;
//        }
//        if (!TKALinkedListEnumeratorIsValid(enumerator)) {
//            resultNode = NULL;
//            break;
//        }        
//    }
    
//    do {
//        resultNode = TKALinkedListEnumeratorGetNextNode(enumerator);
//        if (comparisonFunction(resultNode, context)) {
//            break;
//        }
//        if (!TKALinkedListEnumeratorIsValid(enumerator)) {
//            resultNode = NULL;
//        }
//        
//    } while (TKALinkedListEnumeratorIsValid(enumerator) && NULL != resultNode);
    
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

TKALinkedListNode *TKALinkedListGetNodeForObject(TKALinkedList *list, void *object) {
    if (NULL == list) {
        return NULL;
    }
    
    TKALinkedListContext context = TKALinkedListGetContextForObject(list, object);
    
    return context.currentNode;
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

void TKALinkedListSetRootNode(TKALinkedList *list, TKALinkedListNode *node) {
    if (NULL == list) {
        return;
    }
    
    TKARetainSetter(&list->_rootNode, node);
}

TKALinkedListNode *TKALinkedListGetRootNode(TKALinkedList *list) {
    return (NULL != list) ? list->_rootNode : NULL;
}

uint64_t TKALinkedListGetMutationCount(TKALinkedList *list) {
    return (NULL != list) ? list->_mutationCount : 0;
}


