#include "dragon_cave.hpp"

// Define DragonCave's methods here

DragonCave::DragonCave(){}
DragonCave::~DragonCave(){}


std::list<Dragon*>  DragonCave::GetDragons () const{ //later
    return sisi_;

}

void DragonCave::Accommodate (Dragon*drag){
 sisi_.push_back(drag);
}

void DragonCave::Evict (const std::string &name){
    for (auto i : sisi_)
    {
        if (name==i->GetName()){
            sisi_.remove(i);
            break;
        }
    }

  }



std::ostream& operator<<(std::ostream& out, const DragonCave &cave){
    out<<"DragonCave dwellers:"<<std::endl;

    for (auto i : cave.GetDragons())
    {
        out<<std::endl;
        out<<*i;
        
    }
    return out;
    out << std::endl;
}