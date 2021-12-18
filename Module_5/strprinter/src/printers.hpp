/* Add include guards here */
#ifndef AALTO_ELEC_CPP_PRINTERS_CLASS
#define AALTO_ELEC_CPP_PRINTERS_CLASS
#include "string_printer.hpp"
#include "standard_printer.hpp"
#include "diagonal_printer.hpp"
#include <string>
#include <map>
#include <utility>
#include <stdexcept>
/* TODO: class Printers
 * ------------
 * Description:
 * A storage for StringPrinter pointers associated with a name. The class has 
 * ownership of the objects.
 * ------------
 * Functions:
 * 
 * A default constructor that initializes the object with zero printers.
 * 
 * A copy constructor that copies the object.
 * 
 * Add: A function that adds a new StringPrinter object to the collection
 * and associates it with a name.
 * Takes two parameters:
 *  - a string that contains the name
 *  - the StringPrinter pointer to be added
 * Throws:
 *  - std::invalid_argument if an association for the name already exists ("Duplicate index").
 *  - std::invalid_argument if the pointer is null ("Invalid printer").
 * Note: The Printers object takes ownership of the pointer and is
 *  therefore responsible for eventually calling delete on the pointer.
 * 
 * Indexing operator: The collection is indexed using the
 * name (string) and returns a reference to the associated StringPrinter.
 * Throws:
 *  - std::invalid_argument if an association does not exist ("Unknown index").
 * 
 * Copy assignment operator: copies the object given to self.
 * ------------
 * Members:
 * Whatever you deem necessary.
 * ------------
 * Other:
 * Copying means copying the contained StringPrinters as well.
 * Remember to also implement the destructor.
 */

class Printers
{
private:
    /* data */ 
   // std::string somestring_;
    std::map<std::string , StringPrinter*> data_; 
public:
        //defualt constructor
    Printers() = default;
    //copy constructor
    Printers(const Printers& obj){
        *this = obj;
    }

void Add (const std::string name , StringPrinter* strp){
    auto ret = data_.find(name);
    if (ret !=data_.end()){
        throw std::invalid_argument("Duplicate index");
    }
    
    if (strp == NULL){
        throw std::invalid_argument("Invalid printer");
    }else{
    data_[name]= strp; 
     }  
}

StringPrinter& operator[] (const std::string& name){
    auto it = data_.find(name);
    if (it ==std::end(data_)){
        throw std::invalid_argument("Unknown index");
        
    }
        return *data_[name] ;    
    
}

Printers& operator=(const Printers &obj){
    for (auto i = data_.begin();i !=data_.end();i++)
        {
            delete i->second;
        }
        data_.clear();
    for (auto i = obj.data_.begin();i !=obj.data_.end();i++)
        {
            data_[i->first] = i ->second->Clone();
        }

    return *this;
}


    ~Printers(){
        for (auto i = data_.begin();i !=data_.end();i++)
        {
            delete i->second;
        }
        data_.clear();
    }

/* Printers* Clone() const {

    return new Printers();
} */
};

#endif