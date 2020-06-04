#include "ciclismo.h"
#include <typeinfo>
#include <math.h>

unsigned int Ciclismo::constPian = 5;
unsigned int Ciclismo::constSal = 7;
unsigned int Ciclismo::constDisc = 3;

Ciclismo::Ciclismo(unsigned int dur, unsigned int di, unsigned int pia, unsigned int sal, unsigned int  dis)
    : Workout(dur), distanza(di) ,pianura(pia), salita(sal), discesa(dis){}

unsigned int Ciclismo::calorie() const {
    return (pianura*constPian) + (discesa*constDisc) + (salita*constSal);
}
Ciclismo::Ciclismo(const Ciclismo& c): Workout(c.get_durata()){
       discesa = c.discesa;
       pianura = c.pianura;
       salita = c.salita;
       distanza = c.distanza;
}

unsigned int Ciclismo::avg_Speed() const{
    return distanza/get_durata();
}

unsigned int Ciclismo::GrassiBruc() const {
    return (avg_Speed() + calorie()) / (2*M_PI);
}

bool Ciclismo::operator==(const Workout& w) const {
if(typeid(w) == typeid(const Ciclismo&)){
            return Workout::operator==(w) &&
                distanza == (dynamic_cast<const Ciclismo&>(w)).distanza &&
                pianura == (dynamic_cast<const Ciclismo&>(w)).pianura &&
                salita == (dynamic_cast<const Ciclismo&>(w)).salita &&
                discesa == (dynamic_cast<const Ciclismo&>(w)).discesa;
    }
        return false;
}

bool Ciclismo::operator>=(const Workout& w) const {
if(typeid(w) == typeid(const Ciclismo&)){
            return Workout::operator>=(w) &&
                distanza >= (dynamic_cast<const Ciclismo&>(w)).distanza &&
                pianura >= (dynamic_cast<const Ciclismo&>(w)).pianura &&
                salita >= (dynamic_cast<const Ciclismo&>(w)).salita &&
                discesa >= (dynamic_cast<const Ciclismo&>(w)).discesa;
    }
        return false;
}

bool Ciclismo::operator<=(const Workout& w) const {
    if(typeid(w) == typeid(const Ciclismo&)){
                return Workout::operator<=(w) &&
                    distanza <= (dynamic_cast<const Ciclismo&>(w)).distanza &&
                    pianura <= (dynamic_cast<const Ciclismo&>(w)).pianura &&
                    salita <= (dynamic_cast<const Ciclismo&>(w)).salita &&
                    discesa <= (dynamic_cast<const Ciclismo&>(w)).discesa;
        }
            return false;
}

unsigned int Ciclismo::get_distanza() const {
    return distanza;
}

unsigned int Ciclismo::get_pianura() const {
    return pianura;
}
unsigned int Ciclismo::get_salita() const {
    return salita;
}

unsigned int Ciclismo::get_discesa() const {
    return discesa;
}


void Ciclismo::set_distanza(unsigned int x)  {
    distanza = x;
}

void Ciclismo::set_pianura(unsigned int x)  {
    pianura = x;
}
void Ciclismo::set_salita(unsigned int x)  {
    salita = x;
}

void Ciclismo::set_discesa(unsigned int x)  {
    discesa = x;
}
