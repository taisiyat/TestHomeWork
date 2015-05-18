//
//  TKAThreadTestObject.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 15.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TKAThreadObject : NSObject
//@property (nonatomic, retain)   NSLock      *lock;
@property (nonatomic, retain)   id<NSLocking>      lock;
@property (nonatomic, retain)   id          value;
@property (nonatomic, assign)   NSUInteger  callCount;

-(void)print;

@end
