#include "dog.hpp"

Dog::Dog(const std::string& name, double weight):Mammal(weight), name_(name){

}

std::string Dog::GetName()const {
    return name_;
}

 std::string Dog::MakeSound(){
     std::string sound = "Wuff!";
     return sound;
 }