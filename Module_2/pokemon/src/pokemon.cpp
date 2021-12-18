#include "pokemon.hpp"
#include <algorithm>
#include <map>

PokemonCollection::PokemonCollection(PokemonCollection collection, PokemonCollection collection2):pokemons_(collection2.pokemons_){
    for (auto i : collection.pokemons_)
    {
        pokemons_.push_back(i);
    }

   pokemons_.sort();
   pokemons_.unique();

   
    
} //correct?????

void PokemonCollection:: Add(const std::string& name, size_t id){
    pokemons_.push_back(make_pair(name,id));
}


bool PokemonCollection::Remove(const std::string& name, size_t id){
    
    unsigned int a = pokemons_.size();
        
    pokemons_.remove(make_pair(name,id));

    if (a>pokemons_.size()){
        return true;
    }else{
        return false;
    }  
}

 void PokemonCollection::Print() const{
        for(auto i = pokemons_.cbegin();i != pokemons_.cend();i++){

            std::cout<<"id: "<< i->second <<", "<<"name: "<<i->first<<std::endl;  
        }     
 }


 void PokemonCollection::SortByName(){
      pokemons_.sort();
 }


 void PokemonCollection::SortById(){
     std::list<std::pair<size_t, std::string>> a;

    for (auto i : pokemons_)
    {
        a.push_back(make_pair(i.second,i.first));   

    }
    pokemons_.clear();
    a.sort();

    for (auto j : a)
    {
        pokemons_.push_back(make_pair(j.second,j.first));
    }
    
 }
