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

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

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

TKAHuman *TKAHumanCreate(TKAString *name, uint8_t age, TKAGender gender) {
    
    TKAHuman *human = TKAObjectCreate(TKAHuman);
    
    TKAHumanSetName(human, name);
    TKAHumanSetAge(human, age);
    TKAHumanSetGender(human, gender);
    TKAArray *arrayChild = TKAObjectCreate(TKAArray);
    TKAHumanSetChildren(human, arrayChild);
    TKAObjectRelease(arrayChild);
    
    return human;
}

void TKAHumanSetName(TKAHuman *human, TKAString *name) {
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

TKAString *TKAHumanGetName(TKAHuman *human) {
    return human->_name;
}

void TKAHumanSetAge(TKAHuman *human, uint8_t age) {
    human->_age = age;
}

uint8_t TKAHumanGetAge(TKAHuman *human) {
    return human->_age;
}

void TKAHumanSetGender(TKAHuman *human, TKAGender gender) {
    human->_gender = gender;
}

TKAGender TKAHumanGetGender(TKAHuman *human) {
    return human->_gender;
}

void TKAHumanSetCountChildren(TKAHuman *human, uint8_t count) {
    human->_countChildren = count;
}

uint8_t TKAHumanGetCountChildren(TKAHuman *human) {
    return human->_countChildren;
}

TKAArray *TKAHumanGetChildren(TKAHuman *human) {
    return human->_children;
}

void TKAHumanSetChildren(TKAHuman *parent, TKAArray *children) {
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

TKAHuman *TKAHumanGetPartner(TKAHuman *human) {
    return human->_partner;
}

void TKAHumanSetPartner(TKAHuman *partner1, TKAHuman *partner2) {
    if (partner1->_partner != partner2) {
        
        if (NULL != partner1->_partner) {
            TKAObjectRelease(partner1->_partner);
        }
        
        partner1->_partner = partner2;
        if (NULL != partner1->_partner) {
            TKAObjectRetain(partner2);
        }
        
    }
}

TKAHuman *TKAHumanGetFather(TKAHuman *human) {
    return human->_father;
}

void TKAHumanSetFather(TKAHuman *child, TKAHuman *parent) {
    if (child->_father != parent) {
        
        if (NULL != child->_father) {
            TKAObjectRelease(child->_father);
        }
        
        child->_father = parent;
        if (NULL != child->_father) {
            TKAObjectRetain(parent);
        }
        
    }
}

TKAHuman *TKAHumanGetMother(TKAHuman *human) {
    
    return human->_mother;
}

void TKAHumanSetMother(TKAHuman *child, TKAHuman *parent) {
    if (child->_mother != parent) {
        
        if (NULL != child->_mother) {
            TKAObjectRelease(child->_mother);
        }
        
        child->_mother = parent;
        if (NULL != child->_mother) {
            TKAObjectRetain(parent);
        }
        
    }
}

void TKAHumanDivorcePartner(TKAHuman *human) {
    if (NULL != TKAHumanGetPartner(human) && human != TKAHumanGetPartner(human)) {
        
        if (TKAHumanGetPartner(TKAHumanGetPartner(human)) == human) {
            TKAHumanDivorce(human, TKAHumanGetPartner(human));
            
        } else {
            TKAHumanSetPartner(human, NULL);
        }
        
    }
}

void TKAHumanDivorce(TKAHuman *partner1, TKAHuman *partner2) {
    if (partner1 != partner2 && NULL != partner1 && NULL != partner2) {
        
        if (partner1 == TKAHumanGetPartner(partner2) && partner2 == TKAHumanGetPartner(partner1)) {
            TKAHumanSetPartner(partner1, NULL);
            TKAHumanSetPartner(partner2, NULL);
        }
        
    }
}

void TKAHumanMarry(TKAHuman *partner1, TKAHuman *partner2) {
    if (partner1 != partner2 && NULL != partner1 && NULL != partner2) {
        
        if (NULL != TKAHumanGetPartner(partner1) && partner2 != TKAHumanGetPartner(partner1)) {
            TKAHumanDivorcePartner(partner1);
        }
        
        if (NULL != TKAHumanGetPartner(partner2) && partner1 != TKAHumanGetPartner(partner2)) {
            TKAHumanDivorcePartner(partner2);
        }
        
        TKAHumanSetPartner(partner1, partner2);
        TKAHumanSetPartner(partner2, partner1);
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
            parent->_countChildren++;
        }
    }
}

TKAHuman *TKAHumanBorn(TKAHuman *father, TKAHuman *mother, TKAGender gender) {
    TKAHuman *newBorn = TKAObjectCreate(TKAHuman);
    
    TKAHumanSetAge(newBorn, 0);
    TKAHumanSetGender(newBorn, gender);
    TKAHumanSetCountChildren(newBorn, 0);
    
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
            parent->_countChildren--;
        }
        
    }
}

void TKAHumanRemoveAllChildren(TKAHuman *human) {
    if (NULL != human && NULL != TKAHumanGetChildren(human)) {

        TKAArrayRemoveAllChildren(TKAHumanGetChildren(human));
        
        TKAHumanSetChildren(human, NULL);
        human->_countChildren = 0;
    }

}


