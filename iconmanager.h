#ifndef ICONMANAGER_H
#define ICONMANAGER_H

#include <QIcon>

#include "character.h"

class IconManager
{
public:
    IconManager();

    const QIcon& getClassIcon(Character::WoWClass aClass);
    
private:
    QVector<QIcon> icons;
};

#endif // ICONMANAGER_H
