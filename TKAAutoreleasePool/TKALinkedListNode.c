//
//  TKALinkedListNode.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKALinkedListNode.h"
#include "TKAPropertySetter.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

void TKALinkedListNodeSetNextNode(TKALinkedListNode *node, TKALinkedListNode *nextNode) {
    if (NULL != node && node != nextNode) {
        TKAPropertyRetainSet((void **)&node->_nextNode, nextNode);
    }
}

TKALinkedListNode *TKALinkedListNodeGetNextNode(TKALinkedListNode *node) {
    return (NULL != node) ? node->_nextNode : NULL;
}

void TKALinkedListNodeSetObject(TKALinkedListNode *node, void *object) {
    if (NULL != node && node != object) {
        TKAPropertyRetainSet((void **)&node->_object, object);
    }
}

void *TKALinkedListNodeGetObject(TKALinkedListNode *node) {
    return (NULL != node) ? node->_object : NULL;
}

void __TKALinkedListNodeDeallocate(TKALinkedListNode *node) {
    TKALinkedListNodeSetNextNode(node, NULL);
    TKALinkedListNodeSetObject(node, NULL);
    
    __TKAObjectDeallocate(node);
}

#pragma mark -
#pragma mark Private Implementations