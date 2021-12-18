#include "customer.hpp"
#include <iostream>

   
Customer::Customer(std::string const &CustomerName, std::string const &CustomerNumber):name_(CustomerName), customerID_(CustomerNumber)
{

}

std::string Customer::GetName () const{
    return name_;
}

std::string Customer::GetID () const{
    return customerID_;
}

int Customer::GetLoanAmount () const{
    std::vector<Book> book_;

    size_t amnt = book_.size();
    return amnt;
}

std::vector<Book> Customer::GetLoans () const{  //not clear
    return book_;
}

bool Customer::LoanBook (Book& book){

    if (book.Loan()){
        book_.push_back(book);
        book.GetDueDate();
    }
    return book.Loan();
}

void Customer::ReturnBook (Book& book){ //usderstnad its
    
    
    for(unsigned int i =0 ; i <book_.size(); i++){
        
        if (book_[i].GetName()==book.GetName())
            book_.erase(book_.begin()+i);
    }
    book.Restore();
}

/*Customer: <name>, <customer_id>, has <number_of_loans> books on loan:\n
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
- Book: <name>, author: <author>, ISBN: <isbn>, loaned <true/false>, due date: <day>.<month>.<year>\n
    * This function should not alter the Customer object's state, in other words the function should be const.
    */
void Customer::Print() const{
    
    std::cout<<"Customer: "<<name_<<", "<<customerID_<<","<<" has "<<GetLoanAmount()<<" books on loan:"<<std::endl;
    
    std::vector<Book>::size_type i;
    for(i=0; i<book_.size();i++){
        std::cout<<"- "<<"Book: "<<book_[i].GetName()<<" author: "<<book_[i].GetAuthor()<<","<<" ISBN: "<<book_[i].GetISBN()<<","<<
        " loaned "<<(book_[i].GetStatus() ?"true":"false")<<","<<" due date: "<<book_[i].GetDueDate().day <<"."<<book_[i].GetDueDate().month+1<<"."<<book_[i].GetDueDate().year<<std::endl;
    }
    
}