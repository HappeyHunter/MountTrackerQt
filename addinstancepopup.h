#ifndef ADDINSTANCEPOPUP_H
#define ADDINSTANCEPOPUP_H

#include <QDialog>
#include <QAbstractButton>

#include "instance.h"

namespace Ui {
class AddInstancePopUp;
}

class AddInstancePopUp : public QDialog
{
    Q_OBJECT

public:
    explicit AddInstancePopUp(QWidget *parent = 0);
    ~AddInstancePopUp();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AddInstancePopUp *ui;

signals:
    void createdInstance(Instance& newInstance);
};

#endif // ADDINSTANCEPOPUP_H
