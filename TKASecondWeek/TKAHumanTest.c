//
//  TKAHumanTest.c
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAHumanTest.h"
#include <assert.h>

#pragma mark -
#pragma mark Private Declarations

static
void TKAHumanTest();

static
void TKAHumanOutput(TKAHuman *human);

static
void TKAHumanCreatTest();

static
void TKAHumanMarryDivorceTest();

static
void TKAHumanChildTest();

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
    printf("reference count = %llu, ", TKAObjectGetReferenceCount(human));
    printf("reference count name = %llu, ", TKAObjectGetReferenceCount(human->_name));
    printf("reference count array = %llu, ", TKAObjectGetReferenceCount(human->_children));
    
    printf(" \n");
}

void TKAHumanCreatTest() {
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHumanOutput(man1);
    
    assert(NULL != TKAHumanGetChildren(man1));
    assert(35 == TKAHumanGetAge(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(1 == TKAObjectGetReferenceCount(man1->_name));
    assert(1 == TKAObjectGetReferenceCount(man1->_children));
    assert(1 == TKAObjectGetReferenceCount(man1));
    printf("\n");
    
    TKAHuman *woman1 = TKAHumanCreate(20, TKAFemale);
    TKAHumanOutput(woman1);
    assert(NULL == TKAHumanGetName(woman1));
    
    TKAHumanChangeName(woman1, "woman1");
    TKAHumanOutput(woman1);
    assert(NULL != TKAHumanGetName(woman1));
    printf("\n");
    
    TKAHumanChangeName(woman1, "woman1name2");
    TKAHumanOutput(woman1);
    
//    TKAHumanChangeName(man1, "man1name2");
//    TKAHumanOutput(man1);
    
    TKAObjectRelease(woman1);
    TKAObjectRelease(man1);
    assert(0 == TKAObjectGetReferenceCount(man1->_name));
    assert(0 == TKAObjectGetReferenceCount(man1->_children));
    assert(0 == TKAObjectGetReferenceCount(man1));
}

void TKAHumanMarryDivorceTest() {
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHuman *woman1 = TKAHumanCreateWithNameChar("woman1", 35, TKAFemale);
    TKAHuman *man2 = TKAHumanCreateWithNameChar("man2", 20, TKAMale);
    TKAHuman *woman2 = TKAHumanCreateWithNameChar("woman2", 20, TKAFemale);
    
    TKAHumanMarry(man1, woman1);
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    assert(man1 == TKAHumanGetPartner(woman1));
    assert(woman1 == TKAHumanGetPartner(man1));
    assert(2 == TKAObjectGetReferenceCount(man1));
    assert(2 == TKAObjectGetReferenceCount(woman1));
    printf("\n");
    
    TKAHumanMarry(man1, woman2);
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
    assert(man1 == TKAHumanGetPartner(woman2));
    assert(woman2 == TKAHumanGetPartner(man1));
    assert(NULL == TKAHumanGetPartner(woman1));
    assert(2 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(2 == TKAObjectGetReferenceCount(woman2));
    printf("\n");
    
    TKAHumanMarry(man1, man2);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
    assert(man1 == TKAHumanGetPartner(woman2));
    assert(woman2 == TKAHumanGetPartner(man1));
    assert(NULL == TKAHumanGetPartner(woman1));
    assert(NULL == TKAHumanGetPartner(man2));
    assert(2 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(2 == TKAObjectGetReferenceCount(woman2));
    assert(1 == TKAObjectGetReferenceCount(man2));
    printf("\n");
    
    TKAHumanMarry(man1, NULL);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
    assert(man1 == TKAHumanGetPartner(woman2));
    assert(woman2 == TKAHumanGetPartner(man1));
    assert(NULL == TKAHumanGetPartner(woman1));
    assert(NULL == TKAHumanGetPartner(man2));
    assert(2 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(2 == TKAObjectGetReferenceCount(woman2));
    assert(1 == TKAObjectGetReferenceCount(man2));
    printf("\n");
    
    TKAHumanDivorce(man1);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
    assert(NULL == TKAHumanGetPartner(woman2));
    assert(NULL == TKAHumanGetPartner(man1));
    assert(NULL == TKAHumanGetPartner(woman1));
    assert(NULL == TKAHumanGetPartner(man2));
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(1 == TKAObjectGetReferenceCount(woman2));
    assert(1 == TKAObjectGetReferenceCount(man2));
    printf("\n");

    TKAHumanMarry(man1, NULL);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
    assert(NULL == TKAHumanGetPartner(woman2));
    assert(NULL == TKAHumanGetPartner(man1));
    assert(NULL == TKAHumanGetPartner(woman1));
    assert(NULL == TKAHumanGetPartner(man2));
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(1 == TKAObjectGetReferenceCount(woman2));
    assert(1 == TKAObjectGetReferenceCount(man2));
    printf("\n");
    
    TKAObjectRelease(woman1);
    TKAObjectRelease(man1);
    TKAObjectRelease(woman2);
    TKAObjectRelease(man2);
//    assert(0 == TKAObjectGetReferenceCount(man1));
//    assert(0 == TKAObjectGetReferenceCount(woman1));
//    assert(0 == TKAObjectGetReferenceCount(woman2));
//    assert(0 == TKAObjectGetReferenceCount(man2));
}

void TKAHumanChildTest() {
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHuman *woman1 = TKAHumanCreateWithNameChar("woman1", 35, TKAFemale);
    TKAHuman *man2 = TKAHumanCreateWithNameChar("man2", 20, TKAMale);
    TKAHuman *woman2 = TKAHumanCreateWithNameChar("woman2", 20, TKAFemale);
    TKAHuman *childM1 = TKAHumanCreateWithNameChar("childM1", 10, TKAMale);
    TKAHuman *childF1 = TKAHumanCreateWithNameChar("childF1", 10, TKAFemale);
    TKAHuman *childM2 = TKAHumanCreateWithNameChar("childM2", 5, TKAMale);
    TKAHuman *childF2 = TKAHumanCreateWithNameChar("childF2", 5, TKAFemale);

    
    
    TKAObjectRelease(childM1);
    TKAObjectRelease(childF1);
    TKAObjectRelease(childM2);
    TKAObjectRelease(childF2);
    TKAObjectRelease(woman1);
    TKAObjectRelease(man1);
    TKAObjectRelease(woman2);
    TKAObjectRelease(man2);
}

void TKAHumanTest() {
//    TKAHumanCreatTest();
//    printf("\n");
//    printf("\n");
//    TKAHumanMarryDivorceTest();
//    printf("\n");
//    printf("\n");
    TKAHumanChildTest();
    
    
    
    
    
    
//
//    TKAString *stringGod = TKAStringCreateTest("God");
//    TKAString *stringAdam = TKAStringCreateTest("Adam");
//    TKAString *stringEve = TKAStringCreateTest("Eve");
//    TKAString *stringSon1 = TKAStringCreateTest("Son1");
//    TKAString *stringSon2 = TKAStringCreateTest("Son2");
//    
//    TKAHuman *god = TKAHumanCreateTest(stringGod, 100, TKAMale);
//    TKAHuman *adam = TKAHumanCreateTest(stringAdam, 30, TKAMale);
//    TKAHuman *eve = TKAHumanCreateTest(stringEve, 25, TKAFemale);
//    
//    TKAHumanOutput(god);
//    TKAHumanOutput(adam);
//    TKAHumanOutput(eve);
//    printf(" \n");
//    
//    TKAHumanMarry(adam, eve);
//    
//    TKAHumanOutput(god);
//    TKAHumanOutput(adam);
//    TKAHumanOutput(eve);
//    printf(" \n");
//    
//    TKAHumanDivorce(eve);
//    
//    TKAHumanOutput(god);
//    TKAHumanOutput(adam);
//    TKAHumanOutput(eve);
//    printf(" \n");
//    
//    TKAHumanMarry(god, eve);
//    
//    TKAHumanOutput(god);
//    TKAHumanOutput(adam);
//    TKAHumanOutput(eve);
//    printf(" \n");
//    
//    //    TKAHumanDivorce(adam, eve);
//    //
//    //    TKAHumanOutput(god);
//    //    TKAHumanOutput(adam);
//    //    TKAHumanOutput(eve);
//    //    printf(" \n");
//    
////    TKAHumanDivorce(god, eve);
//    
//    TKAHumanOutput(god);
//    TKAHumanOutput(adam);
//    TKAHumanOutput(eve);
//    printf(" \n");
//    
//    TKAHuman *son1 = TKAHumanBorn(adam, eve, TKAMale);
//  //  TKAHumanSetName(son1, stringSon1);
//    
//    TKAHumanOutput(son1);
//    TKAHumanOutput(god);
//    TKAHumanOutput(adam);
//    TKAHumanOutput(eve);
//    printf(" \n");
//    
//    TKAHuman *son2 = TKAHumanBorn(god, eve, TKAMale);
//  //  TKAHumanSetName(son2, stringSon2);
//    
//    TKAHumanOutput(son1);
//    TKAHumanOutput(son2);
//    TKAHumanOutput(god);
//    TKAHumanOutput(adam);
//    TKAHumanOutput(eve);
//    
//    TKAObjectRelease(son1);
//    TKAObjectRelease(son2);
//    TKAObjectRelease(god);
//    TKAObjectRelease(adam);
//    TKAObjectRelease(eve);
//    
//    TKAObjectRelease(stringSon1);
//    TKAObjectRelease(stringSon2);
//    TKAObjectRelease(stringGod);
//    TKAObjectRelease(stringAdam);
//    TKAObjectRelease(stringEve);
}

#pragma mark -
#pragma mark Public Implementations

void TKAHumanTestMain(){
    
    TKAHumanTest();
}
