/* Add include guards here */
#ifndef AALTO_ELEC_CPP_STANDARD_PRINTER_CLASS
#define AALTO_ELEC_CPP_STANDARD_PRINTER_CLASS
#include <iostream>
#include "string_printer.hpp"
/* TODO: class StandardPrinter
 * ------------
 * Description:
 * A minimal StringPrinter implementation with no special functionality.
 * ------------
 * Functions:
 * A constructor that takes a single parameter:
 *  - A reference to the output stream, which is std::cout by default
 * 
 * Overrides the necessary members from the base class.
 * ------------
 * Other:
 * StandardPrinter prints a string like one normally would but with a 
 * newline at the end. For the string "like this":
like this\n
*/
class StandardPrinter : public StringPrinter
{
private:
    /* data */
public:
    StandardPrinter(std::ostream& os=std::cout):StringPrinter(os){
       /* std::string line;
       os << line << std::endl; */
    } 

    virtual StringPrinter& operator()(const std::string &somestring){
        os_<< somestring << std::endl;
        return *this;
    }
    
    StandardPrinter* Clone() const {

    return new StandardPrinter(os_);
}
};


#endif