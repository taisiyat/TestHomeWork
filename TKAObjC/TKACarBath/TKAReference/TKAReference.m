//
//  TKAReference.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 24.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAReference.h"

@interface TKAReference ()
@property (nonatomic, assign)   id  target;

@end

@implementation TKAReference

@dynamic target;

#pragma mark - 
#pragma mark Class Method

+ (instancetype)referenceWithTarget:(id)target {
    return [[[self alloc] initWithTarget:target] autorelease];
}

#pragma mark -
#pragma mark Initializations Deallocations

- (void)dealloc {
    self.target = nil;
    
    [super dealloc];
}

- (instancetype)initWithTarget:(id)target {
    self = [super init];
    if (self) {
        self.target = target;
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (NSUInteger)hash {
    return (NSUInteger)self.target ^ (NSUInteger)[self class];
}

- (BOOL)isEqual:(id)other {
    if (nil == other) {
        return NO;
    }
    if (other == self) {
        return YES;
    }
    if ([other isMemberOfClass:[self class]]) {
        return [self isEqualToReference:other];
    }
    
    return NO;
}

- (BOOL)isEqualToReference:(TKAReference *)reference {
    return self.target == reference.target;
}

@end

