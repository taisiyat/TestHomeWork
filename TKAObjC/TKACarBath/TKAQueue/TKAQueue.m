//
//  TKAQueue.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 28.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAQueue.h"

@interface TKAQueue ()
@property (nonatomic, assign) NSMutableArray *mutableQueue;

@end

@implementation TKAQueue

#pragma mark -
#pragma mark Class Method

+ (instancetype)queue {
    return [[[self alloc] init] autorelease];
}

#pragma mark -
#pragma mark Initializations Deallocations

- (void)dealloc {
    self.mutableQueue = nil;
    
    [super dealloc];
}

- (instancetype)init {
    [super init];
    if (self) {
        self.mutableQueue = [NSMutableArray array];
    }
    
    return self;
}

#pragma mark -
#pragma mark Public Methods

- (void)addObject:(id)object {
    @synchronized (self) {
        [self.mutableQueue addObject:object];
    }
}

- (void)removeObject:(id)object {
    @synchronized (self) {
        [self.mutableQueue removeObject:object];
    }
}

- (id)nextObjectQueue {
    @synchronized (self) {
        NSMutableArray *objects = self.mutableQueue;
        id result = [[[objects firstObject] retain] autorelease];
        if (result) {
            [objects removeObject:result];
        }
        
        return result;
    }
}

@end
