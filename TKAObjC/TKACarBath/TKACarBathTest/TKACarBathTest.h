//
//  TKACarBathTest.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#ifndef TKAAutoreleasePool_TKACarBathTest_h
#define TKAAutoreleasePool_TKACarBathTest_h

#import "NSObject+TKAExtension.h"

typedef void(^TKABlock)();

extern
void TKAPerformBlockOnMainThread(TKABlock block);

extern
void TKACarBathTask1();

#endif
