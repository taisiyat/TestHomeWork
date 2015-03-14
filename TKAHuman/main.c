//
//  main.c
//  TKASecondWeek
//
//  Created by Taisiya on 17.02.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include <stdio.h>
#include "TKAHumanTest.h"
#include "TKAStringTest.h"
#include "TKAArrayTest.h"
#include "TKAObjectTest.h"


int main(int argc, const char * argv[]) {
    // insert code here...
 
    TKAObjectPerformTests();
    printf("Test TKAObject is OK. \n");

    TKAStringTest();
    printf("Test TKAString is OK. \n");
    
    TKAArrayTestMain();
    printf("Test TKAArray is OK. \n");

    TKAHumanTestMain();
    printf("Test TKAHuman is OK. \n");

    printf("Hello, World!\n");
    
    return 0;
}
