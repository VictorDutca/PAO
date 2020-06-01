#include "nuoto.h"
#include <typeinfo>
#include "math.h"

unsigned int Nuoto::constRana = 5;
unsigned int Nuoto::constDorso = 7;
unsigned int Nuoto::constLibero = 3;
unsigned int Nuoto::constGrassi = 4;

Nuoto::Nuoto(unsigned int durata , unsigned int rana , unsigned int dorso, unsigned int libero)
    : Workout(durata) , VascheRana(rana),VascheDorso(dorso),VascheLibero(libero){}

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

unsigned int Nuoto::GrassiBruc() const {
    return ((calorie()) / (2*M_PI) * constGrassi);
}

unsigned int Nuoto::calorie() const {
    return (VascheRana*constRana) + (VascheDorso*constDorso) + (VascheLibero*constLibero);
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

void Nuoto::set_VascheLibero(unsigned int x) {
    VascheLibero = x;
}

void Nuoto::set_VascheDorso(unsigned int x) {
    VascheDorso = x;
}
void Nuoto::set_VascheRana(unsigned int x) {
    VascheRana = x;
}
