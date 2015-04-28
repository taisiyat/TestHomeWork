//
//  TKAEmployeeProtocol.h
//  TKAAutoreleasePool
//
//  Created by Taisiya on 27.04.15.
//  Copyright (c) 2015 TKAHomeWork. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol TKAEmployeeProtocol <NSObject>

- (void)takeMoney:(id<TKAEmployeeProtocol>)employee;

- (void)giveMoney:(id<TKAEmployeeProtocol>)employee;

@end
