#ifndef SCHEDULES_H
#define SCHEDULES_H
#include<workout.h>
#include<lista.h>


class Schedules
{
public:
    Dlista<Workout*> L;
    Schedules();
    Dlista<Workout*> get_corse() const;
    Dlista<Workout*> get_ciclismi();
    Dlista<Workout*> get_nuoti();
    Dlista<Workout*> get_Triathlon();
    double calorie_totali();

};

//chiedere a favero se ha senso o complica la vita tenere
//una class schedule cosi' specifica.
//per evitare il typename





#endif // SCHEDULES_H
