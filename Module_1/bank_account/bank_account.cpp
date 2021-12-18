#include "bank_account.hpp"
#include <iostream>
// constructor defintion
//BankAccount(std::string const& owner, std::string const& account_number, double balance = 0.0);

BankAccount::BankAccount(std::string const& owner, std::string const& account_number, double balance)
            :owner_(owner),account_number_(account_number),balance_(balance)
{

}

std::string BankAccount::GetOwner() const{
    return owner_;
}

std::string BankAccount::GetNumber() const {
    return account_number_;
}

double BankAccount::GetBalance() const{
    return balance_;
}

void BankAccount::Deposit(double amount){

        balance_ +=amount;
}

bool BankAccount::Withdraw (double amount){

    if (amount <= balance_){
        balance_ -=amount;
        return true;
    }else
    {
        return false;/* code */
    }
    
}

//Account num: <account number>, owned by: <owner>, balance: <balance> eur.
void BankAccount::Print() const {
    std::cout <<"Account num: "<<account_number_<<","<<" owned by: "<<owner_<<","<<" balance: "<<balance_<<" eur."<<std::endl;
}


/* Transfer:
 * Transfers money from the source account to the target account. 
 * If the parameter amount is bigger than the current balance of the source account, 
 * the function returns false and no transfer is made. 
 * If the amount is valid, that is smaller than the source account's current balance, 
 * the function adds the parameter amount to the target account's balance, 
 * reduces the amount from the source account's balance and returns true.
 */
//bool Transfer(BankAccount& source_account, BankAccount& target_account, double amount);
bool Transfer(BankAccount& source_account, BankAccount& target_account, double amount){

            if (amount<source_account.GetBalance())
            {
                target_account.Deposit(amount);
                source_account.Withdraw(amount);
                /* code */return true;
            }
            else
            {
                 /* code */
                
                return false;
            }
            
}