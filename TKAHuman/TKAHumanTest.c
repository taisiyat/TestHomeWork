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

//TKAHuman
//      after creating human with age 20 and gender TKAMale
//          human shouldn't be NULL
//          array of child shouldn't be NULL
//          name of human should be NULL
//          age of human should equal 20
//          gender of human should equal TKAMale
//          object reference count of human should equal 1
//          object reference count of human array of child should equal 1
//      after creating TKAString testName
//          testName shouldn't be NULL
//          object reference count of testName equal 1
//                  after setting testName to  human
//                      human shouldn't be NULL
//                      array of child shouldn't be NULL
//                      name of human shouldn't be NULL, should equal testName
//                      age of human should equal 20
//                      gender of human should equal TKAMale
//                      object reference count of human should equal 1
//                      object reference count of human array of child should equal 1
//                      object reference count of human name should equal 2
//                          after releasing testName
//                              object reference count of human name should be change, should equal 1
//                                       after releasing human
//                                              it should be deallocate

//      after creating TKAString nameWoman
//          nameWoman shouldn't be NULL
//          object reference count of nameWoman should equal 1
//                  after creating human with name TKAString nameWoman, age 20 and gender TKAFemale
//                      human shouldn't be NULL
//                      array of child human shouldn't be NULL
//                      name of human shouldn't be NULL, should equal nameWoman
//                      age of human should equal 20
//                      gender of human should equal TKAFemale
//                      object reference count of human should equal 1
//                      object reference count of human array of child should equal 1
//                      object reference count of human name should equal 2
//                          after releasing nameWoman
//                              object reference count of human name should be change, should equal 1
//                                     after releasing human
//                                              it should be deallocate

void TKAHumanCreatTest() {
    
    TKAHuman *testHuman = TKAHumanCreate(20, TKAMale);
    assert(NULL != testHuman);
    assert(NULL != TKAHumanGet(children, testHuman));
    assert(NULL == TKAHumanGet(name, testHuman));
    assert(20 == TKAHumanGetAge(testHuman));
    assert(TKAMale == TKAHumanGetGender(testHuman));
    assert(1 == TKAObjectGetReferenceCount(testHuman));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, testHuman)));
    
    char *newName = "NewHuman";
    TKAString *testName = TKAObjectCreate(TKAString);
    TKAStringSetData(testName, newName);
    assert(NULL != testName);
    assert(1 == TKAObjectGetReferenceCount(testName));
    
    TKAHumanSetName(testHuman, testName);
    assert(NULL != testHuman);
    assert(NULL != TKAHumanGet(children, testHuman));
    assert(testName == TKAHumanGet(name, testHuman));
    assert(20 == TKAHumanGetAge(testHuman));
    assert(TKAMale == TKAHumanGetGender(testHuman));
    assert(2 == TKAObjectGetReferenceCount(TKAHumanGet(name, testHuman)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, testHuman)));
    assert(1 == TKAObjectGetReferenceCount(testHuman));
    
    TKAObjectRelease(testName);
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(name, testHuman)));
    
    TKAObjectRelease(testHuman);
    
    char *charNameWoman = "NewWoman";
    TKAString *nameWoman = TKAObjectCreate(TKAString);
    TKAStringSetData(nameWoman, charNameWoman);
    assert(NULL != nameWoman);
    assert(1 == TKAObjectGetReferenceCount(nameWoman));
    
    TKAHuman *woman = TKAHumanCreateWithNameString(nameWoman, 20, TKAFemale);
    assert(NULL != woman);
    assert(NULL != TKAHumanGet(children, woman));
    assert(nameWoman == TKAHumanGet(name, woman));
    assert(20 == TKAHumanGetAge(woman));
    assert(TKAFemale == TKAHumanGetGender(woman));
    assert(2 == TKAObjectGetReferenceCount(TKAHumanGet(name, woman)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, woman)));
    assert(1 == TKAObjectGetReferenceCount(woman));
    
    TKAObjectRelease(nameWoman);
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(name, woman)));
 
    TKAObjectRelease(woman);
    
