//
//  TKAHumanTest.c
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAHumanTest.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKAHumanTest();

static
void TKAHumanOutput(TKAHuman *human);

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

void TKAHumanOutput(TKAHuman *human) {
    
    TKAStringOutput(TKAHumanGetName(human));
    printf(" ");
    printf("age = %d, ",TKAHumanGetAge(human));
    printf("gender = %d, ", TKAHumanGetGender(human));
    printf("count children = %d, ", TKAHumanGetChildCount(human));
    
    if (NULL != TKAHumanGetPartner(human)) {
        printf("partner = ");
        TKAStringOutput(TKAHumanGetName(TKAHumanGetPartner(human)));
        printf(", ");
    }
    
    if (NULL != TKAHumanGetFather(human)) {
        printf("father = ");
        TKAStringOutput(TKAHumanGetName(TKAHumanGetFather(human)));
        printf(", ");
    }
    
    if (NULL != TKAHumanGetMother(human)) {
        printf("motner = ");
        TKAStringOutput(TKAHumanGetName(TKAHumanGetMother(human)));
        printf(", ");
    }
    
    if (NULL != TKAHumanGetChildren(human)) {
        printf("children: ");
        TKAArrayOutput(TKAHumanGetChildren(human));
    }
    
    printf(" \n");
}

TKAHuman *TKAHumanCreateTest(TKAString *name, uint8_t age, TKAGender gender) {
    
    TKAHuman *human = TKAObjectCreate(TKAHuman);
    
    TKAHumanSetName(human, name);
    TKAHumanSetAge(human, age);
    TKAHumanSetGender(human, gender);
    
    return human;
}


void TKAHumanTest() {
    
    TKAString *stringGod = TKAStringCreateTest("God");
    TKAString *stringAdam = TKAStringCreateTest("Adam");
    TKAString *stringEve = TKAStringCreateTest("Eve");
    TKAString *stringSon1 = TKAStringCreateTest("Son1");
    TKAString *stringSon2 = TKAStringCreateTest("Son2");
    
    TKAHuman *god = TKAHumanCreateTest(stringGod, 100, TKAMale);
    TKAHuman *adam = TKAHumanCreateTest(stringAdam, 30, TKAMale);
    TKAHuman *eve = TKAHumanCreateTest(stringEve, 25, TKAFemale);
    
    TKAHumanOutput(god);
    TKAHumanOutput(adam);
    TKAHumanOutput(eve);
    printf(" \n");
    
    TKAHumanMarry(adam, eve);
    
    TKAHumanOutput(god);
    TKAHumanOutput(adam);
    TKAHumanOutput(eve);
    printf(" \n");
    
    TKAHumanDivorcePartner(eve);
    
    TKAHumanOutput(god);
    TKAHumanOutput(adam);
    TKAHumanOutput(eve);
    printf(" \n");
    
    TKAHumanMarry(god, eve);
    
    TKAHumanOutput(god);
    TKAHumanOutput(adam);
    TKAHumanOutput(eve);
    printf(" \n");
    
    //    TKAHumanDivorce(adam, eve);
    //
    //    TKAHumanOutput(god);
    //    TKAHumanOutput(adam);
    //    TKAHumanOutput(eve);
    //    printf(" \n");
    
    TKAHumanDivorce(god, eve);
    
    TKAHumanOutput(god);
    TKAHumanOutput(adam);
    TKAHumanOutput(eve);
    printf(" \n");
    
    TKAHuman *son1 = TKAHumanBorn(adam, eve, TKAMale);
    TKAHumanSetName(son1, stringSon1);
    
    TKAHumanOutput(son1);
    TKAHumanOutput(god);
    TKAHumanOutput(adam);
    TKAHumanOutput(eve);
    printf(" \n");
    
    TKAHuman *son2 = TKAHumanBorn(god, eve, TKAMale);
    TKAHumanSetName(son2, stringSon2);
    
    TKAHumanOutput(son1);
    TKAHumanOutput(son2);
    TKAHumanOutput(god);
    TKAHumanOutput(adam);
    TKAHumanOutput(eve);
    
    TKAObjectRelease(son1);
    TKAObjectRelease(son2);
    TKAObjectRelease(god);
    TKAObjectRelease(adam);
    TKAObjectRelease(eve);
    
    TKAObjectRelease(stringSon1);
    TKAObjectRelease(stringSon2);
    TKAObjectRelease(stringGod);
    TKAObjectRelease(stringAdam);
    TKAObjectRelease(stringEve);
}

#pragma mark -
#pragma mark Public Implementations

void TKAHumanTestMain(){
    
    TKAHumanTest();
}
