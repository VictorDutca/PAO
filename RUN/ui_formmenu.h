/********************************************************************************
** Form generated from reading UI file 'formmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMENU_H
#define UI_FORMMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMenu
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *FormMenu)
    {
        if (FormMenu->objectName().isEmpty())
            FormMenu->setObjectName(QStringLiteral("FormMenu"));
        FormMenu->resize(400, 150);
        gridLayout_2 = new QGridLayout(FormMenu);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_3 = new QPushButton(FormMenu);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(FormMenu);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(FormMenu);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(FormMenu);

        QMetaObject::connectSlotsByName(FormMenu);
    } // setupUi

    void retranslateUi(QWidget *FormMenu)
    {
        FormMenu->setWindowTitle(QApplication::translate("FormMenu", "Form", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("FormMenu", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("FormMenu", "PushButton", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FormMenu", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormMenu: public Ui_FormMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMENU_H