//    TKAHuman *man = TKAHumanCreateWithNameChar("man", 35, TKAMale);
//    assert(NULL != TKAHumanGet(children, man));
//    assert(NULL != TKAHumanGet(name, man));
//    assert(35 == TKAHumanGetAge(man));
//    assert(TKAMale == TKAHumanGetGender(man));
//    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(name, man)));
//    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, man)));
//    assert(1 == TKAObjectGetReferenceCount(man));
//    TKAObjectRelease(man);
}

//TKAHuman
//      after creating man1, man2 with gender TKAMale and woman1, and woman2 with gender TKAFemale
//              each of them shouldn't be NULL
//              gender of man1 and man2 should be TKAMale
//              gender of woman1 and woman2 should be TKAFemale
//              object reference count of each of human should equal 1
//              they havn't partner, partner should be NULL
//                  after trying divorce man1
//                  after trying divorce woman1
//                      each of them not change
//                      object reference count each of human should equal 1
//                      they havn't partner, partner should be NULL
//                          after trying to married man1 and NULL
//                          after trying to married woman1 and NULL
//                              each of them not change
//                              object reference count each of human shouldn't change, equal 1
//                              they havn't partner, partner should be NULL
//
//                   after married man1 and woman1
//                         object reference count of man1 should be increment, equal 2
//                         object reference count of woman1 should equal 1
//                         partner of man1 should equal woman1
//                         partner of woman1 should equal man1
//                                  after divorce man1
//                                      object reference count of man1 should be decrement, equal 1
//                                      object reference count of woman1 should equal 1
//                                      partner of man1 shouldn't be, equal NULL
//                                      partner of woman1 shouldn't be, equal NULL
//
//                     after married man1 and woman1
//                          object reference count of man1 should be increment equal 2
//                          object reference count of woman1 should equal 1
//                          partner of man1 should equal woman1
//                          partner of woman1 should equal man1
//                                  after married man2 and woman1
//                                      object reference count of man1 should be decrement, equal 1
//                                      object reference count of woman1 should equal 1
//                                      object reference count of man2 should be increment, equal 2
//                                      partner of man1 shouldn't be, should be change, equal NULL
//                                      partner of woman1 should equal man2
//                                      partner of man2 should equal woman1
//                                          after married man2 and woman2
//                                              object reference count of man1 should equal 1
//                                              object reference count of woman1 should equal 1
//                                              object reference count of man2 should equal 2
//                                              object reference count of woman2 should equal 1
//                                              partner of man1 should equal NULL
//                                              partner of woman1 should be change, shouldn't be, equal NULL
//                                              partner of man2 should change, equal woman2
//                                              partner of woman2 should changhe, equal man2
//                                                  after trying to marry woman2 and NULL, nothing not change
//                                                      object reference count of man2 should equal 2
//                                                      object reference count of woman2 should equal 1
//                                                      partner of man2 should equal woman2
//                                                      partner of woman2 should equal man2
//                                                          after trying to marry man2 and NULL, nothing not change
//                                                              object reference count of man2 should equal 2
//                                                              object reference count of woman2 should equal 1
//                                                              partner of man2 should equal woman2
//                                                              partner of woman2 should equal man2
//                                                                   after divorce woman2
//                                                                          object reference count of man2 should be change, should equal 1
//                                                                          object reference count of woman2 should equal 1
//                                                                          partner of man2 should change, should equal NULL
//                                                                          partner of woman2 should changhe, should equal NULL
//                                                                              release All TKAhuman objects, man1,man2, woman1, woman2
//

