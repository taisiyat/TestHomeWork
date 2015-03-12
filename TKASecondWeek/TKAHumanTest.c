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
void TKAHumanCreatTest();

static
void TKAHumanMarryDivorceTest();

static
void TKAHumanChildBirthTest();

static
void TKAHumanChildTest();

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

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
    assert(1 == TKAObjectGetReferenceCount(man1->_name));
    assert(1 == TKAObjectGetReferenceCount(man1->_children));
    assert(1 == TKAObjectGetReferenceCount(man1));
    
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

void TKAHumanChildBirthTest() {
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHuman *woman1 = TKAHumanCreateWithNameChar("woman1", 35, TKAFemale);
    TKAHuman *newBorn1 = TKAHumanBirth(man1, woman1, TKAMale);
    
    TKAHumanOutput(man1);
    printf(" \n");
    TKAHumanOutput(woman1);
    printf(" \n");
    TKAHumanOutput(newBorn1);
    printf(" \n");
    printf("///////////////////////////// \n");
    printf(" \n");
    
    TKAHumanChangeName(newBorn1, "newborn1");
    
    TKAHumanOutput(man1);
    printf(" \n");
    TKAHumanOutput(woman1);
    printf(" \n");
    TKAHumanOutput(newBorn1);
    printf(" \n");
    printf("/////////////////////////// \n");
    printf(" \n");
    
    TKAHuman *newBorn2 = TKAHumanBirth(NULL, woman1, TKAFemale);
    TKAHumanChangeName(newBorn2, "newborn2");
    
    TKAHumanOutput(man1);
    printf(" \n");
    TKAHumanOutput(woman1);
    printf(" \n");
    TKAHumanOutput(newBorn2);
    printf(" \n");
    printf("///////////////////////// \n");
    printf(" \n");
    
    TKAHuman *newBorn4 = TKAHumanBirth(man1, NULL, TKAFemale);
    TKAHumanChangeName(newBorn4, "newborn4");
    
    TKAHumanOutput(man1);
    printf(" \n");
    TKAHumanOutput(woman1);
    printf(" \n");
    TKAHumanOutput(newBorn4);
    printf(" \n");
    printf("///////////////////////// \n");
    printf(" \n");
    
    TKAHuman *newBorn3 = TKAHumanBirth(NULL, NULL, TKAFemale);
    
    TKAHumanOutput(man1);
    printf(" \n");
    TKAHumanOutput(woman1);
    printf(" \n");
    printf("/////////////////////////// \n");
    printf(" \n");
    
    TKAObjectRelease(woman1);
    TKAObjectRelease(man1);
}

# define TKAHumanBirthChildNumber(number) \
        TKAHuman *newBorn##number = TKAHumanBirth(man1, woman1, TKAFemale);\
        TKAHumanChangeName(newBorn##number, "newborn"#number" ");\
//        TKAHumanOutput(newBorn##number);\
//        printf(" \n");

void TKAHumanChildTest() {
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHuman *woman1 = TKAHumanCreateWithNameChar("woman1", 35, TKAFemale);
    TKAHuman *man2 = TKAHumanCreateWithNameChar("man2", 20, TKAMale);
    TKAHuman *woman2 = TKAHumanCreateWithNameChar("woman2", 20, TKAFemale);
    TKAHuman *childM1 = TKAHumanCreateWithNameChar("childM1", 10, TKAMale);
    TKAHuman *childF1 = TKAHumanCreateWithNameChar("childF1", 10, TKAFemale);
    TKAHuman *childM2 = TKAHumanCreateWithNameChar("childM2", 5, TKAMale);
    TKAHuman *childF2 = TKAHumanCreateWithNameChar("childF2", 5, TKAFemale);
    
    TKAHumanBirthChildNumber(1);
    TKAHumanBirthChildNumber(2);
    TKAHumanBirthChildNumber(3);
    TKAHumanBirthChildNumber(4);
    TKAHumanBirthChildNumber(5);
    TKAHumanBirthChildNumber(6);
    TKAHumanBirthChildNumber(7);
    TKAHumanBirthChildNumber(8);
    TKAHumanOutput(man1);
    printf(" \n");
    TKAHumanOutput(woman1);
    printf(" \n");
    TKAHumanOutput(newBorn5);
    printf(" \n");
    printf("/////////////////////////////// \n");
    printf(" \n");
    
    TKAHumanAddChild(man1, childM1);
    TKAHumanOutput(man1);
    printf(" \n");
    TKAHumanOutput(childM1);
    printf(" \n");
    printf(" \n");
    printf("/////////////////////////////// \n");
    printf(" \n");
    
    TKAHumanAddChild(man1, childM1);
    TKAHumanOutput(man1);
    printf(" \n");
    TKAHumanOutput(childM1);
    printf(" \n");
    printf(" \n");
    printf("/////////////////////////////// \n");
    printf(" \n");
    
    TKAHumanAddChild(man1, NULL);
    TKAHumanOutput(man1);
    printf(" \n");
    TKAHumanOutput(childM1);
    printf(" \n");
    printf(" \n");
    printf("/////////////////////////////// \n");
    printf(" \n");
    
    TKAHumanAddChild(NULL, childF2);
    TKAHumanOutput(man1);
    printf(" \n");
    TKAHumanOutput(childF2);
    printf(" \n");
    printf(" \n");
    printf("/////////////////////////////// \n");
    printf(" ????????????????????????????\n");
    
    TKAHumanRemoveChild(man1, newBorn5);
    TKAHumanOutput(man1);
    printf(" \n");
    TKAHumanOutput(newBorn5);
    printf(" \n");
    printf(" ??????????????????????????\n");
    printf("/////////////////////////////// \n");
    printf(" \n");
    
    
    TKAHumanRemoveChild(woman1, newBorn5);
    TKAHumanOutput(woman1);
    printf(" \n");
    TKAHumanOutput(newBorn5);
    printf(" \n");
    printf(" \n");
    printf("/////////////////////////////// \n");
    printf(" \n");
 ///////////////////
    TKAHumanAddChild(woman1, childM1);
    TKAHumanOutput(woman1);
    printf(" \n");
    TKAHumanOutput(childM1);
    printf(" \n");
    printf(" \n");
    printf("/////////////////////////////// \n");
    printf(" \n");
    
    TKAHumanRemoveChild(woman1, childM1);
    TKAHumanOutput(woman1);
    printf(" \n");
    TKAHumanOutput(childM1);
    printf(" \n");
    printf(" \n");
    printf("/////////////////////////////// \n");
    printf(" \n");

 //////////////////
    TKAHumanRemoveAllChildren(woman1);
    TKAHumanOutput(woman1);
    printf(" \n");
    TKAHumanRemoveAllChildren(man1);
    TKAHumanOutput(man1);
    printf(" \n");
  
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
    TKAHumanCreatTest();
    printf("\n");
    printf("\n");
//   TKAHumanMarryDivorceTest();
//    printf("\n");
//    printf("\n");
//    
//  TKAHumanChildBirthTest();
//    printf("\n");
//        printf("\n");
//    
//   TKAHumanChildTest();
}

#pragma mark -
#pragma mark Public Implementations

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

void TKAHumanTestMain(){
    
    TKAHumanTest();
}
