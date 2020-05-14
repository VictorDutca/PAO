#ifndef QFITMENU_H
#define QFITMENU_H

#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>


class Qfitmenu : public QWidget {
Q_OBJECT
private:
    QLabel *title;
    QPushButton  *Qfitsave, *Qfitnew, *Qfitexport;
    QVBoxLayout *layout;
    QHBoxLayout *layoutMenu;
public:
    Qfitmenu();
private slots:
    void ApriScelta();
};

#endif // QFITMENU_H
