#ifndef QFITCICLISMO_H
#define QFITCICLISMO_H
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

class QfitCiclismo : public QDialog {
Q_OBJECT
public:
    QfitCiclismo(Dlista<Workout*>& , ModelWorkout&,  QWidget* = nullptr);
private:
    QVBoxLayout *LayoutForm;
    QVBoxLayout *MainLayout;
    QLabel *Ldistanza, *Ldurata, *Lpianura, *Lsalita, *Ldiscesa,*LBTciclismo;
    QLineEdit *Tdistanza, *Tdurata, *Tpianura, *Tsalita, *Tdiscesa;
    QPushButton *salva, *reset;
    QHBoxLayout *Hdistanza, *Hdurata, *Hpianura, *Hsalita, *Hdiscesa, *Hbottoni, *TitleLayoutCiclismo;
    Dlista<Workout*>& WL;
    ModelWorkout& m;
    QGroupBox *gbCiclismo;
private slots:
    void SalvaCiclismo();
    void Reset();
};

#endif // QFITCICLISMO_H
