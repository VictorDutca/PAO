#include "qfitedit.h"
#include "qfitcorsa.h"

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
