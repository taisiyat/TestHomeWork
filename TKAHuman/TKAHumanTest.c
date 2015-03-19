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
    assert(NULL != TKAHumanGet(children, testHuman));
    assert(NULL == TKAHumanGet(name, testHuman));
    assert(20 == TKAHumanGetAge(testHuman));
    assert(TKAMale == TKAHumanGetGender(testHuman));
    assert(0 == TKAObjectGetReferenceCount(TKAHumanGet(name, testHuman)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, testHuman)));
    assert(1 == TKAObjectGetReferenceCount(testHuman));
    
    char *newName = "NewHuman";
    TKAString *testName = TKAObjectCreate(TKAString);
    TKAStringSetData(testName, newName);
    assert(1 == TKAObjectGetReferenceCount(testName));
    
    TKAHumanSetName(testHuman, testName);
    assert(NULL != TKAHumanGet(children, testHuman));
    assert(testName == TKAHumanGet(name, testHuman));
    assert(20 == TKAHumanGetAge(testHuman));
    assert(TKAMale == TKAHumanGetGender(testHuman));
    assert(2 == TKAObjectGetReferenceCount(TKAHumanGet(name, testHuman)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, testHuman)));
    assert(1 == TKAObjectGetReferenceCount(testHuman));
    
    TKAHumanOutput(testHuman);
    TKAObjectRelease(testName);
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(name, testHuman)));
    
    TKAObjectRelease(testHuman);
    
    char *charNameWoman = "NewWoman";
    TKAString *nameWoman = TKAObjectCreate(TKAString);
    TKAStringSetData(nameWoman, charNameWoman);
    assert(1 == TKAObjectGetReferenceCount(nameWoman));
    
    TKAHuman *woman = TKAHumanCreateWithNameString(nameWoman, 20, TKAFemale);
    assert(NULL != TKAHumanGet(children, woman));
    assert(nameWoman == TKAHumanGet(name, woman));
    assert(20 == TKAHumanGetAge(woman));
    assert(TKAFemale == TKAHumanGetGender(woman));
    assert(2 == TKAObjectGetReferenceCount(TKAHumanGet(name, woman)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, woman)));
    assert(1 == TKAObjectGetReferenceCount(woman));
    
    TKAObjectRelease(nameWoman);
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(name, woman)));
    TKAHumanOutput(woman);
    TKAObjectRelease(woman);
    
    TKAHuman *man = TKAHumanCreateWithNameChar("man", 35, TKAMale);
    assert(NULL != TKAHumanGet(children, man));
    assert(NULL != TKAHumanGet(name, man));
    assert(35 == TKAHumanGetAge(man));
    assert(TKAMale == TKAHumanGetGender(man));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(name, man)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, man)));
    assert(1 == TKAObjectGetReferenceCount(man));
    TKAHumanOutput(man);
    TKAObjectRelease(man);
}


