#include "vector_strings.hpp"

#include <iostream>
#include <vector>

enum Commands {
    eADD,
    ePRINT,
    eREMOVE,
    eQUIT,
    eNONE
};

Commands hashit (std::string const& inString) {
    if (inString == "ADD") return eADD;
    if (inString == "PRINT") return ePRINT;
    if (inString == "REMOVE") return eREMOVE;
    if (inString == "QUIT") return eQUIT;

    return eNONE;
}

void Adder(std::vector<std::string>& names) {

    std::string name;
    std::cout<<"Enter a name:"<<std::endl;
    std::cin>> name;
    std::cout<<"Number of names in the vector:"<<std::endl;

  //  while (true)
   // {   
        names.push_back(name);      /* code */
   //     if(name != "\n")
            /* code */
   //          break;
   // }
    std::cout<< names.size() <<std::endl;
    
}

void Remover(std::vector<std::string>& names) {
    
}

void Printer(std::vector<std::string>& names) {
    
}

void CMDReader() {
    
    std::cout << "Commands: ADD, PRINT, REMOVE, QUIT"<<std::endl;

    //std::cin >>
}

