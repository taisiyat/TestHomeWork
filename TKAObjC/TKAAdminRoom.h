//
//  TKAAdminRoom.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 16.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKABuilding.h"
#import "TKAStaff.h"
#import "TKAAccountant.h"
#import "TKADirector.h"

@interface TKAAdminRoom : TKABuilding
@property(nonatomic, readonly) NSArray *staffAdmin;//(accountant director) staff

@end
