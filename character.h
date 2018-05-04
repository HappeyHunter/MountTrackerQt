#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>

class Character
{
public:
    enum WoWClass {
        Warrior,
        Paladin,
        Hunter,
        Rogue,
        Priest,
        DeathKnight,
        Shaman,
        Mage,
        Warlock,
        Monk,
        Druid,
        DemonHunter,
        ClassCount
    };

    Character();
    Character(QString name, WoWClass aClass);

    QString& getName();
    void setName(QString name);

    WoWClass getClass();
    void setClass(WoWClass aClass);

private:
    QString name;
    WoWClass charClass;
};

#endif // CHARACTER_H