void TKAHumanMarryDivorceTest() {
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHuman *woman1 = TKAHumanCreateWithNameChar("woman1", 35, TKAFemale);
    TKAHuman *man2 = TKAHumanCreateWithNameChar("man2", 20, TKAMale);
    TKAHuman *woman2 = TKAHumanCreateWithNameChar("woman2", 20, TKAFemale);
    assert(NULL != man1);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL != man2);
    assert(1 == TKAObjectGetReferenceCount(man2));
    assert(TKAMale == TKAHumanGetGender(man2));
    assert(NULL == TKAHumanGet(partner, man2));
    assert(NULL != woman1);
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(NULL == TKAHumanGet(partner, woman1));
    assert(NULL != woman2);
    assert(1 == TKAObjectGetReferenceCount(woman2));
    assert(TKAFemale == TKAHumanGetGender(woman2));
    assert(NULL == TKAHumanGet(partner, woman2));
   
    TKAHumanDivorce(man1);
    TKAHumanDivorce(woman1);
    assert(NULL != man1);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL != woman1);
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(NULL == TKAHumanGet(partner, woman1));
    
    TKAHumanMarry(woman1, man1);
    assert(NULL != man1);
    assert(2 == TKAObjectGetReferenceCount(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(woman1 == TKAHumanGet(partner, man1));
    assert(NULL != woman1);
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(man1 == TKAHumanGet(partner, woman1));
    
    TKAHumanDivorce(man1);
    assert(NULL != man1);
    assert(2 == TKAObjectGetReferenceCount(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(woman1 == TKAHumanGet(partner, man1));
    assert(NULL != woman1);
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(man1 == TKAHumanGet(partner, woman1));
    
    TKAHumanDivorce(woman1);
    assert(NULL != man1);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL != woman1);
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(NULL == TKAHumanGet(partner, woman1));
    
    TKAHumanMarry(woman1, man1);
    TKAHumanMarry(woman1, man2);
    assert(NULL != man1);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL != woman1);
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(man2 == TKAHumanGet(partner, woman1));
    assert(NULL != man2);
    assert(2 == TKAObjectGetReferenceCount(man2));
    assert(TKAMale == TKAHumanGetGender(man2));
    assert(woman1 == TKAHumanGet(partner, man2));

    TKAHumanMarry(woman2, man2);
    assert(NULL != man1);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL != woman1);
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(man2 == TKAHumanGet(partner, woman1));
    assert(NULL != man2);
    assert(2 == TKAObjectGetReferenceCount(man2));
    assert(TKAMale == TKAHumanGetGender(man2));
    assert(woman1 == TKAHumanGet(partner, man2));
    
    TKAHumanDivorce(woman2);
    TKAHumanDivorce(man1);
    TKAHumanDivorce(man2);
    TKAHumanDivorce(woman1);
    assert(NULL != man1);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL != woman1);
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(NULL == TKAHumanGet(partner, woman1));
    assert(NULL != man2);
    assert(1 == TKAObjectGetReferenceCount(man2));
    assert(TKAMale == TKAHumanGetGender(man2));
    assert(NULL == TKAHumanGet(partner, man2));
    assert(NULL != woman2);
    assert(1 == TKAObjectGetReferenceCount(woman2));
    assert(TKAFemale == TKAHumanGetGender(woman2));
    assert(NULL == TKAHumanGet(partner, woman2));
    
    TKAHumanMarry(man1, NULL);
    assert(NULL != man1);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(NULL == TKAHumanGet(partner, man1));
    
    TKAHumanMarry(woman1, NULL);
    assert(NULL != woman1);
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(NULL == TKAHumanGet(partner, woman1));
    
    TKAObjectRelease(woman1);
    TKAObjectRelease(man1);
    TKAObjectRelease(woman2);
    TKAObjectRelease(man2);
}

void TKAHumanMarryDivorceTestOutput() {
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHuman *woman1 = TKAHumanCreateWithNameChar("woman1", 35, TKAFemale);
    TKAHuman *man2 = TKAHumanCreateWithNameChar("man2", 20, TKAMale);
    TKAHuman *woman2 = TKAHumanCreateWithNameChar("woman2", 20, TKAFemale);
    assert(NULL != man1);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL != man2);
    assert(1 == TKAObjectGetReferenceCount(man2));
    assert(TKAMale == TKAHumanGetGender(man2));
    assert(NULL == TKAHumanGet(partner, man2));
    assert(NULL != woman1);
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(NULL == TKAHumanGet(partner, woman1));
    assert(NULL != woman2);
    assert(1 == TKAObjectGetReferenceCount(woman2));
    assert(TKAFemale == TKAHumanGetGender(woman2));
    assert(NULL == TKAHumanGet(partner, woman2));
    
    TKAHumanDivorce(man1);
    TKAHumanDivorce(woman1);
    assert(NULL != man1);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL != woman1);
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(NULL == TKAHumanGet(partner, woman1));
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman2);

    
    TKAHumanMarry(woman1, man1);
//    assert(NULL != man1);
//    assert(2 == TKAObjectGetReferenceCount(man1));
//    assert(TKAMale == TKAHumanGetGender(man1));
//    assert(woman1 == TKAHumanGet(partner, man1));
//    assert(NULL != woman1);
//    assert(1 == TKAObjectGetReferenceCount(woman1));
//    assert(TKAFemale == TKAHumanGetGender(woman1));
//    assert(man1 == TKAHumanGet(partner, woman1));
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman2);

    
    TKAHumanDivorce(man1);
