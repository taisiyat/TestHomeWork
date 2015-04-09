//
//  TKAStartObjC.h
//  TKAStartObjC
//
//  Created by Taisiya on 09.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TKAStartObjC;
@protocol TKAtartObjCProtocol;

@interface TKAStartObjC : NSObject <NSObject> {
    @public
    NSString *_name;
    
    @private
    NSNumber *_age;
    
    @protected
    NSNumber *_IDNumber;
}

//@property();

+ (instancetype)start;

- (void)sayName;
- (void)sayAge;
- (void)sayIDNumber;

- (NSString *)textType;

- (void)sayType;

@end