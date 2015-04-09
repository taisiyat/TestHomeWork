//
//  TKAStart.m
//  TKAStartObjC
//
//  Created by Taisiya on 09.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TKAStartObjC.h"
#import "TKAStart.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKAStartOutputTypes();

static
void TKAStartObjCTestHuman();

#pragma mark -
#pragma mark Public Implementations

void TKAStart() {
    TKAStartOutputTypes();
}

void TKAStartObjCTest() {
    TKAStartObjCTestHuman();
}

#pragma mark -
#pragma mark Private Implementations

void TKAStartOutputTypes() {
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    
    NSObject *object = [[NSObject new] autorelease];
    object = Nil;
    NSLog(@"classs = %@, value = %@", [object class], object);
    
    object = @(111111111111.5);
    NSLog(@"classs = %@, value = %@", [object class], object);
    
    object = MIN(object, @(0.5));
    NSLog(@"classs = %@, value = %@", [object class], object);
    
    object = @[@(1.5), @(3444)];
    NSLog(@"classs = %@, value = %@", [object class], object);
    
    NSString *string = @"tessst string";
    NSLog(@"classs = %@, value = %@", [string class], string);
    
    object = @{@(1): string};
    NSLog(@"classs = %@, value = %@", [object class], object);
    
    object = nil;
    NSLog(@"classs = %@, value = %@", [object class], object);
    
     NSLog(@" ");
    [pool drain];
}

void TKAStartObjCTestHuman() {
    Class class = [TKAStartObjC class];
    id human = [[class new] autorelease];
    
//    id human = [[TKAStartObjC new] autorelease];
    NSLog(@"human = %@", human);
    [human sayName];
    
}

