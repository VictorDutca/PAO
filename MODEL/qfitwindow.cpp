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
    TblModifica = new DelegateChange();
    TblVisualizza = new DelegateView();
    Table->setItemDelegateForColumn(4, TblElimina);
    Table->setItemDelegateForColumn(5, TblModifica);
    Table->setItemDelegateForColumn(6, TblVisualizza);
    //Table->setItemDelegateForColumn(5, modifica);
    //Table->setItemDelegateForColumn(6, dettagli);
    connect(TblElimina, SIGNAL(AlertDelete(int)), this, SLOT(SignalErase(int)));
    connect(this, SIGNAL(ModelRemove(int)), TblElimina, SLOT(DeleteSlot(int)));
    connect(TblElimina, SIGNAL(ModelDelete(int)), TableModel, SLOT(ModelErase(int)));

    connect(TblModifica, SIGNAL(ApriChange(int)), this, SLOT(OpenChangeDialog(int)));
    connect(TblVisualizza, SIGNAL(ApriChange(int)), this, SLOT(OpenViewDialog(int)));



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

void QFitWindow::OpenChangeDialog(int row) {
    Workout* a = WL.At(row);
    if(dynamic_cast<Triathlon*>(a)){
        QfitChangeTriathlon *b = new QfitChangeTriathlon(WL, *TableModel, row);
        b->exec();
    }
    else if(dynamic_cast<Corsa*>(a)) {
        QfitChangeCorsa  *b = new QfitChangeCorsa(WL, *TableModel, row);
        b->exec();
    }
    else if(dynamic_cast<Ciclismo*>(a)){

        QfitChangeCiclismo  *b = new QfitChangeCiclismo(WL, *TableModel, row);
        b->exec();
    }
    else if(dynamic_cast<Nuoto*>(a)){
        QfitChangeNuoto *b = new QfitChangeNuoto(WL, *TableModel, row);
        b->exec();
    }

    /*if(dynamic_cast<Triathlon*>(a)) {
        da = new DialogTriathlon(catleti, ca, true,riga);
    } else if(dynamic_cast<Nuoto*>(a)) {
        da = new DialogNuoto(catleti, ca, true,riga);
    } else if(dynamic_cast<Ciclismo*>(a)) {
        da = new DialogCiclismo(catleti, ca, true,riga);
    } else if(dynamic_cast<Corsa*>(a)) {
        da = new DialogCorsa(catleti, ca, true,riga);
    } else {
        return;
    }

    da->exec();
    delete da;
    // nessuna delete su 'a' perché get ritorna un puntatore grezzo, non copia profonda
    // corrispondente a quello contenuto in DeepPtr<Allenamento>*/
}
void QFitWindow::OpenViewDialog(int row){
    Workout* a = WL.At(row);
    if(dynamic_cast<Triathlon*>(a)){
        QfitChangeTriathlon *b = new QfitChangeTriathlon(WL, *TableModel, row, 1);
        b->exec();
    }
    else if(dynamic_cast<Corsa*>(a)) {
        QfitChangeCorsa  *b = new QfitChangeCorsa(WL, *TableModel, row, 1);
        b->exec();
    }
    else if(dynamic_cast<Ciclismo*>(a)){

        QfitChangeCiclismo  *b = new QfitChangeCiclismo(WL, *TableModel, row, 1);
        b->exec();
    }
    else if(dynamic_cast<Nuoto*>(a)){
        QfitChangeNuoto *b = new QfitChangeNuoto(WL, *TableModel, row, 1);
        b->exec();
    }
}

//! [setting the layout]
