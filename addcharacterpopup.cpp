#include "addcharacterpopup.h"
#include "ui_addcharacterpopup.h"

#include "characterdataaccess.h"
#include "iconmanager.h"

AddCharacterPopUp::AddCharacterPopUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddCharacterPopUp)
{
    ui->setupUi(this);
    IconManager icons;

    for ( int n = 0; n < Character::ClassCount; n++)
    {
       ui->characterClassComboBox->addItem(icons.getClassIcon((Character::WoWClass) n), "");
    }

}

AddCharacterPopUp::~AddCharacterPopUp()
{
    delete ui;
}

void AddCharacterPopUp::on_saveButton_clicked()
{
    // Add character
    CharacterDataAccess charDataAccess;

    Character newChar;
    newChar.setName(ui->characterNameLineEdit->text());
    newChar.setClass((Character::WoWClass)ui->characterClassComboBox->currentIndex());

    charDataAccess.addCharacter(newChar);

    emit createdCharacter(newChar);

    ui->characterNameLineEdit->setText("");
    this->hide();
}

void AddCharacterPopUp::on_cancelButton_clicked()
{
    this->hide();
}
