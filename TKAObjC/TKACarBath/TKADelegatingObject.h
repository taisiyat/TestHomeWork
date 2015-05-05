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

- (void)delagetingObject:(TKADelegatingObject *)object; //should give money
            //shouldChangeSomething:(NSUInteger)money
- (BOOL)delegatingObjectShouldChangeSomething:(TKADelegatingObject *)object; // if clean then YES

@end

@interface TKADelegatingObject : NSObject  //washer - delegat car - delegatingObject isclean should takemoney
@property (nonatomic, assign) NSUInteger  money; //money
@property (nonatomic, assign) BOOL  clean;
@property (nonatomic, assign) id<TKADellegatingObjectDelegate> delegate; //washer

@end
