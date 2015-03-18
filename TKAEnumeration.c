//
//  TKAEnumeration.c
//  TKAHuman
//
//  Created by Taisiya on 18.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAEnumeration.h"

// LinkedList
//      after creating TKAObgect
//          create Enum
//              after adding TKAObject (change ObjectReferenceCount)
//                  enum +1
//                      after removing TKAObject (change ObjectReferenceCount)
//                          enum +1
//                              after ObjectReferenceCount = 0
//                                  enum Deallocate
//
