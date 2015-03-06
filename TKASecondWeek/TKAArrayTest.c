//
//  TKAArrayTest.c
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAArrayTest.h"

#pragma mark -
#pragma mark Privat Declarations

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

#pragma mark -
#pragma mark Public Implementations

void TKAArrayTestMain() {
    
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