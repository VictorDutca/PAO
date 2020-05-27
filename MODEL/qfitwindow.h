#ifndef QFITWINDOW_H
#define QFITWINDOW_H
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include "qfitmenu.h"
#include "lista.h"
#include "workout.h"
#include "modelworkout.h"
#include "xmlhandler.h"
#include "delegatedelete.h"
#include "delegatebutton.h"
#include "delegatechange.h"
#include "qfitchangecorsa.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QTextEdit;
class QVBoxLayout;
QT_END_NAMESPACE

//! [class definition]
class QFitWindow : public QWidget
{
    Q_OBJECT

public:
    QFitWindow(Dlista<Workout*>&, XMLHandler& ,QWidget *parent = nullptr);
private:
    QTableView *Table;
    QLabel *lblTitolo;
    DelegateDelete* TblElimina;
    QPushButton  *salva, *crea, *esporta;
    QLineEdit *nameLine;
    QTextEdit *addressText;
    Qfitmenu *menu;
    Dlista<Workout*>& WL;
    ModelWorkout* TableModel;
    XMLHandler& XMLWorkout;
    DelegateChange *TblModifica;
public slots:
    void SignalErase(int);
    void OpenChangeDialog(int);
signals:
    void ModelRemove(int);

};
//! [class definition]

#endif
