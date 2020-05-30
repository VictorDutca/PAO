#include "qfitchangeciclismo.h"
#include "errhandler.h"
#include <QMessageBox>

QfitChangeCiclismo::QfitChangeCiclismo(Dlista<Workout*>& _WL, ModelWorkout& _m, int _ToEdit, int _Editable,QWidget* parent) : WL(_WL), m(_m) ,QDialog(parent), ToEdit(_ToEdit),Editable(_Editable) {
    Ciclismo *CiclismoEdit = dynamic_cast<Ciclismo*>(WL.At(ToEdit));
    gbCiclismo = new QGroupBox("Ciclismo");
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

 if(Editable){
     QPalette *palette = new QPalette();
     palette->setColor(QPalette::Base,Qt::transparent);

     Tdistanza->setReadOnly(true);
     Tdurata->setReadOnly(true);
     Tpianura->setReadOnly(true);
     Tsalita->setReadOnly(true);
     Tdiscesa->setReadOnly(true);

     Tdistanza->setPalette(*palette);
     Tdurata->setPalette(*palette);
     Tpianura->setPalette(*palette);
     Tsalita->setPalette(*palette);
     Tdiscesa->setPalette(*palette);
}

    Hdistanza = new QHBoxLayout;
    Hdurata = new QHBoxLayout;
    Hpianura = new QHBoxLayout;
    Hsalita = new QHBoxLayout;
    Hdiscesa = new QHBoxLayout;
    Hbottoni = new QHBoxLayout;

    TitleLayoutCiclismo = new QHBoxLayout;
        if(!Editable){
    LBTciclismo = new QLabel(tr("Modifica Ciclismo"));
}else{
LBTciclismo = new QLabel(tr("Visualizza Ciclismo"));

        }
    connect(salva, &QPushButton::clicked, [=]() {
        SalvaChangeCiclismo();
    });

    connect(reset, &QPushButton::clicked, [=]() {
        Reset();
    });



    Tdurata->setText(QString::number(CiclismoEdit->get_durata()));
    Tdiscesa->setText(QString::number(CiclismoEdit->get_discesa()));
    Tdistanza->setText(QString::number(CiclismoEdit->get_distanza()));
    Tpianura->setText(QString::number(CiclismoEdit->get_pianura()));
    Tsalita->setText(QString::number(CiclismoEdit->get_salita()));

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
    if(!Editable){
        Hbottoni->addWidget(salva);
        Hbottoni->addWidget(reset);
    }
    //LayoutForm->addLayout(Hbottoni);

    gbCiclismo->setLayout(LayoutForm);

    setWindowTitle(tr("QFit"));
    setFixedSize(500,250);

    TitleLayoutCiclismo->addWidget(LBTciclismo, Qt::AlignCenter);
    LBTciclismo->setAlignment(Qt::AlignCenter);
    MainLayout->addLayout(TitleLayoutCiclismo);

    MainLayout->addWidget(gbCiclismo);
    MainLayout->addLayout(Hbottoni);
    setLayout(MainLayout);

}

void QfitChangeCiclismo::SalvaChangeCiclismo() {
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

       Ciclismo *CiclismoEdit = dynamic_cast<Ciclismo*>(WL.At(ToEdit));

       CiclismoEdit->set_discesa(x4);
       CiclismoEdit->set_distanza(x1);
       CiclismoEdit->set_durata(x2);
       CiclismoEdit->set_pianura(x3);
       CiclismoEdit->set_salita(x5);



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

void QfitChangeCiclismo::Reset() {
    Tdistanza->setText("");
    Tdurata->setText("");
    Tpianura->setText("");
    Tdiscesa->setText("");
    Tsalita->setText("");
}

