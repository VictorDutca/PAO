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
    unsigned int get_durata() const;
};

#endif // WORKOUT_H
