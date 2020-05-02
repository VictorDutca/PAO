#include "testwindow.h"

testwindow::testwindow(QWidget *parent) : QMainWindow(parent)
{


    test = new QTabWidget();
    checkbox = new QCheckBox();
    lblStalin = new QLabel("STALIN");
    lblHitler = new QLabel("HITLER");
    lblAlieni = new QLabel("ALIENI");
    layout = new QVBoxLayout;
    layout->addWidget(lblStalin);
    layout->setAlignment(lblStalin, Qt::AlignHCenter);
    tabGrid = new QTableView;
    test->addTab(checkbox, "STALIN");
    test->addTab(lblHitler, "HITLER");
    test->addTab(lblAlieni, "ALIENI");
    setCentralWidget(test);
    //setLayout(layout);
}
