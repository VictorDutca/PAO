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
    addressText = new QTextEdit;
//! [constructor and input fields]

//! [layout]
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(nameLine, 0, 1);
    mainLayout->addWidget(addressLabel, 1, 0, Qt::AlignTop);
    mainLayout->addWidget(addressText, 1, 1);
    mainLayout->addWidget(Table,1,1);
//! [layout]

//![setting the layout]
    setLayout(mainLayout);
    setWindowTitle(tr("QFit"));
}
//! [setting the layout]
