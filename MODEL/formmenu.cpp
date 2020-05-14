#include "formmenu.h"
#include "ui_formmenu.h"

FormMenu::FormMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMenu)
{
    ui->setupUi(this);
}

FormMenu::~FormMenu()
{
    delete ui;
}
