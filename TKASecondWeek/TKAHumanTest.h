//
//  TKAHumanTest.h
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#ifndef __TKASecondWeek__TKAHumanTest__
#define __TKASecondWeek__TKAHumanTest__

#include <stdio.h>
#include <string.h>
#include "TKAHuman.h"
#include "TKAArray.h"
#include "TKAStringTest.h"

extern
void TKAHumanTestMain();

#endif /* defined(__TKASecondWeek__TKAHumanTest__) */

//TKAHuman
//      after being created 4 objects
//          objects reference count of Human should be 4
//          objects reference count of Array should be 4
//              after being created 4 TKAString objects with data not NULL
//                  objects reference count of String should be 4
//                  objects reference count of Human should be 4
//                  objects reference count of Array should be 4
//                      after SET name
//                          objects reference count of String should be 8
//                          objects reference count of Human should be 4
//                          objects reference count of Array should be 4
//                              after ObjectRelease TKASTRing
//                                  objects reference count of String should be 4
//                                  objects reference count of Human should be 4
//                                  objects reference count of Array should be 4
//                                      after ObjectRelease TKAHuman
//                                          objects reference count of String should be 0
//                                          objects reference count of Human should be 0
//                                          objects reference count of Array should be 0
//
//
//
//TKAHuman
//      after being created 4 objects
//          objects reference count of Human should be 4
//          objects reference count of Array should be 4
//                 born child
//
//
//
//add 1 child
//
//remove 1 child
//
//add 3 children
//
//remove All children

