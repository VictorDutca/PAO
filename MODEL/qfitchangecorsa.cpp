#include "qfitchangecorsa.h"
#include <iostream>
#include <QMessageBox>
#include "corsa.h"
#include "qfitwindow.h"
#include "modelworkout.h"
#include <string.h>
#include "errhandler.h"

QfitChangeCorsa::QfitChangeCorsa(Dlista<Workout*>& _WL, ModelWorkout& _m, int _ToEdit, int _Editable,QWidget* parent) : WL(_WL), m(_m) ,QDialog(parent), ToEdit(_ToEdit), Editable(_Editable) {
    Corsa *CorsaEdit = dynamic_cast<Corsa*>(WL.At(ToEdit));
    gbCorsa = new QGroupBox("Corsa");
    LayoutForm = new QVBoxLayout;
    MainLayout = new QVBoxLayout;
    Ldistanza = new QLabel;
    Ldurata = new QLabel;
    Lpianura = new QLabel;
    Lsalita = new QLabel;
    Ldiscesa = new QLabel;
    Tdistanza = new QLineEdit;
    Tdurata = new QLineEdit;
    Tpianura = new QLineEdit;
    Tsalita = new QLineEdit;
    Tdiscesa = new QLineEdit;
    salva = new QPushButton;
    reset = new QPushButton;
    Hdistanza = new QHBoxLayout;
    Hdurata = new QHBoxLayout;
    Hpianura = new QHBoxLayout;
    Hsalita = new QHBoxLayout;
    Hdiscesa = new QHBoxLayout;
    Hbottoni = new QHBoxLayout;

    TitleLayoutCorsa = new QHBoxLayout;
    LBTcorsa = new QLabel(tr("Modifica Corsa"));

    connect(salva, &QPushButton::clicked, [=]() {
        SalvaChangeCorsa();
    });

    connect(reset, &QPushButton::clicked, [=]() {
        Reset();
    });



    Tdurata->setText(QString::number(CorsaEdit->get_durata()));
    Tdiscesa->setText(QString::number(CorsaEdit->get_discesa()));
    Tdistanza->setText(QString::number(CorsaEdit->get_distanza()));
    Tpianura->setText(QString::number(CorsaEdit->get_pianura()));
    Tsalita->setText(QString::number(CorsaEdit->get_salita()));

    Ldistanza->setText("Distanza:");
    Ldurata->setText("Durata:");
    Lpianura->setText("Pianura:");
    Lsalita->setText("Salita:");
    Ldiscesa->setText("Discesa:");

    Tdurata->setFixedWidth(350);
    Tdistanza->setFixedWidth(350);
    Tpianura->setFixedWidth(350);
    Tsalita->setFixedWidth(350);
    Tdiscesa->setFixedWidth(350);

    Hdistanza->addWidget(Ldistanza);
    Hdistanza->addWidget(Tdistanza);

    Hdurata->addWidget(Ldurata);
    Hdurata->addWidget(Tdurata);

    Hpianura->addWidget(Lpianura);
    Hpianura->addWidget(Tpianura);

    Hsalita->addWidget(Lsalita);
    Hsalita->addWidget(Tsalita);

    Hdiscesa->addWidget(Ldiscesa);
    Hdiscesa->addWidget(Tdiscesa);

    LayoutForm->addLayout(Hdistanza);
    LayoutForm->addLayout(Hdurata);
    LayoutForm->addLayout(Hpianura);
    LayoutForm->addLayout(Hsalita);
    LayoutForm->addLayout(Hdiscesa);

    salva->setText("Salva");
    reset->setText("Reset");
    Hbottoni->addWidget(salva);
    Hbottoni->addWidget(reset);
    //LayoutForm->addLayout(Hbottoni);

    gbCorsa->setLayout(LayoutForm);

    setWindowTitle(tr("QFit"));
    setFixedSize(500,250);

    TitleLayoutCorsa->addWidget(LBTcorsa, Qt::AlignCenter);
    LBTcorsa->setAlignment(Qt::AlignCenter);
    MainLayout->addLayout(TitleLayoutCorsa);

    MainLayout->addWidget(gbCorsa);
    MainLayout->addLayout(Hbottoni);
    setLayout(MainLayout);
}

void QfitChangeCorsa::SalvaChangeCorsa() {
    try {
        QString Odistanza = Tdistanza->text();
        int x1 = Odistanza.toInt();

        QString Odurata = Tdurata->text();
        int x2 = Odurata.toInt();

        QString Opianura = Tpianura->text();
        int x3 = Opianura.toInt();

        QString Odiscesa = Tdiscesa->text();
        int x4 = Odiscesa.toInt();

        QString Osalita = Tsalita->text();
        int x5 = Osalita.toInt();

        if(!x1 || !x2 || !x3 || !x4 || !x5) {
            throw ErrEmptyForm();
        }

       Corsa *CorsaEdit = dynamic_cast<Corsa*>(WL.At(ToEdit));

       CorsaEdit->set_discesa(x4);
       CorsaEdit->set_distanza(x1);
       CorsaEdit->set_durata(x2);
       CorsaEdit->set_pianura(x3);
       CorsaEdit->set_salita(x5);


       // WL.pushT(w);
        m.update();
        close();
    }
    catch(ErrEmptyForm) {
        QMessageBox msgBox;
        msgBox.setText("Dati non corretti.");
        msgBox.exec();
    }
}

void QfitChangeCorsa::Reset() {
    Tdistanza->setText("");
    Tdurata->setText("");
    Tpianura->setText("");
    Tdiscesa->setText("");
    Tsalita->setText("");
}
