#include "qfitwindow.h"
#include "modelworkout.h"
#include <QtWidgets>
#include <QPalette>
#include <QColor>

//! [constructor and input fields]
QFitWindow::QFitWindow(Dlista<Workout*>& _WL,XMLHandler& _XMLWorkout,QWidget *parent)
    : WL(_WL), XMLWorkout(_XMLWorkout) , QWidget(parent)
{
   TableModel = new ModelWorkout(WL);
   Table = new QTableView;

   QVBoxLayout *mainLayout = new QVBoxLayout;


    menu = new Qfitmenu(WL,*TableModel,XMLWorkout);

    mainLayout->addWidget(menu);
    mainLayout->addWidget(Table);
    mainLayout->setAlignment(Qt::AlignCenter);

    Table->setModel(TableModel);
    //aggiunta bottoni finti da rifare
    //QPushButton *elimina = new QPushButton();
    QPushButton *modifica = new QPushButton();
    QPushButton *dettagli = new QPushButton();
    TblElimina = new DelegateDelete();
    Table->setItemDelegateForColumn(4, TblElimina);
    //Table->setItemDelegateForColumn(5, modifica);
    //Table->setItemDelegateForColumn(6, dettagli);
    connect(TblElimina, SIGNAL(AlertDelete(int)), this, SLOT(SignalErase(int)));
    connect(this, SIGNAL(ModelRemove(int)), TblElimina, SLOT(DeleteSlot(int)));
    connect(TblElimina, SIGNAL(ModelDelete(int)), TableModel, SLOT(ModelErase(int)));


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

void QFitWindow::SignalErase(int row){
    QMessageBox ConfirmDelete;
    ConfirmDelete.setIcon(QMessageBox::Question);
    ConfirmDelete.setText("ATTENZIONE!");
    ConfirmDelete.setInformativeText("Vuoi davvero eliminare l'allenamento?");
    ConfirmDelete.addButton("No", QMessageBox::NoRole);
    ConfirmDelete.addButton("Sì", QMessageBox::YesRole);
    int choice = ConfirmDelete.exec();
    if(choice)
        emit ModelRemove(row);


}


//! [setting the layout]
