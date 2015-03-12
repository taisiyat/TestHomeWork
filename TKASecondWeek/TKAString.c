//
//  TKAString.c
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAString.h"

#pragma mark -
#pragma mark Privat Declarations

uint64_t TKAStringReturnError = UINT64_MAX;

#pragma mark -
#pragma mark Privat Implementations

void __TKAStringDeallocate(TKAString *string) {
    TKAStringSetData(string, NULL);
    
    __TKAObjectDeallocate(string);
}

#pragma mark -
#pragma mark Public Implementations

void TKAStringSetLength(TKAString *string, uint64_t length) {
    if (NULL == string) {
        return;
    }
    
    if (0 == length && string->_length != length) {
        free(string->_data);
        string->_data = NULL;
        string->_length = length;
    }

    if (string->_length != length) {
        string->_data = realloc(string->_data, length * sizeof(*string->_data));
        
        if (string->_length < length) {
            memset(string->_data + string->_length, 0, length - string->_length);
        }
        
        string->_length = length;
    }
}

uint64_t TKAStringGetLength(TKAString *string) {
    return (NULL == string) ? TKAStringReturnError : string->_length;
}

void TKAStringSetData(TKAString *string, char *data) {
    if (NULL == string) {
        return;
    }

    if (string->_data != data) {
        uint64_t lengthData = 0;
        
        if (NULL != string->_data || NULL == data) {
            TKAStringSetLength(string, lengthData);
        }

        if (NULL != data) {
            lengthData = strlen(data)+1;
            TKAStringSetLength(string, lengthData);
            memmove(string->_data, data, lengthData);
        }
    }
}

char *TKAStringGetData(TKAString *string) {
    return (NULL == string) ? NULL : string->_data;
}

void TKAStringOutput(TKAString *string) {
    printf("%s", TKAStringGetData(string));
}

