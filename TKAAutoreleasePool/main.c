//
//  main.c
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.03.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#include <stdio.h>

#include "TKAObjectTest.h"
#include "TKAStackTest.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TKAObjectPerformTests();
    printf("TKAObject test is OK \n");
    
<<<<<<< HEAD
    TKAStackPerformTest();
    printf("TKAStack test is OK \n");
=======
   // TKAStackPerformTest();
   // printf("TKAStack test is OK \n");
>>>>>>> feature/AutoreleasePool
    
    printf("Hello, World!\n");
    return 0;
}
