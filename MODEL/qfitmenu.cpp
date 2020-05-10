#include "qfitmenu.h"

Qfitmenu::Qfitmenu()
{
    Qfitnew = new QPushButton(tr("Crea"));
    Qfitsave = new QPushButton(tr("Salva"));
    Qfitexport = new QPushButton(tr("Esporta"));

    QPixmap banner("../MODEL/img/logoProg.png");
    title = new QLabel;
    title->setPixmap(banner.scaled(200,100)); //modificare in futuro
    title->setAlignment(Qt::AlignCenter);
    layout = new QHBoxLayout();
    layoutMenu = new QVBoxLayout();
    layoutMenu->addWidget(Qfitnew);
    layoutMenu->addWidget(Qfitsave);
    layoutMenu->addWidget(Qfitexport);
   // layout->setContentsMargins(100,100,100,100);
    layout->addWidget(title);
    layout->setAlignment(title, Qt::AlignLeft);

    layout->addLayout(layoutMenu);
    layoutMenu->setAlignment(Qt::AlignRight);
    setLayout(layout);
}
