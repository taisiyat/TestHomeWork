//
//  TKAPropertySetter.h
//  TKAHuman
//
//  Created by Taisiya on 16.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#ifndef __TKAHuman__TKAropertySetter__
#define __TKAHuman__TKAropertySetter__

#include <stdio.h>

#include "TKAObject.h"

extern
void TKAPropertyRetainSet(void **humanField, void *human);

extern
void TKAPropertyAssignSet(void **humanField, void *human);

#endif /* defined(__TKAHuman__TKAPropertySetter__) */
