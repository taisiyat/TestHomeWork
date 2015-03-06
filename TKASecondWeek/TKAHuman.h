//
//  TKAHuman.h
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#ifndef __TKASecondWeek__TKAHuman__
#define __TKASecondWeek__TKAHuman__

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "TKAString.h"
#include "TKAArray.h"

typedef struct TKAHuman TKAHuman;
typedef struct TKAArray TKAArray;

typedef enum {
    TKAMale,
    TKAFemale
} TKAGender;

struct TKAHuman {
    TKAObject _object;
    
    TKAString *_name;
    TKAHuman *_partner;
    TKAHuman *_father;
    TKAHuman *_mother;
    TKAArray *_children;
    
    uint8_t _age;
    TKAGender _gender;
    uint8_t _childCount;
};
typedef struct TKAHuman TKAHuman;

extern
TKAHuman *TKAHumanCreate(TKAString *name, uint8_t age, TKAGender gender);


extern
void TKAHumanSetName(TKAHuman *human, TKAString *name);

extern
void TKAHumanSetAge(TKAHuman *human, uint8_t age);

extern
void TKAHumanSetGender(TKAHuman *human, TKAGender gender);

extern
TKAString *TKAHumanGetName(TKAHuman *human);

extern
uint8_t TKAHumanGetAge(TKAHuman *human);

extern
TKAGender TKAHumanGetGender(TKAHuman *human);

extern
uint8_t TKAHumanGetChildCount(TKAHuman *human);

extern
void TKAHumanSetChildCount(TKAHuman *human, uint8_t count);

extern
TKAHuman *TKAHumanGetPartner(TKAHuman *human);

extern
void TKAHumanSetPartner(TKAHuman *human1, TKAHuman *human2);

extern
TKAHuman *TKAHumanGetFather(TKAHuman *human);

extern
void TKAHumanSetFather(TKAHuman *human1, TKAHuman *human2);

extern
TKAHuman *TKAHumanGetMother(TKAHuman *human);

extern
void TKAHumanSetMother(TKAHuman *human1, TKAHuman *human2);

extern
TKAArray *TKAHumanGetChildren(TKAHuman *human);

extern
void TKAHumanSetChildren(TKAHuman *human, TKAArray *children);

extern
TKAHuman *TKAHumanBorn(TKAHuman *father, TKAHuman *mother, TKAGender gender);

extern
void TKAHumanAddChild(TKAHuman *parent, TKAHuman *child);

extern
void TKAHumanMarry(TKAHuman *humanMale, TKAHuman *humanFemale);

extern
void TKAHumanDivorcePartner(TKAHuman *human);

extern
void TKAHumanDivorce(TKAHuman *partner1, TKAHuman *partner2);

extern
void TKAHumanRemoveChild(TKAHuman *parent, TKAHuman *child);

extern
void TKAHumanRemoveAllChildren(TKAHuman *parent);

extern
void __TKAHumanDeallocate(TKAHuman *human);

#endif /* defined(__TKASecondWeek__TKAHuman__) */
