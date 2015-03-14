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
#pragma mark Public Declarations

#pragma mark -
#pragma mark Private Declarations

static
void TKAHumanChangeName();

static
void TKAHumanTest();

static
void TKAHumanCreatTest();

static
void TKAHumanMarryDivorceTest();

static
void TKAHumanGiveBirthtChildTest();

static
void TKAHumanAddRemoveChildTest();

#pragma mark -
#pragma mark Privat Implementations

void TKAHumanChangeName(TKAHuman *human, char *name) {
    if (NULL != human && NULL != name) {
        TKAString *newName = TKAObjectCreate(TKAString);
        TKAStringSetData(newName, name);
        TKAHumanSetName(human, newName);
        TKAObjectRelease(newName);
    }
}

void TKAHumanCreatTest() {
    
    TKAHuman *testHuman = TKAHumanCreate(20, TKAMale);
    assert(NULL != TKAHumanGetChildren(testHuman));
    assert(NULL == TKAHumanGetName(testHuman));
    assert(20 == TKAHumanGetAge(testHuman));
    assert(TKAMale == TKAHumanGetGender(testHuman));
    assert(0 == TKAObjectGetReferenceCount(TKAHumanGetName(testHuman)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGetChildren(testHuman)));
    assert(1 == TKAObjectGetReferenceCount(testHuman));
    
    char *newName = "NewHuman";
    TKAString *testName = TKAObjectCreate(TKAString);
    TKAStringSetData(testName, newName);
    assert(1 == TKAObjectGetReferenceCount(testName));
    
    TKAHumanSetName(testHuman, testName);
    assert(NULL != TKAHumanGetChildren(testHuman));
    assert(testName == TKAHumanGetName(testHuman));
    assert(20 == TKAHumanGetAge(testHuman));
    assert(TKAMale == TKAHumanGetGender(testHuman));
    assert(2 == TKAObjectGetReferenceCount(TKAHumanGetName(testHuman)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGetChildren(testHuman)));
    assert(1 == TKAObjectGetReferenceCount(testHuman));
    
    TKAObjectRelease(testName);
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGetName(testHuman)));
    
    TKAObjectRelease(testHuman);
    
    char *charNameWoman = "NewWoman";
    TKAString *nameWoman = TKAObjectCreate(TKAString);
    TKAStringSetData(nameWoman, charNameWoman);
    assert(1 == TKAObjectGetReferenceCount(nameWoman));
    
    TKAHuman *woman = TKAHumanCreateWithNameString(nameWoman, 20, TKAFemale);
    assert(NULL != TKAHumanGetChildren(woman));
    assert(nameWoman == TKAHumanGetName(woman));
    assert(20 == TKAHumanGetAge(woman));
    assert(TKAFemale == TKAHumanGetGender(woman));
    assert(2 == TKAObjectGetReferenceCount(TKAHumanGetName(woman)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGetChildren(woman)));
    assert(1 == TKAObjectGetReferenceCount(woman));
    
    TKAObjectRelease(nameWoman);
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGetName(woman)));
    
    TKAObjectRelease(woman);
    
    TKAHuman *man = TKAHumanCreateWithNameChar("man", 35, TKAMale);
    assert(NULL != TKAHumanGetChildren(man));
    assert(NULL != TKAHumanGetName(man));
    assert(35 == TKAHumanGetAge(man));
    assert(TKAMale == TKAHumanGetGender(man));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGetName(man)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGetChildren(man)));
    assert(1 == TKAObjectGetReferenceCount(man));
    TKAObjectRelease(man);
}

