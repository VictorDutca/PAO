#ifndef WORKOUT_H
#define WORKOUT_H

class Workout {
private:
    unsigned int durata;
public:
    Workout (unsigned int=0);
    virtual ~Workout() = default;
    virtual double calorie( ) const = 0;
    virtual double GrassiBruc( ) const =0;
    virtual bool operator==(const Workout& ) const;
    virtual bool operator<=(const Workout& ) const;
    virtual bool operator>=(const Workout& ) const;
    virtual unsigned int get_durata() const;
    virtual void set_durata(unsigned int);
};

#endif // WORKOUT_H
