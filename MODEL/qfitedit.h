#ifndef QFITEDIT_H
#define QFITEDIT_H
#include <QWidget>
#include <QTableView>
#include <QPushButton>
#include <QFormLayout>

class QfitEdit : public QWidget
{
    Q_OBJECT
public:
    QfitEdit();

private:
    QPushButton *sceltaCorsa, *sceltaCiclismo, *sceltaNuoto, *sceltaTriathlon;
    QVBoxLayout *layoutScelta;
};

#endif // QFITEDIT_H
