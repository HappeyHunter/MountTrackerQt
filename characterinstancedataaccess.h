#ifndef CHARACTERINSTANCEDATAACCESS_H
#define CHARACTERINSTANCEDATAACCESS_H

#include "characterinstance.h"

#include <QVector>
#include <QString>

class CharacterInstanceDataAccess
{
public:
    CharacterInstanceDataAccess();

    QVector<CharacterInstance> getAllByCharacterName(const QString& name);

    void update(CharacterInstance&);
    void resetAll();
};

#endif // CHARACTERINSTANCEDATAACCESS_H
