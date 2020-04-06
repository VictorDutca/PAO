#ifndef NUOTO_H
#define NUOTO_H
#include <workout.h>


class Nuoto : virtual public Workout{
private:
    unsigned int VascheRana;
    unsigned int VascheDorso;
    unsigned int VascheLibero;
public:
    Nuoto(unsigned int =0, unsigned int =0, unsigned int =0, unsigned int =0);
    virtual double calorie() const;
virtual double GrassiBruc() const;
unsigned int getVascheLibero() const;
unsigned int getVascheRana() const;
unsigned int getVascheDorso() const;
virtual bool operator==(const Workout& ) const;
virtual bool operator<=(const  Workout& ) const;
virtual bool operator>=(const  Workout& ) const;
};


#endif // NUOTO_H
