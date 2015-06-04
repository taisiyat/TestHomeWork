//
//  TKAGCDObject.m
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.06.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import "TKAGCDObject.h"

@interface TKAGCDObject ();
//@property (nonatomic, retain)   dispatch_queue_t    queue;

- (void)executeWithQueueType:(dispatch_queue_attr_t)attribute block:block;

@end

@implementation TKAGCDObject

#pragma mark -
#pragma mark Class Methods

#pragma mark -
#pragma mark Initializations and Deallocations

- (void)dealloc {
    self.queue = NULL;
    
    [super dealloc];
}

#pragma mark -
#pragma mark Acessors Methods

#pragma mark -
#pragma mark Public Methods

- (void)executeSerialBlock:block {
    [self executeWithQueueType:DISPATCH_QUEUE_SERIAL block:block];
}

- (void)executeConcurrentBlock:block {
    [self executeWithQueueType:DISPATCH_QUEUE_CONCURRENT block:block];
}

#pragma mark -
#pragma mark Private Methods

- (void)executeWithQueueType:(dispatch_queue_attr_t)attribute block:block {
    
    dispatch_queue_t queue = dispatch_get_global_queue(QOS_CLASS_UTILITY, 0);
    self.queue = queue;
    
    dispatch_sync (queue, ^{
        dispatch_apply(50, queue, block);
    });
}

//- (void)executeWithQueueType:(dispatch_queue_attr_t)attribute block:block {
//    
//}

@end

