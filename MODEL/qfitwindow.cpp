#include "qfitwindow.h"
#include "modelworkout.h"
#include <QtWidgets>
#include <QPalette>
#include <QColor>

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

    TblElimina = new DelegateDelete();
    TblModifica = new DelegateChange();
    TblVisualizza = new DelegateView();
    Table->setItemDelegateForColumn(4, TblElimina);
    Table->setItemDelegateForColumn(5, TblModifica);
    Table->setItemDelegateForColumn(6, TblVisualizza);

    connect(TblElimina, SIGNAL(AlertDelete(int)), this, SLOT(SignalErase(int)));
    connect(this, SIGNAL(ModelRemove(int)), TblElimina, SLOT(DeleteSlot(int)));
    connect(TblElimina, SIGNAL(ModelDelete(int)), TableModel, SLOT(ModelErase(int)));

    connect(TblModifica, SIGNAL(ApriChange(int)), this, SLOT(OpenChangeDialog(int)));
    connect(TblVisualizza, SIGNAL(ApriChange(int)), this, SLOT(OpenViewDialog(int)));

    Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->setFixedSize(1152,800);

    setLayout(mainLayout);
    setWindowTitle(tr("QFit"));
    setWindowIcon(QIcon(":/utils/small_icon.png"));

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
