#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QMap>

#include "characterdataaccess.h"
#include "instancedataaccess.h"
#include "characterinstancedataaccess.h"
#include "iconmanager.h"
#include "character.h"
#include "characterinstance.h"
#include "instance.h"
#include "addcharacterpopup.h"
#include "addinstancepopup.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    CharacterDataAccess charDataAccess;
    InstanceDataAccess instanceDataAccess;
    CharacterInstanceDataAccess characterInstanceDataAccess;
    IconManager iconManager;

    AddCharacterPopUp addCharacterPopUp;
    AddInstancePopUp addInstancePopUp;

    QVector<Character> characters;
    QHash<QString, Instance> instances;
    QVector<CharacterInstance> charInstances;

    void loadCharacters();
    void loadInstances();
    void initDB();
    void resetCheck();
    Instance& getInstance(QString& instanceName);


public slots:
    void characterChanged(const QString&);
    void showAddCharacter();
    void showAddInstance();
    void addNewCharacter(Character&);
    void addNewInstance(Instance&);

};

#endif // MAINWINDOW_H
