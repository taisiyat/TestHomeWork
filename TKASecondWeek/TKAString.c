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

#pragma mark -
#pragma mark Privat Implementations

void __TKAStringDeallocate(TKAString *string) {
    TKAStringSetData(string, NULL);
    
    __TKAObjectDeallocate(string);
}

#pragma mark -
#pragma mark Public Implementations

void TKAStringSetLength(TKAString *string, uint64_t length) {
    if (string->_length != length) {
        string->_data = realloc(string->_data, length * sizeof(*string->_data));
        
        if (string->_length < length) {
            memset(string->_data + string->_length, 0, length - string->_length);
        }
        
        string->_length = length;
    }
}

uint64_t TKAStringGetLength(TKAString *string) {
    if (NULL == string) {
        return 18446744073709551615;//??
    }
    
    return string->_length;
}

void TKAStringSetData(TKAString *string, char *data) {
    if (NULL == string) {
        return;
    }
    
    if (string->_data != data) {
        if (NULL != string->_data) {
            free(string->_data);
            string->_data = NULL;
        }
 
        if (NULL != data) {
            TKAStringCopyData(string, data);
        }
        if (NULL == data) {
            TKAStringSetLength(string, 0);
        }
    }
    
}


void TKAStringCopyData(TKAString *string, char *data) {
    uint64_t lengthData = strlen(data);
    TKAStringSetLength(string, lengthData+1);
    memmove(string->_data, data, lengthData+1);
}

char *TKAStringGetData(TKAString *string) {
    if (NULL == string) {
        return NULL;
        //NULL;//65535 //""??
    }

    return string->_data;
}

void TKAStringOutput(TKAString *string) {
    printf("%s", TKAStringGetData(string));
}

