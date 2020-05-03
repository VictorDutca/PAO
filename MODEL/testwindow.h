#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>
#include <QFrame>
#include <QTextEdit>

class testwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit testwindow(QWidget *parent = nullptr);

private:
QLineEdit *nameLine;
QTextEdit *addressText;


signals:

public slots:
};

#endif // TESTWINDOW_H
