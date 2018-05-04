#ifndef DUNGEONFORM_H
#define DUNGEONFORM_H

#include "characterinstance.h"
#include "instance.h"

#include <QWidget>

namespace Ui {
class DungeonForm;
}

class DungeonForm : public QWidget
{
    Q_OBJECT

public:
    explicit DungeonForm(QWidget *parent, CharacterInstance& characterInstance, Instance& instance);
    ~DungeonForm();

private slots:
    void on_killButton_clicked(bool checked);

private:
    Ui::DungeonForm *ui;

    CharacterInstance& characterInstance;
    Instance& instance;
};

#endif // DUNGEONFORM_H
