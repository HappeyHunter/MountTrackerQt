#ifndef INSTANCEDATAACCESS_H
#define INSTANCEDATAACCESS_H

#include <QVector>
#include <QSqlDatabase>

#include "instance.h"

class InstanceDataAccess
{
public:
    InstanceDataAccess();

    QVector<Instance> getInstances();
    void addInstance(Instance& anInstance);

    void update(Instance& anInstance);
};

#endif // INSTANCEDATAACCESS_H
