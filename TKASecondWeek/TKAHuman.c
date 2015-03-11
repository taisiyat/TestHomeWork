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
void TKAHumanSet(void **human1, void *human2);

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

const uint16_t arrayLength = 20;

#pragma mark -
#pragma mark Public Declarations

#pragma mark -
#pragma mark Privat Implementations

//void TKAHumanSet(void **human1, void *human2) {
//    if (human1 != human2) {
//        
//        if (NULL != *human1) {
//            TKAObjectRelease(*human1);
//        }
//        
//        *human1 = human2;
//        if (NULL != *human1) {
//            TKAObjectRetain(human2);
//        }
//        
//    }
//}
//
//void TKAHumanSetPartner(TKAHuman *human, TKAHuman *partner) {
// 
//    if (NULL == human) {
//        return;
//    }
//    
//    if (human != partner) {
//        TKAHumanSet(human->_partner, partner);
//    }
//
//}
//
//void TKAHumanSetMother(TKAHuman *child, TKAHuman *parent) {
//  
//    if (NULL == child) {
//        return;
//    }
//    
//    if (child != parent) {
//       TKAHumanSet(child->_mother, parent);
//    }
//    
//}
//
//void TKAHumanSetFather(TKAHuman *child, TKAHuman *parent) {
//   
//    if (NULL == child) {
//        return;
//    }
//    
//    if (child != parent) {
//        TKAHumanSet(child->_father, parent);
//    }
//    
//}
//
//void TKAHumanSetParent(TKAHuman *child, TKAHuman *parent) {
//    if (NULL == child) {
//        return;
//    }
//    
//    if (child != parent) {
//        if (TKAMale == TKAHumanGetGender(parent)) {
//            TKAHumanSet(child->_father, parent);
//
//        } else {
//            TKAHumanSet(child->_mother, parent);
//            
//        }
//    }
//    
//}

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
   //
    TKAArraySetLength(arrayChild, arrayLength);
   //
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
    //
    TKAArraySetLength(arrayChild, arrayLength);
    //
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
        return UINT8_MAX;
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
        return UINT8_MAX ;
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
        TKAArray *tempArraychild = TKAHumanGetChildren(parent);
        if (NULL != child && NULL != parent && NULL != tempArraychild) {
            if (UINT16_MAX == TKAArrayGetIndexOfChild(tempArraychild, child)) {

                uint16_t indexAddChild = TKAArrayGetIndexOfFirstNullChild(tempArraychild);
                TKAArrayAddChildAtIndex(tempArraychild, child, indexAddChild);
                TKAHumanSetChildCount(parent, TKAHumanGetChildCount(parent)+1);

                if (TKAMale == TKAHumanGetGender(parent)) {
                    TKAHumanSetFather(child, parent);
           
                } else {
 
                    TKAHumanSetMother(child, parent);
                }

            }
        }
    }
}
//void TKAHumanAddChild(TKAHuman *parent, TKAHuman *child) {
//    if (child != parent) {
//
//        if (NULL != child && NULL != parent && NULL != TKAHumanGetChildren(parent)) {
//            if (UINT16_MAX == TKAArrayGetIndexOfChild(TKAHumanGetChildren(parent), child)) {
//                
//                uint16_t childCount = TKAArrayGetIndexOfFirstNullChild(TKAHumanGetChildren(parent));
//                TKAArrayAddChildAtIndex(TKAHumanGetChildren(parent), child, childCount);
//                TKAHumanSetChildCount(parent, TKAHumanGetChildCount(parent)+1);
//                
//                if (TKAMale == TKAHumanGetGender(parent)) {
//                    TKAHumanSetFather(child, parent);
//                    
//                } else {
//                    
//                    TKAHumanSetMother(child, parent);
//                }
//                
//            }
//        }
//    }
//}

TKAHuman *TKAHumanBirth(TKAHuman *father, TKAHuman *mother, TKAGender gender) {
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
        TKAArray *tempChildArray = TKAHumanGetChildren(parent);
        if (NULL != tempChildArray){
            TKAArrayRemoveChild(tempChildArray, child);
        
            if (TKAMale == TKAHumanGetGender(parent)) {
                TKAHumanSetFather(child, NULL);
                
            } else {
            
                TKAHumanSetMother(child, NULL);
            }
        
            uint8_t childCount = TKAHumanGetChildCount(parent);
            TKAHumanSetChildCount(parent, childCount-1);
        }
    }
}

//void TKAHumanRemoveAllChildren(TKAHuman *human) {
//    if (NULL != human && NULL != TKAHumanGetChildren(human)) {
//       
//        if (0 != TKAArrayGetIndexOfLastChild(TKAHumanGetChildren(human)) && UINT16_MAX != TKAArrayGetIndexOfLastChild(TKAHumanGetChildren(human))) {
//            for (uint8_t iter = 0; iter <= TKAArrayGetIndexOfLastChild(TKAHumanGetChildren(human)); iter++) {
//                if (NULL != TKAArrayGetChildAtIndex(TKAHumanGetChildren(human), iter)) {
//                    TKAHumanRemoveChild(human, TKAArrayGetChildAtIndex(TKAHumanGetChildren(human), iter));
//                }
//            }
//        }
//        
//    }
//}

void TKAHumanRemoveAllChildren(TKAHuman *human) {
    if (NULL != human && NULL != TKAHumanGetChildren(human)) {
        TKAArray *tempChildArray = TKAHumanGetChildren(human);
        uint16_t tempIndexOfChild = TKAArrayGetIndexOfLastChild(tempChildArray);
        if (0 != tempIndexOfChild && UINT16_MAX != tempIndexOfChild) {
            for (uint8_t iter = 0; iter <= tempIndexOfChild; iter++) {
                if (NULL != TKAArrayGetChildAtIndex(tempChildArray, iter)) {
                    TKAHumanRemoveChild(human, TKAArrayGetChildAtIndex(tempChildArray, iter));
                }
            }
        }
   }
}

