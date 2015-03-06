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
void TKAHumanSetName(TKAHuman *human, TKAString *name);

static
void TKAHumanSetChildren(TKAHuman *human, TKAArray *children);

static
void TKAHumanSetPartner(TKAHuman *human1, TKAHuman *human2);

static
void TKAHumanSetFather(TKAHuman *human1, TKAHuman *human2);

static
void TKAHumanSetMother(TKAHuman *human1, TKAHuman *human2);

const uint8_t uint8ReturnError = 255;

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

void TKAHumanSetPartner(TKAHuman *human, TKAHuman *partner) {
    if (NULL == human) {
        return;
    }
    
    if (human->_partner != partner && human != partner) {
        if (NULL != human->_partner) {
            TKAObjectRelease(human->_partner);
        }
        
        human->_partner = partner;
        if (NULL != human->_partner) {
            TKAObjectRetain(partner);
        }
    }
}

void TKAHumanSetMother(TKAHuman *child, TKAHuman *parent) {
    if (NULL == child) {
        return;
    }
    
    if (child->_mother != parent && child != parent) {
        
        if (NULL != child->_mother) {
            TKAObjectRelease(child->_mother);
        }
        
        child->_mother = parent;
        if (NULL != child->_mother) {
            TKAObjectRetain(parent);
        }
    }
}

void TKAHumanSetFather(TKAHuman *child, TKAHuman *parent) {
    if (NULL == child) {
        return;
    }
    
    if (child->_father != parent && child != parent) {
        
        if (NULL != child->_father) {
            TKAObjectRelease(child->_father);
        }
        
        child->_father = parent;
        if (NULL != child->_father) {
            TKAObjectRetain(parent);
        }
        
    }
}

void TKAHumanSetName(TKAHuman *human, TKAString *name) {
    if (NULL == human) {
        return;
    }
    if (human->_name != name) {
        
        if (NULL != human->_name) {
            TKAObjectRelease(human->_name);
        }
        
        human->_name = name;
        if (NULL != human->_name) {
            TKAObjectRetain(name);
        }
        
    }
}

void TKAHumanSetChildren(TKAHuman *parent, TKAArray *children) {
    if (NULL == parent) {
        return;
    }
    
    if (parent->_children != children) {
        
        if (NULL != parent->_children) {
            TKAObjectRelease(parent->_children);
        }
        
        parent->_children = children;
        if (NULL != parent->_children) {
            TKAObjectRetain(children);
        }
        
    }
    
}

#pragma mark -
#pragma mark Public Implementations

void __TKAHumanDeallocate(TKAHuman *human) {
    TKAHumanSetName(human, NULL);
    TKAHumanSetChildren(human, NULL);
    TKAHumanSetPartner(human, NULL);
    TKAHumanSetMother(human, NULL);
    TKAHumanSetFather(human, NULL);

    __TKAObjectDeallocate(human);
}

TKAHuman *TKAHumanCreateWithNameString(TKAString *name, uint8_t age, TKAGender gender) {
    TKAHuman *human = TKAObjectCreate(TKAHuman);
    
    TKAHumanSetName(human, name);
    TKAHumanSetAge(human, age);
    TKAHumanSetGender(human, gender);
    TKAHumanSetChildCount(human, 0);

    TKAArray *arrayChild = TKAObjectCreate(TKAArray);
    TKAHumanSetChildren(human, arrayChild);
    TKAObjectRelease(arrayChild);
    
    return human;
}

TKAHuman *TKAHumanCreateWithNameChar(char *name, uint8_t age, TKAGender gender) {
    TKAHuman *human = TKAObjectCreate(TKAHuman);
    
    TKAHumanSetAge(human, age);
    TKAHumanSetGender(human, gender);
    TKAHumanSetChildCount(human, 0);
    
    if (NULL != name) {
        TKAString *newName = TKAObjectCreate(TKAString);
        TKAStringSetData(newName, name);
        TKAHumanSetName(human, newName);
        TKAObjectRelease(newName);
    }
    
    TKAArray *arrayChild = TKAObjectCreate(TKAArray);
    TKAHumanSetChildren(human, arrayChild);
    TKAObjectRelease(arrayChild);
    
    return human;
}

TKAHuman *TKAHumanCreate(uint8_t age, TKAGender gender){
    TKAHuman *human = TKAObjectCreate(TKAHuman);

    TKAHumanSetAge(human, age);
    TKAHumanSetGender(human, gender);
    TKAHumanSetChildCount(human, 0);

    TKAArray *arrayChild = TKAObjectCreate(TKAArray);
    TKAHumanSetChildren(human, arrayChild);
    TKAObjectRelease(arrayChild);

    return human;
}

void TKAHumanChangeName(TKAHuman *human, char *name) {
    if (NULL == human) {
        return;
    }
    
    if (NULL != name) {
        TKAString *newName = TKAObjectCreate(TKAString);
        TKAStringSetData(newName, name);
        TKAHumanSetName(human, newName);
        TKAObjectRelease(newName);
    }
    
}

