#include "workout.h"

Workout::Workout(unsigned int d): durata(d) {}

bool Workout::operator<=(const Workout& w) const {
    return durata <= w.durata;
}

bool Workout::operator==(const Workout& w) const{
    return durata == w.durata;
}

bool Workout::operator>=(const Workout&  w) const {
    return durata >= w.durata;
}

unsigned int Workout::get_durata() const {
    return durata;
}

void Workout::set_durata(unsigned int x) {
   durata = x;
}
