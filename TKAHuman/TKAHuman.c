//
//  TKAHuman.c
//  TKASecondWeek
//
//  Created by Taisiya on 01.03.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAHuman.h"
#include "TKAArray.h"

#pragma mark -
#pragma mark Private Declarations

const uint8_t TKAHumanReturnError = UINT8_MAX;

static
void TKAHumanSetArrayOfChildren(TKAHuman *human, TKAArray *children);

static
void TKAHumanSetPartner(TKAHuman *human, TKAHuman *partner);

static
void TKAHumanSetFather(TKAHuman *child, TKAHuman *parent);

static
void TKAHumanSetMother(TKAHuman *child, TKAHuman *parent);

static
bool TKAHumanIsMarred(TKAHuman *human);

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

void TKAHumanSetPartner(TKAHuman *human, TKAHuman *partner) {
    if (NULL != human && human != partner) {
        if ((TKAHumanGetGender(human) == TKAFemale)) {
//            if (human->_partner != NULL) {
//                TKAPropertyAssignSet((void *)&partner->_partner, human);
//            }
            
            TKAPropertyRetainSet((void *)&human->_partner, partner);

        } else {
            
            TKAPropertyAssignSet((void *)&human->_partner, partner);
        }
    }
}

void TKAHumanSetMother(TKAHuman *child, TKAHuman *parent) {
    if (NULL != child && child != parent) {
//       TKAPropertyRetainSet((void *)&child->_mother, parent);
        TKAPropertyAssignSet((void *)&child->_mother, parent);
    }
}

void TKAHumanSetFather(TKAHuman *child, TKAHuman *parent) {
    if (NULL != child && child != parent) {
//        TKAPropertyRetainSet((void *)&child->_father, parent);
        TKAPropertyAssignSet((void *)&child->_father, parent);
    }
}

void TKAHumanSetArrayOfChildren(TKAHuman *parent, TKAArray *children) {
    if (NULL != parent) {
        TKAPropertyRetainSet((void *)&parent->_children, children);
    }
}

bool TKAHumanIsMarred(TKAHuman *human) {
    return (NULL != TKAHumanGet(partner, human)) ? true : false;
}

#pragma mark -
#pragma mark Public Implementations

void __TKAHumanDeallocate(TKAHuman *human) {
    TKAHumanSetName(human, NULL);
    TKAHumanSetArrayOfChildren(human, NULL);
    TKAHumanSetPartner(human, NULL);
    TKAHumanSetMother(human, NULL);
    TKAHumanSetFather(human, NULL);

    __TKAObjectDeallocate(human);
}

void TKAHumanSetName(TKAHuman *human, TKAString *name) {
    if (NULL != human) {
        TKAPropertyRetainSet((void *)&human->_name, name);
    }
}

TKAHuman *TKAHumanCreateWithNameString(TKAString *name, uint8_t age, TKAGender gender) {
    TKAHuman *human = TKAHumanCreate(age, gender);
    
    TKAHumanSetName(human, name);
    
    return human;
}

TKAHuman *TKAHumanCreate(uint8_t age, TKAGender gender) {
    TKAHuman *human = TKAObjectCreate(TKAHuman);

    TKAHumanSetAge(human, age);
    TKAHumanSetGender(human, gender);

    TKAArray *arrayChild = TKAObjectCreate(TKAArray);
    TKAHumanSetArrayOfChildren(human, arrayChild);
    TKAObjectRelease(arrayChild);

    return human;
}

void TKAHumanSetAge(TKAHuman *human, uint8_t age) {
    if (NULL != human) {
        human->_age = age;
    }
}

uint8_t TKAHumanGetAge(TKAHuman *human) {
    return (NULL == human) ? TKAHumanReturnError : human->_age;
}

void TKAHumanSetGender(TKAHuman *human, TKAGender gender) {
    if (NULL != human) {
        human->_gender = gender;
    }
}

TKAGender TKAHumanGetGender(TKAHuman *human) {
    return (NULL == human) ? TKANone : human->_gender;
}

uint16_t TKAHumanGetChildCount(TKAHuman *human) {
    return (NULL == human) ? 0 : TKAArrayGetObjectCount(human->_children);
}

TKAHumanGetImplementation(partner);

TKAHumanGetImplementation(father);

TKAHumanGetImplementation(mother);

TKAHumanGetImplementation(name);

TKAHumanGetImplementation(children);

void TKAHumanDivorce(TKAHuman *human) {
    if (TKAHumanIsMarred(human) && human != TKAHumanGet(partner, human)
        /*&& TKAFemale == TKAHumanGetGender(human)*/) {
        
        TKAHumanSetPartner(TKAHumanGet(partner, human), NULL);
        TKAHumanSetPartner(human, NULL);
    }
}

void TKAHumanMarry(TKAHuman *partner1, TKAHuman *partner2) {
    if (partner1 != partner2 && NULL != partner1 && NULL != partner2) {
        if (TKAHumanGetGender(partner1) != TKAHumanGetGender(partner2)) {
//            if (TKAFemale == TKAHumanGetGender(partner1)) {
//               if (!TKAHumanIsMarred(partner2)) {
//                    TKAHumanDivorce(partner1);
//                    TKAHumanSetPartner(partner1, partner2);
//               }
//                
//            } else if (!TKAHumanIsMarred(partner1)) {
//                TKAHumanDivorce(partner2);
//                TKAHumanSetPartner(partner2, partner1);
//           }
            TKAHumanDivorce(partner1);
            TKAHumanDivorce(partner2);
            
            TKAHumanSetPartner(partner1, partner2);
            TKAHumanSetPartner(partner2, partner1);
        }
    }
}

void TKAHumanAddChild(TKAHuman *parent, TKAHuman *child) {
    if (NULL != child && NULL != parent && child != parent) {
        TKAArray *array = TKAHumanGet(children, parent);
        if (NULL != array) {
                TKAArrayAddObject(array, child);

                if (TKAMale == TKAHumanGetGender(parent)) {
                    TKAHumanSetFather(child, parent);
           
                } else {
 
                    TKAHumanSetMother(child, parent);
                }
        }
    }
}

TKAHuman *TKAHumanGiveBirth(TKAHuman *father, TKAHuman *mother, TKAGender gender) {
    if (NULL != father || NULL != mother ) {
        TKAHuman *newBorn = TKAHumanCreate(0, gender);

        if (NULL != father ) {
            TKAHumanAddChild(father, newBorn);
        }
    
        if (father != mother && NULL != mother) {
            TKAHumanAddChild(mother, newBorn);
        }
    
        TKAObjectRelease(newBorn);
    
        return newBorn;
    }
    
    return NULL;
}

void TKAHumanRemoveChild(TKAHuman *parent, TKAHuman *child) {
    if (child != parent && NULL != parent && NULL != child) {
        TKAArray *array = TKAHumanGet(children, parent);
        if (NULL != array){
            if (TKAMale == TKAHumanGetGender(parent)) {
                TKAHumanSetFather(child, NULL);
                
            } else {
                TKAHumanSetMother(child, NULL);
            }
            
            TKAArrayRemoveObject(array, child);
        }
    }
}

void TKAHumanRemoveAllChildren(TKAHuman *human) {
    if (NULL != human) {
        TKAArray *array = TKAHumanGet(children, human);
        uint16_t childCount = TKAHumanGetChildCount(human);
        
        if (NULL != array && 0 != childCount) {
            for (uint8_t iter = childCount; iter > 0; iter--) {
            TKAHumanRemoveChild(human, TKAArrayGetObjectAtIndex(array, iter - 1));
            }
        }
    }
}
