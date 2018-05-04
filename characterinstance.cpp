#include "characterinstance.h"

CharacterInstance::CharacterInstance()
{

}

CharacterInstance::CharacterInstance(QString aCharacterName, QString anInstanceName, bool isKilled) :
    characterName(aCharacterName),
    instanceName(anInstanceName),
    killed(isKilled) {

}

QString& CharacterInstance::getCharacterName() {
    return characterName;
}

void CharacterInstance::setCharacterName(QString& aCharacterName) {
    characterName = aCharacterName;
}

QString& CharacterInstance::getInstanceName() {
    return instanceName;
}

void CharacterInstance::setInstanceName(QString& anInstanceName) {
    instanceName = anInstanceName;
}

bool CharacterInstance::isKilled() {
    return killed;
}

void CharacterInstance::setKilled(bool isKilled) {
    killed = isKilled;
}

void CharacterInstance::toggleKilled() {
    killed = !killed;
}
