//
//  TKAArrayTest.c
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAArrayTest.h"
#include <assert.h>

#pragma mark -
#pragma mark Privat Declarations

static
void TKAArrayCreateTest();

static
void TKAArrayAddChildTest();

static
void TKAArrayRemoveChildTest();

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

void TKAArrayCreateTest() {
    uint8_t arrayLength = 20;
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHuman *childM1 = TKAHumanCreateWithNameChar("childM1", 10, TKAMale);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(childM1);
    printf("\n");
    printf("\n");
    assert(NULL != TKAHumanGetChildren(man1));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGetChildren(man1)));
    assert(arrayLength == TKAArrayGetLength(TKAHumanGetChildren(man1)));
    
    TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), childM1, 0);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(childM1);
    printf("\n");
    printf("\n");
    assert(NULL != TKAArrayGetChildAtIndex(TKAHumanGetChildren(man1), 0));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGetChildren(man1)));
    assert(2 == TKAObjectGetReferenceCount(childM1));
   
    TKAObjectRelease(childM1);
    TKAObjectRelease(man1);
}

void TKAArrayAddChildTest() {
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHuman *woman1 = TKAHumanCreateWithNameChar("woman1", 35, TKAFemale);
    TKAHuman *man2 = TKAHumanCreateWithNameChar("man2", 20, TKAMale);
    TKAHuman *woman2 = TKAHumanCreateWithNameChar("woman2", 20, TKAFemale);
    TKAHuman *childM1 = TKAHumanCreateWithNameChar("childM1", 10, TKAMale);
    TKAHuman *childF1 = TKAHumanCreateWithNameChar("childF1", 10, TKAFemale);
    TKAHuman *childM2 = TKAHumanCreateWithNameChar("childM2", 5, TKAMale);
    TKAHuman *childF2 = TKAHumanCreateWithNameChar("childF2", 5, TKAFemale);
    
    //adding child at index
    TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), childM1, 0);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(childM1);
    printf("\n");
    printf("\n");
    
    TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), childM2, 1);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(childM1);
    printf("\n");
    TKAHumanOutput(childM2);
    printf("\n");
    printf("///////////////////\n");
    
    //adding child to place NUll element of array
    TKAArrayAddChild(TKAHumanGetChildren(man1), childF1);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(childF1);
    printf("\n");
    printf("///////////////////\n");
    
    TKAArrayAddChild(TKAHumanGetChildren(man1), childF2);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(childF2);
    printf("\n");
    printf("///////////////////\n");
    
    //add an existing child
    TKAArrayAddChild(TKAHumanGetChildren(man1), childM2);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(childM2);
    printf("\n");
    printf("///////////////////\n");
    
    TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), childF1, 1);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(childM2);
    printf("\n");
    TKAHumanOutput(childF1);
    printf("\n");
    printf("///////////////////\n");

    //adding NULL child
    TKAArrayAddChild(TKAHumanGetChildren(man1), NULL);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
//    TKAHumanOutput(childM2);
//    printf("\n");
    printf("///////////////////\n");
    
    //adding NULL child at index
    TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), NULL, 2);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(childF1);
    printf("\n");
    printf("///////////////////\n");
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("///////////////////\n");
    
    for (uint8_t iter = TKAArrayGetIndexOfLastChild(TKAHumanGetChildren(man1))+1; TKAArrayGetLength(TKAHumanGetChildren(man1)) > iter ; iter++) {
        TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), woman2, iter);
        TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), man2, iter);
    }
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(woman2);
    printf("\n");
    TKAHumanOutput(man2);
    printf("\n");
    printf("///////////////////\n");
   
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("///////////////////\n");
    
    TKAArrayRemoveAllChildren(TKAHumanGetChildren(man1));
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(woman2);
    printf("\n");
    printf("///////////////////\n");
    
    TKAObjectRelease(childM1);
    TKAObjectRelease(childF1);
    TKAObjectRelease(childM2);
    TKAObjectRelease(childF2);
    TKAObjectRelease(woman1);
    TKAObjectRelease(man1);
    TKAObjectRelease(woman2);
    TKAObjectRelease(man2);
}

