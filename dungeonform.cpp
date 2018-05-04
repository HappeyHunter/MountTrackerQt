#include "dungeonform.h"
#include "ui_dungeonform.h"

#include "characterinstancedataaccess.h"
#include "instancedataaccess.h"

DungeonForm::DungeonForm(QWidget *parent, CharacterInstance& aCharacterInstance, Instance& anInstance) :
    QWidget(parent),
    ui(new Ui::DungeonForm),
    characterInstance(aCharacterInstance),
    instance(anInstance) {

    ui->setupUi(this);
    ui->dungeonLabel->setText(instance.getName());
    ui->killButton->setChecked(characterInstance.isKilled());
    ui->dropPercentage->setText(QString::asprintf("%.1f\%", instance.getChanceForKills()));
}

DungeonForm::~DungeonForm()
{
    delete ui;
}

void DungeonForm::on_killButton_clicked(bool checked)
{
    characterInstance.setKilled(checked);

    checked ? instance.incrementKills() : instance.decrementKills();
    ui->dropPercentage->setText(QString::asprintf("%.1f\%", instance.getChanceForKills()));

    // update db
    CharacterInstanceDataAccess().update(characterInstance);
    InstanceDataAccess().update(instance);
}
