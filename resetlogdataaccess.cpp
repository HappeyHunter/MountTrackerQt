#include "resetlogdataaccess.h"

#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVariant>

const QString ResetLogDataAccess::dateFormat = "yyyy-MM-dd";

ResetLogDataAccess::ResetLogDataAccess()
{

}

QDate ResetLogDataAccess::lastReset() {
    QSqlQuery query("SELECT LastReset FROM ResetLog", QSqlDatabase::database());

    while(query.next()) {
        return QDate::fromString(query.value(0).toString(), dateFormat);
    }

    QSqlQuery insertQuery(QSqlDatabase::database());
    insertQuery.prepare("INSERT INTO ResetLog VALUES(:date)");
    insertQuery.bindValue(":date", QDate::currentDate().toString(dateFormat));

    insertQuery.exec();

    return QDate::currentDate();
}

void ResetLogDataAccess::reset() {
    QSqlQuery update(QSqlDatabase::database());
    update.prepare("UPDATE ResetLog SET LastReset = :date");
    update.bindValue(":date", QDate::currentDate().toString(dateFormat));

    update.exec();
}