void TKAHumanMarryDivorceTest() {
    
    TKAHuman *man1 = TKAHumanCreateWithNameChar("man1", 35, TKAMale);
    TKAHuman *woman1 = TKAHumanCreateWithNameChar("woman1", 35, TKAFemale);
    TKAHuman *man2 = TKAHumanCreateWithNameChar("man2", 20, TKAMale);
    TKAHuman *woman2 = TKAHumanCreateWithNameChar("woman2", 20, TKAFemale);
    
    assert(NULL != man1);
    assert(NULL != man2);
    assert(NULL != woman1);
    assert(NULL != woman2);
    assert(TKAMale == TKAHumanGetGender(man1));
    assert(TKAMale == TKAHumanGetGender(man2));
    assert(TKAFemale == TKAHumanGetGender(woman1));
    assert(TKAFemale == TKAHumanGetGender(woman2));
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(man2));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(1 == TKAObjectGetReferenceCount(woman2));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL == TKAHumanGet(partner, man2));
    assert(NULL == TKAHumanGet(partner, woman1));
    assert(NULL == TKAHumanGet(partner, woman2));
   
    TKAHumanDivorce(man1);
    TKAHumanDivorce(woman1);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL == TKAHumanGet(partner, woman1));

    TKAHumanMarry(woman1, man1);
    assert(2 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(woman1 == TKAHumanGet(partner, man1));
    assert(man1 == TKAHumanGet(partner, woman1));
    
    TKAHumanDivorce(man1);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL == TKAHumanGet(partner, woman1));
    
    TKAHumanMarry(woman1, man1);
    assert(2 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(woman1 == TKAHumanGet(partner, man1));
    assert(man1 == TKAHumanGet(partner, woman1));

    TKAHumanMarry(woman1, man2);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(2 == TKAObjectGetReferenceCount(man2));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(man2 == TKAHumanGet(partner, woman1));
    assert(woman1 == TKAHumanGet(partner, man2));
    
    TKAHumanMarry(woman2, man2);
    assert(1 == TKAObjectGetReferenceCount(man1));
    assert(1 == TKAObjectGetReferenceCount(woman1));
    assert(2 == TKAObjectGetReferenceCount(man2));
    assert(1 == TKAObjectGetReferenceCount(woman2));
    assert(NULL == TKAHumanGet(partner, man1));
    assert(NULL == TKAHumanGet(partner, woman1));
    assert(woman2 == TKAHumanGet(partner, man2));
    assert(man2 == TKAHumanGet(partner, woman2));
    
    TKAHumanMarry(woman2, NULL);
    assert(2 == TKAObjectGetReferenceCount(man2));
    assert(1 == TKAObjectGetReferenceCount(woman2));
    assert(woman2 == TKAHumanGet(partner, man2));
    assert(man2 == TKAHumanGet(partner, woman2));
    
    TKAHumanMarry(man2, NULL);
    assert(2 == TKAObjectGetReferenceCount(man2));
    assert(1 == TKAObjectGetReferenceCount(woman2));
    assert(woman2 == TKAHumanGet(partner, man2));
    assert(man2 == TKAHumanGet(partner, woman2));
    
    TKAHumanDivorce(woman2);
    assert(1 == TKAObjectGetReferenceCount(man2));
    assert(1 == TKAObjectGetReferenceCount(woman2));
    assert(NULL == TKAHumanGet(partner, man2));
    assert(NULL == TKAHumanGet(partner, woman2));
   
    TKAObjectRelease(woman1);
    TKAObjectRelease(man1);
    TKAObjectRelease(woman2);
    TKAObjectRelease(man2);
}

