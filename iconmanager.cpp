#include "iconmanager.h"

#include "character.h"

IconManager::IconManager() : icons(Character::WoWClass::ClassCount)
{
    icons.replace(Character::WoWClass::Warrior, QIcon(":/warriorIcon.png"));
    icons.replace(Character::WoWClass::Paladin, QIcon(":/paladinIcon.png"));
    icons.replace(Character::WoWClass::Hunter, QIcon(":/hunterIcon.png"));
    icons.replace(Character::WoWClass::Rogue, QIcon(":/rogueIcon.png"));
    icons.replace(Character::WoWClass::Priest, QIcon(":/priestIcon.png"));
    icons.replace(Character::WoWClass::DeathKnight, QIcon(":/DKIcon.png"));
    icons.replace(Character::WoWClass::Shaman, QIcon(":/shamanIcon.png"));
    icons.replace(Character::WoWClass::Mage, QIcon(":/mageIcon.png"));
    icons.replace(Character::WoWClass::Warlock, QIcon(":/warlockIcon.png"));
    icons.replace(Character::WoWClass::Monk, QIcon(":/monkIcon.png"));
    icons.replace(Character::WoWClass::Druid, QIcon(":/druidIcon.png"));
    icons.replace(Character::WoWClass::DemonHunter, QIcon(":/demonHunterIcon.jpg"));
}

const QIcon& IconManager::getClassIcon(Character::WoWClass aClass) {
    return icons.at(aClass);
}
