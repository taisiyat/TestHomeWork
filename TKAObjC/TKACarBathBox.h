//
//  TKACarBathBox.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKABuilding.h"
#include "TKACarBath.h"
#include "TKACar.h"
#include "TKAWasher.h"

@interface TKACarBathBox : TKABuilding
@property(nonatomic, retain) TKACar *car;
@property(nonatomic, assign) NSArray *staffWashers;//washer

@end