void TKAArrayRemoveChildTest() {
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHuman *woman1 = TKAHumanCreateWithNameChar("woman1", 35, TKAFemale);
    TKAHuman *man2 = TKAHumanCreateWithNameChar("man2", 20, TKAMale);
    TKAHuman *woman2 = TKAHumanCreateWithNameChar("woman2", 20, TKAFemale);
    TKAHuman *childM1 = TKAHumanCreateWithNameChar("childM1", 10, TKAMale);
    TKAHuman *childF1 = TKAHumanCreateWithNameChar("childF1", 10, TKAFemale);
    TKAHuman *childM2 = TKAHumanCreateWithNameChar("childM2", 5, TKAMale);
    TKAHuman *childF2 = TKAHumanCreateWithNameChar("childF2", 5, TKAFemale);
    
    TKAArrayAddChild(TKAHumanGetChildren(man1), childM1);
    TKAArrayAddChild(TKAHumanGetChildren(man1), childM2);
    TKAArrayAddChild(TKAHumanGetChildren(man1), childF1);
    TKAArrayAddChild(TKAHumanGetChildren(man1), childF2);
    
    for (uint8_t iter = TKAArrayGetIndexOfLastChild(TKAHumanGetChildren(man1))+1; TKAArrayGetLength(TKAHumanGetChildren(man1)) > iter ; iter++) {
        TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), woman2, iter);
        TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), man2, iter);
    }
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");
    TKAHumanOutput(woman2);
    printf("\n");
    printf("///////////////////\n");
    printf("\n");
    
    //removing  of child at index
    TKAArrayRemoveChildAtIndex(TKAHumanGetChildren(man1), 8);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(woman2);
    printf("\n");
    printf("////////////////////\n");
    printf("\n");
    
     //removing  of child at index with NULL
    TKAArrayRemoveChildAtIndex(TKAHumanGetChildren(man1), 8);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(woman2);
    printf("\n");
    printf("///////////////////\n");
    printf("\n");
    
    //removing  of child
    TKAArrayRemoveChild(TKAHumanGetChildren(man1), childF1);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(childF1);
    printf("\n");
    printf("///////////////////\n");
    printf("\n");
    
    TKAArrayRemoveChild(TKAHumanGetChildren(man1), childF1);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(childF1);
    printf("\n");
    printf("///////////////////\n");
    printf("\n");
    
    //removing of non-existent child
    TKAArrayRemoveChild(TKAHumanGetChildren(man1), man2);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    TKAHumanOutput(man2);
    printf("\n");
    printf("///////////////////\n");
    printf("\n");
    
    //removing  of child at big index
    TKAArrayRemoveChildAtIndex(TKAHumanGetChildren(man1), 25);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    printf("///////////////////\n");
    printf("\n");
    
    //Adding of NULL child 
    TKAArrayAddChild(TKAHumanGetChildren(man1), NULL);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    printf("///////////////////\n");
    printf("\n");
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("\n");
    printf("///////////////////\n");
    
    TKAArrayRemoveAllChildren(TKAHumanGetChildren(man1));
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");
    TKAHumanOutput(man1);
    printf("\n");
    printf("///////////////////\n");
   
    TKAObjectRelease(childM1);
    TKAObjectRelease(childF1);
    TKAObjectRelease(childM2);
    TKAObjectRelease(childF2);
    TKAObjectRelease(woman1);
    TKAObjectRelease(man1);
    TKAObjectRelease(woman2);
    TKAObjectRelease(man2);
}



