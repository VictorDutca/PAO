#ifndef QFITCHANGETRIATHLON_H
#define QFITCHANGETRIATHLON_H
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
#include "triathlon.h"
#include <QGroupBox>

class QfitChangeTriathlon : public QDialog {
Q_OBJECT
public:
    QfitChangeTriathlon(Dlista<Workout*>& , ModelWorkout&, int, int =0,QWidget* = nullptr);
private:
    QVBoxLayout *LayoutForm;
    QVBoxLayout *MainLayout;
    QLabel *COdistanza, *COdurata, *COpianura, *COsalita, *COdiscesa, *CIdistanza, *CIdurata, *CIpianura, *CIsalita, *CIdiscesa, *Ndurata, *Nrana, *Ndorso, *Nlibero, *LBTTriat;
    QLineEdit *TCOdistanza, *TCOdurata, *TCOpianura, *TCOsalita, *TCOdiscesa, *TCIdistanza, *TCIdurata, *TCIpianura, *TCIsalita, *TCIdiscesa, *TNdurata, *TNrana, *TNdorso, *TNlibero;
    QPushButton *salva, *reset;
    QHBoxLayout *HCOdistanza, *HCOdurata, *HCOpianura, *HCOsalita, *HCOdiscesa, *HCIdistanza, *HCIdurata, *HCIpianura, *HCIsalita, *HCIdiscesa, *HNdurata, *HNrana, *HNdorso, *HNlibero, *Hbottoni,*TitleLayout;
    Dlista<Workout*>& WL;
    ModelWorkout& m;
    QGroupBox *gbCorsa;
    QGroupBox *gbCiclismo;
    QGroupBox *gbNuoto;
    QVBoxLayout *LTCorsa, *LTCiclismo, *LTNuoto;
    int ToEdit;
    int Editable;
private slots:
    void SalvaChangeTriathlon();
    void Reset();
};

#endif // QFITCHANGETRIATHLON_H