void TKAHumanMarryDivorceTest() {
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHuman *woman1 = TKAHumanCreateWithNameChar("woman1", 35, TKAFemale);
    TKAHuman *man2 = TKAHumanCreateWithNameChar("man2", 20, TKAMale);
    TKAHuman *woman2 = TKAHumanCreateWithNameChar("woman2", 20, TKAFemale);
    
    TKAHumanMarry(man1, woman1);
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    printf("\n");
    
    TKAHumanMarry(woman1, man2);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
    printf("\n");
    
    TKAHumanMarry(woman2, man2);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
    printf("\n");
    
    TKAHumanMarry(man1, NULL);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
//    assert(man1 == TKAHumanGetPartner(woman2));
//    assert(woman2 == TKAHumanGetPartner(man1));
//    assert(NULL == TKAHumanGetPartner(woman1));
//    assert(NULL == TKAHumanGetPartner(man2));
//    assert(2 == TKAObjectGetReferenceCount(man1));
//    assert(1 == TKAObjectGetReferenceCount(woman1));
//    assert(2 == TKAObjectGetReferenceCount(woman2));
//    assert(1 == TKAObjectGetReferenceCount(man2));
    printf("\n");
    
    TKAHumanDivorce(man2);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
    printf("\n");

    TKAHumanDivorce(woman1);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
    //    assert(NULL == TKAHumanGetPartner(woman2));
    //    assert(NULL == TKAHumanGetPartner(man1));
    //    assert(NULL == TKAHumanGetPartner(woman1));
    //    assert(NULL == TKAHumanGetPartner(man2));
    //    assert(1 == TKAObjectGetReferenceCount(man1));
    //    assert(1 == TKAObjectGetReferenceCount(woman1));
    //    assert(1 == TKAObjectGetReferenceCount(woman2));
    //    assert(1 == TKAObjectGetReferenceCount(man2));
    printf("\n");

    TKAHumanDivorce(woman2);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
      printf("\n");
    
    
    TKAHumanMarry(NULL, woman1);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
        printf("\n");

    
    TKAHumanMarry(man1, NULL);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);

    printf("\n");
    
    TKAHumanMarry(man1, woman1);
    TKAHumanMarry(man2, woman2);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
    //    assert(NULL == TKAHumanGetPartner(woman2));
    //    assert(NULL == TKAHumanGetPartner(man1));
    //    assert(NULL == TKAHumanGetPartner(woman1));
    //    assert(NULL == TKAHumanGetPartner(man2));
    //    assert(1 == TKAObjectGetReferenceCount(man1));
    //    assert(1 == TKAObjectGetReferenceCount(woman1));
    //    assert(1 == TKAObjectGetReferenceCount(woman2));
    //    assert(1 == TKAObjectGetReferenceCount(man2));
    printf("\n");
    
    TKAHumanMarry(man2, woman1);
//    TKAHumanMarry(man2, woman2);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
       printf("\n");

    TKAHumanDivorce(man2);
    TKAHumanDivorce(woman1);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
       printf("\n");
    TKAHumanDivorce(woman2);
    TKAHumanDivorce(woman1);
    TKAHumanOutput(man1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman1);
    TKAHumanOutput(woman2);
    
    TKAObjectRelease(woman1);
    TKAObjectRelease(man1);
    TKAObjectRelease(woman2);
    TKAObjectRelease(man2);
//    assert(0 == TKAObjectGetReferenceCount(man1));
//    assert(0 == TKAObjectGetReferenceCount(woman1));
//    assert(0 == TKAObjectGetReferenceCount(woman2));
//    assert(0 == TKAObjectGetReferenceCount(man2));
}

