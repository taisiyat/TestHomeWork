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

static
const uint8_t TKAHumanReturnError = UINT8_MAX;

static
void TKAAssign(void **humanFild, void *human);

static
void TKAUniversalSet(void **humanFild, void *human);

static
void TKAHumanSet(void **humanFild, void *human);

static
void TKAHumanSetArrayOfChildren(TKAHuman *human, TKAArray *children);

static
void TKAHumanSetPartner(TKAHuman *human, TKAHuman *partner);

static
void TKAHumanSetFather(TKAHuman *child, TKAHuman *parent);

static
void TKAHumanSetMother(TKAHuman *child, TKAHuman *parent);

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

void TKAAssign(void **humanFild, void *human) {
    if (*humanFild != human ) {
        *humanFild = human;
    }
}

void TKAUniversalSet(void **humanFild, void *human) {
    if (*humanFild != human) {
        if (NULL != *humanFild) {
            TKAObjectRelease(*humanFild);
        }
        
        *humanFild = human;
        if (NULL != *humanFild) {
            TKAObjectRetain(human);
        }
    }
}

void TKAHumanSetPartner(TKAHuman *human, TKAHuman *partner) {
    if (NULL != human && human != partner) {
        if ((TKAHumanGetGender(human) == TKAFemale)) {
             TKAUniversalSet((void *)&human->_partner, partner);
            
            if (human->_partner != NULL) {
                TKAAssign((void *)&partner->_partner, human);
            }

        } else {
            TKAAssign((void *)&human->_partner, partner);
        }
    }
}

//void TKAHumanSetPartner(TKAHuman *human, TKAHuman *partner) {
//    if (NULL == human) {
//        return;
//    }
//    if (human->_partner != partner) {
//        if (TKAHumanGetGender(human) == TKAFemale) {
//             if (NULL != human->_partner) {
//                (human->_partner)->_partner = NULL;
//                TKAObjectRelease(human->_partner);
//             }
//            
//            human->_partner = partner;
//
//            if (NULL != human->_partner) {
//                TKAObjectRetain(partner);
//                partner->_partner = human;
//            }
//        } else {
//            
////        human->_partner = partner;
//        }
//    }
//}

void TKAHumanSet(void **humanFild, void *human) {
    if (*humanFild != human) {
        if (NULL != *humanFild) {
            TKAObjectRelease(*humanFild);
        }
        
        *humanFild = human;
        if (NULL != *humanFild) {
            TKAObjectRetain(human);
        }
    }
}

//void TKAHumanSetPartner(TKAHuman *human, TKAHuman *partner) {
//     if (NULL == human) {
//        return;
//    }
// 
//    if (human != partner) {
//        TKAHumanSet((void *)&human->_partner, partner);
//    }
//}

void TKAHumanSetMother(TKAHuman *child, TKAHuman *parent) {
    if (NULL != child && child != parent) {
       TKAHumanSet((void *)&child->_mother, parent);
    }
}

void TKAHumanSetFather(TKAHuman *child, TKAHuman *parent) {
    if (NULL != child && child != parent) {
        TKAHumanSet((void *)&child->_father, parent);
    }
}

void TKAHumanSetArrayOfChildren(TKAHuman *parent, TKAArray *children) {
    if (NULL != parent) {
        TKAHumanSet((void *)&parent->_children, children);
    }
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
        TKAHumanSet((void *)&human->_name, name);
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


TKAString *TKAHumanGetName(TKAHuman *human) {
    return (NULL == human) ? NULL : human->_name;
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
    return (NULL == human) ? TKAHumanReturnError : human->_gender; 
}

uint16_t TKAHumanGetChildCount(TKAHuman *human) {
    return (NULL == human) ? TKAHumanReturnError : TKAArrayGetChildCount(human->_children);
}

TKAArray *TKAHumanGetArrayOfChildren(TKAHuman *human) {
    return (NULL == human) ? NULL : human->_children;
}

TKAHuman *TKAHumanGetPartner(TKAHuman *human) {
    return (NULL == human) ? NULL : human->_partner;
}

TKAHuman *TKAHumanGetFather(TKAHuman *human) {
    return (NULL == human) ? NULL : human->_father;
}

TKAHuman *TKAHumanGetMother(TKAHuman *human) {
    return (NULL == human) ? NULL : human->_mother;
}

void TKAHumanDivorce(TKAHuman *human) {
    if (NULL != TKAHumanGetPartner(human) && human != TKAHumanGetPartner(human)
        && TKAFemale == TKAHumanGetGender(human)) {
        
        TKAHumanSetPartner(TKAHumanGetPartner(human), NULL);
        TKAHumanSetPartner(human, NULL);
    }
}

void TKAHumanMarry(TKAHuman *partner1, TKAHuman *partner2) {
    if (partner1 != partner2 && NULL != partner1 && NULL != partner2) {
        if (TKAHumanGetGender(partner1) != TKAHumanGetGender(partner2)) {
            if (TKAFemale == TKAHumanGetGender(partner1)) {
               if (NULL == TKAHumanGetPartner(partner2)) {
                    TKAHumanDivorce(partner1);
                    TKAHumanSetPartner(partner1, partner2);
               }
                
            } else if (NULL == TKAHumanGetPartner(partner1)) {
                TKAHumanDivorce(partner2);
                TKAHumanSetPartner(partner2, partner1);
           }
//            TKAHumanDivorce(partner1);
//            TKAHumanDivorce(partner2);
//            
//            TKAHumanSetPartner(partner1, partner2);
//            TKAHumanSetPartner(partner2, partner1);
        }
    }
}

void TKAHumanAddChild(TKAHuman *parent, TKAHuman *child) {
    if (NULL != child && NULL != parent && child != parent) {
        TKAArray *arrayOfChild = TKAHumanGetArrayOfChildren(parent);
        if (NULL != arrayOfChild) {
                TKAArrayAddChild(arrayOfChild, child);

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
        TKAArray *arrayOfChildren = TKAHumanGetArrayOfChildren(parent);
        if (NULL != arrayOfChildren){
            TKAArrayRemoveOfChild(arrayOfChildren, child);
        
            if (TKAMale == TKAHumanGetGender(parent)) {
                TKAHumanSetFather(child, NULL);
                
            } else {
          
                TKAHumanSetMother(child, NULL);
            }
        }
    }
}

void TKAHumanRemoveAllChildren(TKAHuman *human) {
    if (NULL != human) {
        TKAArray *arrayOfChildren = TKAHumanGetArrayOfChildren(human);
        if ( NULL != arrayOfChildren) {
            uint16_t indexOfChild = TKAArrayGetIndexOfLastChild(arrayOfChildren);
            if (0 != indexOfChild &&  TKAArrayReturnError != indexOfChild) {
                for (uint8_t iter = 0; iter <= indexOfChild; iter++) {
                    TKAHumanRemoveChild(human, TKAArrayGetChildAtIndex(arrayOfChildren, iter));
                }
            }
        }
    }
}
