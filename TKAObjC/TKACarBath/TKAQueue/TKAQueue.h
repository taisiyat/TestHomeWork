//
//  TKAQueue.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 28.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TKAQueue : NSObject

+ (instancetype)queue;

- (void)addObject:(id)object;
- (void)removeObject:(id)object;
- (id)nextObjectQueue;

@end
