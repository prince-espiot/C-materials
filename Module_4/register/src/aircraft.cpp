#include "aircraft.hpp"
#include <sstream>

//TODO: implement Aircraft's members

Aircraft::Aircraft(std::string register_number, std::string owner, std::string model, double wingspan, unsigned int cruise_speed):Vehicle(register_number,owner),model_(model),
                    wingspan_(wingspan),cruise_speed_(cruise_speed){}
        
void Aircraft::Write(std::ostream& stream){

      stream<<"A;"<<this->GetRegisterNumber()<<";"<<this->GetOwner()<<";"<<model_<<";"<<wingspan_<<
            ";"<<cruise_speed_<<std::endl;
}

void Aircraft::Print(){
            Write(std::cout);
}

 Aircraft* Aircraft::Read(std::istream& stream){
      std::string regis_number;
      std::string owner;
      std::string model;
      std::string wingspan;
      std::string cruise_speed;
    
     std::string input;
	std::getline(stream,input,';');  
    if (input[0] != 'A'){
         return nullptr;
      }else {
    std::getline(stream,regis_number,';');
	std::getline(stream,owner,';');
	std::getline(stream,model,';');
	std::getline(stream,wingspan,';');
	std::getline(stream,cruise_speed,';');
			
    }  
        return new Aircraft(regis_number,owner,model,std::stod(wingspan),std::stoi(cruise_speed));
}

    
        