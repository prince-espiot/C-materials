/* Add include guards here */
#ifndef AALTO_ELEC_CPP_DIAGONAL_PRINTER_CLASS
#define AALTO_ELEC_CPP_DIAGONAL_PRINTER_CLASS
#include <string>
#include <iostream>
#include "string_printer.hpp"
/* TODO: class DiagonalPrinter
 * ------------
 * Description:
 * A class that is used to print strings diagonally (see below).
 * The class inherits (public inheritance) class StringPrinter.
 * ------------
 * Functions:
 * 
 * A constructor that takes three parameters:
 *  - The first line, which is "" by default, i.e. it is not printed at all
 *  - The last line, which is "" by default, i.e. it is not printed at all either
 *  - A reference to the output stream, which is std::cout by default
 * 
 * Overrides the necessary members from the base class.
 * ------------
 * Other:
 * DiagonalPrinter prints a string diagonally. For the string "like this":
<first line>\n
l        \n
 i       \n
  k      \n
   e     \n
         \n
     t   \n
      h  \n
       i \n
        s\n
<last line>\n
 * where <first line> and <last line> are replaced by the strings given in the
 * constructor. If the first line is empty, it is not printed. The same applies
 * to the last line.
 */
class DiagonalPrinter : public StringPrinter
{
private:
    std::string first_;
    std::string second_;
    
public:
    DiagonalPrinter(const std::string& first = "",const std::string& second = "",std::ostream &os = std::cout):StringPrinter(os),first_(first),second_(second){}

virtual StringPrinter& operator()(const std::string &somestring){
        if(first_.length())
        os_ << first_ << std::endl;
        for (unsigned int i = 0; i < somestring.length();i++)
        {
            for (unsigned int j = 0; j < somestring.length(); j++)
            {   
                if(i == j){ 
                    os_ << somestring[i];
                }else{
                 os_<<' ';
                 }       
            }
        os_ << std::endl;
        }
        if(second_.length())
        os_ << second_ <<std::endl;
        return *this;
}
    ~DiagonalPrinter(){}

DiagonalPrinter* Clone() const {
    return new DiagonalPrinter(first_,second_, os_);
}
};


#endif