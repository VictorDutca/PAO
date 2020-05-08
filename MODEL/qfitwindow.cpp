#include "qfitwindow.h"
#include <QtWidgets>

//! [constructor and input fields]
QFitWindow::QFitWindow(QWidget *parent)
    : QWidget(parent)
{
    QLabel *nameLabel = new QLabel(tr("Name:"));
    nameLine = new QLineEdit;
    Table = new QTableView();
    QLabel *addressLabel = new QLabel(tr("Address:"));
    QLabel *dioken = new QLabel(tr("Cazzate"));
    salva = new QPushButton(tr("Salva"));
    esporta = new QPushButton(tr("Esporta"));
    crea = new QPushButton(tr("Crea"));
    QGridLayout *mainLayout = new QGridLayout;
    addressText = new QTextEdit;
    lblTitolo = new QLabel;
    QPixmap banner("../MODEL/img/logoProg.png");
    lblTitolo->setPixmap(banner);
    lblTitolo->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(lblTitolo,0,0);
    mainLayout->setAlignment(lblTitolo, Qt::AlignHCenter);
    menu = new Qfitmenu();
    mainLayout->addWidget(menu);
//! [constructor and input fields]

//! [layout]

    mainLayout->addWidget(salva,0,0);
    mainLayout->addWidget(crea,1,0);
    mainLayout->addWidget(esporta,2,0);

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
