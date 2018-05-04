#ifndef RESETLOGDATAACCESS_H
#define RESETLOGDATAACCESS_H

#include <QTime>

class ResetLogDataAccess
{
public:
    ResetLogDataAccess();
    QDate lastReset();

    void reset();

private:
    static QString const dateFormat;
};

#endif // RESETLOGDATAACCESS_H