//    assert(NULL != man1);
//    assert(2 == TKAObjectGetReferenceCount(man1));
//    assert(TKAMale == TKAHumanGetGender(man1));
//    assert(woman1 == TKAHumanGet(partner, man1));
//    assert(NULL != woman1);
//    assert(1 == TKAObjectGetReferenceCount(woman1));
//    assert(TKAFemale == TKAHumanGetGender(woman1));
//    assert(man1 == TKAHumanGet(partner, woman1));
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman2);

    
    TKAHumanDivorce(woman1);
//    assert(NULL != man1);
//    assert(1 == TKAObjectGetReferenceCount(man1));
//    assert(TKAMale == TKAHumanGetGender(man1));
//    assert(NULL == TKAHumanGet(partner, man1));
//    assert(NULL != woman1);
//    assert(1 == TKAObjectGetReferenceCount(woman1));
//    assert(TKAFemale == TKAHumanGetGender(woman1));
//    assert(NULL == TKAHumanGet(partner, woman1));
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman2);

    
    TKAHumanMarry(woman1, man1);
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman2);

    TKAHumanMarry(woman1, man2);
//    assert(NULL != man1);
//    assert(1 == TKAObjectGetReferenceCount(man1));
//    assert(TKAMale == TKAHumanGetGender(man1));
//    assert(NULL == TKAHumanGet(partner, man1));
//    assert(NULL != woman1);
//    assert(1 == TKAObjectGetReferenceCount(woman1));
//    assert(TKAFemale == TKAHumanGetGender(woman1));
//    assert(man2 == TKAHumanGet(partner, woman1));
//    assert(NULL != man2);
//    assert(2 == TKAObjectGetReferenceCount(man2));
//    assert(TKAMale == TKAHumanGetGender(man2));
//    assert(woman1 == TKAHumanGet(partner, man2));
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman2);

    
    TKAHumanMarry(woman2, man2);
//    assert(NULL != man1);
//    assert(1 == TKAObjectGetReferenceCount(man1));
//    assert(TKAMale == TKAHumanGetGender(man1));
//    assert(NULL == TKAHumanGet(partner, man1));
//    assert(NULL != woman1);
//    assert(1 == TKAObjectGetReferenceCount(woman1));
//    assert(TKAFemale == TKAHumanGetGender(woman1));
//    assert(man2 == TKAHumanGet(partner, woman1));
//    assert(NULL != man2);
//    assert(2 == TKAObjectGetReferenceCount(man2));
//    assert(TKAMale == TKAHumanGetGender(man2));
//    assert(woman1 == TKAHumanGet(partner, man2));
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman2);

    
    TKAHumanDivorce(woman2);
    TKAHumanDivorce(man1);
    TKAHumanDivorce(man2);
    TKAHumanDivorce(woman1);
//    assert(NULL != man1);
//    assert(1 == TKAObjectGetReferenceCount(man1));
//    assert(TKAMale == TKAHumanGetGender(man1));
//    assert(NULL == TKAHumanGet(partner, man1));
//    assert(NULL != woman1);
//    assert(1 == TKAObjectGetReferenceCount(woman1));
//    assert(TKAFemale == TKAHumanGetGender(woman1));
//    assert(NULL == TKAHumanGet(partner, woman1));
//    assert(NULL != man2);
//    assert(1 == TKAObjectGetReferenceCount(man2));
//    assert(TKAMale == TKAHumanGetGender(man2));
//    assert(NULL == TKAHumanGet(partner, man2));
//    assert(NULL != woman2);
//    assert(1 == TKAObjectGetReferenceCount(woman2));
//    assert(TKAFemale == TKAHumanGetGender(woman2));
//    assert(NULL == TKAHumanGet(partner, woman2));
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman2);

    
    TKAHumanMarry(man1, NULL);
//    assert(NULL != man1);
//    assert(1 == TKAObjectGetReferenceCount(man1));
//    assert(TKAMale == TKAHumanGetGender(man1));
//    assert(NULL == TKAHumanGet(partner, man1));
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman2);

    
    TKAHumanMarry(woman1, NULL);
