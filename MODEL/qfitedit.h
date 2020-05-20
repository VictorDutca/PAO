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
#include "modelworkout.h"

class QfitEdit : public QDialog {
    Q_OBJECT
public:
    QfitEdit(Dlista<Workout*>&, ModelWorkout& ,QWidget* = nullptr);
private:
    QPushButton *sceltaCorsa, *sceltaCiclismo, *sceltaNuoto, *sceltaTriathlon;
    QVBoxLayout *layoutScelta;
    QVBoxLayout *MainLayout;
    Dlista<Workout*>& WL;
    ModelWorkout& m;
private slots:
    void ApriCorsaForm();
    void ApriCiclismoForm();
    void ApriNuotoForm();
    void ApriTriathlonForm();
};

#endif // QFITEDIT_H
