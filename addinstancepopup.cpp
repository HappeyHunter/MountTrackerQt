#include "addinstancepopup.h"
#include "ui_addinstancepopup.h"

#include "instancedataaccess.h"
#include "instance.h"

AddInstancePopUp::AddInstancePopUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInstancePopUp)
{
    ui->setupUi(this);
}

AddInstancePopUp::~AddInstancePopUp()
{
    delete ui;
}

void AddInstancePopUp::on_saveButton_clicked()
{
    // Add character
    InstanceDataAccess instDataAccess;

    Instance newInstance;
    newInstance.setName(ui->instanceNameLineEdit->text());
    newInstance.setBossCount(ui->bossCountSpinBox->value());
    newInstance.setKillCount(ui->killCountSpinBox->value());

    instDataAccess.addInstance(newInstance);

    emit createdInstance(newInstance);

    ui->instanceNameLineEdit->setText("");
    ui->bossCountSpinBox->setValue(0);
    ui->killCountSpinBox->setValue(0);

    this->hide();
}

void AddInstancePopUp::on_cancelButton_clicked()
{
    this->hide();
}
