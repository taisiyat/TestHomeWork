//
//  TKAHumanStruct.h
//  TKASecondWeek
//
//  Created by Taisiya on 17.02.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#ifndef __TKASecondWeek__TKAHumanStruct__
#define __TKASecondWeek__TKAHumanStruct__

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "TKAStringStruct.h"
//#include "TKAArrayStruct.h"

typedef struct TKAHumanStruct TKAHumanStruct;
typedef struct TKAArrayStruct TKAArrayStruct;

typedef enum {
    TKAMaleStruct,
    TKAFemaleStruct
} TKAGenderStruct;

struct TKAHumanStruct {
    TKAArrayStruct *_children;
    TKAHumanStruct *_partner;
    TKAHumanStruct *_father;
    TKAHumanStruct *_mother;
    TKAStringStruct *_name;
    uint64_t _referenceCount;
    uint8_t _age;
    TKAGenderStruct _gender;
    uint8_t _countChildren;
};
typedef struct TKAHumanStruct TKAHumanStruct;

extern
TKAHumanStruct *TKAHumanStructCreate();

extern
void TKAHumanStructRetain(TKAHumanStruct *human);

extern
void TKAHumanStructRelease(TKAHumanStruct *human);

extern
void TKAHumanStructSetName(TKAHumanStruct *human, TKAStringStruct *name);

extern
void TKAHumanStructSetAge(TKAHumanStruct *human, uint8_t age);

extern
void TKAHumanStructSetGender(TKAHumanStruct *human, TKAGenderStruct gender);

extern
TKAStringStruct *TKAHumanStructGetName(TKAHumanStruct *human);

extern
uint8_t TKAHumanStructGetAge(TKAHumanStruct *human);

extern
TKAGenderStruct TKAHumanStructGetGender(TKAHumanStruct *human);

extern
uint8_t TKAHumanStructGetCountChildren(TKAHumanStruct *human);

extern
void TKAHumanStructSetCountChildren(TKAHumanStruct *human, uint8_t count);

extern
TKAHumanStruct *TKAHumanStructGetPartner(TKAHumanStruct *human);

extern
void TKAHumanStructSetPartner(TKAHumanStruct *human1, TKAHumanStruct *human2);

extern
TKAHumanStruct *TKAHumanStructGetFather(TKAHumanStruct *human);

extern
void TKAHumanStructSetFather(TKAHumanStruct *human1, TKAHumanStruct *human2);

extern
TKAHumanStruct *TKAHumanStructGetMother(TKAHumanStruct *human);

extern
void TKAHumanStructSetMother(TKAHumanStruct *human1, TKAHumanStruct *human2);

extern
TKAArrayStruct *TKAHumanStructGetChildren(TKAHumanStruct *human);

extern
void TKAHumanStructSetChildren(TKAHumanStruct *human, TKAArrayStruct *children);

extern
TKAHumanStruct *TKAHumanStructBorn(TKAHumanStruct *father, TKAHumanStruct *mother, TKAGenderStruct gender);

extern
void TKAHumanStructAddChild(TKAHumanStruct *parent, TKAHumanStruct *child);

extern
void TKAHumanStructMarry(TKAHumanStruct *humanMale, TKAHumanStruct *humanFemale);

extern
void TKAHumanStructDivorcePartner(TKAHumanStruct *human);

extern
void TKAHumanStructDivorce(TKAHumanStruct *partner1, TKAHumanStruct *partner2);

#endif /* defined(__TKASecondWeek__TKAHumanStruct__) */
