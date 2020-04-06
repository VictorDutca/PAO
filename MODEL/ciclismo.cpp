#include "ciclismo.h"
#include <typeinfo>

Ciclismo::Ciclismo(unsigned int di,unsigned int pia, unsigned int sal, unsigned int  dis, unsigned int dur): Workout(dur), distanza(di) ,pianura(pia), salita(sal), discesa(dis){}

double Ciclismo::calorie() const {
    return 1;
}

double Ciclismo::GrassiBruc() const {
    return 1;
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

