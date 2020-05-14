#include "qfitwindow.h"
#include "modelworkout.h"
#include <QtWidgets>
#include <QPalette>
#include <QColor>

//! [constructor and input fields]
QFitWindow::QFitWindow(Dlista<Workout*>& _WL,QWidget *parent)
    : WL(_WL) , QWidget(parent)
{
   TableModel = new ModelWorkout(WL);
   Table = new QTableView;
   QGridLayout *mainLayout = new QGridLayout;


    menu = new Qfitmenu();
    mainLayout->addWidget(menu);
    mainLayout->addWidget(Table);

    Table->setModel(TableModel);
    //aggiunta bottoni finti da rifare
    QPushButton *elimina = new QPushButton();
    QPushButton *modifica = new QPushButton();
    QPushButton *dettagli = new QPushButton();



    Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //this->setFixedSize(1000,800);

    //QPalette pal = palette();

    // set black background
    //pal.setColor(QPalette::Background, QColor(113,180,141));
    //setAutoFillBackground(true);
    //setPalette(pal);

//! [constructor and input fields]

//! [layout]


//    mainLayout->addWidget(dioken, 1, 0);
//    mainLayout->addWidget(nameLabel, 0, 0);
//    mainLayout->addWidget(nameLine, 0, 1);
//    mainLayout->addWidget(addressLabel, 2, 0, Qt::AlignTop);
//    mainLayout->addWidget(addressText, 1, 1);
//    mainLayout->addWidget(Table,2,1);
//! [layout]

//![setting the layout]
    setLayout(mainLayout);
    setWindowTitle(tr("QFit"));
}
//! [setting the layout]
