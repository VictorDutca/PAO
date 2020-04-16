#ifndef CICLISMO_H
#define CICLISMO_H
#include <workout.h>

class Ciclismo: virtual public Workout{
private:
    //avg speed
    unsigned int distanza;
    unsigned int pianura;
    unsigned int salita;
    unsigned int  discesa;
    static unsigned int constPian;
    static unsigned int constSal;
    static unsigned int constDisc;
public:
    Ciclismo(unsigned int =0, unsigned int = 0, unsigned int = 0, unsigned int = 0, unsigned int = 0);
    virtual double calorie() const;
    virtual double GrassiBruc() const;
    unsigned int get_distanza() const;
    unsigned int get_pianura() const;
    unsigned int get_salita() const;
    unsigned int get_discesa() const;
    virtual bool operator==(const Workout& ) const;
    virtual bool operator<=(const Workout& ) const;
    virtual bool operator>=(const Workout& ) const;
};

#endif // CICLISMO_H
