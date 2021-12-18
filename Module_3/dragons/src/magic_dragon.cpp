#include "magic_dragon.hpp"


void MagicDragon::Eat(std::list<Food>& food)  {

    auto it = food.begin();

    while (it != food.end()) {

        if (it->type == FoodType::Herbs)

        {  //yes before it did and i modified the coode here

            this->size_ += 1;

            std::cout << "Magic dragon ate: " << it->name << std::endl;

            food.erase(it);

            it = food.begin();

        } else {it++;}

    }

}


void MagicDragon::Hoard(std::list<Treasure>&treasure)  {
    auto it = treasure.begin();

    //std::list <Treasure> tee;  //empty list to hold the hoard list

    while (it != treasure.end())
    {
        if (it->type == TreasureType::Potions){ 
            this->treasures.push_back(*it);     
            std::cout<<"Magic dragon received: "<<it->name<<std::endl;
            it=treasure.erase(it);  //okk
            it = treasure.begin();
        }else{it++;}
    }
    

}