//TKAHuman
//      after creating man and woman
//           man and woman should have array of child  not NULL
//           man and woman should have  fist element array of child equal NULL,
//           object reference count array of child for man and woman should equal 1
//           object reference count man and woman should equal 1
//           man and woman should have count of child equal 0
//                  after giving birth newBorn human from man and woman with gender TKAMale and
//                  after renaming name to newborn1
//                          man and woman should have array of child  not NULL
//                          man and woman should have  fist element array of child not NULL, equal newBorn
//                          object reference count array of child for man and woman should equal 1
//                          object reference count man and woman should equal 1
//                          man and woman should have count of child equal 1
//                          newBorn shouldn't be NULL
//                          array of child shouldn't be NULL
//                          first element of child array should be equal NULL
//                          name shouldn't be NULL
//                          age of newBorn should equal 0
//                          gender of newBorn should equal TKAMale
//                          object reference count array of child for newBorn should equal 1
//                          object reference count name of newBorn should equal 1
//                          object reference count of newBorn should equal 2
//                          child count should equal 0
//                          father of newBorn shouldn't be NULL, should equal man
//                          mother of newBorn shouldn't be NULL, should equal woman
//                              after giving birth next newBorn2 human from man and NULL
//                                  newBorn2 should be NULL
//                                  man and woman should have  fist element array of child not NULL, equal newBorn1
//                                  man and woman should have  second element array of child equal NULL
//                                  object reference count man and woman should equal 1
//                                  man and woman should have count of child equal 1
//                                      after giving birth next newBorn3 human from woman and NULL
//                                          newBorn3 should be NULL
//                                          man and woman should have  fist element array of child not NULL, equal newBorn1
//                                          man and woman should have  second element array of child equal NULL
//                                          object reference count man and woman should equal 1
//                                          man and woman should have count of child equal 1
//                                              after giving birth next newBorn4 human from NULL and NULL
//                                                  newBorn4 should be NULL
//                                                          after giving birth next newBorn5 human from man and newBorn1 (the same gender)
//                                                              newBorn5 should be NULL
//                                                              man, and newBorn1 shouldn't change
//                                                              man should have  fist element array of child not NULL, equal newBorn1
//                                                              man and newborn1 should have  second element array of child equal NULL
//                                                              object reference count man should equal 1
//                                                              object reference count newborn should equal 2
//                                                              man should have count of child equal 1
//                                                              newborn1 should have count of child equal 0
//                                                                       after releasing man ,woman, newborn1
//                                                                                  they should be deallocate
//

void TKAHumanGiveBirthtChildTest() {
    
    TKAHuman *man = TKAHumanCreateWithNameChar("man", 35, TKAMale);
    TKAHuman *woman = TKAHumanCreateWithNameChar("woman", 35, TKAFemale);

    assert(NULL != TKAHumanGet(children, man));
    assert(NULL != TKAHumanGet(children, woman));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, man)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, woman)));
    assert(0 == TKAHumanGetChildCount(man));
    assert(0 == TKAHumanGetChildCount(woman));
    
    TKAHuman *newBorn1 = TKAHumanGiveBirth(man, woman, TKAMale);
    TKAHumanChangeName(newBorn1, "newborn1");
    assert(NULL != TKAHumanGet(children, man));
    assert(NULL != TKAHumanGet(children, woman));
    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, man)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, woman)));
    assert(1 == TKAHumanGetChildCount(man));
    assert(1 == TKAHumanGetChildCount(woman));

    assert(NULL != newBorn1);
    assert(NULL != TKAHumanGet(children, newBorn1));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, newBorn1), 0));
    assert(NULL != TKAHumanGet(name, newBorn1));
    assert(0 == TKAHumanGetAge(newBorn1));
    assert(TKAMale == TKAHumanGetGender(newBorn1));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(children, newBorn1)));
    assert(1 == TKAObjectGetReferenceCount(TKAHumanGet(name, newBorn1)));
    assert(2 == TKAObjectGetReferenceCount(newBorn1));
    assert(0 == TKAHumanGetChildCount(newBorn1));
    assert(man == TKAHumanGet(father, newBorn1));
    assert(woman == TKAHumanGet(mother, newBorn1));
    
    TKAHuman *newBorn2 = TKAHumanGiveBirth(NULL, woman, TKAFemale);
    assert(NULL == newBorn2);
    assert(NULL != TKAHumanGet(children, man));
    assert(NULL != TKAHumanGet(children, woman));
    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 1));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 1));
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(1 == TKAHumanGetChildCount(man));
    assert(1 == TKAHumanGetChildCount(woman));

    TKAHuman *newBorn3 = TKAHumanGiveBirth(man, NULL, TKAFemale);
    assert(NULL == newBorn3);
    assert(NULL != TKAHumanGet(children, man));
    assert(NULL != TKAHumanGet(children, woman));
    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(1 == TKAHumanGetChildCount(man));
    assert(1 == TKAHumanGetChildCount(woman));

    TKAHuman *newBorn4 = TKAHumanGiveBirth(NULL, NULL, TKAFemale);
    assert(NULL == newBorn4);
    assert(NULL != TKAHumanGet(children, man));
    assert(NULL != TKAHumanGet(children, woman));
    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(1 == TKAHumanGetChildCount(man));
    assert(1 == TKAHumanGetChildCount(woman));

    TKAHuman *newBorn5 = TKAHumanGiveBirth(man, newBorn1, TKAFemale);
    assert(NULL == newBorn5);
    assert(NULL != TKAHumanGet(children, man));
    assert(NULL != TKAHumanGet(children, newBorn1));
    assert(newBorn1 == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, newBorn1), 0));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 1));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, newBorn1), 1));
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(2 == TKAObjectGetReferenceCount(newBorn1));
    assert(1 == TKAHumanGetChildCount(man));
    assert(0 == TKAHumanGetChildCount(newBorn1));
    
    TKAObjectRelease(newBorn1);
    TKAObjectRelease(woman);
    TKAObjectRelease(man);
}

