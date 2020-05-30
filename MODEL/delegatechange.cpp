#include "delegatechange.h"

DelegateChange::DelegateChange(QIcon strButton, QObject* parent)
    : DelegateButton (strButton, parent)
{
    connect(this, SIGNAL(TableButtonPressed(int)), this, SIGNAL(ApriChange(int)));
}
