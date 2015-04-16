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
#include "TKAEnterprise.h"

@interface TKABuilding : NSObject
@property(nonatomic, retain) NSString *address;
@property(nonatomic, retain) TKAEnterprise *enterprise;
@property(nonatomic, retain) TKAPerson *owner;
@property(nonatomic, readonly) NSArray *adminRooms;//AdminRoom
@property(nonatomic, readonly) NSArray *carBathBoxes;//CarBathBox

+(instancetype)buildingWhithAddress:(NSString *)address
                              owner:(TKAPerson *)owner;

@end
