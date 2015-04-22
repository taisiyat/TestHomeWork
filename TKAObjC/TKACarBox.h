//
//  TKACarBox.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKARoom.h"
#import "TKACar.h"

@interface TKACarBox : TKARoom
@property(nonatomic,retain) TKACar *car;

- (void)output;
- (void)addCar:(TKACar *)car;
- (void)removeCar:(TKACar *)car;

@end
