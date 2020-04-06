#include "corsa.h"
#include <typeinfo>

Corsa::Corsa (unsigned int dur, unsigned int dist, unsigned int pian, unsigned int sal, unsigned int disc) : Workout(dur), distanza(dist), pianura(pian), salita(sal), discesa(disc) {}

double Corsa::calorie() const {
    return 1;
}

double Corsa::GrassiBruc() const {
    return 1;
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

