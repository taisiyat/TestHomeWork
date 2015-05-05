//
//  TKADelegate.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 04.05.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TKADelegatingObject.h"

@interface TKADelegate : NSObject <TKADellegatingObjectDelegate>
@property (nonatomic, retain) TKADelegatingObject *delegatingObject;

@end
