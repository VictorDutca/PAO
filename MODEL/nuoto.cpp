#include "nuoto.h"
#include <typeinfo>

Nuoto::Nuoto(unsigned int durata , unsigned int rana , unsigned int dorso, unsigned int libero): Workout(durata) , VascheRana(rana),VascheDorso(dorso),VascheLibero(libero){
}

bool Nuoto::operator==(const Workout& w) const {
if(typeid(w) == typeid(const Nuoto&)){
            return Workout::operator==(w) &&
                VascheRana == (dynamic_cast<const Nuoto&>(w)).VascheRana &&
                VascheDorso== (dynamic_cast<const Nuoto&>(w)).VascheDorso &&
        VascheRana== (dynamic_cast<const Nuoto&>(w)).VascheRana;
    }
        return false;
}

bool Nuoto::operator>=(const Workout& w) const {

        if(typeid(w) == typeid(const Nuoto&)){
            return Workout::operator>=(w) &&
                VascheRana >= (dynamic_cast<const Nuoto&>(w)).VascheRana &&
                VascheDorso >= (dynamic_cast<const Nuoto&>(w)).VascheDorso &&
VascheLibero >= (dynamic_cast<const Nuoto&>(w)).VascheLibero;
}
        return false;

}

bool Nuoto::operator<=(const Workout& w) const {

        if(typeid(w) == typeid(const Nuoto&)){
            return Workout::operator>=(w) &&
                VascheRana <= (dynamic_cast<const Nuoto&>(w)).VascheRana &&
                VascheDorso <= (dynamic_cast<const Nuoto&>(w)).VascheDorso &&
VascheLibero <= (dynamic_cast<const Nuoto&>(w)).VascheLibero;
}
        return false;

}
double Nuoto::GrassiBruc() const {
return 4;
}

double Nuoto::calorie() const {
return 2;
}
unsigned int Nuoto::getVascheLibero() const{
return VascheLibero;
}

unsigned int Nuoto::getVascheRana() const{
return VascheRana;
}
unsigned int Nuoto::getVascheDorso() const{
return VascheDorso;
}

