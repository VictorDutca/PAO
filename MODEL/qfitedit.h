#ifndef QFITEDIT_H
#define QFITEDIT_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QDateEdit>
#include "lista.h"

class QfitEdit : public QDialog {
    Q_OBJECT
public:
    QfitEdit(Dlista<Workout*>&, QWidget* = nullptr);
private:
    QPushButton *sceltaCorsa, *sceltaCiclismo, *sceltaNuoto, *sceltaTriathlon;
    QVBoxLayout *layoutScelta;
    QVBoxLayout *MainLayout;
    Dlista<Workout*>& WL;
private slots:
    void ApriCorsaForm();
};

#endif // QFITEDIT_H