void TKAHumanGiveBirthtChildTest() {
    
    TKAHuman *man = TKAHumanCreateWithNameChar("man", 35, TKAMale);
    TKAHuman *woman = TKAHumanCreateWithNameChar("woman", 35, TKAFemale);
    assert(NULL != man);
    assert(NULL != TKAHumanGetChildren(man));
    assert(0 == TKAHumanGetChildCount(man));
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 0));
    
    assert(NULL != woman);
    assert(NULL != TKAHumanGetChildren(woman));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(0 == TKAHumanGetChildCount(woman));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 0));
    
    TKAHuman *newBorn1 = TKAHumanGiveBirth(man, woman, TKAMale);
    TKAHumanChangeName(newBorn1, "newborn1");
    assert(2 == TKAObjectGetReferenceCount(man));
    assert(1 == TKAHumanGetChildCount(man));
    assert(newBorn1 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 0));
    assert(2 == TKAObjectGetReferenceCount(woman));
    assert(1 == TKAHumanGetChildCount(woman));
    assert(newBorn1 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 0));
    assert(NULL != newBorn1);
    assert(2 == TKAObjectGetReferenceCount(newBorn1));
    assert(0 == TKAHumanGetChildCount(newBorn1));
    assert(man == TKAHumanGetFather(newBorn1));
    assert(woman == TKAHumanGetMother(newBorn1));
    
    
    TKAHuman *newBorn2 = TKAHumanGiveBirth(NULL, woman, TKAFemale);
    TKAHumanChangeName(newBorn2, "newborn2");
    
    assert(2 == TKAObjectGetReferenceCount(man));
    assert(1 == TKAHumanGetChildCount(man));
    assert(newBorn1 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 0));
    assert(newBorn2 != TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 0));
    assert(3 == TKAObjectGetReferenceCount(woman));
    assert(2 == TKAHumanGetChildCount(woman));
    assert(newBorn1 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 0));
    assert(newBorn2 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 1));
    assert(NULL != newBorn2);
    assert(1 == TKAObjectGetReferenceCount(newBorn2));
    assert(0 == TKAHumanGetChildCount(newBorn2));
    assert(NULL == TKAHumanGetFather(newBorn2));
    assert(woman == TKAHumanGetMother(newBorn2));
    
    TKAHuman *newBorn3 = TKAHumanGiveBirth(man, NULL, TKAFemale);
    TKAHumanChangeName(newBorn3, "newborn3");
    
    assert(3 == TKAObjectGetReferenceCount(man));
    assert(2 == TKAHumanGetChildCount(man));
    assert(newBorn1 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 0));
    assert(newBorn3 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 1));
    assert(3 == TKAObjectGetReferenceCount(woman));
    assert(2 == TKAHumanGetChildCount(woman));
    assert(newBorn1 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 0));
    assert(newBorn2 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 1));
    assert(NULL != newBorn3);
    assert(1 == TKAObjectGetReferenceCount(newBorn3));
    assert(0 == TKAHumanGetChildCount(newBorn3));
    assert(man == TKAHumanGetFather(newBorn3));
    assert(NULL == TKAHumanGetMother(newBorn3));

    TKAHuman *newBorn4 = TKAHumanGiveBirth(NULL, NULL, TKAFemale);
    assert(NULL == newBorn4);
    assert(3 == TKAObjectGetReferenceCount(man));
    assert(2 == TKAHumanGetChildCount(man));
    assert(newBorn1 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 0));
    assert(newBorn3 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 1));
    assert(3 == TKAObjectGetReferenceCount(woman));
    assert(2 == TKAHumanGetChildCount(woman));
    assert(newBorn1 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 0));
    assert(newBorn2 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 1));
    assert(NULL == newBorn4);
    assert(0 == TKAObjectGetReferenceCount(newBorn4));


    TKAObjectRelease(newBorn4);
    TKAObjectRelease(newBorn3);
    TKAObjectRelease(newBorn2);
    TKAObjectRelease(newBorn1);
    TKAObjectRelease(woman);
    TKAObjectRelease(man);
}

