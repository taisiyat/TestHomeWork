//
//  TKAHumanStruct.c
//  TKASecondWeek
//
//  Created by Taisiya on 17.02.15.
//  Copyright (c) 2015 TKhomeWork. All rights reserved.
//

#include "TKAHumanStruct.h"
#include "TKAArrayStruct.h"

#pragma mark -
#pragma mark Private Declarations

static
void TKAHumanStructDealloc(TKAHumanStruct *human);

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

void TKAHumanStructDealloc(TKAHumanStruct *human) {
    TKAHumanStructSetName(human, NULL);
    TKAHumanStructSetChildren(human, NULL);
    TKAHumanStructSetPartner(human, NULL);
    TKAHumanStructSetMother(human, NULL);
    TKAHumanStructSetFather(human, NULL);

    free(human);
}

#pragma mark -
#pragma mark Public Implementations

TKAHumanStruct *TKAHumanStructCreate() {
    TKAHumanStruct *human = calloc(1, sizeof(*human));
    human->_referenceCount = 1;
    
    return human;
}

void TKAHumanStructRetain(TKAHumanStruct *human) {
    human->_referenceCount++;
}

void TKAHumanStructRelease(TKAHumanStruct *human) {
    human->_referenceCount--;
    
    if (0 == human->_referenceCount){
        TKAHumanStructDealloc(human);
    }
}

void TKAHumanStructSetName(TKAHumanStruct *human, TKAStringStruct *name) {
    if (human->_name != name) {
        
        if (NULL != human->_name) {
            TKAStringStructRelease(human->_name);
        }
        
        human->_name = name;
        
        if (NULL != human->_name) {
            TKAStringStructRetain(name);
        }
        
    }
}

TKAStringStruct *TKAHumanStructGetName(TKAHumanStruct *human) {
    
    return human->_name;
}

void TKAHumanStructSetAge(TKAHumanStruct *human, uint8_t age) {
    human->_age = age;
}

uint8_t TKAHumanStructGetAge(TKAHumanStruct *human) {
    
    return human->_age;
}

void TKAHumanStructSetGender(TKAHumanStruct *human, TKAGenderStruct gender) {
    human->_gender = gender;
}

TKAGenderStruct TKAHumanStructGetGender(TKAHumanStruct *human) {
    
    return human->_gender;
}

void TKAHumanStructSetCountChildren(TKAHumanStruct *human, uint8_t count) {
    human->_countChildren = count;
}

uint8_t TKAHumanStructGetCountChildren(TKAHumanStruct *human) {
    
    return human->_countChildren;
}

TKAArrayStruct *TKAHumanStructGetChildren(TKAHumanStruct *human) {
    
    return human->_children;
}

void TKAHumanStructSetChildren(TKAHumanStruct *parent, TKAArrayStruct *children) {
    if (parent->_children != children) {
    
        if (NULL != parent->_children) {
            TKAArrayStructRelease(parent->_children);
        }
        
        parent->_children = children;
        
        if (NULL != parent->_children) {
            TKAArrayStructRetain(children);
        }
        
    }
}

TKAHumanStruct *TKAHumanStructGetPartner(TKAHumanStruct *human) {

    return human->_partner;
}

void TKAHumanStructSetPartner(TKAHumanStruct *partner1, TKAHumanStruct *partner2) {
    if (partner1->_partner != partner2) {
        
        if (NULL != partner1->_partner) {
            TKAHumanStructRelease(partner1->_partner);
        }
        
        partner1->_partner = partner2;
        
        if (NULL != partner1->_partner) {
            TKAHumanStructRetain(partner2);
        }
        
    }
}

TKAHumanStruct *TKAHumanStructGetFather(TKAHumanStruct *human) {
    
    return human->_father;
}

void TKAHumanStructSetFather(TKAHumanStruct *child, TKAHumanStruct *parent) {
    if (child->_father != parent) {

        if (NULL != child->_father) {
            TKAHumanStructRelease(child->_father);
        }
        
        child->_father = parent;
        
        if (NULL != child->_father) {
            TKAHumanStructRetain(parent);
        }
        
    }
}

TKAHumanStruct *TKAHumanStructGetMother(TKAHumanStruct *human) {
    
    return human->_mother;
}

void TKAHumanStructSetMother(TKAHumanStruct *child, TKAHumanStruct *parent) {
    if (child->_mother != parent) {
        
        if (NULL != child->_mother) {
            TKAHumanStructRelease(child->_mother);
        }
        
        child->_mother = parent;
        
        if (NULL != child->_mother) {
            TKAHumanStructRetain(parent);
        }
        
    }
}

void TKAHumanStructDivorcePartner(TKAHumanStruct *human) {
    if (NULL != TKAHumanStructGetPartner(human) && human != TKAHumanStructGetPartner(human)) {

        if (TKAHumanStructGetPartner(TKAHumanStructGetPartner(human)) == human) {
            TKAHumanStructDivorce(human, TKAHumanStructGetPartner(human));
        } else {
            TKAHumanStructSetPartner(human, NULL);
        }
        
    }
}

void TKAHumanStructDivorce(TKAHumanStruct *partner1, TKAHumanStruct *partner2) {
    if (partner1 != partner2 && NULL != partner1 && NULL != partner2) {
  
        if (partner1 == TKAHumanStructGetPartner(partner2) && partner2 == TKAHumanStructGetPartner(partner1)) {
            TKAHumanStructSetPartner(partner1, NULL);
            TKAHumanStructSetPartner(partner2, NULL);
        }
        
    }
}

void TKAHumanStructMarry(TKAHumanStruct *partner1, TKAHumanStruct *partner2) {
    if (partner1 != partner2 && NULL != partner1 && NULL != partner2) {
        
        if (NULL != TKAHumanStructGetPartner(partner1)) {
            TKAHumanStructDivorcePartner(partner1);
        }
        
        if (NULL != TKAHumanStructGetPartner(partner2)) {
            TKAHumanStructDivorcePartner(partner2);
        }
        
        TKAHumanStructSetPartner(partner1, partner2);
        TKAHumanStructSetPartner(partner2, partner1);
    }
}

void TKAHumanStructAddChild(TKAHumanStruct *parent, TKAHumanStruct *child) {
    if (child != parent) {
        if (NULL != child) {
            
            if (NULL == TKAHumanStructGetChildren(parent)) {
                TKAArrayStruct *arrayChild = TKAArrayStructCreate();
                TKAHumanStructSetChildren(parent, arrayChild);
            }
            
            if (NULL != TKAHumanStructGetChildren(parent)) {
                TKAArrayStructAddChild(TKAHumanStructGetChildren(parent), child);
            }
            
            //MAKE WITH BOOL RESAULT
            parent->_countChildren++;
        }
    }
}

TKAHumanStruct *TKAHumanStructBorn(TKAHumanStruct *father, TKAHumanStruct *mother, TKAGenderStruct gender) {
    TKAHumanStruct *newBorn = TKAHumanStructCreate();
    
    TKAHumanStructSetAge(newBorn, 0);
    TKAHumanStructSetGender(newBorn, gender);
    TKAHumanStructSetCountChildren(newBorn, 0);
    
    if (NULL != father) {
        TKAHumanStructAddChild(father, newBorn);
        TKAHumanStructSetFather(newBorn, father);
    }
    if (father !=mother && NULL != mother) {
        TKAHumanStructAddChild(mother, newBorn);
        TKAHumanStructSetMother(newBorn, mother);
    }
        
    return newBorn;
}



