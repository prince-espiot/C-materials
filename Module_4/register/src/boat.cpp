#include "boat.hpp"
#include <sstream>
//TODO: implement Boat's members


Boat::Boat(std::string register_number, std::string owner, std::string name, double draft, double power):Vehicle(register_number,owner),name_(name),
                    draft_(draft),power_(power){}

void Boat::Write(std::ostream& stream){

      stream<<"B;"<<this->GetRegisterNumber()<<";"<<this->GetOwner()<<";"<<name_<<";"<<draft_<<
            ";"<<power_<<std::endl;
}

void Boat::Print(){
            Write(std::cout);
}

Boat* Boat::Read(std::istream& stream){  
      std::string regis_number;
      std::string owner;
      std::string name;
      std::string draft;
      std::string power;
    
     std::string input;
	std::getline(stream,input,';');  
    if (input[0] != 'B'){
         return nullptr;
      }else {
    std::getline(stream,regis_number,';');
	std::getline(stream,owner,';');
	std::getline(stream,name,';');
	std::getline(stream,draft,';');
	std::getline(stream,power,';');
			
    }
        
        
        return new Boat(regis_number,owner,name,std::stod(draft),std::stod(power));
}
  