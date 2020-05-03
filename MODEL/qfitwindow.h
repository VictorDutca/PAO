#ifndef QFITWINDOW_H
#define QFITWINDOW_H
#include <QWidget>
#include <QTableView>

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
    QLineEdit *nameLine;
    QTextEdit *addressText;
    QTableView *Table;
};
//! [class definition]

#endif
