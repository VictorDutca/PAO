#ifndef CORSA_H
#define CORSA_H
#include <workout.h>

class Corsa : virtual public Workout {
private:
    unsigned int distanza;
    unsigned int pianura;
    unsigned int salita;
    unsigned int discesa;
public:
    Corsa (unsigned int =0, unsigned int = 0, unsigned int = 0, unsigned int = 0, unsigned int = 0);
    virtual double calorie() const;
    virtual double GrassiBruc( ) const;
    virtual bool operator==(const Workout& ) const;
    virtual bool operator<=(const  Workout& ) const;
    virtual bool operator>=(const  Workout& ) const;
    unsigned int get_distanza() const;
    unsigned int get_pianura() const;
    unsigned int get_salita() const;
    unsigned int get_discesa() const;
};


#endif // CORSA_H
