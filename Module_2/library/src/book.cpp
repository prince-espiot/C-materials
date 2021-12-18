#include "book.hpp"

#include <ctime>
#include <iostream>


Book::Book(std::string const &BookName, std::string const &Author,std::string const &IsbnNumber,bool status, Date due_date )
            :name_(BookName),author_(Author),isbn_(IsbnNumber),loaned_(status) ,due_date_(due_date){
            }

std::string Book::GetName()const{
    return name_;
}

std::string Book::GetAuthor()const{
    return author_;
}

std::string Book::GetISBN() const{
    return isbn_;
}
 /* GetStatus:
    * returns the Book's status as a bool, takes no parameters.
    * This function should not alter the Book object's state, in other words the function should be const.
    */
bool Book::GetStatus () const{

    return loaned_ ;
}

Date Book::GetDueDate() const{
    return due_date_;
}


bool Book::Loan () {
    
    if (loaned_){
        return false;
    }

    loaned_=true;

    due_date_ = Date::Today();
    due_date_.month++;
  
 return true;
}


void Book::Restore (){
    due_date_= Date::Zero();
    loaned_ =false;
        
}

/* Print:
    * prints the book's information to the standard output stream.
    * The function takes no parameters and returns nothing. 
    * The output format should be like the following:
Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
    * This function should not alter the Book object's state, in other words the function should be const.
    */
void Book::Print() const{
    std::cout<<"Book: "<<name_<<","<<" author: "<<author_<<","<<" ISBN: "<<isbn_<<","<<" loaned "<<(loaned_ ?"true":"false")
   <<"," <<" due date: "<<due_date_.day<<"."<<due_date_.month<<"."<<due_date_.year<<std::endl;
}