//    assert(NULL != woman1);
//    assert(1 == TKAObjectGetReferenceCount(woman1));
//    assert(TKAFemale == TKAHumanGetGender(woman1));
//    assert(NULL == TKAHumanGet(partner, woman1));
    TKAHumanOutput(man1);
    TKAHumanOutput(woman1);
    TKAHumanOutput(man2);
    TKAHumanOutput(woman2);

    
    TKAObjectRelease(woman1);
    TKAObjectRelease(man1);
    TKAObjectRelease(woman2);
    TKAObjectRelease(man2);
}


void TKAHumanGiveBirthtChildTest() {
    
    TKAHuman *man = TKAHumanCreateWithNameChar("man", 35, TKAMale);
    TKAHuman *woman = TKAHumanCreateWithNameChar("woman", 35, TKAFemale);
    assert(NULL != man);
    assert(NULL != TKAHumanGet(children, man));
    assert(0 == TKAHumanGetChildCount(man));
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    
    assert(NULL != woman);
    assert(NULL != TKAHumanGet(children, woman));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(0 == TKAHumanGetChildCount(woman));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    
    TKAHuman *newBorn1 = TKAHumanGiveBirth(man, woman, TKAMale);
    TKAHumanChangeName(newBorn1, "newborn1");
    assert(2 == TKAObjectGetReferenceCount(man));
    assert(1 == TKAHumanGetChildCount(man));
    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(2 == TKAObjectGetReferenceCount(woman));
    assert(1 == TKAHumanGetChildCount(woman));
    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    assert(NULL != newBorn1);
    assert(2 == TKAObjectGetReferenceCount(newBorn1));
    assert(0 == TKAHumanGetChildCount(newBorn1));
    assert(man == TKAHumanGet(father, newBorn1));
    assert(woman == TKAHumanGet(mother, newBorn1));
    
    
    TKAHuman *newBorn2 = TKAHumanGiveBirth(NULL, woman, TKAFemale);
    TKAHumanChangeName(newBorn2, "newborn2");
    
//    assert(2 == TKAObjectGetReferenceCount(man));
//    assert(1 == TKAHumanGetChildCount(man));
//    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
//    assert(newBorn2 != TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
//    assert(3 == TKAObjectGetReferenceCount(woman));
//    assert(2 == TKAHumanGetChildCount(woman));
//    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
//    assert(newBorn2 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 1));
//    assert(NULL != newBorn2);
//    assert(1 == TKAObjectGetReferenceCount(newBorn2));
//    assert(0 == TKAHumanGetChildCount(newBorn2));
//    assert(NULL == TKAHumanGet(father, newBorn2));
//    assert(woman == TKAHumanGet(mother, newBorn2));
    
    TKAHuman *newBorn3 = TKAHumanGiveBirth(man, NULL, TKAFemale);
    TKAHumanChangeName(newBorn3, "newborn3");
    
//    assert(3 == TKAObjectGetReferenceCount(man));
//    assert(2 == TKAHumanGetChildCount(man));
//    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
//    assert(newBorn3 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 1));
//    assert(3 == TKAObjectGetReferenceCount(woman));
//    assert(2 == TKAHumanGetChildCount(woman));
//    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
//    assert(newBorn2 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 1));
//    assert(NULL != newBorn3);
//    assert(1 == TKAObjectGetReferenceCount(newBorn3));
//    assert(0 == TKAHumanGetChildCount(newBorn3));
//    assert(man == TKAHumanGet(father, newBorn3));
//    assert(NULL == TKAHumanGet(mother, newBorn3));

    TKAHuman *newBorn4 = TKAHumanGiveBirth(NULL, NULL, TKAFemale);
//    assert(NULL == newBorn4);
//    assert(3 == TKAObjectGetReferenceCount(man));
//    assert(2 == TKAHumanGetChildCount(man));
//    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
//    assert(newBorn3 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 1));
//    assert(3 == TKAObjectGetReferenceCount(woman));
//    assert(2 == TKAHumanGetChildCount(woman));
//    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
//    assert(newBorn2 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 1));
//    assert(NULL == newBorn4);
//    assert(0 == TKAObjectGetReferenceCount(newBorn4));


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
    assert(NULL != TKAHumanGet(children, man));
    assert(0 == TKAHumanGetChildCount(man));
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    
    assert(NULL != woman);
    assert(NULL != TKAHumanGet(children, woman));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(0 == TKAHumanGetChildCount(woman));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    
    assert(NULL != childMale);
    assert(NULL != TKAHumanGet(children, childMale));
    assert(1 == TKAObjectGetReferenceCount(childMale));
    assert(0 == TKAHumanGetChildCount(childMale));
    assert(NULL == TKAHumanGet(father, childMale));
    assert(NULL == TKAHumanGet(mother, childMale));

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
    assert(NULL != TKAHumanGet(children, man));
    assert(9 == TKAHumanGetChildCount(man));
    assert(10 == TKAObjectGetReferenceCount(man));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 9));
    assert(newBorn8 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 8));
    assert(newBorn0 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));

    assert(NULL != woman);
    assert(NULL != TKAHumanGet(children, woman));
    assert(10 == TKAObjectGetReferenceCount(woman));
    assert(9 == TKAHumanGetChildCount(woman));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 9));
    assert(newBorn8 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 8));
    assert(newBorn0 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    
    assert(NULL != newBorn5);
    assert(2 == TKAObjectGetReferenceCount(newBorn5));
    assert(0 == TKAHumanGetChildCount(newBorn5));
    assert(man == TKAHumanGet(father, newBorn5));
    assert(woman == TKAHumanGet(mother, newBorn5));
    
    TKAHumanOutput(man);
    TKAHumanOutput(woman);
    
    TKAHumanAddChild(man, childMale);
    assert(NULL != childMale);
    assert(2 == TKAObjectGetReferenceCount(childMale));
    assert(0 == TKAHumanGetChildCount(childMale));
    assert(man == TKAHumanGet(father, childMale));
    assert(NULL == TKAHumanGet(mother, childMale));

    assert(NULL != man);
    assert(NULL != TKAHumanGet(children, man));
    assert(10 == TKAHumanGetChildCount(man));
    assert(11 == TKAObjectGetReferenceCount(man));
    assert(childMale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 9));
    assert(NULL != TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 8));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 10));

    TKAHumanAddChild(man, childMale);
    assert(NULL != childMale);
    assert(2 == TKAObjectGetReferenceCount(childMale));
    assert(0 == TKAHumanGetChildCount(childMale));
    assert(man == TKAHumanGet(father, childMale));
    assert(NULL == TKAHumanGet(mother, childMale));
    
    assert(NULL != man);
    assert(NULL != TKAHumanGet(children, man));
    assert(10 == TKAHumanGetChildCount(man));
    assert(11 == TKAObjectGetReferenceCount(man));
    assert(childMale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 9));
    assert(NULL != TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 8));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 10));
    printf("////////////");
    TKAHumanOutput(man);
    TKAHumanOutput(woman);
   printf("////////////");
    TKAHumanAddChild(man, NULL);
    assert(NULL != man);
    assert(NULL != TKAHumanGet(children, man));
    assert(10 == TKAHumanGetChildCount(man));
    assert(11 == TKAObjectGetReferenceCount(man));
    assert(childMale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 9));
    assert(NULL != TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 8));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 10));
    
    TKAHumanAddChild(NULL, childFemale);
    assert(NULL != childFemale);
    assert(1 == TKAObjectGetReferenceCount(childFemale));
    assert(0 == TKAHumanGetChildCount(childFemale));
    assert(NULL == TKAHumanGet(father, childFemale));
    assert(NULL == TKAHumanGet(mother, childFemale));
    
    printf("////////////");
    TKAHumanOutput(man);
    TKAHumanOutput(woman);
    printf("////////////");
    TKAHumanRemoveChild(man, newBorn5);
    assert(NULL != man);
    assert(NULL != TKAHumanGet(children, man));
    assert(9 == TKAHumanGetChildCount(man));
    assert(10 == TKAObjectGetReferenceCount(man));
 //   assert(newBorn4 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 4));
