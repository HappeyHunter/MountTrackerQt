#ifndef ADDCHARACTERPOPUP_H
#define ADDCHARACTERPOPUP_H

#include <QDialog>
#include <QAbstractButton>

#include "character.h"

namespace Ui {
class AddCharacterPopUp;
}

class AddCharacterPopUp : public QDialog
{
    Q_OBJECT

public:
    explicit AddCharacterPopUp(QWidget *parent = 0);
    ~AddCharacterPopUp();

private slots:
    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::AddCharacterPopUp *ui;

signals:
    void createdCharacter(Character& newCharacter);
};

#endif // ADDCHARACTERPOPUP_H
