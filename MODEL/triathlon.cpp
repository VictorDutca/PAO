#include "triathlon.h"
#include <typeinfo>

Triathlon::Triathlon(Corsa c1, Ciclismo c2, Nuoto n) : Corsa(c1), Ciclismo(c2), Nuoto(n) {}

Triathlon::Triathlon(unsigned int a, unsigned int b,
              unsigned int c, unsigned int d, unsigned int e, unsigned int f,
              unsigned int g, unsigned int h, unsigned int i, unsigned int l,
             unsigned int m, unsigned int n, unsigned int o, unsigned int p) : Corsa(a,b,c,d,e), Ciclismo(f,g,h,i,l), Nuoto(m,n,o,p) {}

double Triathlon::calorie() const {
    return Corsa::calorie() + Ciclismo::calorie() + Nuoto::calorie();
}

double Triathlon::GrassiBruc() const {
    return 1;
}

bool Triathlon::operator==(const Workout& w) const {
if(typeid(w) == typeid(const Triathlon&)){
            return Corsa::operator==(w) && Ciclismo::operator==(w) && Nuoto::operator==(w);
    }
        return false;
}

bool Triathlon::operator>=(const Workout& w) const {
if(typeid(w) == typeid(const Triathlon&)){
            return Corsa::operator>=(w) && Ciclismo::operator>=(w) && Nuoto::operator>=(w);
    }
        return false;
}

bool Triathlon::operator<=(const Workout& w) const {
if(typeid(w) == typeid(const Triathlon&)){
            return Corsa::operator<=(w) && Ciclismo::operator<=(w) && Nuoto::operator<=(w);
    }
        return false;
}
