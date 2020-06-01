#include "qfitchangenuoto.h"
#include <iostream>
#include <QMessageBox>
#include "nuoto.h"
#include "qfitwindow.h"
#include "modelworkout.h"
#include <string.h>
#include "errhandler.h"

QfitChangeNuoto::QfitChangeNuoto(Dlista<Workout*>& _WL, ModelWorkout& _m, int _ToEdit, int _Editable ,QWidget* parent) : WL(_WL), m(_m) ,QDialog(parent), ToEdit(_ToEdit),Editable(_Editable) {
    Nuoto *NuotoEdit = dynamic_cast<Nuoto*>(WL.At(ToEdit));
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
    if(Editable){
        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,Qt::transparent);

        Tdurata->setReadOnly(true);
        TRana->setReadOnly(true);
        TDorso->setReadOnly(true);
        TLibero->setReadOnly(true);

        Tdurata->setPalette(*palette);
        TRana->setPalette(*palette);
        TDorso->setPalette(*palette);
        TLibero->setPalette(*palette);
    }

    Hdurata = new QHBoxLayout;
    HRana = new QHBoxLayout;
    HDorso = new QHBoxLayout;
    HLibero = new QHBoxLayout;
    Hbottoni = new QHBoxLayout;

    TitleLayoutNuoto = new QHBoxLayout;
    if(!Editable){
        LBTnuoto = new QLabel(tr("Modifica Nuoto"));
    }else{
        LBTnuoto = new QLabel(tr("Visualizza Nuoto"));
    }
    connect(salva, &QPushButton::clicked, [=]() {
        SalvaChangeNuoto();
    });

    connect(reset, &QPushButton::clicked, [=]() {
        Reset();
    });

    Tdurata->setText(QString::number(NuotoEdit->get_durata()));
    TRana->setText(QString::number(NuotoEdit->getVascheRana()));
    TDorso->setText(QString::number(NuotoEdit->getVascheDorso()));
    TLibero->setText(QString::number(NuotoEdit->getVascheLibero()));

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


    gbNuoto->setLayout(LayoutForm);

    setWindowTitle(tr("QFit"));
    setWindowIcon(QIcon(":/utils/small_icon.png"));

    setFixedSize(500,220);

    TitleLayoutNuoto->addWidget(LBTnuoto, Qt::AlignCenter);
    LBTnuoto->setAlignment(Qt::AlignCenter);
    MainLayout->addLayout(TitleLayoutNuoto);

    MainLayout->addWidget(gbNuoto);
    MainLayout->addLayout(Hbottoni);
    setLayout(MainLayout);
}

void QfitChangeNuoto::SalvaChangeNuoto() {
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
            throw ErrEmptyForm();
        }
        Nuoto *NuotoEdit = dynamic_cast<Nuoto*>(WL.At(ToEdit));


        NuotoEdit->set_durata(x2);
        NuotoEdit->set_VascheRana(x3);
        NuotoEdit->set_VascheDorso(x4);
        NuotoEdit->set_VascheLibero(x5);

        m.update();
        close();
    }
    catch(ErrEmptyForm) {
        QMessageBox msgBox;
        msgBox.setText("Dati non corretti.");
        msgBox.exec();
    }
}

void QfitChangeNuoto::Reset() {
    Tdurata->setText("");
    TRana->setText("");
    TDorso->setText("");
    TLibero->setText("");
}
