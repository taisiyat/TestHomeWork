//
//  main.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include <stdio.h>

#include "TKAObjectTest.h"
#include "TKAAutoreleasingStackTest.h"
#include "TKALinkedListNodeTest.h"
#include "TKALinkedListTest.h"
#include "TKAAutoreleasePoolTest.h"
#include "TKAStringTest.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TKAObjectPerformTests();
    printf("TKAObject test is OK \n");
    
    TKAAutoreleasingStackPerformTest();
    printf("TKAAutoreleasingStack test is OK \n");
    
    TKALinkedListNodePerformTest();
    printf("TKALinkedListNode test is OK \n");
    
    TKALinkedListPerformTest();
    printf("TKALinkedList test is OK \n");
    
    TKAAutoreleasePoolPerformTest();
    printf("TKAAutoreleasePool test is OK \n");
    
    TKAStringTest();
    printf("TKAString test is OK \n");
    
    printf("Hello, World!\n");
    return 0;
}
