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

class QfitCorsa : public QDialog {
Q_OBJECT
public:
    QfitCorsa(QWidget* = nullptr);
private:
    QVBoxLayout *LayoutForm;
    QVBoxLayout *MainLayout;
    QLabel *Ldistanza, *Ldurata, *Lpianura, *Lsalita, *Ldiscesa;
    QLineEdit *Tdistanza, *Tdurata, *Tpianura, *Tsalita, *Tdiscesa;
    QPushButton *salva, *cancella;
    QHBoxLayout *Hdistanza, *Hdurata, *Hpianura, *Hsalita, *Hdiscesa, *Hbottoni;
};

#endif // QFITCORSA_H
