#ifndef DELEGATEDELETE_H
#define DELEGATEDELETE_H
#include "delegatebutton.h"

class DelegateDelete : public DelegateButton
{
    Q_OBJECT
public:
    DelegateDelete(QString = "Elimina", QObject* = nullptr);
public slots:
    void DeleteSlot(int);

signals:
    void AlertDelete(int);
    void ModelDelete(int);
};

#endif // DELEGATEDELETE_H
