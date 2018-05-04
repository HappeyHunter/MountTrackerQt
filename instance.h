#ifndef INSTANCE_H
#define INSTANCE_H

#include <QString>

class Instance
{
public:
    Instance();
    Instance(QString name, int bossCount, int killCount);

    QString& getName();
    void setName(QString name);

    int getBossCount();
    void setBossCount(int bossCount);

    int getKillCount();
    void setKillCount(int killCount);

    void incrementKills();
    void decrementKills();
    float getChanceForKills();

private:
    QString name;
    int bossCount;
    int killCount;
};

#endif // INSTANCE_H
