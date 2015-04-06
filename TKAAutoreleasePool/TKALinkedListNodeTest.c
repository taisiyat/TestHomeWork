//
//  TKALinkedListNodeTest.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 06.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include "TKALinkedListNodeTest.h"

#pragma mark -
#pragma mark Private Declarations

#pragma mark -
#pragma mark Public Implementations

//TKAinkedListNode
//      after being created
//          next node of node should equal NULL
//          object of node should equal NUUL
//              after creating and setting testObject to node
//                  testObject reference count should equal 2
//                  object of node should equal testObject
//                      after creating and setting nextNode to node
//                          nextNode reference count should equal 2
//                          next node of node should equal nextNode
//                              after setting object of node to NULL
//                                  testObject reference count should equal 1
//                                  object of node should equal NULL
//                                      after setting next node of node to NULL
//                                          nextNode reference count should equal 1
//                                          next node of node should equal NULL
//      after being created new node with netNode and testObject
//          nextNode of new node should equal nextNode
//          testObject of new node shold equal testObject
//          testObject reference count should equal 2
//          nextNode reference count should equal 2
//                  after releasing new node
//                          testObject reference count should equal 2
//                          nextNode reference count should equal 2
//                                    Releasse node, testObjet nextNode

void TKALinkedListNodePerformTest() {
//    TKAinkedListNode
//    after being cresated
    TKALinkedListNode *node = TKAObjectCreate(TKALinkedListNode);
    
//    next node of node should equal NULL
    assert(NULL == TKALinkedListNodeGetNextNode(node));
//    object of node should equal NUUL
    assert(NULL == TKALinkedListNodeGetObject(node));
    
//    after creating and setting testObject to node
    TKAObject *testObject = TKAObjectCreate(TKAObject);
    TKALinkedListNodeSetObject(node, testObject);
    
//    testObject reference count should equal 2
    assert(2 == TKAObjectGetReferenceCount(testObject));
//    object of node should equal testObject
    assert(testObject == TKALinkedListNodeGetObject(node));
    
//    after creating and setting nextNode to node
    TKALinkedListNode *nextNode = TKAObjectCreate(TKALinkedListNode);
    TKALinkedListNodeSetNextNode(node, nextNode);
    
//    nextNode reference count should equal 2
    assert(2 == TKAObjectGetReferenceCount(nextNode));
//    next node of node should equal nextNode
    assert(nextNode == TKALinkedListNodeGetNextNode(node));
    
//    after setting object of node to NULL
    TKALinkedListNodeSetObject(node, NULL);
    
//    testObject reference count should equal 1
    assert(1 == TKAObjectGetReferenceCount(testObject));
//    object of node should equal NULL
    assert(NULL == TKALinkedListNodeGetObject(node));
    
//    after setting next node of node to NULL
    TKALinkedListNodeSetNextNode(node, NULL);
    
//    nextNode reference count should equal 1
    assert(1 == TKAObjectGetReferenceCount(nextNode));
//    next node of node should equal NULL
    assert(NULL == TKALinkedListNodeGetNextNode(node));
    
//    after being created new node with netNode and testObject
    TKALinkedListNode *newNode = TKALinkedListNodeCreateWithNextNodeAndObject(nextNode, testObject);

//    nextNode of new node should equal nextNode
    assert(nextNode == TKALinkedListNodeGetNextNode(newNode));
//    testObject of new node shold equal testObject
    assert(testObject == TKALinkedListNodeGetObject(newNode));
//    testObject reference count should equal 2
    assert(2 == TKAObjectGetReferenceCount(testObject));
//    nextNode reference count should equal 2
    assert(2 == TKAObjectGetReferenceCount(nextNode));

//    after releasing new node
    TKAObjectRelease(newNode);

//    testObject reference count should equal 2
    assert(1 == TKAObjectGetReferenceCount(testObject));
//    nextNode reference count should equal 2
    assert(1 == TKAObjectGetReferenceCount(nextNode));

//    Releasse node, testObjet nextNode
    TKAObjectRelease(nextNode);
    TKAObjectRelease(testObject);
    TKAObjectRelease(node);
}

#pragma mark -
#pragma mark Private Implementations

