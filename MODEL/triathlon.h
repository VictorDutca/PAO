#ifndef TRIATHLON_H
#define TRIATHLON_H
#include <corsa.h>
#include <ciclismo.h>
#include <nuoto.h>

class Triathlon : public Corsa, public Ciclismo, public Nuoto {
public:
    //  Triathlon(Corsa, Ciclismo, Nuoto);
    Triathlon(unsigned int, unsigned int,
              unsigned int, unsigned int, unsigned int, unsigned int,
              unsigned int, unsigned int, unsigned int, unsigned int,
              unsigned int, unsigned int, unsigned int, unsigned int,unsigned int);
    virtual double calorie() const;
    virtual double GrassiBruc() const;
    virtual unsigned int get_durata() const;
    virtual bool operator==(const Workout&) const;
    virtual bool operator>=(const Workout&) const;
    virtual bool operator<=(const Workout&) const;
};

#endif // TRIATHLON_H
