#ifndef QFITEDIT_H
#define QFITEDIT_H
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QDateEdit>

class QfitEdit : public QDialog {
    Q_OBJECT
public:
    QfitEdit(QWidget* = nullptr);
private:
    QPushButton *sceltaCorsa, *sceltaCiclismo, *sceltaNuoto, *sceltaTriathlon;
    QVBoxLayout *layoutScelta;
};

#endif // QFITEDIT_H
