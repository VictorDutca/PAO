#ifndef TRIATHLON_H
#define TRIATHLON_H
#include <corsa.h>
#include <ciclismo.h>
#include <nuoto.h>
#include <QGroupBox>

class Triathlon : public Corsa, public Ciclismo, public Nuoto {
public:
    Triathlon(unsigned int, unsigned int,
              unsigned int, unsigned int, unsigned int, unsigned int,
              unsigned int, unsigned int, unsigned int, unsigned int,
              unsigned int, unsigned int, unsigned int, unsigned int);

    virtual unsigned int calorie() const;
    virtual unsigned int GrassiBruc() const;
    virtual bool operator==(const Workout&) const;
    virtual bool operator>=(const Workout&) const;
    virtual bool operator<=(const Workout&) const;

};

#endif // TRIATHLON_H
