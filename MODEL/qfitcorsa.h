#ifndef QFITCORSA_H
#define QFITCORSA_H
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

class QfitCorsa : public QDialog {
Q_OBJECT
public:
    QfitCorsa(Dlista<Workout*>& , ModelWorkout&,  QWidget* = nullptr);
private:
    QVBoxLayout *LayoutForm;
    QVBoxLayout *MainLayout;
    QLabel *Ldistanza, *Ldurata, *Lpianura, *Lsalita, *Ldiscesa;
    QLineEdit *Tdistanza, *Tdurata, *Tpianura, *Tsalita, *Tdiscesa;
    QPushButton *salva, *reset;
    QHBoxLayout *Hdistanza, *Hdurata, *Hpianura, *Hsalita, *Hdiscesa, *Hbottoni;
    Dlista<Workout*>& WL;
    ModelWorkout& m;
    QGroupBox *gbCorsa;
private slots:
    void SalvaCorsa();
    void Reset();
};

#endif // QFITCORSA_H
