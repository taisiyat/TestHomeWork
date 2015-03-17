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

static
void TKAStringSetLength(TKAString *string, uint64_t length);

#pragma mark -
#pragma mark Privat Implementations

void TKAStringSetLength(TKAString *string, uint64_t length) {
    if (NULL != string && string->_length != length) {
        if (0 == length ) {
            free(string->_data);
            string->_data = NULL;
            
        } else {
            string->_data = realloc(string->_data, length * sizeof(*string->_data));
            
            if (string->_length < length) {
                memset(string->_data + string->_length, 0, length - string->_length);
            }
        }
        
        string->_length = length;
    }
}

#pragma mark -
#pragma mark Public Implementations

void __TKAStringDeallocate(TKAString *string) {
    TKAStringSetData(string, NULL);
    
    __TKAObjectDeallocate(string);
}

uint64_t TKAStringGetLength(TKAString *string) {
    return (NULL == string) ? 0 : string->_length;
}

void TKAStringSetData(TKAString *string, char *data) {
    if (NULL != string && string->_data != data) {
        uint64_t lengthData = (NULL == data) ? 0 : strlen(data)+1;
        TKAStringSetLength(string, lengthData);
                
        if (0 != lengthData) {
            memmove(string->_data, data, lengthData);
        }
    }
}

char *TKAStringGetData(TKAString *string) {
    return (NULL == string) ? 0 : string->_data;
}

void TKAStringOutput(TKAString *string) {
    printf("%s", TKAStringGetData(string));
}

