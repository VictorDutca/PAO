#include "qfitmenu.h"
#include "qfitedit.h"
#include "qfitwindow.h"
#include "errhandler.h"
#include <QLabel>
#include <QStringList>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QMessageBox>
#include <QDialog>
#include <QFileDialog>

Qfitmenu::Qfitmenu(Dlista<Workout*>& _WL,ModelWorkout& _m, XMLHandler& _XMLWorkout, QWidget *_parent): WL(_WL),m(_m), XMLWorkout(_XMLWorkout), QWidget(_parent) {
    Qfitnew = new QPushButton(tr("Crea"));
    Qfitsave = new QPushButton(tr("Salva"));
    Qfitexport = new QPushButton(tr("Esporta"));
    connect(Qfitnew, &QPushButton::clicked, [=]() {
        ApriScelta();
    });
    connect(Qfitsave, &QPushButton::clicked, [=]() {
        SalvaFile();
    });
    connect(Qfitexport, &QPushButton::clicked, [=]() {
        EsportaFile();
    });

    QPixmap banner(":/utils/logoProg.png");
    title = new QLabel;
    title->setPixmap(banner.scaled(200,100));
    title->setAlignment(Qt::AlignCenter);

    layoutMenu = new QVBoxLayout();
    layoutMenu->addWidget(Qfitnew);
    Qfitnew->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    layoutMenu->addWidget(Qfitsave);
    Qfitsave->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    layoutMenu->addWidget(Qfitexport);
    Qfitexport->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    layoutMenu->setAlignment(Qt::AlignRight);

    layout = new QHBoxLayout();
    layout->addWidget(title,3);
    layout->setAlignment(title, Qt::AlignCenter);
    layout->addLayout(layoutMenu);
    setLayout(layout);
}

void Qfitmenu::ApriScelta() {
    QfitEdit* dialog = new QfitEdit(WL,m);
    dialog->exec();
    dialog->disconnect();
    delete dialog;
}

void Qfitmenu::SalvaFile() {
    XMLWorkout.FileWriter();
}

void Qfitmenu::EsportaFile(){
    QFileDialog diag;
    QString suffix = "xml";
    diag.setDefaultSuffix(suffix);
    QString fileName = diag.getSaveFileName(this, tr("Save QFitWorkout"), "", tr("XML Workout (*.xml);;All Files ()"));

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("File non apribile"),
                                     file.errorString());
            return;
        }
        XMLWorkout.FileExport(file);
    }
}

