#include "instance.h"

#include <math.h>

Instance::Instance()
{

}

Instance::Instance(QString aName, int aBossCount, int aKillCount) :
    name(aName),
    bossCount(aBossCount),
    killCount(aKillCount) {

}

QString& Instance::getName() {
    return name;
}

void Instance::setName(QString aName) {
    name = aName;
}

int Instance::getBossCount() {
    return bossCount;
}

void Instance::setBossCount(int aBossCount) {
    bossCount = aBossCount;
}

int Instance::getKillCount() {
    return killCount;
}

void Instance::setKillCount(int aKillCount) {
    killCount = aKillCount;
}

void Instance::incrementKills() {
    killCount++;
}

void Instance::decrementKills() {
    killCount--;
}

float Instance::getChanceForKills() {
    return (1 - pow(0.99, killCount))*100;
}
