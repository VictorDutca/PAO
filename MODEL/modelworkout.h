#ifndef MODELWORKOUT_H
#define MODELWORKOUT_H

#include <QAbstractTableModel>
#include "workout.h"
#include "lista.h"

class ModelWorkout : public QAbstractTableModel {
    Q_OBJECT
private:
    Dlista<Workout*>& enfo;
public:
    ModelWorkout(Dlista<Workout*>&, QObject* = nullptr);
    QVariant data(const QModelIndex&, int = Qt::DisplayRole) const override;
    QVariant headerData(int, Qt::Orientation, int) const override;
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    bool removeRows(int, int, const QModelIndex &) override;
    bool insertRows(int, int, const QModelIndex &) override;
public slots:
    void update();
    void ModelErase(int);
};

#endif // MODELWORKOUT_H
