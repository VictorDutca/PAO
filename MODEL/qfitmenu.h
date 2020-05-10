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
    QHBoxLayout *layout;
    QVBoxLayout *layoutMenu;
public:
    Qfitmenu();
};

#endif // QFITMENU_H
