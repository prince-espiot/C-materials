#include "register.hpp"
#include "aircraft.hpp"
#include "boat.hpp"
#include <fstream>
#include <sstream>
#include<limits>
//TODO: implement Register's members

 void Register::Add(Vehicle* v){
     vehicles_.push_back(v);
 }

 void Register::Save(const std::string& filename) const{
     
     std::ofstream output(filename);
    
     for (auto i : vehicles_ )
    {
         i->Write(output);
    } 
}

 bool Register::ReadLine(std::istream& stream){ //come back
            Vehicle  *v;
            char c = stream.peek();
        if (c =='A'){
            v=Aircraft::Read(stream);

            if (v!=NULL){
                Add(v);
                return true;
            }
        }
        else if (c =='B'){
            v = Boat::Read(stream);
            if (v!=NULL){
                Add(v);
                return true;
            }
        }else {
     stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
     return false;
        
 }
                
 
int Register::Load(const std::string& filename){
        std::ifstream istr (filename);
        int i =0;
        
        if(!istr.is_open()){
            return -1;
        }
        while (!istr.eof()){
            if(ReadLine(istr)==true){
                ReadLine(istr);
                i++;
            }
        }
        istr.close();
    return i;
    
}

void Register::Print(){

    for (auto i : vehicles_)
    {
        i->Print();
    }
}

size_t Register::Size() const{
    return vehicles_.size() ;
}

Register::~Register(){

}