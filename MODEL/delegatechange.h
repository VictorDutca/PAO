#ifndef DELEGATECHANGE_H
#define DELEGATECHANGE_H
#include "delegatebutton.h"

class DelegateChange : public DelegateButton
{
    Q_OBJECT
public:
    DelegateChange(QString = "Modifica", QObject* = nullptr);

signals:
    void ApriChange(int); //avviso modifica
};

#endif // DELEGATECHANGE_H
