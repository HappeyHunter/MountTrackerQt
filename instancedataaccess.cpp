#include "instancedataaccess.h"

#include <QSqlQuery>
#include <QVariant>

enum Field { Name, BossCount, KillCount};

InstanceDataAccess::InstanceDataAccess()
{

}

QVector<Instance> InstanceDataAccess::getInstances() {
    QVector<Instance> results;
    QSqlQuery query("SELECT Name, BossCount, KillCount FROM Instances", QSqlDatabase::database());

    while(query.next()) {
        Instance anIns(query.value(Name).toString(), query.value(BossCount).toInt(), query.value(KillCount).toInt());
        results.append(anIns);
    }

    return results;
}

void InstanceDataAccess::addInstance(Instance& anInstance) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO Instances ( Name, BossCount, KillCount) VALUES (:name, :bossCount, :killCount)");
    query.bindValue(":name", anInstance.getName());
    query.bindValue(":bossCount", anInstance.getBossCount());
    query.bindValue(":killCount", anInstance.getKillCount());

    query.exec();
}

void InstanceDataAccess::update(Instance& update) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("UPDATE Instances SET KillCount = :killCount WHERE Name = :name");
    query.bindValue(":killCount", update.getKillCount());
    query.bindValue(":name", update.getName());

    query.exec();
}
