#ifndef CICLISMO_H
#define CICLISMO_H
#include <workout.h>

class Ciclismo: virtual public Workout{
private:
    unsigned int distanza;
    unsigned int pianura;
    unsigned int salita;
    unsigned int discesa;
    static unsigned int constPian;
    static unsigned int constSal;
    static unsigned int constDisc;
public:
    Ciclismo(unsigned int =0, unsigned int = 0, unsigned int = 0, unsigned int = 0, unsigned int = 0);
    Ciclismo(const Ciclismo&);
    virtual unsigned int calorie() const;
    virtual unsigned int GrassiBruc() const;

    unsigned int get_distanza() const;
    unsigned int get_pianura() const;
    unsigned int get_salita() const;
    unsigned int get_discesa() const;
    unsigned int avg_Speed() const;

    void set_distanza(unsigned int);
    void set_pianura(unsigned int);
    void set_salita(unsigned int);
    void set_discesa(unsigned int);
    virtual bool operator==(const Workout& ) const;
    virtual bool operator<=(const Workout& ) const;
    virtual bool operator>=(const Workout& ) const;
};

#endif // CICLISMO_H
