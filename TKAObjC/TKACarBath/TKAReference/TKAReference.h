//
//  TKAReference.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TKAReference : NSObject
@property (nonatomic, readonly)     id  target;

+ (instancetype)referenceWithTarget:(id)target;

- (NSUInteger)hash;
- (BOOL)isEqual:(id)other;
- (BOOL)isEqualToReference:(TKAReference *)reference;

@end
