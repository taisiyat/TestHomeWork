//
//  TKAStartObjC.m
//  TKAStartObjC
//
//  Created by Taisiya on 09.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TKAStartObjC.h"

@implementation TKAStartObjC

+ (instancetype)start {
    return [[[self alloc] init] autorelease];
}

- (void)sayName {
    NSLog(@" name = %@", _name);
}

- (void)sayAge {
    NSLog(@" age = %@", _age);
}

- (void)sayIDNumber {
    NSLog(@" ID = %@", _IDNumber);
}
    
- (NSString *)textType {
    return NSStringFromClass([self class]);
}

- (void)sayType {
    NSLog(@" type = %@", [self class]);
}

//- (void)sayType {
//    NSLog(@"%@", textType);
//}

@end


