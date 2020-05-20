#include "qfitedit.h"
#include "qfitcorsa.h"
#include "qfitciclismo.h"
#include "qfitnuoto.h"
#include "qfittriathlon.h"

QfitEdit::QfitEdit(Dlista<Workout*>& _WL,ModelWorkout& _m ,QWidget* parent) : WL(_WL), m(_m) , QDialog(parent) {
    layoutScelta = new QVBoxLayout;
    MainLayout = new QVBoxLayout;

    sceltaCorsa = new QPushButton(tr("Corsa"));
    sceltaCiclismo = new QPushButton(tr("Ciclismo"));
    sceltaNuoto = new QPushButton(tr("Nuoto"));
    sceltaTriathlon = new QPushButton(tr("Triathlon"));

    connect(sceltaCorsa, &QPushButton::clicked, [=]() {
        ApriCorsaForm();
    });

    connect(sceltaCiclismo, &QPushButton::clicked, [=]() {
        ApriCiclismoForm();
    });

    connect(sceltaNuoto, &QPushButton::clicked, [=]() {
        ApriNuotoForm();
    });

    connect(sceltaTriathlon, &QPushButton::clicked, [=]() {
        ApriTriathlonForm();
    });

    layoutScelta->addWidget(sceltaCorsa);
    layoutScelta->addWidget(sceltaCiclismo);
    layoutScelta->addWidget(sceltaNuoto);
    layoutScelta->addWidget(sceltaTriathlon);
    MainLayout->addLayout(layoutScelta);
    setLayout(MainLayout);
    setWindowTitle(tr("QFit"));
    setFixedSize(100,150);
}

void QfitEdit::ApriCorsaForm() {
    QfitCorsa* dialog1 = new QfitCorsa(WL,m);
    dialog1->exec();
    dialog1->disconnect();
    delete dialog1;
}


void QfitEdit::ApriCiclismoForm() {
    QfitCiclismo* dialog2 = new QfitCiclismo(WL,m);
    dialog2->exec();
    dialog2->disconnect();
    delete dialog2;
}

void QfitEdit::ApriNuotoForm() {
    QfitNuoto* dialog3 = new QfitNuoto(WL,m);
    dialog3->exec();
    dialog3->disconnect();
    delete dialog3;
}

void QfitEdit::ApriTriathlonForm() {
    QfitTriathlon* dialog4 = new QfitTriathlon(WL,m);
    dialog4->exec();
    dialog4->disconnect();
    delete dialog4;
}
