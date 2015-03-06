//
//  TKAHumanStructTest.c
//  TKASecondWeek
//
//  Created by Taisiya on 17.02.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAHumanStructTest.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKAHumanStructKillTest(TKAHumanStruct *human);

static
void TKAHumanStructTest();

static
void TKAHumanStructOutput(TKAHumanStruct *human);

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

void TKAHumanStructOutput(TKAHumanStruct *human) {
    
    TKAStringStructOutput(TKAHumanStructGetName(human));
    printf(" ");
    printf("age = %d, ",TKAHumanStructGetAge(human));
    printf("gender = %d, ", TKAHumanStructGetGender(human));
    printf("count children = %d, ", TKAHumanStructGetCountChildren(human));
    
    if (NULL != TKAHumanStructGetPartner(human)) {
        printf("partner = ");
        TKAStringStructOutput(TKAHumanStructGetName(TKAHumanStructGetPartner(human)));
        printf(", ");
    }
    
    if (NULL != TKAHumanStructGetFather(human)) {
        printf("father = ");
        TKAStringStructOutput(TKAHumanStructGetName(TKAHumanStructGetFather(human)));
        printf(", ");
    }
    
    if (NULL != TKAHumanStructGetMother(human)) {
        printf("motner = ");
        TKAStringStructOutput(TKAHumanStructGetName(TKAHumanStructGetMother(human)));
        printf(", ");
    }
    
    if (NULL != TKAHumanStructGetChildren(human)) {
        printf("children: ");
        TKAArrayStructOutput(TKAHumanStructGetChildren(human));
    }
    
       printf(" \n");
}

TKAHumanStruct *TKAHumanStructCreateTest(TKAStringStruct *name, uint8_t age, TKAGenderStruct gender) {

    TKAHumanStruct *human = TKAHumanStructCreate();

    TKAHumanStructSetName(human, name);
    TKAHumanStructSetAge(human, age);
    TKAHumanStructSetGender(human, gender);
    
    return human;
}

void TKAHumanStructKillTest(TKAHumanStruct *human) {
    TKAHumanStructRelease(human);
}

void TKAHumanStructTest() {
    
    TKAStringStruct *stringGod = TKAStringStructCreateTest("God");
    TKAStringStruct *stringAdam = TKAStringStructCreateTest("Adam");
    TKAStringStruct *stringEve = TKAStringStructCreateTest("Eve");
    TKAStringStruct *stringSon1 = TKAStringStructCreateTest("Son1");
    TKAStringStruct *stringSon2 = TKAStringStructCreateTest("Son2");

    TKAHumanStruct *god = TKAHumanStructCreateTest(stringGod, 100, TKAMaleStruct);
    TKAHumanStruct *adam = TKAHumanStructCreateTest(stringAdam, 30, TKAMaleStruct);
    TKAHumanStruct *eve = TKAHumanStructCreateTest(stringEve, 25, TKAFemaleStruct);
    
    TKAHumanStructOutput(god);
    TKAHumanStructOutput(adam);
    TKAHumanStructOutput(eve);
    printf(" \n");

    TKAHumanStructMarry(adam, eve);
    
    TKAHumanStructOutput(god);
    TKAHumanStructOutput(adam);
    TKAHumanStructOutput(eve);
    printf(" \n");
    
    TKAHumanStructDivorcePartner(eve);
    
    TKAHumanStructOutput(god);
    TKAHumanStructOutput(adam);
    TKAHumanStructOutput(eve);
    printf(" \n");
    
    TKAHumanStructMarry(god, eve);
    
    TKAHumanStructOutput(god);
    TKAHumanStructOutput(adam);
    TKAHumanStructOutput(eve);
    printf(" \n");

//    TKAHumanStructDivorce(adam, eve);
//    
//    TKAHumanStructOutput(god);
//    TKAHumanStructOutput(adam);
//    TKAHumanStructOutput(eve);
//    printf(" \n");
    
    TKAHumanStructDivorce(god, eve);
    
    TKAHumanStructOutput(god);
    TKAHumanStructOutput(adam);
    TKAHumanStructOutput(eve);
    printf(" \n");
    
    TKAHumanStruct *son1 = TKAHumanStructBorn(adam, eve, TKAMaleStruct);
    TKAHumanStructSetName(son1, stringSon1);

    TKAHumanStructOutput(son1);
    TKAHumanStructOutput(god);
    TKAHumanStructOutput(adam);
    TKAHumanStructOutput(eve);
    printf(" \n");
    
    TKAHumanStruct *son2 = TKAHumanStructBorn(god, eve, TKAMaleStruct);
    TKAHumanStructSetName(son2, stringSon2);
    
    TKAHumanStructOutput(son1);
    TKAHumanStructOutput(son2);
    TKAHumanStructOutput(god);
    TKAHumanStructOutput(adam);
    TKAHumanStructOutput(eve);
    
    TKAHumanStructKillTest(son1);
    TKAHumanStructKillTest(son2);
    TKAHumanStructKillTest(god);
    TKAHumanStructKillTest(adam);
    TKAHumanStructKillTest(eve);
    
    TKAStringStructKillTest(stringSon1);
    TKAStringStructKillTest(stringSon2);
    TKAStringStructKillTest(stringGod);
    TKAStringStructKillTest(stringAdam);
    TKAStringStructKillTest(stringEve);
}

#pragma mark -
#pragma mark Public Implementations

void TKAHumanStructTestMain(){
  
     TKAHumanStructTest();
}