TKAString *TKAHumanGetName(TKAHuman *human) {
    if (NULL == human) {
        return NULL;
    }
    
    return human->_name;
}

void TKAHumanSetAge(TKAHuman *human, uint8_t age) {
    if (NULL == human) {
        return;
    }
    
    human->_age = age;
}

uint8_t TKAHumanGetAge(TKAHuman *human) {
    if (NULL == human) {
        return uint8ReturnError;
    }
    return human->_age;
}

void TKAHumanSetGender(TKAHuman *human, TKAGender gender) {
    if (NULL == human) {
        return;
    }
    
    human->_gender = gender;
}

TKAGender TKAHumanGetGender(TKAHuman *human) {
    if (NULL == human) {
        return -1;
    }
    
    return human->_gender;
}

void TKAHumanSetChildCount(TKAHuman *human, uint8_t count) {
    if (NULL == human) {
        return;
    }
    
    human->_childCount = count;
}

uint8_t TKAHumanGetChildCount(TKAHuman *human) {
    if (NULL == human) {
        return uint8ReturnError ;
    }
    
    return human->_childCount;
}

TKAArray *TKAHumanGetChildren(TKAHuman *human) {
    if (NULL == human) {
        return NULL;
    }
    
    return human->_children;
}

TKAHuman *TKAHumanGetPartner(TKAHuman *human) {
    if (NULL == human) {
        return NULL;
    }
    
    return human->_partner;
}

TKAHuman *TKAHumanGetFather(TKAHuman *human) {
    if (NULL == human) {
        return NULL;
    }
    
    return human->_father;
}

TKAHuman *TKAHumanGetMother(TKAHuman *human) {
    if (NULL == human) {
        return NULL;
    }
    
    return human->_mother;
}

void TKAHumanDivorce(TKAHuman *human) {
    if (NULL != TKAHumanGetPartner(human) && human != TKAHumanGetPartner(human)) {

        TKAHumanSetPartner(TKAHumanGetPartner(human), NULL);
        TKAHumanSetPartner(human, NULL);
    }
    
}

void TKAHumanMarry(TKAHuman *partner1, TKAHuman *partner2) {
    if (partner1 != partner2 && NULL != partner1 && NULL != partner2) {
        if (partner1 != TKAHumanGetPartner(partner2) && partner2 != TKAHumanGetPartner(partner1) && TKAHumanGetGender(partner1) != TKAHumanGetGender(partner2)) {

            TKAHumanDivorce(partner1);
            TKAHumanDivorce(partner2);
            
            TKAHumanSetPartner(partner1, partner2);
            TKAHumanSetPartner(partner2, partner1);
        }
        
    }
}

void TKAHumanAddChild(TKAHuman *parent, TKAHuman *child) {
    if (child != parent) {
        if (NULL != child && NULL != parent) {
            
            if (NULL == TKAHumanGetChildren(parent)) {
                TKAArray *arrayChild = TKAObjectCreate(TKAArray);
                TKAHumanSetChildren(parent, arrayChild);
                TKAObjectRelease(arrayChild);
            }
            
            if (NULL != TKAHumanGetChildren(parent)) {
                TKAArrayAddChild(TKAHumanGetChildren(parent), child);
                
                if (TKAMale == TKAHumanGetGender(parent)) {
                    TKAHumanSetFather(child, parent);
                }
                
                // or else
                if (TKAFemale == TKAHumanGetGender(parent)) {
                    TKAHumanSetMother(child, parent);
                }
                
            }
            
            //MAKE WITH BOOL RESAULT
            parent->_childCount++;
        }
    }
}

TKAHuman *TKAHumanBorn(TKAHuman *father, TKAHuman *mother, TKAGender gender) {
    TKAHuman *newBorn = TKAObjectCreate(TKAHuman);
    
    TKAHumanSetAge(newBorn, 0);
    TKAHumanSetGender(newBorn, gender);
    TKAHumanSetChildCount(newBorn, 0);
    
    if (father != mother) {
        if (NULL != father) {
           TKAHumanAddChild(father, newBorn);
        }
        
        if (NULL != mother) {
            TKAHumanAddChild(mother, newBorn);
        }

    }
    
    TKAObjectRelease(newBorn);
    return newBorn;
}

void TKAHumanRemoveChild(TKAHuman *parent, TKAHuman *child) {
    if (child != parent && NULL != parent) {
        
        if (NULL != child) {
            TKAArrayRemoveChild(TKAHumanGetChildren(parent), child);
            
            if (TKAMale == TKAHumanGetGender(parent)) {
                TKAHumanSetFather(child, NULL);
            }
            
            // or else
            if (TKAFemale == TKAHumanGetGender(parent)) {
                TKAHumanSetMother(child, NULL);
            }
            //MAKE WITH BOOL RESAULT
            parent->_childCount--;
        }
        
    }
}

void TKAHumanRemoveAllChildren(TKAHuman *human) {
    if (NULL != human && NULL != TKAHumanGetChildren(human)) {

        TKAArrayRemoveAllChildren(TKAHumanGetChildren(human));
        
        TKAHumanSetChildren(human, NULL);
        human->_childCount = 0;
    }

}


