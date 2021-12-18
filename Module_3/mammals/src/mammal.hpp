#ifndef AALTO_ELEC_CPP_MAMMAL_CLASS
#define AALTO_ELEC_CPP_MAMMAL_CLASS

#include <iostream>
#include <string>

class Mammal {
public:
    Mammal(double weight);
    double GetWeight() const;

private:
    double weight_;
};

#endif
