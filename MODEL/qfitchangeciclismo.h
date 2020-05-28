#ifndef QFITCHANGECICLISMO_H
#define QFITCHANGECICLISMO_H
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
#include "ciclismo.h"

class QfitChangeCiclismo : public QDialog
{
    Q_OBJECT
public:
    QfitChangeCiclismo(Dlista<Workout*>& , ModelWorkout&, int, QWidget* = nullptr);
private:
    QVBoxLayout *LayoutForm;
    QVBoxLayout *MainLayout;
    QLabel *Ldistanza, *Ldurata, *Lpianura, *Lsalita, *Ldiscesa,*LBTciclismo;
    QLineEdit *Tdistanza, *Tdurata, *Tpianura, *Tsalita, *Tdiscesa;
    QPushButton *salva, *reset;
    QHBoxLayout *Hdistanza, *Hdurata, *Hpianura, *Hsalita, *Hdiscesa, *Hbottoni,*TitleLayoutCiclismo;
    Dlista<Workout*>& WL;
    ModelWorkout& m;
    QGroupBox *gbCiclismo;
    int ToEdit;
private slots:
    void SalvaChangeCiclismo();
    void Reset();


};

#endif // QFITCHANGECICLISMO_H