//TKAHuman
//      after creating man, woman, childMAle and ChildFemale
//          each of them have
//          object reference count should equal 1
//          count of children should equal 0
//          firsst element of children array should be NULL
//          father of child should be NULL
//          mother of child should be NULL
//              after adding childMAle and ChildFemale to man
//                  man and woman object reference count should equal 1
//                  man count of children should equal 2
//                  firsst 2 element of children of man shouldn't be NULL, should equal childMAle and ChildFemale
//                  object reference count childMAle and ChildFemale should equal 2
//                  father each of childMAle and ChildFemale should be man
//                      after adding childMAle to man
//                          man object reference count should equal 1
//                          man count of children should equal 2
//                          firsst 2 element of children of man shouldn't be NULL, should equal childMAle and ChildFemale
//                          object reference count childMAle and ChildFemale should equal 2
//                          father each of childMAle and ChildFemale should be man
//                              after adding NULL child to man noting should be change
//                                  man and woman object reference count should equal 1
//                                  man count of children should equal 2
//                                  firsst 2 element of children of man shouldn't be NULL, should equal childMAle and ChildFemale
//                                      after adding childMale to man noting should be change
//                                          object reference count childMAle should equal 2
//                                          father each of childMAle should be man
//                                          mother each of childFeMAle should be woman
//                                              after removing ChildMale
//                                                  man object reference count should equal 1
//                                                  man count of children should equal 1
//                                                  firsst 2 element of children of man should equal childFemale and NULL
//                                                  object reference count childMAle should equal 1
//                                                  father childMAle should be NULL
//                                                       after removing ChildFemale
//                                                          man object reference count should equal 1
//                                                          man count of children should equal 0
//                                                          firsst 2 element of children of man should be NULL
//                                                          object reference count childMAle and ChildFemale should equal 1
//                                                          father each of childMAle and ChildFemale should be NULL
//
//                after adding childMAle to woman
//                    man and woman object reference count should equal 1
//                    woman count of children should equal 1
//                    firsst 2 element of children of woman should equal childMAle and NULL
//                     object reference count childMAle should equal 2
//                     mother childMAle should be woman
//                           after adding ChildFemale to woman
//                                  man and woman object reference count should equal 1
//                                  woman count of children should equal 2
//                                  firsst 2 element of children of woman shouldn't be NULL, should equal childMAle and ChildFemale
//                                  object reference count childMAle and ChildFemale should equal 2
//                                  mother each of childMAle and ChildFemale should be woman
//                                      after removing child man from woman nothing should ba change
//                                          man and woman object reference count should equal 1
//                                          woman count of children should equal 2
//                                          firsst 2 element of children of woman shouldn't be NULL, should equal childMAle and ChildFemale
//                                          object reference count childMAle and ChildFemale should equal 2
//                                          mother each of childMAle and ChildFemale should be woman
//                                              after removing all children
//                                                  woman object reference count should equal 1
//                                                  woman count of children should equal 0
//                                                  firsst element of children of woman should equal NULL
//                                                  object reference count childMAle and childFemAle should equal 1
//                                                  mother childMAle and childFemAle should be NULL
//                                                         after releasing man ,woman, childMAle and childFemAle
//                                                                  they should be deallocated

