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
//          human shoudn't be NULL
//          array of child shoudn't be NULL
//          name of human shoud be NULL
//          age of human shoud equal 20
//          gender of human shoud equal TKAMale
//          object reference count of human shoud equal 1
//          object reference count of human array of child shoud equal 1
//      after creating TKAString testName
//          testName shoudn't be NULL
//          object reference count of testName equal 1
//                  after setting testName to  human
//                      human shoudn't be NULL
//                      array of child shoudn't be NULL
//                      name of human shoudn't be NULL, shoud equal testName
//                      age of human shoud equal 20
//                      gender of human shoud equal TKAMale
//                      object reference count of human shoud equal 1
//                      object reference count of human array of child shoud equal 1
//                      object reference count of human name shoud equal 2
//                          after releasing testName
//                              object reference count of human name shoud be change, shoud equal 1
//                                       after releasing human
//                                              it shoud be deallocate

//      after creating TKAString nameWoman
//          nameWoman shoudn't be NULL
//          object reference count of nameWoman shoud equal 1
//                  after creating human with name TKAString nameWoman, age 20 and gender TKAFemale
//                      human shoudn't be NULL
//                      array of child human shoudn't be NULL
//                      name of human shoudn't be NULL, shoud equal nameWoman
//                      age of human shoud equal 20
//                      gender of human shoud equal TKAFemale
//                      object reference count of human shoud equal 1
//                      object reference count of human array of child shoud equal 1
//                      object reference count of human name shoud equal 2
//                          after releasing nameWoman
//                              object reference count of human name shoud be change, shoud equal 1
//                                     after releasing human
//                                              it shoud be deallocate

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
//              each of them shoudn't be NULL
//              gender of man1 and man2 shoud be TKAMale
//              gender of woman1 and woman2 shoud be TKAFemale
//              object reference count of each of human shoud equal 1
//              they havn't partner, partner shoud be NULL
//                  after trying divorce man1
//                  after trying divorce woman1
//                      each of them not change
//                      object reference count each of human shoud equal 1
//                      they havn't partner, partner shoud be NULL
//                          after trying to married man1 and NULL
//                          after trying to married woman1 and NULL
//                              each of them not change
//                              object reference count each of human shoudn't change, equal 1
//                              they havn't partner, partner shoud be NULL
//
//                   after married man1 and woman1
//                         object reference count of man1 shoud be increment, equal 2
//                         object reference count of woman1 shoud equal 1
//                         partner of man1 shoud equal woman1
//                         partner of woman1 shoud equal man1
//                                  after divorce man1
//                                      object reference count of man1 shoud be decrement, equal 1
//                                      object reference count of woman1 shoud equal 1
//                                      partner of man1 shoudn't be, equal NULL
//                                      partner of woman1 shoudn't be, equal NULL
//
//                     after married man1 and woman1
//                          object reference count of man1 shoud be increment equal 2
//                          object reference count of woman1 shoud equal 1
//                          partner of man1 shoud equal woman1
//                          partner of woman1 shoud equal man1
//                                  after married man2 and woman1
//                                      object reference count of man1 shoud be decrement, equal 1
//                                      object reference count of woman1 shoud equal 1
//                                      object reference count of man2 shoud be increment, equal 2
//                                      partner of man1 shoudn't be, shoud be change, equal NULL
//                                      partner of woman1 shoud equal man2
//                                      partner of man2 shoud equal woman1
//                                          after married man2 and woman2
//                                              object reference count of man1 shoud equal 1
//                                              object reference count of woman1 shoud equal 1
//                                              object reference count of man2 shoud equal 2
//                                              object reference count of woman2 shoud equal 1
//                                              partner of man1 shoud equal NULL
//                                              partner of woman1 shoud be change, shoudn't be, equal NULL
//                                              partner of man2 shoud change, equal woman2
//                                              partner of woman2 shoud changhe, equal man2
//                                                  after trying to marry woman2 and NULL, nothing not change
//                                                      object reference count of man2 shoud equal 2
//                                                      object reference count of woman2 shoud equal 1
//                                                      partner of man2 shoud equal woman2
//                                                      partner of woman2 shoud equal man2
//                                                          after trying to marry man2 and NULL, nothing not change
//                                                              object reference count of man2 shoud equal 2
//                                                              object reference count of woman2 shoud equal 1
//                                                              partner of man2 shoud equal woman2
//                                                              partner of woman2 shoud equal man2
//                                                                   after divorce woman2
//                                                                          object reference count of man2 shoud be change, shoud equal 1
//                                                                          object reference count of woman2 shoud equal 1
//                                                                          partner of man2 shoud change, shoud equal NULL
//                                                                          partner of woman2 shoud changhe, shoud equal NULL
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
//           man and woman shoud have array of child  not NULL
//           man and woman shoud have  fist element array of child equil NULL,
//           object reference count array of child for man and woman shoud equl 1
//           object reference count man and woman shoud equl 1
//           man and woman shoud have count of child equl 0
//                  after giving birth newBorn human from man and woman with gender TKAMale and
//                  after renaming name to newborn1
//                          man and woman shoud have array of child  not NULL
//                          man and woman shoud have  fist element array of child not NULL, equl newBorn
//                          object reference count array of child for man and woman shoud equl 1
//                          object reference count man and woman shoud equl 1
//                          man and woman shoud have count of child equl 1
//                          newBorn shoudn't be NULL
//                          array of child shoudn't be NULL
//                          first element of child array shoud be equil NULL
//                          name shoudn't be NULL
//                          age of newBorn shoud equil 0
//                          gender of newBorn shoud equil TKAMale
//                          object reference count array of child for newBorn shoud equil 1
//                          object reference count name of newBorn shoud equil 1
//                          object reference count of newBorn shoud equil 2
//                          child count shoud equal 0
//                          father of newBorn shoudn't be NULL, shoud equil man
//                          mother of newBorn shoudn't be NULL, shoud equil woman
//                              after giving birth next newBorn2 human from man and NULL
//                                  newBorn2 shoud be NULL
//                                  man and woman shoud have  fist element array of child not NULL, equl newBorn1
//                                  man and woman shoud have  second element array of child equil NULL
//                                  object reference count man and woman shoud equl 1
//                                  man and woman shoud have count of child equl 1
//                                      after giving birth next newBorn3 human from woman and NULL
//                                          newBorn3 shoud be NULL
//                                          man and woman shoud have  fist element array of child not NULL, equl newBorn1
//                                          man and woman shoud have  second element array of child equil NULL
//                                          object reference count man and woman shoud equl 1
//                                          man and woman shoud have count of child equl 1
//                                              after giving birth next newBorn4 human from NULL and NULL
//                                                  newBorn4 shoud be NULL
//                                                          after giving birth next newBorn5 human from man and newBorn1 (the same gender)
//                                                              newBorn5 shoud be NULL
//                                                              man, and newBorn1 shoudn't change
//                                                              man shoud have  fist element array of child not NULL, equl newBorn1
//                                                              man and newborn1 shoud have  second element array of child equil NULL
//                                                              object reference count man shoud equl 1
//                                                              object reference count newborn shoud equl 2
//                                                              man shoud have count of child equl 1
//                                                              newborn1 shoud have count of child equl 0
//                                                                       after releasing man ,woman, newborn1
//                                                                                  they shoud be deallocate
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
//          object reference count shoud equil 1
//          count of children shoud equil 0
//          firsst element of children array shoud be NULL
//          father of child shoud be NULL
//          mother of child shoud be NULL
//              after adding childMAle and ChildFemale to man
//                  man and woman object reference count shoud equil 1
//                  man count of children shoud equil 2
//                  firsst 2 element of children of man shoudn't be NULL, shoud equil childMAle and ChildFemale
//                  object reference count childMAle and ChildFemale shoud equal 2
//                  father each of childMAle and ChildFemale shoud be man
//                      after adding childMAle to man
//                          man object reference count shoud equil 1
//                          man count of children shoud equil 2
//                          firsst 2 element of children of man shoudn't be NULL, shoud equil childMAle and ChildFemale
//                          object reference count childMAle and ChildFemale shoud equal 2
//                          father each of childMAle and ChildFemale shoud be man
//                              after adding NULL child to man noting shoud be change
//                                  man and woman object reference count shoud equil 1
//                                  man count of children shoud equil 2
//                                  firsst 2 element of children of man shoudn't be NULL, shoud equil childMAle and ChildFemale
//                                      after adding childMale to man noting shoud be change
//                                          object reference count childMAle shoud equal 2
//                                          father each of childMAle shoud be man
//                                          mother each of childFeMAle shoud be woman
//                                              after removing ChildMale
//                                                  man object reference count shoud equil 1
//                                                  man count of children shoud equil 1
//                                                  firsst 2 element of children of man shoud equil childFemale and NULL
//                                                  object reference count childMAle shoud equal 1
//                                                  father childMAle shoud be NULL
//                                                       after removing ChildFemale
//                                                          man object reference count shoud equil 1
//                                                          man count of children shoud equil 0
//                                                          firsst 2 element of children of man shoud be NULL
//                                                          object reference count childMAle and ChildFemale shoud equal 1
//                                                          father each of childMAle and ChildFemale shoud be NULL
//
//                after adding childMAle to woman
//                    man and woman object reference count shoud equil 1
//                    woman count of children shoud equil 1
//                    firsst 2 element of children of woman shoud equil childMAle and NULL
//                     object reference count childMAle shoud equal 2
//                     mother childMAle shoud be woman
//                           after adding ChildFemale to woman
//                                  man and woman object reference count shoud equil 1
//                                  woman count of children shoud equil 2
//                                  firsst 2 element of children of woman shoudn't be NULL, shoud equil childMAle and ChildFemale
//                                  object reference count childMAle and ChildFemale shoud equal 2
//                                  mother each of childMAle and ChildFemale shoud be woman
//                                      after removing child man from woman nothing shoud ba change
//                                          man and woman object reference count shoud equil 1
//                                          woman count of children shoud equil 2
//                                          firsst 2 element of children of woman shoudn't be NULL, shoud equil childMAle and ChildFemale
//                                          object reference count childMAle and ChildFemale shoud equal 2
//                                          mother each of childMAle and ChildFemale shoud be woman
//                                              after removing all children
//                                                  woman object reference count shoud equil 1
//                                                  woman count of children shoud equil 0
//                                                  firsst element of children of woman shoud equil NULL
//                                                  object reference count childMAle and childFemAle shoud equal 1
//                                                  mother childMAle and childFemAle shoud be NULL
//                                                         after releasing man ,woman, childMAle and childFemAle
//                                                                  they shoud be deallocated

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
