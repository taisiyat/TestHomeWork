//
//  TKADelegatingObject.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TKADelegatingObject;

@protocol TKADellegatingObjectDelegate <NSObject>

- (void)delagetingObject:(TKADelegatingObject *)object shuldGiveMoney:(NSUInteger)state;
- (BOOL)delegatingObjectShoulGiveMoney:(TKADelegatingObject *)object;

@end

@interface TKADelegatingObject : NSObject  //washer - delegat car - delegatingObject isclean should takemoney
@property (nonatomic,assign) NSUInteger  Money; //money
@property (nonatomic,assign) BOOL  clean; //clean

@end
