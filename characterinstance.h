#ifndef CHARACTERINSTANCE_H
#define CHARACTERINSTANCE_H

#include <QString>

class CharacterInstance
{
public:
    CharacterInstance();
    CharacterInstance(QString aCharacterName, QString anInstanceName, bool killed);

    QString& getCharacterName();
    void setCharacterName(QString& aCharacterName);

    QString& getInstanceName();
    void setInstanceName(QString& anInstanceName);

    bool isKilled();
    void setKilled(bool isKilled);
    void toggleKilled();

private:
    QString characterName;
    QString instanceName;
    bool killed;
};

#endif // CHARACTERINSTANCE_H
