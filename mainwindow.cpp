#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dungeonform.h"
#include "resetlogdataaccess.h"

#include <QMessageBox>
#include <QFile>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->instanceLayout->setAlignment(ui->instanceLayout, Qt::AlignTop);

    if (!QSqlDatabase::drivers().contains("QSQLITE")) {
        QMessageBox::critical(this, "Unable to load database", "This demo needs the SQLITE driver");
    } else {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("MountTrackerDB");
        db.open();
    }

    initDB();
    resetCheck();

    // Load Characters
    connect(ui->CharacterSelectionCombo, SIGNAL(currentTextChanged(const QString&)), this, SLOT(characterChanged(const QString&)));

    loadInstances();
    loadCharacters();

    // Bottom buttons
    connect(ui->addCharacterButton, SIGNAL(clicked()), this, SLOT(showAddCharacter()));
    connect(&addCharacterPopUp, SIGNAL(createdCharacter(Character&)), this, SLOT(addNewCharacter(Character&)));

    connect(ui->addInstanceButton, SIGNAL(clicked()), this, SLOT(showAddInstance()));
    connect(&addInstancePopUp, SIGNAL(createdInstance(Instance&)), this, SLOT(addNewInstance(Instance&)));
}

void MainWindow::addNewCharacter(Character& newCharacter) {
    characters.append(newCharacter);
    ui->CharacterSelectionCombo->addItem(iconManager.getClassIcon(newCharacter.getClass()), newCharacter.getName());
}

void MainWindow::resetCheck() {
    QDate lastReset = ResetLogDataAccess().lastReset();
    QDate today = QDate::currentDate();

    if(today.weekNumber()-lastReset.weekNumber() > 1 ||
            (lastReset.weekNumber() < today.weekNumber() && (today.dayOfWeek() > 2 || lastReset.dayOfWeek() < 3))
            || (lastReset.weekNumber() == today.weekNumber() && (today.dayOfWeek() > 2 && lastReset.dayOfWeek() < 3))) {
        characterInstanceDataAccess.resetAll();
        ResetLogDataAccess().reset();
    }
}

void MainWindow::addNewInstance(Instance& newInstance) {
    instances.insert(newInstance.getName(), newInstance);
}

void MainWindow::showAddCharacter() {
    addCharacterPopUp.show();
}

void MainWindow::showAddInstance() {
    addInstancePopUp.show();
}

MainWindow::~MainWindow() {
    delete ui;
    QSqlDatabase::database().close();
}

void MainWindow::loadCharacters() {
    // db get characters
    characters = charDataAccess.getCharacters();
    foreach(Character character, characters) {
        ui->CharacterSelectionCombo->addItem(iconManager.getClassIcon(character.getClass()), character.getName());
    }

}

void MainWindow::loadInstances() {
    // db get instances
    QVector<Instance> instancesList = instanceDataAccess.getInstances();

    foreach(Instance ins, instancesList) {
        instances.insert(ins.getName(), ins);
    }

}

void MainWindow::initDB() {
    QSqlQuery query(QSqlDatabase::database());

    QFile file(":/Database.sql");
    file.open(QFile::ReadOnly|QFile::Text);
    QString fileData(file.readAll());
    QStringList splitCommands(fileData.split("|"));

    foreach(QString command, splitCommands) {
        if(!query.exec(command)) {
            qDebug() << query.lastError();
        }
    }
}

Instance& MainWindow::getInstance(QString& instanceName) {
    QMutableHashIterator<QString, Instance> it(instances);

    while(it.hasNext()) {
        it.next();
        if(!it.key().compare(instanceName)) {
            return it.value();
        }
    }
}

void MainWindow::characterChanged(const QString& characterName) {
    // Get all character instances
    charInstances = characterInstanceDataAccess.getAllByCharacterName(characterName);

    // Clear old ones
    QLayoutItem *child;
    while ((child = ui->instanceLayout->takeAt(0)) != 0) {
        delete child->widget();
    }

    // Add to layout
    QMutableVectorIterator<CharacterInstance> it(charInstances);

    while(it.hasNext()) {
        CharacterInstance& charInst = it.next();
        DungeonForm* df = new DungeonForm(NULL, charInst, getInstance(charInst.getInstanceName()));
        ui->instanceLayout->addWidget(df);
        ui->instanceLayout->setAlignment(df, Qt::AlignTop);
    }/*

    foreach(CharacterInstance charInst, charInstances) {
        DungeonForm* df = new DungeonForm(NULL, charInst, getInstance(charInst.getInstanceName()));
        ui->instanceLayout->addWidget(df);
        ui->instanceLayout->setAlignment(df, Qt::AlignTop);
    }*/
}
