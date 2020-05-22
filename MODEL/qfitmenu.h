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
#include "xmlhandler.h"

class Qfitmenu : public QWidget {
Q_OBJECT
private:
    QLabel *title;
    QPushButton  *Qfitsave, *Qfitnew, *Qfitexport;
    QHBoxLayout *layout;
    QVBoxLayout *layoutMenu;
    Dlista<Workout*>& WL;
    ModelWorkout& m;
    XMLHandler& XMLWorkout;
public:
    Qfitmenu(Dlista<Workout*>&,ModelWorkout&,XMLHandler& , QWidget *parent = nullptr);
private slots:
    void ApriScelta();
    void SalvaFile();
    void EsportaFile();
};

#endif // QFITMENU_H
