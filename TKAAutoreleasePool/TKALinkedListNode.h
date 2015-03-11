//
//  TKALinkedListNode.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 10.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef __TKAAutoreleasePool__TKALinkedListNode__
#define __TKAAutoreleasePool__TKALinkedListNode__

#include <stdio.h>
#include "TKAObject.h"
//#include "TKAStack.h"

typedef struct TKALinkedListNode TKALinkedListNode;

struct TKALinkedListNode {
    TKAObject _superObject;
    
    TKALinkedListNode *_nextNode;
    TKAObject *_object;
//    TKAStack *_stack;
};

extern
void __TKALinkedListNodeDeallocate(TKALinkedListNode *node);

extern
void TKALinkedListNodeSetNextNode(TKALinkedListNode *node, TKALinkedListNode *nextNode);

extern
TKALinkedListNode *TKALinkedListNodeGetNextNode(TKALinkedListNode *node);

extern
void TKALinkedListNodeSetObject(TKALinkedListNode *node, TKAObject *object);

extern
TKAObject *TKALinkedListNodeGetObject(TKALinkedListNode *node);

#endif /* defined(__TKAAutoreleasePool__TKALinkedListNode__) */
