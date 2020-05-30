#include "delegateview.h"

DelegateView::DelegateView(QIcon strButton, QObject* parent)
    : DelegateButton (strButton, parent)
{
    connect(this, SIGNAL(TableButtonPressed(int)), this, SIGNAL(ApriChange(int)));
}
