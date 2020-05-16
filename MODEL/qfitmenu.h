#ifndef QFITMENU_H
#define QFITMENU_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include "lista.h"
#include "modelworkout.h"

class Qfitmenu : public QWidget {
Q_OBJECT
private:
    QLabel *title;
    QPushButton  *Qfitsave, *Qfitnew, *Qfitexport;
    QHBoxLayout *layout;
    QVBoxLayout *layoutMenu;
    Dlista<Workout*>& WL;
    ModelWorkout& m;
public:
    Qfitmenu(Dlista<Workout*>&,ModelWorkout&, QWidget *parent = nullptr);
private slots:
    void ApriScelta();
};

#endif // QFITMENU_H
