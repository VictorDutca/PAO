#ifndef CORSA_H
#define CORSA_H
#include <workout.h>

class Corsa : virtual public Workout {
private:
    unsigned int distanza;
    unsigned int pianura;
    unsigned int salita;
    unsigned int discesa;
    static unsigned int constPian;
    static unsigned int constSal;
    static unsigned int constDisc;
public:
    Corsa (unsigned int =0, unsigned int = 0, unsigned int = 0, unsigned int = 0, unsigned int = 0);
    //Corsa(const Corsa&);
    virtual double calorie() const;
    virtual double GrassiBruc() const;
    virtual bool operator==(const Workout& ) const;
    virtual bool operator<=(const Workout& ) const;
    virtual bool operator>=(const Workout& ) const;
    unsigned int get_distanza() const;
    unsigned int get_pianura() const;
    unsigned int get_salita() const;
    unsigned int get_discesa() const;
    void set_distanza(unsigned int);
    void set_pianura(unsigned int);
    void set_salita(unsigned int);
    void set_discesa(unsigned int);

    unsigned int avg_Speed() const;
};

#endif // CORSA_H
