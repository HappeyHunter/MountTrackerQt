#include "character.h"

Character::Character()
{

}

Character::Character(QString aName, WoWClass aClass) :
    name(aName),
    charClass(aClass) {
    
}

QString& Character::getName() {
    return name;
}

void Character::setName(QString aName) {
    name = aName;
}

Character::WoWClass Character::getClass() {
    return charClass;
}

void Character::setClass(WoWClass aClass) {
    charClass = aClass;
}
