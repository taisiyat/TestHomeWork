//
//  TKAWasher.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"
#import "TKACar.h"

@class TKAWasher;

@protocol TKAWasherDelegate <NSObject>

- (void)washer:(TKAWasher *)object shouldGiveMoney:(NSUInteger)money;
- (BOOL)washerShouldHaveMoney:(TKAWasher *)object;

@end

@interface TKAWasher : TKAEmployee <TKACarDelegate, TKAWasherDelegate>
@property (nonatomic, retain) TKACar *car;
@property (nonatomic, retain) id<TKAWasherDelegate> delegate;

- (void)washCar:(TKACar *)car;

@end
