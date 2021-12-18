#include <iostream>
#include "book.hpp"
#include "customer.hpp"
#include "library.hpp"


Library::Library (std::string const &name ):name_(name)
{

}

std::string Library::GetName() const{
    return name_;
}

std::vector<Book>& Library::GetBooks(){

    return books_;
}

std::vector<Customer>& Library::GetCustomers (){
    return customer_;
}
 //above good

Book Library::FindBookByName (std::string const &book_name ){  //not clear
        bool empty = false;

        unsigned int i;
        for (i=0;i<books_.size();i++)
        {
            if (books_[i].GetName() == book_name)
            {
               
                empty=true;
                break;
            }
            
        }
        if (empty==true)
        {
            return books_[i];
            
        }else{
            return Book("", "", "");
        }
        
}


std::vector<Book> Library::FindBooksByAuthor (std::string const &author ){ //not clear
        
        unsigned int i;
        std::vector<Book> authorbooks;
        for (i=0;i<books_.size();i++)
        {
            if (books_[i].GetAuthor() == author)
            {
                authorbooks.push_back(books_[i]);
                
            }
            
        }
        return authorbooks;

        

}

std::vector<Book> Library::FindAllLoanedBooks (){
    unsigned int i;
    std::vector<Book> loanbook;
     for (i=0;i<books_.size();i++)
        {
            if (books_[i].Loan() == true)
            {
                loanbook.push_back(books_[i]);
                
            }
            
        }
        return loanbook;

    
}

Customer Library::FindCustomer (std::string const &CustomerID){
        bool empty = false;

        unsigned int i;
        for (i=0;i<customer_.size();i++)
        {
            if (customer_[i].GetName() ==CustomerID )
            {
                /// return books_[i];
                empty=true;
                break;
            }
            
        }
        if (empty==true)
        {
            return customer_[i];
            
        }else{
            return Customer("", "");
        }
        

    
}