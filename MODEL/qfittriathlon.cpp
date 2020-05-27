#include "qfittriathlon.h"
#include <iostream>
#include <QMessageBox>
#include "triathlon.h".
#include "qfitwindow.h"
#include "modelworkout.h"

QfitTriathlon::QfitTriathlon(Dlista<Workout*>& _WL, ModelWorkout& _m, QWidget* parent) : WL(_WL), m(_m) ,QDialog(parent) {
    gbCorsa = new QGroupBox("Corsa");
    gbCiclismo = new QGroupBox("Ciclismo");
    gbNuoto = new QGroupBox("Nuoto");
    LayoutForm = new QVBoxLayout;
    MainLayout = new QVBoxLayout;

    LTCorsa = new QVBoxLayout;
    LTCiclismo = new QVBoxLayout;
    LTNuoto = new QVBoxLayout;

    TitleLayout = new QHBoxLayout;
    LBTTriat = new QLabel(tr("Nuovo allenamento Triathlon"));

    COdistanza = new QLabel;
    COdurata = new QLabel;
    COpianura = new QLabel;
    COsalita = new QLabel;
    COdiscesa = new QLabel;
    CIdistanza = new QLabel;
    CIdurata = new QLabel;
    CIpianura = new QLabel;
    CIsalita = new QLabel;
    CIdiscesa = new QLabel;
    Ndurata = new QLabel;
    Nrana = new QLabel;
    Ndorso = new QLabel;
    Nlibero = new QLabel;

    TCOdistanza = new QLineEdit;
    TCOdurata = new QLineEdit;
    TCOpianura = new QLineEdit;
    TCOsalita = new QLineEdit;
    TCOdiscesa = new QLineEdit;
    TCIdistanza = new QLineEdit;
    TCIdurata = new QLineEdit;
    TCIpianura = new QLineEdit;
    TCIsalita = new QLineEdit;
    TCIdiscesa = new QLineEdit;
    TNdurata = new QLineEdit;
    TNrana = new QLineEdit;
    TNdorso = new QLineEdit;
    TNlibero = new QLineEdit;

    salva = new QPushButton;
    reset = new QPushButton;

    HCOdistanza = new QHBoxLayout;
    HCOdurata = new QHBoxLayout;
    HCOpianura = new QHBoxLayout;
    HCOsalita = new QHBoxLayout;
    HCOdiscesa = new QHBoxLayout;
    HCIdistanza = new QHBoxLayout;
    HCIdurata = new QHBoxLayout;
    HCIpianura = new QHBoxLayout;
    HCIsalita = new QHBoxLayout;
    HCIdiscesa = new QHBoxLayout;
    HNdurata = new QHBoxLayout;
    HNrana = new QHBoxLayout;
    HNdorso = new QHBoxLayout;
    HNlibero = new QHBoxLayout;

    Hbottoni = new QHBoxLayout;

    connect(salva, &QPushButton::clicked, [=]() {
        SalvaTriathlon();
    });

    connect(reset, &QPushButton::clicked, [=]() {
        Reset();
    });

    COdistanza->setText("Distanza:");
    COdurata->setText("Durata:");
    COpianura->setText("Pianura:");
    COsalita->setText("Salita:");
    COdiscesa->setText("Discesa:");
    CIdistanza->setText("Distanza:");
    CIdurata->setText("Durata:");
    CIpianura->setText("Pianura:");
    CIsalita->setText("Salita:");
    CIdiscesa->setText("Discesa:");
    Ndurata->setText("Durata:");
    Nrana->setText("Rana:");
    Ndorso->setText("Dorso:");
    Nlibero->setText("Libero:");

    TCOdurata->setFixedWidth(350);
    TCOdistanza->setFixedWidth(350);
    TCOpianura->setFixedWidth(350);
    TCOsalita->setFixedWidth(350);
    TCOdiscesa->setFixedWidth(350);
    TCIdurata->setFixedWidth(350);
    TCIdistanza->setFixedWidth(350);
    TCIpianura->setFixedWidth(350);
    TCIsalita->setFixedWidth(350);
    TCIdiscesa->setFixedWidth(350);
    TNdurata->setFixedWidth(350);
    TNrana->setFixedWidth(350);
    TNdorso->setFixedWidth(350);
    TNlibero->setFixedWidth(350);

    HCOdistanza->addWidget(COdistanza);
    HCOdistanza->addWidget(TCOdistanza);

    HCOdurata->addWidget(COdurata);
    HCOdurata->addWidget(TCOdurata);

    HCOpianura->addWidget(COpianura);
    HCOpianura->addWidget(TCOpianura);

    HCOsalita->addWidget(COsalita);
    HCOsalita->addWidget(TCOsalita);

    HCOdiscesa->addWidget(COdiscesa);
    HCOdiscesa->addWidget(TCOdiscesa);

    HCIdistanza->addWidget(CIdistanza);
    HCIdistanza->addWidget(TCIdistanza);

    HCIdurata->addWidget(CIdurata);
    HCIdurata->addWidget(TCIdurata);

    HCIpianura->addWidget(CIpianura);
    HCIpianura->addWidget(TCIpianura);

    HCIsalita->addWidget(CIsalita);
    HCIsalita->addWidget(TCIsalita);

    HCIdiscesa->addWidget(CIdiscesa);
    HCIdiscesa->addWidget(TCIdiscesa);

    HNdurata->addWidget(Ndurata);
    HNdurata->addWidget(TNdurata);

    HNrana->addWidget(Nrana);
    HNrana->addWidget(TNrana);

    HNdorso->addWidget(Ndorso);
    HNdorso->addWidget(TNdorso);

    HNlibero->addWidget(Nlibero);
    HNlibero->addWidget(TNlibero);

    LTCorsa->addLayout(HCOdistanza);
    LTCorsa->addLayout(HCOdurata);
    LTCorsa->addLayout(HCOpianura);
    LTCorsa->addLayout(HCOsalita);
    LTCorsa->addLayout(HCOdiscesa);
    LTCiclismo->addLayout(HCIdistanza);
    LTCiclismo->addLayout(HCIdurata);
    LTCiclismo->addLayout(HCIpianura);
    LTCiclismo->addLayout(HCIsalita);
    LTCiclismo->addLayout(HCIdiscesa);
    LTNuoto->addLayout(HNdurata);
    LTNuoto->addLayout(HNrana);
    LTNuoto->addLayout(HNdorso);
    LTNuoto->addLayout(HNlibero);

    gbCorsa->setLayout(LTCorsa);
    gbCiclismo->setLayout(LTCiclismo);
    gbNuoto->setLayout(LTNuoto);

    salva->setText("Salva");
    reset->setText("Reset");
    Hbottoni->addWidget(salva);
    Hbottoni->addWidget(reset);

    //titolo pag
    TitleLayout->addWidget(LBTTriat, Qt::AlignHCenter);
    LBTTriat->setAlignment (Qt::AlignHCenter);
    MainLayout->addLayout(TitleLayout);


    MainLayout->addWidget(gbCorsa);
    MainLayout->addWidget(gbCiclismo);
    MainLayout->addWidget(gbNuoto);
    LayoutForm->addLayout(Hbottoni);

    setWindowTitle(tr("QFit"));
    //setFixedSize(500,200);


    MainLayout->addLayout(LayoutForm);
    setLayout(MainLayout);

}

