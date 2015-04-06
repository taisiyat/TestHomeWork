//
//  TKALinkedListNode.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef __TKAAutoreleasePool__TKALinkedListNode__
#define __TKAAutoreleasePool__TKALinkedListNode__

#include <stdio.h>

#include "TKAObject.h"
#include "TKAPropertySetter.h"

typedef struct TKALinkedListNode TKALinkedListNode;
struct TKALinkedListNode {
    TKAObject _superObject;
    
    TKALinkedListNode *_nextNode;
    void *_object;
};

extern
void TKALinkedListNodeSetNextNode(TKALinkedListNode *node, TKALinkedListNode *nextNode);

extern
TKALinkedListNode *TKALinkedListNodeGetNextNode(TKALinkedListNode *node);

extern
void TKALinkedListNodeSetObject(TKALinkedListNode *node, void *object);

extern
void *TKALinkedListNodeGetObject(TKALinkedListNode *node);

extern
void __TKALinkedListNodeDeallocate(TKALinkedListNode *node);

extern
TKALinkedListNode *TKALinkedListNodeCreateWithNextNodeAndObject(TKALinkedListNode *nextNode, void *object);

#endif /* defined(__TKAAutoreleasePool__TKALinkedListNode__) */


