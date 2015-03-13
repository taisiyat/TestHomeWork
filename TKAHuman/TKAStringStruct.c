//
//  TKAStringStruct.c
//  TKASecondWeek
//
//  Created by Taisiya on 21.02.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAStringStruct.h"

#pragma mark -
#pragma mark Privat Declarations

static
void TKAStringStructDealloc(TKAStringStruct *string);

#pragma mark -
#pragma mark Privat Implementations

void TKAStringStructDealloc(TKAStringStruct *string) {
    if (NULL != string->_data) {
        free(string->_data);
    }
    
    free(string);
}

#pragma mark -
#pragma mark Public Implementations

TKAStringStruct *TKAStringStructCreate() {
    TKAStringStruct *string = calloc(1, sizeof(*string));
    string->_referenceCount = 1;

    return string;
}

void TKAStringStructRetain(TKAStringStruct *string) {
    string->_referenceCount++;
}

void TKAStringStructRelease(TKAStringStruct *string) {
    string->_referenceCount--;
    if (0 == string->_referenceCount) {
        TKAStringStructDealloc(string);
    }
}

void TKAStringStructSetLength(TKAStringStruct *string, uint64_t length) {
    if (string->_length != length) {
        string->_data = realloc(string->_data, length * sizeof(*string->_data));
        
        if (string->_length < length) {
            memset(string->_data + string->_length, 0, length - string->_length);
        }
        
        string->_length = length;
    }
}

uint64_t TKAStringStructGetLength(TKAStringStruct *string) {
    
    return string->_length;
}

void TKAStringStructCopyData(TKAStringStruct *string, char *data, uint64_t length) {
    
    TKAStringStructSetLength(string, length);
    memmove(string->_data, data, length);
}
                             
char *TKAStringStructGetData(TKAStringStruct *string) {
    
    return string->_data;
}

void TKAStringStructOutput(TKAStringStruct *string) {
    printf("%s", TKAStringStructGetData(string));
}

