#include "delegatedelete.h"

DelegateDelete::DelegateDelete(QString ButtonSTR, QObject* parent)
    : DelegateButton (ButtonSTR, parent)
{
    connect(this, SIGNAL (TableButtonPressed(int)), this, SIGNAL(AlertDelete(int)));
}


void DelegateDelete::DeleteSlot(int row) {
    BTNElement.remove(BTNElement.key(BTNElement.last()));
    emit ModelDelete(row);
}

