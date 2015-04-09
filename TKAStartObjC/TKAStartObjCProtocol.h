//
//  TKAStartObjCProtocol.h
//  TKAStartObjC
//
//  Created by Taisiya on 09.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TKAStartObjCProtocol <NSObject>

- (void) sayNameFromProtocol;

@required
- (void) sayIDFromProtocol;

@optional
- (void) sayAgeFromProtocol;

@end
