#ifndef QFITWINDOW_H
#define QFITWINDOW_H
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include "qfitmenu.h"
#include "lista.h"
#include "workout.h"
#include "modelworkout.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

//! [class definition]
class QFitWindow : public QWidget
{
    Q_OBJECT

public:
    QFitWindow(Dlista<Workout*>&, QWidget *parent = nullptr);
    QTableView *Table;
private:
    QLabel *lblTitolo;
    QPushButton  *salva, *crea, *esporta;
    QLineEdit *nameLine;
    QTextEdit *addressText;
    Qfitmenu *menu;
    Dlista<Workout*>& WL;
    ModelWorkout* TableModel;


};
//! [class definition]

#endif
