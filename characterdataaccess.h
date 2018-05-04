#ifndef CHARACTERDATAACCESS_H
#define CHARACTERDATAACCESS_H

#include <QVector>
#include <QSqlDatabase>

#include "character.h"

class CharacterDataAccess
{
public:
    CharacterDataAccess();

    QVector<Character> getCharacters();
    void addCharacter(Character& aCharacter);
};

#endif // CHARACTERDATAACCESS_H
