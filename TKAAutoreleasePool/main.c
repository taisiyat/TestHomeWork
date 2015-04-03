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

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TKAObjectPerformTests();
    printf("TKAObject test is OK \n");
    
    TKAAutoreleasingStackPerformTest();
    printf("TKAAutoreleasingStack test is OK \n");
    
    printf("Hello, World!\n");
    return 0;
}
