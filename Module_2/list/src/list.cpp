#include "list.hpp"
#include <iostream>

// Implement the functions here

std::istream& GetLines(std::istream& is, std::list<std::string>& list){
    list.clear();
    std::string line;
    while (is.good()) {
        
        std::getline(is,line);
       if (is.eof()) break;
        list.push_back(line);
    }

 return is;
}

void Print(const std::list<std::string>& list){
    for (auto i : list)
    {
        std::cout << i << std::endl;
    }
    
}

void SortAndUnique(std::list<std::string>& list){
    list.sort();
    list.unique();
}
