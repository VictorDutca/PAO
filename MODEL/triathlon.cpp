#include "triathlon.h"
#include <typeinfo>


Triathlon::Triathlon(Corsa c1, Ciclismo c2, Nuoto n) : Corsa(c1), Ciclismo(c2), Nuoto(n) {}

Triathlon::Triathlon(unsigned int a, unsigned int b,
              unsigned int c, unsigned int d, unsigned int e, unsigned int f,
              unsigned int g, unsigned int h, unsigned int i, unsigned int l,
             unsigned int m, unsigned int n, unsigned int o, unsigned int p) : Corsa(a,b,c,d,e), Ciclismo(f,g,h,i,l), Nuoto(m,n,o,p) {}

 unsigned int Triathlon::get_durata() const{
    return Corsa::get_durata() + Nuoto::get_durata() + Ciclismo::get_durata();
}



double Triathlon::calorie() const {
    return Corsa::calorie() + Ciclismo::calorie() + Nuoto::calorie();
}

double Triathlon::GrassiBruc() const {
    return 1;
}

bool Triathlon::operator==(const Workout& w) const {
    if(typeid(w) == typeid(const Triathlon&)){
        return  get_durata() == (dynamic_cast<const Triathlon&>(w)).get_durata() &&
                Corsa::get_distanza() == (dynamic_cast<const Corsa&>(w)).get_distanza() &&
                Corsa::get_discesa() == (dynamic_cast<const Corsa&>(w)).get_discesa() &&
                Corsa::get_pianura() == (dynamic_cast<const Corsa&>(w)).get_pianura() &&
                Corsa::get_salita() == (dynamic_cast<const Corsa&>(w)).get_salita() &&
                Ciclismo::get_distanza() == (dynamic_cast<const Ciclismo&>(w)).get_distanza() &&
                Ciclismo::get_discesa() == (dynamic_cast<const Ciclismo&>(w)).get_discesa() &&
                Ciclismo::get_pianura() == (dynamic_cast<const Ciclismo&>(w)).get_pianura() &&
                Ciclismo::get_salita() == (dynamic_cast<const Ciclismo&>(w)).get_salita() &&
                Nuoto::getVascheDorso() == (dynamic_cast<const Nuoto&>(w)).getVascheDorso() &&
                Nuoto::getVascheLibero() == (dynamic_cast<const Nuoto&>(w)).getVascheLibero() &&
                Nuoto::getVascheRana() == (dynamic_cast<const Nuoto&>(w)).getVascheRana();
        }
        return false;
}

bool Triathlon::operator>=(const Workout& w) const {
    if(typeid(w) == typeid(const Triathlon&)){
        return  get_durata() >= (dynamic_cast<const Triathlon&>(w)).get_durata() &&
                Corsa::get_distanza() >= (dynamic_cast<const Corsa&>(w)).get_distanza() &&
                Corsa::get_discesa() >= (dynamic_cast<const Corsa&>(w)).get_discesa() &&
                Corsa::get_pianura() >= (dynamic_cast<const Corsa&>(w)).get_pianura() &&
                Corsa::get_salita() >= (dynamic_cast<const Corsa&>(w)).get_salita() &&
                Ciclismo::get_distanza() >= (dynamic_cast<const Ciclismo&>(w)).get_distanza() &&
                Ciclismo::get_discesa() >= (dynamic_cast<const Ciclismo&>(w)).get_discesa() &&
                Ciclismo::get_pianura() >= (dynamic_cast<const Ciclismo&>(w)).get_pianura() &&
                Ciclismo::get_salita() >= (dynamic_cast<const Ciclismo&>(w)).get_salita() &&
                Nuoto::getVascheDorso() >= (dynamic_cast<const Nuoto&>(w)).getVascheDorso() &&
                Nuoto::getVascheLibero() >= (dynamic_cast<const Nuoto&>(w)).getVascheLibero() &&
                Nuoto::getVascheRana() >= (dynamic_cast<const Nuoto&>(w)).getVascheRana();
        }
        return false;
}

bool Triathlon::operator<=(const Workout& w) const {
    if(typeid(w) == typeid(const Triathlon&)){
        return  get_durata() <= (dynamic_cast<const Triathlon&>(w)).get_durata() &&
                Corsa::get_distanza() <= (dynamic_cast<const Corsa&>(w)).get_distanza() &&
                Corsa::get_discesa() <= (dynamic_cast<const Corsa&>(w)).get_discesa() &&
                Corsa::get_pianura() <= (dynamic_cast<const Corsa&>(w)).get_pianura() &&
                Corsa::get_salita() <= (dynamic_cast<const Corsa&>(w)).get_salita() &&
                Ciclismo::get_distanza() <= (dynamic_cast<const Ciclismo&>(w)).get_distanza() &&
                Ciclismo::get_discesa() <= (dynamic_cast<const Ciclismo&>(w)).get_discesa() &&
                Ciclismo::get_pianura() <= (dynamic_cast<const Ciclismo&>(w)).get_pianura() &&
                Ciclismo::get_salita() <= (dynamic_cast<const Ciclismo&>(w)).get_salita() &&
                Nuoto::getVascheDorso() <= (dynamic_cast<const Nuoto&>(w)).getVascheDorso() &&
                Nuoto::getVascheLibero() <= (dynamic_cast<const Nuoto&>(w)).getVascheLibero() &&
                Nuoto::getVascheRana() <= (dynamic_cast<const Nuoto&>(w)).getVascheRana();
        }
        return false;
}
