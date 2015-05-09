//
//  TKAAccountant.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 21.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAEmployee.h"

#import "TKAWasher.h"

//@protocol TKADelegatingObject <NSObject>
//
//- (void)delegatingObject:(TKAEmployee *)object shouldGiveMoney:(NSUInteger)money;
//- (BOOL)delegatingObjectShouldHaveMoney:(TKAEmployee *)object;
//
//@end


@interface TKAAccountant : TKAEmployee <TKAWasherDelegate>
@property (nonatomic, retain) TKAWasher *delegatingObject;

@end
