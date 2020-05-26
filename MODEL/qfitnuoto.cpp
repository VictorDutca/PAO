#include "qfitnuoto.h"
#include <iostream>
#include <QMessageBox>
#include "nuoto.h"
#include "qfitwindow.h"
#include "modelworkout.h"

QfitNuoto::QfitNuoto(Dlista<Workout*>& _WL, ModelWorkout& _m, QWidget* parent) : WL(_WL), m(_m) ,QDialog(parent) {
    gbNuoto = new QGroupBox("Nuoto");
    LayoutForm = new QVBoxLayout;
    MainLayout = new QVBoxLayout;
    Ldurata = new QLabel;
    LRana = new QLabel;
    LDorso = new QLabel;
    LLibero = new QLabel;
    Tdurata = new QLineEdit;
    TRana = new QLineEdit;
    TDorso = new QLineEdit;
    TLibero = new QLineEdit;
    salva = new QPushButton;
    reset = new QPushButton;
    Hdurata = new QHBoxLayout;
    HRana = new QHBoxLayout;
    HDorso = new QHBoxLayout;
    HLibero = new QHBoxLayout;
    Hbottoni = new QHBoxLayout;

    connect(salva, &QPushButton::clicked, [=]() {
        SalvaNuoto();
    });

    connect(reset, &QPushButton::clicked, [=]() {
        Reset();
    });

    Ldurata->setText("Durata:");
    LRana->setText("Rana:");
    LDorso->setText("Dorso:");
    LLibero->setText("Libero:");

    Tdurata->setFixedWidth(350);
    TRana->setFixedWidth(350);
    TDorso->setFixedWidth(350);
    TLibero->setFixedWidth(350);

    Hdurata->addWidget(Ldurata);
    Hdurata->addWidget(Tdurata);

    HRana->addWidget(LRana);
    HRana->addWidget(TRana);

    HDorso->addWidget(LDorso);
    HDorso->addWidget(TDorso);

    HLibero->addWidget(LLibero);
    HLibero->addWidget(TLibero);

    LayoutForm->addLayout(Hdurata);
    LayoutForm->addLayout(HRana);
    LayoutForm->addLayout(HDorso);
    LayoutForm->addLayout(HLibero);

    salva->setText("Salva");
    reset->setText("Reset");
    Hbottoni->addWidget(salva);
    Hbottoni->addWidget(reset);
    //LayoutForm->addLayout(Hbottoni);

    gbNuoto->setLayout(LayoutForm);

    setWindowTitle(tr("QFit"));
    setFixedSize(500,220);

    MainLayout->addWidget(gbNuoto);
    MainLayout->addLayout(Hbottoni);
    setLayout(MainLayout);
}

void QfitNuoto::SalvaNuoto() {
    try {

        QString Odurata = Tdurata->text();
        int x2 = Odurata.toInt();

        QString ORana = TRana->text();
        int x3 = ORana.toInt();

        QString ODorso = TDorso->text();
        int x4 = ODorso.toInt();

        QString OLibero = TLibero->text();
        int x5 = OLibero.toInt();

        if(!x2 || !x3 || !x4 || !x5) {
            throw 0;
        }
        Nuoto *w = new Nuoto(x2, x3, x4, x5);
        WL.pushT(w);
        m.update();
        close();
    }
    catch(int ex) {
        QMessageBox msgBox;
        msgBox.setText("Dati non corretti.");
        msgBox.exec();
    }
}

void QfitNuoto::Reset() {
    Tdurata->setText("");
    TRana->setText("");
    TDorso->setText("");
    TLibero->setText("");
}