void TKAHumanAddRemoveChildTest() {
    
    TKAHuman *man = TKAHumanCreateWithNameChar("man", 35, TKAMale);
    TKAHuman *woman = TKAHumanCreateWithNameChar("woman", 35, TKAFemale);
    TKAHuman *childMale = TKAHumanCreateWithNameChar("childMale", 10, TKAMale);
    TKAHuman *childFemale = TKAHumanCreateWithNameChar("childFemale", 5, TKAFemale);
    
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(1 == TKAObjectGetReferenceCount(childMale));
    assert(1 == TKAObjectGetReferenceCount(childFemale));
    assert(0 == TKAHumanGetChildCount(man));
    assert(0 == TKAHumanGetChildCount(woman));
    assert(0 == TKAHumanGetChildCount(childMale));
    assert(0 == TKAHumanGetChildCount(childFemale));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, childMale), 0));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, childFemale), 0));
    assert(NULL == TKAHumanGet(father, man));
    assert(NULL == TKAHumanGet(father, woman));
    assert(NULL == TKAHumanGet(father, childMale));
    assert(NULL == TKAHumanGet(father, childFemale));
    assert(NULL == TKAHumanGet(mother, man));
    assert(NULL == TKAHumanGet(mother, woman));
    assert(NULL == TKAHumanGet(mother, childMale));
    assert(NULL == TKAHumanGet(mother, childFemale));
    
    
    TKAHumanAddChild(man, childMale);
    TKAHumanAddChild(man, childFemale);
    TKAHumanOutput(man);
    TKAHumanOutput(childMale);
    TKAHumanOutput(childFemale);
    printf("\n");
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(2 == TKAHumanGetChildCount(man));
    assert(childMale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(childFemale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 1));
    assert(2 == TKAObjectGetReferenceCount(childMale));
    assert(2 == TKAObjectGetReferenceCount(childFemale));
    assert(man == TKAHumanGet(father, childMale));
    assert(man == TKAHumanGet(father, childFemale));
    
    TKAHumanAddChild(man, childMale);
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(2 == TKAHumanGetChildCount(man));
    assert(childMale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(childFemale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 1));
    assert(2 == TKAObjectGetReferenceCount(childMale));
    assert(2 == TKAObjectGetReferenceCount(childFemale));
    assert(man == TKAHumanGet(father, childMale));
    assert(man == TKAHumanGet(father, childFemale));
    
    TKAHumanAddChild(man, NULL);
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(2 == TKAHumanGetChildCount(man));
    assert(childMale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(childFemale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 1));
    
    TKAHumanAddChild(NULL, childMale);
    assert(2 == TKAObjectGetReferenceCount(childMale));
    assert(man == TKAHumanGet(father, childMale));
    assert(NULL == TKAHumanGet(mother, childMale));
    
    TKAHumanRemoveChild(man, childMale);
    TKAHumanOutput(man);
    TKAHumanOutput(childMale);
    TKAHumanOutput(childFemale);
    printf("\n");

    assert(1 == TKAObjectGetReferenceCount(man));
    assert(1 == TKAHumanGetChildCount(man));
    assert(childFemale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(1 == TKAObjectGetReferenceCount(childMale));
    assert(2 == TKAObjectGetReferenceCount(childFemale));
    assert(NULL == TKAHumanGet(father, childMale));
    assert(man == TKAHumanGet(father, childFemale));

    TKAHumanRemoveChild(man, childFemale);
    TKAHumanOutput(man);
    TKAHumanOutput(childFemale);

    assert(1 == TKAObjectGetReferenceCount(man));
    assert(0 == TKAHumanGetChildCount(man));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 0));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, man), 1));
    assert(1 == TKAObjectGetReferenceCount(childMale));
    assert(1 == TKAObjectGetReferenceCount(childFemale));
    assert(NULL == TKAHumanGet(father, childMale));
    assert(NULL == TKAHumanGet(father, childFemale));
    
    TKAHumanAddChild(woman, childMale);
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(1 == TKAHumanGetChildCount(woman));
    assert(childMale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 1));
    assert(2 == TKAObjectGetReferenceCount(childMale));
    assert(woman == TKAHumanGet(mother, childMale));
    
    TKAHumanAddChild(woman, childFemale);
    TKAHumanOutput(woman);
    TKAHumanOutput(childMale);
    TKAHumanOutput(childFemale);

    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(2 == TKAHumanGetChildCount(woman));
    assert(childMale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    assert(childFemale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 1));
    assert(2 == TKAObjectGetReferenceCount(childFemale));
    assert(woman == TKAHumanGet(mother, childFemale));

    TKAHumanRemoveChild(woman, man);
    assert(1 == TKAObjectGetReferenceCount(man));
    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(2 == TKAHumanGetChildCount(woman));
    assert(childMale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    assert(childFemale == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 1));
    
    TKAHumanRemoveAllChildren(woman);
    TKAHumanOutput(woman);
    TKAHumanOutput(childMale);
    TKAHumanOutput(childFemale);

    assert(1 == TKAObjectGetReferenceCount(woman));
    assert(0 == TKAHumanGetChildCount(woman));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 0));
    assert(NULL == TKAArrayGetObjectAtIndex(TKAHumanGet(children, woman), 1));
    assert(1 == TKAObjectGetReferenceCount(childMale));
    assert(1 == TKAObjectGetReferenceCount(childFemale));
    assert(NULL == TKAHumanGet(mother, childMale));
    assert(NULL == TKAHumanGet(mother, childFemale));

    
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
//    printf("gender = %d, ", TKAHumanGetGender(human));
    printf("count children = %d, ", TKAHumanGetChildCount(human));
    
//    if (NULL != TKAHumanGet(partner, human)) {
//        printf("partner = ");
//        TKAStringOutput(TKAHumanGet(name, TKAHumanGet(partner, human)));
//        printf(", ");
//    }
    
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
//
//    printf(" \n");
//    printf("ref count name = %llu, ", TKAObjectGetReferenceCount(human->_name));
//    printf("ref count array = %llu, ", TKAObjectGetReferenceCount(human->_children));
//    
    printf(" \n");
}

void TKAHumanTestMain(){
    
    printf("\n");
    TKAHumanCreatTest();
    printf("test creating Human is OK  \n");

    TKAHumanMarryDivorceTest();
    printf("test Marry Divorce Human is OK \n");
   
    TKAHumanGiveBirthtChildTest();
    printf("test GiveBirth Human is OK \n");
    
    TKAHumanAddRemoveChildTest();
    printf("test Add and Remove Child Human \n");
    printf("\n");
    
}
