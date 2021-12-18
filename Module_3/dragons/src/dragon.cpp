#include "dragon.hpp"


std::ostream& operator<<(std::ostream& out, const Dragon& drag){
    out << "Dragon named: " << drag.GetName() << ", age: " << drag.GetAge() <<", size: "<< drag.GetSize() <<std::endl;
    out<<"Treasures:"<<std::endl;
    
    for (auto i : drag.GetTreasures())
    {
        out<<i.name<<std::endl;
        
    }
    return out;
} 


