#include "person.hpp"

// define your Person class' functions here
//defualt constructor

Person::Person(std::string name, int year)
       :name_(name),birthyear_(year)
{

}

// getter sside
 std::string& Person::GetName()  {
    return name_;
}

int Person::GetAge(int year ) 
{  
    return birthyear_ = year - birthyear_;  //get the age
}


