#include "qfitcorsa.h"
#include <iostream>
#include <QMessageBox>
#include "corsa.h"

QfitCorsa::QfitCorsa(Dlista<Workout*>& _WL, QWidget* parent) : WL(_WL), QDialog(parent) {
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

    connect(salva, &QPushButton::clicked, [=]() {
        SalvaCorsa();
    });

    Ldistanza->setText("Distanza:");
    Ldurata->setText("Durata:");
    Lpianura->setText("Pianura:");
    Lsalita->setText("Salita:");
    Ldiscesa->setText("Discesa:");

    Tdurata->setFixedWidth(400);
    Tdistanza->setFixedWidth(400);
    Tpianura->setFixedWidth(400);
    Tsalita->setFixedWidth(400);
    Tdiscesa->setFixedWidth(400);

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
    LayoutForm->addLayout(Hbottoni);

    setWindowTitle(tr("QFit"));
    setFixedSize(500,200);

    MainLayout->addLayout(LayoutForm);
    setLayout(MainLayout);
}

void QfitCorsa::SalvaCorsa() {
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
            throw 0;
        }
        Corsa *w = new Corsa(x2, x1, x3, x5, x4);
        WL.pushT(w);
    }
    catch(int ex) {
        QMessageBox msgBox;
        msgBox.setText("Dati non corretti.");
        msgBox.exec();
    }
}
