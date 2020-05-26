#ifndef QFITNUOTO_H
#define QFITNUOTO_H
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QLineEdit>
#include "lista.h"
#include "modelworkout.h"
#include <QGroupBox>

class QfitNuoto : public QDialog {
Q_OBJECT
public:
    QfitNuoto(Dlista<Workout*>& , ModelWorkout&,  QWidget* = nullptr);
private:
    QVBoxLayout *LayoutForm;
    QVBoxLayout *MainLayout;
    QLabel *Ldurata, *LRana, *LDorso, *LLibero;
    QLineEdit *Tdurata, *TRana, *TDorso, *TLibero;
    QPushButton *salva, *reset;
    QHBoxLayout *Hdurata, *HRana, *HDorso, *HLibero, *Hbottoni;
    Dlista<Workout*>& WL;
    ModelWorkout& m;
    QGroupBox *gbNuoto;
private slots:
    void SalvaNuoto();
    void Reset();
};

#endif // QFITNUOTO_H