//    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 5));
//    assert(newBorn6 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 6));
    
    assert(NULL != newBorn5);
    assert(1 == TKAObjectGetReferenceCount(newBorn5));
    assert(0 == TKAHumanGetChildCount(newBorn5));
    assert(NULL == TKAHumanGet(father, newBorn5));
    assert(woman == TKAHumanGet(mother, newBorn5));
    printf("////////////");
    TKAHumanOutput(man);
    TKAHumanOutput(woman);
    printf("////////////");
    TKAHumanAddChild(man, childFemale);
    assert(NULL != man);
    assert(NULL != TKAHumanGet(children, man));
    assert(10 == TKAHumanGetChildCount(man));
    assert(11 == TKAObjectGetReferenceCount(man));
//    assert(newBorn4 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 4));
//    assert(childFemale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 5));
//    assert(newBorn6 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 6));
    
    assert(NULL != childFemale);
    assert(2 == TKAObjectGetReferenceCount(childFemale));
    assert(0 == TKAHumanGetChildCount(childFemale));
    assert(man == TKAHumanGet(father, childFemale));
    assert(NULL == TKAHumanGet(mother, childFemale));

    printf("////////////");
    TKAHumanOutput(man);
    TKAHumanOutput(woman);
    printf("////////////");
    TKAHumanRemoveAllChildren(man);
    assert(NULL != man);
    assert(NULL != TKAHumanGet(children, man));
