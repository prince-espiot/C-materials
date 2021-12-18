#include "rectangle.hpp"

#include <iostream>

// Write you function here and test it with the main.

void Rectangle() {
    double width;
    double height;
    const double two = 2.0;

    std::cout<<"Please enter width and height"<<std::endl;
    std::cin>> width >> height;
    std::cout<<"Area: "<< width*height<< std::endl;
    std::cout <<"Circumference: "<< ((int)two*( width + height))<<std::endl;

}

