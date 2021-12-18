#include "poly.hpp"
#include <sstream>
#include <vector>
#include<iostream>


Poly& Poly::operator+=(Poly const& b) {

    for (auto const& i: b.values_) {
        values_[i.first] += i.second;
    }
    return *this;
}

Poly operator+(const Poly& a, const Poly& b){
    Poly add;
    add += a;
    add += b;
    return add;
}

Poly& Poly::operator-=(Poly const& b) {
    for (auto const& i: b.values_) {
        values_[i.first] -= i.second;
    }
    return *this;
}
Poly operator-(const Poly& a, const Poly& b) {
    Poly sub;
    sub += a;
    sub -= b;
    return sub;
}
Poly operator-(const Poly& p) {
    Poly sub;
    sub -= p;
    return sub;
    }

std::istream& operator>>(std::istream& is, Poly& p) {
    
    std::string mystr;
    is >> mystr;
    std::stringstream ss(mystr);
    while (ss)
    {
        char s;
        int multi;
        int exp;
        ss >> multi >> s >> exp;
        p[exp] = multi;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Poly& p){
      auto it = p.rbegin();
   auto end = p.rend();
   while (it != end) {
      os << it->second << "x" << it->first;
      it++;
      if (it != end) {
         if (it->second >= 0)
            os << "+";
      }
   }
   return os;
}  

bool operator<(const Poly& a, const Poly& b) {
    if (a.end()->first != 0 && b.end()->first != 0){
        return a.end()->first < b.end()->first;
        }

    else if (a.end()->first == 0 && b.end()->first != 0) {
        return true;
    }

    else if (a.end()->first  > b.end()->first ) {
            return false;
    }

    else if (a.end()->first != 0 && b.end()->first == 0) {
        return false;
    }
    else { return false;}
    }

bool operator>(const Poly& a, const Poly& b){
    if (a.end()->first != 0 && b.end()->first != 0){
        return a.end()->first > b.end()->first;
        }
    else if (a.end()->first == 0 && b.end()->first != 0) {
        return false;
    }
    else if (a.end()->first != 0 && b.end()->first == 0) {
        return true;
    }
    else { return false;}
    }

bool operator==(const Poly& a, const Poly& b) {
        return a.end()->first == b.end()->first;
    }

bool operator!=(const Poly& a, const Poly& b) {
        return a.end()->first != b.end()->first;
}