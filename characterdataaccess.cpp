#include "characterdataaccess.h"

#include <QSqlQuery>
#include <QVariant>

enum Field { Name, Class};

CharacterDataAccess::CharacterDataAccess()
{

}

QVector<Character> CharacterDataAccess::getCharacters() {
    QVector<Character> results;
    QSqlQuery query("SELECT Name, Class FROM Characters", QSqlDatabase::database());
    
    while(query.next()) {
        Character aChar(query.value(Name).toString(), (Character::WoWClass) query.value(Class).toInt());
        results.append(aChar);
    }
    
    return results;
}

void CharacterDataAccess::addCharacter(Character &aCharacter) {
    QSqlQuery query(QSqlDatabase::database());
    query.prepare("INSERT INTO Characters (Name, Class) VALUES (:name, :class)");
    query.bindValue(":name", aCharacter.getName());
    query.bindValue(":class", aCharacter.getClass());

    query.exec();
}
