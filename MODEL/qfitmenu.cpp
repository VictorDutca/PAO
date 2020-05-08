#include "qfitmenu.h"

Qfitmenu::Qfitmenu()
{
    Qfitnew = new QPushButton(tr("crea"));
    Qfitsave = new QPushButton(tr("salva"));
    Qfitexport = new QPushButton(tr("esporta"));

    QPixmap banner("../MODEL/img/logoProg.png");
    title = new QLabel;
    title->setPixmap(banner);
    title->setAlignment(Qt::AlignCenter);
    layout = new QVBoxLayout();
    layoutMenu = new QHBoxLayout();
    layoutMenu->addWidget(Qfitnew);
    layoutMenu->addWidget(Qfitsave);
    layoutMenu->addWidget(Qfitexport);
    layout->addWidget(title);
    layout->setAlignment(title, Qt::AlignHCenter);
    layout->addLayout(layoutMenu);
    layoutMenu->setAlignment(Qt::AlignRight);
    setLayout(layout);
}
