#ifndef QFITCHANGENUOTO_H
#define QFITCHANGENUOTO_H
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

class QfitChangeNuoto : public QDialog {
Q_OBJECT
public:
    QfitChangeNuoto(Dlista<Workout*>& , ModelWorkout&, int, int =0,QWidget* = nullptr);
private:
    QVBoxLayout *LayoutForm;
    QVBoxLayout *MainLayout;
    QLabel *Ldurata, *LRana, *LDorso, *LLibero,* LBTnuoto;
    QLineEdit *Tdurata, *TRana, *TDorso, *TLibero;
    QPushButton *salva, *reset;
    QHBoxLayout *Hdurata, *HRana, *HDorso, *HLibero, *Hbottoni, *TitleLayoutNuoto;
    Dlista<Workout*>& WL;
    ModelWorkout& m;
    QGroupBox *gbNuoto;
    int ToEdit, Editable;
private slots:
    void SalvaChangeNuoto();
    void Reset();
};

#endif // QFITCHANGENUOTO_H
