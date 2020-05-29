#include "corsa.h"
#include <typeinfo>

unsigned int Corsa::constPian = 5;
unsigned int Corsa::constSal = 7;
unsigned int Corsa::constDisc = 3;

Corsa::Corsa (unsigned int dur, unsigned int dist, unsigned int pian, unsigned int sal, unsigned int disc) : Workout(dur), distanza(dist), pianura(pian), salita(sal), discesa(disc) {}

double Corsa::calorie() const {
    return (pianura*constPian) + (discesa*constDisc) + (salita*constSal);
}

unsigned int Corsa::avg_Speed() const {
    return distanza/get_durata();
}
double Corsa::GrassiBruc() const {
    return avg_Speed() + calorie();     // per ora lasciamo sta cazzata
}

bool Corsa::operator==(const Workout& w) const {
if(typeid(w) == typeid(const Corsa&)){
            return Workout::operator==(w) &&
                distanza == (dynamic_cast<const Corsa&>(w)).distanza &&
                pianura == (dynamic_cast<const Corsa&>(w)).pianura &&
                salita == (dynamic_cast<const Corsa&>(w)).salita &&
                discesa == (dynamic_cast<const Corsa&>(w)).discesa;
    }
        return false;
}

bool Corsa::operator<=(const Workout& w) const {
if(typeid(w) == typeid(const Corsa&)){
            return Workout::operator<=(w) &&
                distanza <= (dynamic_cast<const Corsa&>(w)).distanza &&
                pianura <= (dynamic_cast<const Corsa&>(w)).pianura &&
                salita <= (dynamic_cast<const Corsa&>(w)).salita &&
                discesa <= (dynamic_cast<const Corsa&>(w)).discesa;

    }
        return false;
}

bool Corsa::operator>=(const Workout& w) const {
if(typeid(w) == typeid(const Corsa&)){
            return Workout::operator>=(w) &&
                distanza >= (dynamic_cast<const Corsa&>(w)).distanza &&
                pianura >= (dynamic_cast<const Corsa&>(w)).pianura &&
                salita >= (dynamic_cast<const Corsa&>(w)).salita &&
                discesa >= (dynamic_cast<const Corsa&>(w)).discesa;

    }
        return false;
}

unsigned int Corsa::get_distanza() const {
return distanza;
}

unsigned int Corsa::get_pianura() const {
    return pianura;
}
unsigned int Corsa::get_salita() const {
    return salita;
}

unsigned int Corsa::get_discesa() const {
    return discesa;
}



void Corsa::set_distanza(unsigned int x) {
    distanza = x;
}

void Corsa::set_pianura(unsigned int x) {
    pianura = x;
}
void Corsa::set_salita(unsigned int x) {
    salita = x;
}

void Corsa::set_discesa(unsigned int x) {
    discesa = x;
}
