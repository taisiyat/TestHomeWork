//
//  TKALinkedListNode.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 10.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKALinkedListNode.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Private Implementations

#pragma mark -
#pragma mark Public Implementations

void __TKALinkedListNodeDeallocate(TKALinkedListNode *node) {
    TKALinkedListNodeSetNextNode(node, NULL);
    TKALinkedListNodeSetObject(node, NULL);
    
    __TKAObjectDeallocate(node);
}

void TKALinkedListNodeSetNextNode(TKALinkedListNode *node, TKALinkedListNode *nextNode) {
    if (node->_nextNode != nextNode) {
        if (NULL != node->_nextNode) {
            TKAObjectRelease(node->_nextNode);
        }
        
        node->_nextNode = nextNode;
        
        if (NULL != node->_nextNode) {
            TKAObjectRatain(nextNode);
        }
    }
}

TKALinkedListNode *TKALinkedListNodeGetNextNode(TKALinkedListNode *node) {
    return node->_nextNode;
}

void TKALinkedListNodeSetObject(TKALinkedListNode *node, TKAObject *object) {
    if (node->_object != object) {
        if (NULL != node->_object) {
            TKAObjectRelease(node->_object);
        }
        
        node->_object = object;
        
        if (NULL != node->_object) {
            TKAObjectRatain(object);
        }
    }
}

TKAObject *TKALinkedListNodeGetObject(TKALinkedListNode *node) {
    return node->_object;
}
