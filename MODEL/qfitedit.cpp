#include "qfitedit.h"

QfitEdit::QfitEdit()
{
    sceltaCorsa = new QPushButton(tr("Corsa"));
    sceltaCiclismo = new QPushButton(tr("Ciclismo"));
    sceltaNuoto = new QPushButton(tr("Nuoto"));
    sceltaTriathlon = new QPushButton(tr("Triathlon"));
    layoutScelta->addWidget(sceltaCorsa);
    layoutScelta->addWidget(sceltaCiclismo);
    layoutScelta->addWidget(sceltaNuoto);
    layoutScelta->addWidget(sceltaTriathlon);
}
