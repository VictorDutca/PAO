#include "modelworkout.h"
#include "workout.h"
#include "lista.h"
#include "triathlon.h"
#include "nuoto.h"
#include "ciclismo.h"
#include "corsa.h"

ModelWorkout::ModelWorkout(Dlista<Workout*>& Tinfo,QObject *parent) : enfo(Tinfo), QAbstractTableModel(parent)
{}

int ModelWorkout::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return enfo.getSize();
}

int ModelWorkout::columnCount(const QModelIndex &parent) const{
    Q_UNUSED(parent);
    return 7;
}

QVariant ModelWorkout::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();

    switch(role){
    case Qt::DisplayRole:
        switch(column){
        case 0:
            if(dynamic_cast<Triathlon*>(enfo.At(row))){
                return QString::fromStdString("Triathlon");
               }else if(dynamic_cast<Nuoto*>(enfo.At(row))){
                return QString::fromStdString("Nuoto");
            }else if(dynamic_cast<Corsa*>(enfo.At(row))){
                return QString::fromStdString("Corsa");
            }else if(dynamic_cast<Ciclismo*>(enfo.At(row))){
                return QString::fromStdString("Ciclismo");
            }
        case 1:
            return QString::fromStdString(std::to_string(enfo.At(row)->get_durata()));
        case 2:
            return QString::fromStdString(std::to_string(enfo.At(row)->calorie()));
        case 3:
            return QString::fromStdString(std::to_string(enfo.At(row)->GrassiBruc()));


    }
}
    return QVariant();

}

QVariant ModelWorkout::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch(section){
        case 0:
            return QString("Allenamento");
        case 1:
            return QString("Durata (Min)");
        case 2:
            return QString("Calorie");
        case 3:
            return QString("Grassi Bruciati (g)");
        case 4:
            return QString("Elimina");
        case 5:
            return QString("Modifica");
        case 6:
            return QString("Visualizza");

        }


    }
    return QVariant();

}

bool ModelWorkout::removeRows(int position, int rows, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), position, position+rows-1);
    endRemoveRows();
    return true;
}

bool ModelWorkout::insertRows(int position, int rows, const QModelIndex &parent) {
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), position, position+rows-1);
    // inserisce nuove righe nei dati sottostanti
    endInsertRows();
    return true;
}

void ModelWorkout::update(){
    beginResetModel();
        insertRow(rowCount());
    endResetModel();

}

void ModelWorkout::ModelErase(int row){
    if(row >= 0 && row < rowCount()) {
       enfo.removeAt(static_cast<unsigned int>(row));
        removeRow(row);
    }
}






