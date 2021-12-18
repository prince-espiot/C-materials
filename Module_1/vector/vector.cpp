#include "vector.hpp"
#include <iostream>
#include <vector>

int GetMin(std::vector<int> v) {
    
    int min_number= v[0];
    for(unsigned int i = 0; i < v.size() ; i++)
    {
            if(v[i] < min_number) {
                min_number = v[i];
            }

    }   
    return min_number;    
}

int GetMax(std::vector<int> v) {
    int max_number= v[0];
    for(unsigned int i = 0; i < v.size() ; i++)
    {
            if(v[i] > max_number) {
                max_number = v[i];
            }

    }   
    return max_number;    
}

double GetAvg(std::vector<int> v) {
    double sum;
    double average;

    for(unsigned int i = 0; i < v.size() ; i++){
        sum +=v[i];
    }

    average=sum/v.size();
    return average; 
}
