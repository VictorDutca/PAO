#ifndef MODELWORKOUT_H
#define MODELWORKOUT_H

#include <QAbstractTableModel>
#include "lista.h"
#include "workout.h"

class ModelWorkout : public QAbstractTableModel {
    Q_OBJECT
public:
    ModelWorkout(Dlista<Workout*>&,QObject* = nullptr);
    QVariant data(const QModelIndex&, int = Qt::DisplayRole) const override;
    QVariant headerData(int, Qt::Orientation, int) const override;
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    bool removeRows(int, int, const QModelIndex &) override;
    bool insertRows(int, int, const QModelIndex &) override;
private:
    Dlista<Workout*>& enfo;
public slots:
    void update();
    void ModelErase(int);
};

#endif // MODELWORKOUT_H
