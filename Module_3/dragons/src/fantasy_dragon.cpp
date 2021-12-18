#include "fantasy_dragon.hpp"

// Define FantasyDragon's methods here  
//FantasyDragon::FantasyDragon(const std::string& name, size_t age, size_t size):Dragon( name,  age,  size){}

void FantasyDragon::Eat(std::list<Food>& food) {

    auto it = food.begin();

    while (it != food.end()) {

        if (it->type == FoodType::People || it->type == FoodType::PeopleFood)

        {

            this->size_ += 1;

            std::cout << "Fantasy dragon ate: " << it->name << std::endl;

            food.erase(it);

            it = food.begin();

        } else {it++;}

    }

}
//lemee see

void FantasyDragon::Hoard(std::list<Treasure> &treasure)  {
    auto it = treasure.begin();

    //std::list <Treasure> tee;

    while (it != treasure.end())
    {
        if (it->type == TreasureType::Jewellery){ 
            this->treasures.push_back(*it);     
            std::cout<<"Fantasy dragon received: "<<it->name<<std::endl;
            treasure.erase(it);
            it = treasure.begin();
        }else{it++;}
    }

}