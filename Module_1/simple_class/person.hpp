#ifndef AALTO_ELEC_CPP_PERSON
#define AALTO_ELEC_CPP_PERSON

#include <string>
// define your Person class here
class Person
{
private:
    /* data */
    std::string name_;
    int birthyear_; //compute year  //int age
    
public:         
    Person(std::string name, int year);  //Person constructor
    
    std::string& GetName ()  ;
    int GetAge (int year) ;
};

#endif


