//
//  TKABuilding.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "TKACarBath.h"
#include "TKAPerson.h"
#include "TKADirector.h"
#include "TKAStaff.h"

@interface TKABuilding : NSObject
@property(nonatomic, copy) NSString *address;
@property(nonatomic, readonly) NSArray *adminRooms;//AdminRoom
@property(nonatomic, readonly) NSArray *carBathBoxes;//CarBathBox

+(instancetype)buildingWhithAddress:(NSString *)address
                              owner:(TKAPerson *)owner;

@end