//    assert(0 == TKAHumanGetChildCount(man));
//    assert(1 == TKAObjectGetReferenceCount(man));
//    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 9));
//    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 8));
//    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 10));
    
//    assert(1 == TKAObjectGetReferenceCount(childFemale));
//    assert(0 == TKAHumanGetChildCount(childFemale));
//    assert(NULL == TKAHumanGet(father, childFemale));
//    assert(NULL == TKAHumanGet(mother, childFemale));
    printf("////////////");
    TKAHumanOutput(man);
    TKAHumanOutput(woman);
    printf("////////////");
    TKAHumanRemoveAllChildren(woman);
//    assert(NULL != TKAHumanGet(children, woman));
//    assert(1 == TKAObjectGetReferenceCount(woman));
//    assert(0 == TKAHumanGetChildCount(woman));
//    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 9));
//    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 8));
//    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    printf("////////////");
    TKAHumanOutput(man);
    TKAHumanOutput(woman);
    printf("////////////");
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
    
    TKAStringOutput(TKAHumanGet(name, human));
    printf("  ");
    printf("ref_count = %llu, ", TKAObjectGetReferenceCount(human));
//    printf("age = %d, ",TKAHumanGetAge(human));
    printf("gender = %d, ", TKAHumanGetGender(human));
    printf("count children = %d, ", TKAHumanGetChildCount(human));
    
    if (NULL != TKAHumanGet(partner, human)) {
        printf("partner = ");
        TKAStringOutput(TKAHumanGet(name, TKAHumanGet(partner, human)));
        printf(", ");
    }
    
    if (NULL != TKAHumanGet(father, human)) {
        printf("father = ");
        TKAStringOutput(TKAHumanGet(name, TKAHumanGet(father, human)));
        printf(", ");
    }
    
    if (NULL != TKAHumanGet(mother, human)) {
        printf("motner = ");
        TKAStringOutput(TKAHumanGet(name, TKAHumanGet(mother, human)));
        printf(", ");
    }
    
    if (NULL != TKAHumanGet(children, human)) {
        printf("children: ");
        TKAArrayOutput(TKAHumanGet(children, human));
    }

    printf(" \n");
    printf("ref count name = %llu, ", TKAObjectGetReferenceCount(human->_name));
    printf("ref count array = %llu, ", TKAObjectGetReferenceCount(human->_children));
    
    printf(" \n");
}

void TKAHumanTestMain(){
    
    printf("\n");
    TKAHumanCreatTest();
    printf("test creating Human \n");

//    TKAHumanMarryDivorceTest();
//    printf("test Marry Divorce Human \n");
        TKAHumanMarryDivorceTestOutput();
        printf("test Marry Divorce Human \n");

    
    TKAHumanGiveBirthtChildTest();
    printf("test GiveBirth Human \n");
    
    TKAHumanAddRemoveChildTest();
    printf("test Add and Remove Child Human \n");
    printf("\n");
    
}
