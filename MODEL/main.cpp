#include "mainwindow.h"

#include <QApplication>

#include<iostream>

#include<typeinfo>

#include <vector>

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

    //bool b = c2>=c3;
    //cout << b << endl;

    //    double d1 = c2.calorie();
    //    cout << d1 << endl;

    //    double d2 = c1.calorie();
    //    cout << d2 << endl;

    //    double n1 = n.calorie();
    //    cout << n1 << endl;

    Triathlon c4(1,1,1,1,1,1,1,1,1,1,1,1,1,1);
    double d3 = c4.calorie();
    //cout << d3;
    Triathlon c5(1,1,1,1,1,1,1,1,1,1,1,1,1,1);

    Dlista<Workout*> dl;
    Corsa*    cc = new Corsa(180,30,10,10,10);
    Ciclismo* nn = new Ciclismo(180,30,10,10,10);
    Nuoto* nnn = new Nuoto(100,30,15,23);
    Nuoto* n1=new Nuoto(101,30,15,23);
    Triathlon* tt = new Triathlon(10,1,1,1,1,10,1,1,1,1,1,1,1,1);
    dl.pushT(cc);
    dl.pushT(nn);
    dl.pushT(nnn);
    dl.pushT(tt);
    /*try {
        Workout* s = dl.popFirst(); cout << "la durata è " << s->get_durata();
        dl.popFirst();
        dl.popFirst();
        dl.popFirst();
        dl.popFirst();
        dl.popFirst();
        dl.popFirst();
    } catch(ListaVuota e) {
        cout << "negro, la lista è vuota, che cazzo fai?";
    }*/

    for(Dlista<Workout*>::iterator it = dl.begin(); it!=dl.end(); it++) {
        std::cout << "sbora nel culo " <<(*it)->get_durata() << endl;
        dl.erase(it);
        it--;
    }

    /*
    cout<<" cazzo in culo "<<endl;
    cout << dl.cancellaElemento(n1)<<endl;

    //Nodo<Corsa> n = dl.popFirst();
    //l.stampa();
    cout <<"ora stampo"<<endl;
    std::vector<Workout*> v= dl.stampa();
    std::vector<Workout*>::iterator it = v.begin();
    for(; it != v.end(); it++) {
        std::cout << "sbora nel culo " <<(*it)->get_durata() << endl;
    }
*/


    cout<<" figa nel culo"<<endl;

//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
}
