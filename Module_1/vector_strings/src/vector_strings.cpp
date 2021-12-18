#include "vector_strings.hpp"

#include <iostream>
#include <vector>

enum string_code {
    eADD,
    ePRINT,
    eREMOVE,
    eQUIT,
    eNONE
};

string_code hashit (std::string const& inString) {
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

    while (true)
    {   
        names.push_back(name);      /* code */
        if(name != "\n")
            /* code */
             break;
    }
    std::cout<< names.size() <<std::endl;
}

void Remover(std::vector<std::string>& names) {
    ///pop_back.
    std::cout<<"Removing the last element:"<<std::endl;
    int n = names.size();
    std::cout<<names[n-1]<<std::endl;
    names.pop_back();
 
}

void Printer(std::vector<std::string>& names) {

    for(unsigned int i = 0; i < names.size(); i++ )
    {
        std::cout << names[i] <<std::endl;
    }
}


void CMDReader() {
    std::vector<std::string> entry;
    std::string com ;
    std::cout<< "Commands: ADD, PRINT, REMOVE, QUIT" <<std::endl;

    do
    {
        /* code */
        std::cout << "Enter a command:" << std::endl;
        std::cin >> com;

        switch (hashit(com) )
        {
        case eADD : /* constant-expression */
            //ReadUserinput(entry);
             Adder(entry);/* code */
            break;

        case ePRINT:
            Printer(entry); 
            break;

        case eREMOVE:
            Remover(entry);
            break;
        case eQUIT:
            break; // exit(1);
        default:
            std::cout<<"This is not a valid entry"<<std::endl;
            break;
        } 
    }while (com != "QUIT"); 
}

