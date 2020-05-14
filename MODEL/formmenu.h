#ifndef FORMMENU_H
#define FORMMENU_H

#include <QWidget>

namespace Ui {
class FormMenu;
}

class FormMenu : public QWidget
{
    Q_OBJECT

public:
    explicit FormMenu(QWidget *parent = 0);
    ~FormMenu();

private:
    Ui::FormMenu *ui;
};

#endif // FORMMENU_H
