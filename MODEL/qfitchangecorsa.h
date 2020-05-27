#ifndef QFITCHANGECORSA_H
#define QFITCHANGECORSA_H
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
#include "corsa.h"

class QfitChangeCorsa : public QDialog {
Q_OBJECT
public:
    QfitChangeCorsa(Dlista<Workout*>& , ModelWorkout&, int, QWidget* = nullptr);
private:
    QVBoxLayout *LayoutForm;
    QVBoxLayout *MainLayout;
    QLabel *Ldistanza, *Ldurata, *Lpianura, *Lsalita, *Ldiscesa,*LBTcorsa;
    QLineEdit *Tdistanza, *Tdurata, *Tpianura, *Tsalita, *Tdiscesa;
    QPushButton *salva, *reset;
    QHBoxLayout *Hdistanza, *Hdurata, *Hpianura, *Hsalita, *Hdiscesa, *Hbottoni,*TitleLayoutCorsa;
    Dlista<Workout*>& WL;
    ModelWorkout& m;
    QGroupBox *gbCorsa;
    int ToEdit;
private slots:
    void SalvaChangeCorsa();
    void Reset();
};

#endif // QFITCHANGECORSA_H
