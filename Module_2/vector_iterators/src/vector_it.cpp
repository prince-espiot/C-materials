#include <iostream>
#include <vector>
#include "vector_it.hpp"

// Implement the functions here

//std::vector<int>
std::vector<int> ReadVector(){
    std::cout << "Please enter the integer values. When you are finished, write something else." << std::endl;
    int i;

    std::vector<int> number;
    while (std::cin>>i)
    {
         number.push_back(i);
         
        /* code */
    }
    return number;
}

void PrintSum1(const std::vector<int>& num ){

    int sum = std::vector<int>::value_type(0);
    
    for(std::vector<int>::const_iterator i=num.begin(); i != num.end()-1; i++)
    {   
        sum = *(i)+*(i+1);
        std::cout <<sum<<" " ;

    }

    std::cout<<std::endl;  

}


void PrintSum2(const std::vector<int>& num){

    int sum =0;
    for(std::vector<int>::const_iterator  i=num.begin(), j = num.end()-1; i<j; ++i,--j){
            sum = *i+*j;
            std::cout <<sum<<" " ;
    }

    std::cout<<std::endl;  

}






