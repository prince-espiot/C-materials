#include "rectangle.hpp"

#include <iostream>

// Write you function here and test it with the main.
double Area (double height, double width){
    return height*width;
}

double Circumference (double height, double width){
    return 2*(height + width);
}


void Rectangle() {

    double height,width=0;

    std::cout<< "Please enter width and height"<<std::endl;
    std::cin >> width >> height;

    std::cout << "Area: "<< Area(height,width)<<std::endl;
    std::cout << "Circumference: "<< Circumference(height,width)<<std::endl;
    
    
}