void TKAArrayResizeTest() {
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
//    TKAHuman *woman1 = TKAHumanCreateWithNameChar("woman1", 35, TKAFemale);
//    TKAHuman *man2 = TKAHumanCreateWithNameChar("man2", 20, TKAMale);
//    TKAHuman *woman2 = TKAHumanCreateWithNameChar("woman2", 20, TKAFemale);
//    TKAHuman *childM1 = TKAHumanCreateWithNameChar("childM1", 10, TKAMale);
//    TKAHuman *childF1 = TKAHumanCreateWithNameChar("childF1", 10, TKAFemale);
//    TKAHuman *childM2 = TKAHumanCreateWithNameChar("childM2", 5, TKAMale);
//    TKAHuman *childF2 = TKAHumanCreateWithNameChar("childF2", 5, TKAFemale);
//    
//    TKAArrayAddChild(TKAHumanGetChildren(man1), childM1);
//    TKAArrayAddChild(TKAHumanGetChildren(man1), childM2);
//    TKAArrayAddChild(TKAHumanGetChildren(man1), childF1);
//    TKAArrayAddChild(TKAHumanGetChildren(man1), childF2);
    
    
    
//    for (uint8_t iter = TKAArrayGetIndexOfLastChild(TKAHumanGetChildren(man1))+1; TKAArrayGetLength(TKAHumanGetChildren(man1)) > iter ; iter++) {
//        TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), woman2, iter);
//        TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), man2, iter);
//    }


#define TKADEFCreateChild(number) \
        TKAHuman *child_##number = TKAHumanCreateWithNameChar("child "#number" ", number, TKAMale); \


#define TKADEFAddChild(number) \
        TKAArrayAddChildAtIndex(TKAHumanGetChildren(man1), child_##number, number); \

    
#define TKADEFRemoveChild(number) \
        \
        TKAArrayRemoveChildAtIndex(TKAHumanGetChildren(man1), number);\
        TKAObjectRelease(child_##number);\

    TKADEFCreateChild(0);
    TKADEFCreateChild(1);
    TKADEFCreateChild(2);
    TKADEFCreateChild(3);
    TKADEFCreateChild(4);
    TKADEFCreateChild(5);
    TKADEFAddChild(0);
    TKADEFAddChild(1);
    TKAArrayChangeLength(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");

    TKADEFAddChild(2);
    TKAArrayChangeLength(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");

    TKADEFAddChild(3);
    TKAArrayChangeLength(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");

    TKADEFAddChild(4);
    TKAArrayChangeLength(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");

    TKADEFAddChild(5);
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");
    
   
    TKADEFRemoveChild(5);
     TKAArrayOutput(TKAHumanGetChildren(man1));
    TKAArrayChangeLength(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");

    TKADEFRemoveChild(4);
     TKAArrayOutput(TKAHumanGetChildren(man1));
    TKAArrayChangeLength(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");

    TKADEFRemoveChild(3);
     TKAArrayOutput(TKAHumanGetChildren(man1));
    TKAArrayChangeLength(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");

    TKADEFRemoveChild(2);
     TKAArrayOutput(TKAHumanGetChildren(man1));
    TKAArrayChangeLength(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");

    TKADEFRemoveChild(1);
    TKADEFRemoveChild(0);
    
  

    //    for (uint16_t iter = TKAArrayGetLength(TKAHumanGetChildren(man1)); iter >= 0; iter--) {
//        TKADEFRemoveChild(iter);
//    }
    
    TKAArrayOutput(TKAHumanGetChildren(man1));
    printf("\n");
    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
    printf("\n");
    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
    printf("\n");
    
    
//    TKAHumanOutput(woman2);
//    printf("\n");
//    printf("///////////////////\n");
//    printf("\n");
//    
//    //removing  of child at index
//    TKAArrayRemoveChildAtIndex(TKAHumanGetChildren(man1), 8);
//    
//    TKAArrayOutput(TKAHumanGetChildren(man1));
//    printf("\n");
//    TKAHumanOutput(man1);
//    printf("\n");
//    TKAHumanOutput(woman2);
//    printf("\n");
//    printf("////////////////////\n");
//    printf("\n");
//    
//    //removing  of child at index with NULL
//    TKAArrayRemoveChildAtIndex(TKAHumanGetChildren(man1), 8);
//    
//    TKAArrayOutput(TKAHumanGetChildren(man1));
//    printf("\n");
//    TKAHumanOutput(man1);
//    printf("\n");
//    TKAHumanOutput(woman2);
//    printf("\n");
//    printf("///////////////////\n");
//    printf("\n");
//    
//    //removing  of child
//    TKAArrayRemoveChild(TKAHumanGetChildren(man1), childF1);
//    
//    TKAArrayOutput(TKAHumanGetChildren(man1));
//    printf("\n");
//    TKAHumanOutput(man1);
//    printf("\n");
//    TKAHumanOutput(childF1);
//    printf("\n");
//    printf("///////////////////\n");
//    printf("\n");
//    
//    TKAArrayRemoveChild(TKAHumanGetChildren(man1), childF1);
//    
//    TKAArrayOutput(TKAHumanGetChildren(man1));
//    printf("\n");
//    TKAHumanOutput(man1);
//    printf("\n");
//    TKAHumanOutput(childF1);
//    printf("\n");
//    printf("///////////////////\n");
//    printf("\n");
//    
//    //removing of non-existent child
//    TKAArrayRemoveChild(TKAHumanGetChildren(man1), man2);
//    
//    TKAArrayOutput(TKAHumanGetChildren(man1));
//    printf("\n");
//    TKAHumanOutput(man1);
//    printf("\n");
//    TKAHumanOutput(man2);
//    printf("\n");
//    printf("///////////////////\n");
//    printf("\n");
//    
//    //removing  of child at big index
//    TKAArrayRemoveChildAtIndex(TKAHumanGetChildren(man1), 25);
//    
//    TKAArrayOutput(TKAHumanGetChildren(man1));
//    printf("\n");
//    TKAHumanOutput(man1);
//    printf("\n");
//    printf("///////////////////\n");
//    printf("\n");
//    
//    //Adding of NULL child
//    TKAArrayAddChild(TKAHumanGetChildren(man1), NULL);
//    
//    TKAArrayOutput(TKAHumanGetChildren(man1));
//    printf("\n");
//    TKAHumanOutput(man1);
//    printf("\n");
//    printf("///////////////////\n");
//    printf("\n");
//    
//    TKAArrayOutput(TKAHumanGetChildren(man1));
//    printf("\n");
//    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
//    printf("\n");
//    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
//    printf("\n");
//    printf("\n");
//    printf("///////////////////\n");
//    
//    TKAArrayRemoveAllChildren(TKAHumanGetChildren(man1));
//    TKAArrayOutput(TKAHumanGetChildren(man1));
//    printf("\n");
//    printf("count of children in array = %d", TKAArrayGetChildCount(TKAHumanGetChildren(man1)));
//    printf("\n");
//    printf("length of array = %d", TKAArrayGetLength(TKAHumanGetChildren(man1)));
//    printf("\n");
////    TKAHumanOutput(man1);
//    printf("\n");
//    printf("///////////////////\n");
    
//    TKAObjectRelease(childM1);
//    TKAObjectRelease(childF1);
//    TKAObjectRelease(childM2);
//    TKAObjectRelease(childF2);
//    TKAObjectRelease(woman1);
    TKAObjectRelease(man1);
//    TKAObjectRelease(woman2);
//    TKAObjectRelease(man2);
}



#pragma mark -
#pragma mark Public Implementations

void TKAArrayTestMain() {
    TKAArrayResizeTest();
 //   TKAArrayCreateTest();
//    TKAArrayAddChildTest();
//    TKAArrayRemoveChildTest();
 
}

// TKAArray
//        after being created
//          array should be NULL, length should be 0
//          objects reference count of Array should be 1
//              after adding 5 child
//                  array shouldn't be NULL, length should be increment by 5
//                  objects reference count of child should be increment by 5
//                  objects reference count of Array should be 1
//                         after removing ALL children
//                              array shouldn be NULL, length should be decrement by 5
//                              objects reference count of child should be decrement by 5
//                              objects reference count of Array should be 1
//                                  ObjectRelease Array
//
// TKAArray
//        after being created
//          array should be NULL, length should be 0
//          objects reference count of Array should be 1
//              after adding 1 child by index 3
//                  array shouldn't be NULL, length should be increment by 3
//                  objects reference count of child should be increment by 1
//                  objects reference count of Array should be 1
//                         after removing ALL children
//                              array should be NULL, length should be 0
//                              objects reference count of child should be decrement by 1
//                              objects reference count of Array should be 1
//                                  ObjectRelease Array
//
// TKAArray
//        after being created
//          array should be NULL, length should be 0
//          objects reference count of Array should be 1
//              after adding 1 child by pointer
//                  array shouldn't be NULL, length should be increment by 1
//                  objects reference count of child should be increment by 1
//                  objects reference count of Array should be 1
//                      after removing ALL children
//                              array should be NULL, length should be  0
//                              objects reference count of child should be decrement by 1
//                              objects reference count of Array should be 1
////                                  ObjectRelease Array
//
//TKAArray
//        after being created
//           after adding 3 child
//                          array shouldn't be NULL, length should be increment by 3
//                          objects reference count of child should be increment by 3
//                          objects reference count of Array should be 1
//                              after removing 1 child by index 2
//                                  array shouldn't be NULL, length shouldn't change
//                                  objects reference count of child should be decrement by 1
//                                  objects reference count of Array should be 1
//                                         after removing ALL child
//                                          array should be NULL, length should be 0
//                                          objects reference count of child should be decrement by 2
//                                          objects reference count of Array should be 1
//                                              ObjectRelease Array
//
//      