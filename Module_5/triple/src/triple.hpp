/* Add include guards here */
#ifndef AALTO_ELEC_CPP_TRIPLE_CLASS
#define AALTO_ELEC_CPP_TRIPLE_CLASS
#include <memory>
#include <string>
#include <iostream>
#include <type_traits>
/* Class: Triple
 * -------------
 * The template class Triple is a container class, which holds three values.
 * All of the values can be of different type. All of the values should be
 * private.
 *
 * The constructor of the class takes three const references to values as a
 * parameter. The parameters are in order, in other words, after construction
 * the first parameter should be accessible through the public member function
 * First, the second parameter through the public member function Second, and
 * the third through the public member function Third. 
 *
 * The default empty constructor should also work.
 *
 * The Triple class should also support the copy constructor, and assignment
 * operations.
 */
 template <typename A, typename B , typename C>
 class Triple
 {
 private:
     A first_;
     B second_;
     C third_;
 public:
     //Triple( ) = defualt;  ///defualt

    Triple (const A& first, const B& second, const C& third ):first_(first), second_(second), third_(third){      //main guy
            
    }
     Triple (const Triple <A,B,C> & obj){
        this->first_ = obj.first_;
        this-> second_ = obj.second_;
        this->third_ = obj.third_;
    } 

    Triple& operator= (const Triple <A,B,C> &obj){
            this->first_ = obj.first_;
        this-> second_ = obj.second_;
        this->third_ = obj.third_;

        return *this;
    }

    const A& First() const{
        return first_;
    }

     const B& Second() const {
        return second_;
    }

     const C& Third() const {
        return third_;
    }




friend bool  operator==(const Triple<A,B,C> & one, const Triple <A,B,C>& two){
        if (one.First() == two.First() && one.Second() == two.Second() && one.Third() == two.Third() ){

            return true;
        }else {
            return false;
        }
}

friend bool  operator!=(const Triple<A,B,C> & one, const Triple <A,B,C> &two){
        if (one.First() != two.First() && one.Second() != two.Second() && one.Third() != two.Third() ){

            return true;
        }else {
            return false;
        }
}

friend  std::ostream& operator<<(std::ostream& os, const Triple <A,B,C> & tri){
        os << "[" << tri.first_ <<", " << tri.second_ <<", "<< tri.third_ << "]";
        return os;
}

     ~Triple(){}
 };
 

 template <typename A, typename B , typename C>
bool IsHomogenous (Triple < A , B , C > ){
    return std::is_same < A , B >::value && std::is_same <B,C>::value;
   // return detail::IsHomogenous <A,B,C>;
}

/* Public member functions:
 * ------------------------
 * The Triple class has three public member functions, which are used to
 * access the stored elements. All three should work with const instances
 * of Triple.
 *
 * Function: First
 * The function takes no parameters.
 * The function returns a const reference to the first value of the triple.
 *
 * Function: Second
 * The function takes no parameters.
 * The function returns a const reference to the second value of the triple.
 *
 * Function: Third
 * The function takes no parameters.
 * The function returns a const reference to the third value of the triple.
 */

/* Non-member functions:
 * ---------------------
 * Function: IsHomogenous
 * The function is a non-member function that takes a Triple as a parameter.
 * The function returns a boolean value indicating whether the triple is
 * homogenous or not. A triple is homogenous if all of its three values are of
 * the same type.
 * Hint: specialisation can help you here.
 */


/* Operator overloads:
 * -------------------
 * The triple class should support the following operators:
 *
 * Assignment operator, =
 * The default functionality should do here.
 *
 * Equality operator, ==
 * You can assume that all the values in the triple can be compared by the
 * == -operator. Two triples are equal if the corresponding values in both
 * of the triples are equal.
 *
 * Inequality operator, !=
 * You can assume that all the values in the triple can be compared by the
 * != -operator. Two triples are inequal if even one corresponding value in
 * the triples is different.
 *
 * The output stream operator, <<
 * You can assume that all the values in the triple support the << -operator.
 * The triple should be printed to the output stream in the following format: 
[<first value>, <second value>, <third value>]
 * Note that there is NO new line at the end of the output.
 */

/* Remember the endif here to close the header guards */





#endif