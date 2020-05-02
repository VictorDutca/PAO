#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTableView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QCheckBox>


class testwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit testwindow(QWidget *parent = nullptr);

private:
QCheckBox *checkbox;
QVBoxLayout *layout;
QLabel *lblStalin;
QLabel *lblHitler;
QLabel *lblAlieni;
QTableView *tabGrid;
QTabWidget* test;

signals:

public slots:
};

#endif // TESTWINDOW_H