# define TKAHumanBirthChildNumber(number) \
        TKAHuman *newBorn##number = TKAHumanGiveBirth(man, woman, TKAFemale);\
        TKAHumanChangeName(newBorn##number, "newborn"#number" ");\

void TKAHumanAddRemoveChildTest() {
    
    TKAHuman *man = TKAHumanCreateWithNameChar("man", 35, TKAMale);
    TKAHuman *woman = TKAHumanCreateWithNameChar("woman", 35, TKAFemale);
    TKAHuman *childMale = TKAHumanCreateWithNameChar("childMale", 10, TKAMale);
    TKAHuman *childFemale = TKAHumanCreateWithNameChar("childFemale", 5, TKAFemale);
    
    assert(NULL != man);
    assert(NULL != TKAHumanGetChildren(man));
    assert(0 == TKAHumanGetChildCount(man));
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 0));
    
    assert(NULL != woman);
    assert(NULL != TKAHumanGetChildren(woman));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(0 == TKAHumanGetChildCount(woman));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 0));
    
    assert(NULL != childMale);
    assert(NULL != TKAHumanGetChildren(childMale));
    assert(1 == TKAObjectGetReferenceCount(childMale));
    assert(0 == TKAHumanGetChildCount(childMale));
    assert(NULL == TKAHumanGetFather(childMale));
    assert(NULL == TKAHumanGetMother(childMale));

    TKAHumanBirthChildNumber(0);
    TKAHumanBirthChildNumber(1);
    TKAHumanBirthChildNumber(2);
    TKAHumanBirthChildNumber(3);
    TKAHumanBirthChildNumber(4);
    TKAHumanBirthChildNumber(5);
    TKAHumanBirthChildNumber(6);
    TKAHumanBirthChildNumber(7);
    TKAHumanBirthChildNumber(8);
    assert(NULL != man);
    assert(NULL != TKAHumanGetChildren(man));
    assert(9 == TKAHumanGetChildCount(man));
    assert(10 == TKAObjectGetReferenceCount(man));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 9));
    assert(newBorn8 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 8));
    assert(newBorn0 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 0));

    assert(NULL != woman);
    assert(NULL != TKAHumanGetChildren(woman));
    assert(10 == TKAObjectGetReferenceCount(woman));
    assert(9 == TKAHumanGetChildCount(woman));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 9));
    assert(newBorn8 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 8));
    assert(newBorn0 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 0));
    
    assert(NULL != newBorn5);
    assert(2 == TKAObjectGetReferenceCount(newBorn5));
    assert(0 == TKAHumanGetChildCount(newBorn5));
    assert(man == TKAHumanGetFather(newBorn5));
    assert(woman == TKAHumanGetMother(newBorn5));
    
    TKAHumanAddChild(man, childMale);
    assert(NULL != childMale);
    assert(2 == TKAObjectGetReferenceCount(childMale));
    assert(0 == TKAHumanGetChildCount(childMale));
    assert(man == TKAHumanGetFather(childMale));
    assert(NULL == TKAHumanGetMother(childMale));

    assert(NULL != man);
    assert(NULL != TKAHumanGetChildren(man));
    assert(10 == TKAHumanGetChildCount(man));
    assert(11 == TKAObjectGetReferenceCount(man));
    assert(childMale == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 9));
    assert(NULL != TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 8));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 10));

    TKAHumanAddChild(man, childMale);
    assert(NULL != childMale);
    assert(2 == TKAObjectGetReferenceCount(childMale));
    assert(0 == TKAHumanGetChildCount(childMale));
    assert(man == TKAHumanGetFather(childMale));
    assert(NULL == TKAHumanGetMother(childMale));
    
    assert(NULL != man);
    assert(NULL != TKAHumanGetChildren(man));
    assert(10 == TKAHumanGetChildCount(man));
    assert(11 == TKAObjectGetReferenceCount(man));
    assert(childMale == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 9));
    assert(NULL != TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 8));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 10));
   
    TKAHumanAddChild(man, NULL);
    assert(NULL != man);
    assert(NULL != TKAHumanGetChildren(man));
    assert(10 == TKAHumanGetChildCount(man));
    assert(11 == TKAObjectGetReferenceCount(man));
    assert(childMale == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 9));
    assert(NULL != TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 8));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 10));
    
    TKAHumanAddChild(NULL, childFemale);
    assert(NULL != childFemale);
    assert(1 == TKAObjectGetReferenceCount(childFemale));
    assert(0 == TKAHumanGetChildCount(childFemale));
    assert(NULL == TKAHumanGetFather(childFemale));
    assert(NULL == TKAHumanGetMother(childFemale));
    
    TKAHumanRemoveChild(man, newBorn5);
    assert(NULL != man);
    assert(NULL != TKAHumanGetChildren(man));
    assert(9 == TKAHumanGetChildCount(man));
    assert(10 == TKAObjectGetReferenceCount(man));
    assert(newBorn4 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 4));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 5));
    assert(newBorn6 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 6));
    
    assert(NULL != newBorn5);
    assert(1 == TKAObjectGetReferenceCount(newBorn5));
    assert(0 == TKAHumanGetChildCount(newBorn5));
    assert(NULL == TKAHumanGetFather(newBorn5));
    assert(woman == TKAHumanGetMother(newBorn5));
    
    TKAHumanAddChild(man, childFemale);
    assert(NULL != man);
    assert(NULL != TKAHumanGetChildren(man));
    assert(10 == TKAHumanGetChildCount(man));
    assert(11 == TKAObjectGetReferenceCount(man));
    assert(newBorn4 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 4));
    assert(childFemale == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 5));
    assert(newBorn6 == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 6));
    
    assert(NULL != childFemale);
    assert(2 == TKAObjectGetReferenceCount(childFemale));
    assert(0 == TKAHumanGetChildCount(childFemale));
    assert(man == TKAHumanGetFather(childFemale));
    assert(NULL == TKAHumanGetMother(childFemale));

    
    TKAHumanRemoveAllChildren(man);
    assert(NULL != man);
    assert(NULL != TKAHumanGetChildren(man));
    assert(0 == TKAHumanGetChildCount(man));
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 9));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 8));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(man), 10));
    
    assert(1 == TKAObjectGetReferenceCount(childFemale));
    assert(0 == TKAHumanGetChildCount(childFemale));
    assert(NULL == TKAHumanGetFather(childFemale));
    assert(NULL == TKAHumanGetMother(childFemale));
    
    TKAHumanRemoveAllChildren(woman);
    assert(NULL != TKAHumanGetChildren(woman));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(0 == TKAHumanGetChildCount(woman));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 9));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 8));
    assert(NULL == TKAArrayGetChildAtIndex(TKAHumanGetChildren(woman), 0));
    
    TKAObjectRelease(childMale);
    TKAObjectRelease(childFemale);
    TKAObjectRelease(woman);
    TKAObjectRelease(man);
}

#pragma mark -
#pragma mark Public Implementations

TKAHuman *TKAHumanCreateWithNameChar(char *name, uint8_t age, TKAGender gender) {
    TKAHuman *human = TKAHumanCreate(age, gender);
    
    TKAHumanChangeName(human, name);
    
    return human;
}


void TKAHumanOutput(TKAHuman *human) {
    
    TKAStringOutput(TKAHumanGetName(human));
    printf("  ");
    printf("ref_count = %llu, ", TKAObjectGetReferenceCount(human));
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
//    printf("ref count name = %llu, ", TKAObjectGetReferenceCount(human->_name));
//    printf("ref count array = %llu, ", TKAObjectGetReferenceCount(human->_children));
//    
    printf(" \n");
}

void TKAHumanTestMain(){
    
    printf("\n");
    TKAHumanCreatTest();
    printf("test creating Human \n");

    // TKAHumanMarryDivorceTest();
    //    printf("\n");
    
    TKAHumanGiveBirthtChildTest();
    printf("test GiveBirth Human \n");
    
    TKAHumanAddRemoveChildTest();
    printf("test Add and Remove Child Human \n");
    printf("\n");
    
}
