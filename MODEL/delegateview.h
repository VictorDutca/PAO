#ifndef DELEGATEVIEW_H
#define DELEGATEVIEW_H
#include "delegatebutton.h"

class DelegateView : public DelegateButton
{
    Q_OBJECT
public:
    DelegateView(QString = "Visualizza", QObject* = nullptr);

signals:
    void ApriChange(int); //avviso modifica
};

#endif // DELEGATEVIEW_H