void QfitTriathlon::SalvaTriathlon() {
    try {
        QString OCOdistanza = TCOdistanza->text();
        int x1 = OCOdistanza.toInt();

        QString OCOdurata = TCOdurata->text();
        int x2 = OCOdurata.toInt();

        QString OCOpianura = TCOpianura->text();
        int x3 = OCOpianura.toInt();

        QString OCOdiscesa = TCOdiscesa->text();
        int x4 = OCOdiscesa.toInt();

        QString OCOsalita = TCOsalita->text();
        int x5 = OCOsalita.toInt();

        QString OCIdistanza = TCIdistanza->text();
        int x6 = OCIdistanza.toInt();

        QString OCIdurata = TCIdurata->text();
        int x7 = OCIdurata.toInt();

        QString OCIpianura = TCIpianura->text();
        int x8 = OCIpianura.toInt();

        QString OCIdiscesa = TCIdiscesa->text();
        int x9 = OCIdiscesa.toInt();

        QString OCIsalita = TCIsalita->text();
        int x10 = OCIsalita.toInt();

        QString ONdurata = TNdurata->text();
        int x11 = ONdurata.toInt();

        QString ONRana = TNrana->text();
        int x12 = ONRana.toInt();

        QString ONDorso = TNdorso->text();
        int x13 = ONDorso.toInt();

        QString ONLibero = TNlibero->text();
        int x14 = ONLibero.toInt();

        if(!x1 || !x2 || !x3 || !x4 || !x5 || !x6 || !x7 || !x8 || !x9 || !x10 || !x11 || !x12 || !x13 || !x14) {
            throw 0;
        }
        Triathlon *w = new Triathlon(x1, x3, x5, x4, x7, x6, x8, x10, x9, x10, x11, x12, x13, x14);
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

void QfitTriathlon::Reset() {
    TCOdistanza->setText("");
    TCOdurata->setText("");
    TCOpianura->setText("");
    TCOdiscesa->setText("");
    TCOsalita->setText("");
    TCIdistanza->setText("");
    TCIdurata->setText("");
    TCIpianura->setText("");
    TCIdiscesa->setText("");
    TCIsalita->setText("");
    TNdurata->setText("");
    TNrana->setText("");
    TNdorso->setText("");
    TNlibero->setText("");
}
