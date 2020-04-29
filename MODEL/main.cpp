#include "mainwindow.h"

#include <QApplication>

#include<iostream>

#include<typeinfo>

using namespace std;

#include "ciclismo.h"
#include "corsa.h"
#include "lista.h"
#include "mainwindow.h"
#include "nuoto.h"
#include "schedules.h"
#include "triathlon.h"
#include "workout.h"

int main(int argc, char *argv[])
{
    Corsa c1(180,30,10,10,10);
    Corsa c11(80,30,10,10,10);
    Ciclismo c2(180,30,10,10,10);
    Ciclismo c3(180,30,10,10,10);
    Nuoto n(15,2,2,2);
    Nuoto n11(15,2,2,2);

    bool b = c2>=c3;
    cout << b << endl;

    double d1 = c2.calorie();
    cout << d1 << endl;

    double d2 = c1.calorie();
    cout << d2 << endl;

    double n1 = n.calorie();
    cout << n1 << endl;

    Triathlon c4(c1, c2, n);
    double d3 = c4.calorie();
    cout << d3;
    Triathlon c5(c11, c2, n);

    Dlista<Workout*> dl;
    Corsa* cc = new Corsa(180,30,10,10,10);
    Ciclismo* nn = new Ciclismo(180,30,10,10,10);
    dl.pushT(cc);
    dl.pushT(nn);
    //Nodo<Corsa> n = dl.popFirst();
    //l.stampa();

    if(c5==c4){
        cout<<" ok "<<endl;
    }
    else{
        cout<<" figa nel culo"<<endl;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
