#include "characterinstancedataaccess.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>

enum Field { CharacterName, InstanceName, Killed};

CharacterInstanceDataAccess::CharacterInstanceDataAccess()
{

}

QVector<CharacterInstance> CharacterInstanceDataAccess::getAllByCharacterName(const QString& name) {
    QVector<CharacterInstance> results;
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("SELECT CI.CharacterName, CI.InstanceName, CI.Killed FROM CharacterInstances CI JOIN Instances I ON CI.InstanceName = I.Name WHERE CI.CharacterName = :name ORDER BY I.KillCount DESC");
    query.bindValue(":name", name);
    query.exec();

    while(query.next()) {
        CharacterInstance aChar(query.value(CharacterName).toString(), query.value(InstanceName).toString(), query.value(Killed).toBool());
        results.append(aChar);
    }

    return results;
}

void CharacterInstanceDataAccess::update(CharacterInstance& update) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE CharacterInstances SET Killed = :killed WHERE CharacterName = :characterName AND InstanceName = :instanceName");
    query.bindValue(":killed", update.isKilled());
    query.bindValue(":characterName", update.getCharacterName());
    query.bindValue(":instanceName", update.getInstanceName());

    query.exec();
}

void CharacterInstanceDataAccess::resetAll() {
    QSqlQuery("UPDATE CharacterInstances SET Killed = 'FALSE'", QSqlDatabase::database()).exec();
}
