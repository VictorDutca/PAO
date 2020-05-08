#ifndef QFITWINDOW_H
#define QFITWINDOW_H
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include "qfitmenu.h"

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
    QFitWindow(QWidget *parent = nullptr);


private:
    QLabel *lblTitolo;
    QPushButton  *salva, *crea, *esporta;
    QLineEdit *nameLine;
    QTextEdit *addressText;
    QTableView *Table;
    Qfitmenu *menu;
};
//! [class definition]

#endif
