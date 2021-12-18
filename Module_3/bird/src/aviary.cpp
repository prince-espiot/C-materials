#include "aviary.hpp"



 void Aviary::Add(Bird* b){
     dino_.push_back(b);
 }

    void Aviary::SpeakAll(std::ostream& out){
          for (auto i: dino_){
              i->Speak(out);
          }  
        }

    size_t Aviary::Size (){
        return dino_.size();
    }

    Aviary::~Aviary(){
    }


