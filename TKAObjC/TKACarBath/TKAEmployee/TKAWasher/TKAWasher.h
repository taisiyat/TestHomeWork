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

typedef NS_ENUM(NSUInteger, TKAEmployeeState) {
    TKAReadyToWork,
    TKAPerformWork
};

@protocol TKAWashObserver <NSObject>

@optional
- (void)washerBecomeReadyToWork:(TKAWasher *)washer;
- (void)washerPerformWorkNow:(TKAWasher *)washer;
//- (void)washerGiveMoney:(TKAWasher *)washer;

 @end

@interface TKAWasher : TKAEmployee <TKACarDelegate>
@property (nonatomic, retain) TKACar *car;

- (void)washCar:(TKACar *)car;

@end
